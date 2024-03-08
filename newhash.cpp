//Alexander Trunzo 
//
//
//
#include <list>


class HashTable {
	private:
		std::list <int> * map;
		int size;
	public:
		HashTable (){
			this->size = 10;
			map = new std::list <int> [this->size];
		}

		HashTable (int size){
			this->size = size;
			map = new std::list <int> [this->size];
		}
		~HashTable (){
			delete [] map;
		}
}
