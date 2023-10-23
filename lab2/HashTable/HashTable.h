///hashtable.h
//
// Created by oanam on 10/23/2023.
//

#ifndef LAB2_HASHTABLE_H
#define LAB2_HASHTABLE_H

using namespace std;
#include <vector>

template <class T>
struct Entry{
    T token;
    int nextPosition = -1;
};


template <class T>
class HashTable {
private :
    vector<Entry<T>> table;
    int size = 101; //prime number

    int hashFunction(T element);
    int nextEmptyPosition();



public:
    HashTable();
    HashTable(HashTable &ht);
    int addValue(T element);
    int position(T element);
    int removeValue(T element);
    int containsValue(T element);

};



#endif //LAB2_HASHTABLE_H