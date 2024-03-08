//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// two ways to implement a binary search tree...

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#ifndef BST_HH
#define BST_HH
#include <sys/time.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// the BSTNode class is what we're making the binary search tree out of

template<typename T>
class BSTNode
{
public: 

  BSTNode(T theKey) {key = theKey; left = NULL; right = NULL; number = 1; }
  BSTNode(T theKey, BSTNode<T> *theLeft, BSTNode<T> *theRight) { key = theKey; left = theLeft; right = theRight; number = 1; }

  const T & getKey() { return key; }
  void setKey(T theKey) { key = theKey; }
  
  int getNumber() { return number; }
  void setNumber(){ number = number + 1;}
  BSTNode<T> *getLeft() { return left; }
  void setLeft(BSTNode<T> * theLeft) { left = theLeft; }

  BSTNode<T> *getRight() { return right; }
  void setRight(BSTNode<T> * theRight) { right = theRight; }

  void print() { cout << key << " (" << number << ")" << endl; }
  
  BSTNode<T> *getNew(T & key) {
	BSTNode* newNode = new BSTNode(key);
	return newNode;
}
private:

  T key;

  BSTNode<T> *left;   // link to left child
  BSTNode<T> *right;  // link to right child
  int number;         // how many occurrences of key there are

};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// BSTREE_FAST
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// a binary search tree, implemented as a linked structure

// this is only partial--there's no remove functionality, for example

template<typename T>
class BSTree_Fast
{
public:
  //int uniquecount = 0;
  //int totalcount = 0;
  BSTree_Fast() { maxDepth = 0; uniquecount = 0; totalcount = 0; root = NULL; }  // make an empty BST

  void insert(T &);                             // put a key into the BST 
  bool contains(T &);                           // does this BST contain a certain key?
  const T & findMax();                          // what is the smallest key in the BST?
  const T & findMin();
  int getMaxDepth() { return maxDepth; }
  void print();
private:

  int maxDepth;
  int uniquecount;
  int totalcount;
  BSTNode<T> *root;                             // pointer to the node at the root of the tree
  BSTNode<T> *realroot;
};



//----------------------------------------------------------------------------
template <typename T>
void BSTree_Fast<T>::print(){
cout<<"total elements " << totalcount<<"\n";
cout<<"unique elements "<<root->getNumber()<<"\n";
cout<<"min "<<findMin()<<"\n";
cout<<"max "<<findMax()<<"\n";
string love;
string death;
string tyranny;
love.push_back('l');
love.push_back('o');
love.push_back('v');
love.push_back('e');
cout<<"contains love "<<contains(love)<<"\n";
death.push_back('d');
death.push_back('e');
death.push_back('a');
death.push_back('t');
death.push_back('h');
cout<<"contains death "<<contains(death)<<"\n";
tyranny.push_back('t');
tyranny.push_back('y');
tyranny.push_back('r');
tyranny.push_back('a');
tyranny.push_back('n');
tyranny.push_back('n');
tyranny.push_back('y');
cout<<"contains tyranny "<<contains(tyranny)<<"\n";
//cout<<"time of love "<< gettimeofday(contains(love), NULL)<<"\n";
//cout<<"time of death "<<gettimeofday(contains(death), NULL)"\n";
//cout<<"time of tyranny "<< gettimeofday(contains(tyranny), NULL)"\n";
//cout<<"contains death"<<contains("death")<<"\n";
//cout<<"contains tyranny"<<contains("tyranny")<<"\n";
}


//--------------------------------------------------------
//

template<typename T>
void BSTree_Fast<T>::insert(T & key)
{
//need to fix functions so that honor isn't the only thing in the list
  if(root == NULL){
	
	root = root -> getNew(key);
	realroot = root;
	//BSTNode <T> 
	//* root = BSTNode<T>(key);
	//set key as root
	//root = new BSTNode<T>(key); 
	//root.getNew(key);
	//root = getNew();
	//cout<<"new"<<root<<"\n";
	totalcount = totalcount + 1;
	uniquecount = uniquecount + 1;
	}else{
  	if(key < root -> getKey()){
	  root-> setLeft(root -> getNew(key));
	  totalcount = totalcount + 1;
	  uniquecount = uniquecount + 1;
	//cout<<"less"<<root<<"\n";
}else if(key > root -> getKey()){
	root -> setRight(root -> getNew(key));
	totalcount = totalcount + 1;
	uniquecount = uniquecount + 1;
	//cout<<"greater"<<root<<"\n";
}else{
//increase number by 1
//
	root-> setNumber();
	totalcount = totalcount + 1;
}
	
}
}

//----------------------------------------------------------------------------

template<typename T>
bool BSTree_Fast<T>::contains(T & key)
{
//BSTNode<T> temp = root;
bool run = true;
while(run){
  if(key > root -> getKey()){
	if(root -> getRight() == NULL){
	run = false;
	return false;
}
	root -> getRight();
	if(key == root -> getKey()){
	run = false;
	return true;
}
}
else if(key < root -> getKey()){
	if(root -> getLeft() == NULL){
	run = false;
	return false;
}
	root -> getLeft();
	if(key == root -> getKey()){
	run = false;
	return true;
}
}
else if (key == root -> getKey()){
run = false;
return true;

}
}
}


//----------------------------------------------------------------------------

// return largest key in BST
// print error and exit if BST is empty
template<typename T>
const T & BSTree_Fast<T>::findMin(){
  
  //new bst node
  //BSTNode<T> current = root -> getNew(key);
  while(root -> getLeft() != NULL){
	//follow the pointers left	
	root =	root -> getLeft();
}
  return root -> getKey(); 
}

//-----------------------------------
//
template<typename T>
const T & BSTree_Fast<T>::findMax()
{
  //BSTNode<T> current = root;
  while(root -> getRight() != NULL){
 	//follow the pointers  right
 	root = root -> getRight();
}
  return root -> getKey();
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// BSTREE_SLOW
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// a binary search tree, implemented as an unordered STL vector

// once again, this is only partial

template<typename T>
class BSTree_Slow
{
  
  BSTree_Slow() {unique = 0; total = 0; tree.clear(); }               // make an empty BST

  void insert(T &);                             // put a key into the BST 
  bool contains(T &);                           // does this BST contain a certain key?
  const T & findMax();                          // what is the smallest key in the BST?
  const T & findMin();
  void print(); 
private:
  int unique;
  int total;
  vector < BSTNode<T> * > tree;                 // vector of pointers to nodes in the "tree"

};

//----------------------------------------------------------------------------

template<typename T>
void BSTree_Slow<T>::insert(T & key)
{
  if(contains(key)){
//count + 1;
  total = total + 1;
}else{
  tree.push_back(key);
  total = total + 1;
  unique = unique + 1;
  }
}

//----------------------------------------------------------------------------

template<typename T>
bool BSTree_Slow<T>::contains(T & key)
{
  if(/*std::cout */(tree.begin(), tree.end(), key)){
	return true;
}
  else{
	return false;
}
}

//----------------------------------------------------------------------------

// return largest key in BST
// print error and exit if BST is empty

template<typename T>
const T & BSTree_Slow<T>::findMax()
{
  return *max_element(tree.begin(), tree.end());
}


template<typename T>
const T & BSTree_Slow<T>::findMin(){

  return *min_element(tree.begin(), tree.end());
}

template<typename T>
void BSTree_Slow<T>::print(){
cout<<"max "<<findMax()<<"\n";
cout<<"min "<<findMin()<<"\n";
cout<<"total "<<total<<"\n";
cout<<"unique "<<unique<<"\n";
string love;
string death;
string tyranny;
love.push_back('l');
love.push_back('o');
love.push_back('v');
love.push_back('e');
cout<<"contains love "<<contains(love)<<"\n";
death.push_back('d');
death.push_back('e');
death.push_back('a');
death.push_back('t');
death.push_back('h');
cout<<"contains death "<<contains(death)<<"\n";
tyranny.push_back('t');
tyranny.push_back('y');
tyranny.push_back('r');
tyranny.push_back('a');
tyranny.push_back('n');
tyranny.push_back('n');
tyranny.push_back('y');
cout<<"contains tyranny "<<contains(tyranny)<<"\n";
//cout<<"time of love "<< gettimeofday(contains(love), NULL)<<"\n";
//cout<<"time of death "<<gettimeofday(contains(death), NULL)"\n";
//cout<<"time of tyranny "<< gettimeofday(contains(tyranny), NULL)"\n";
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif
