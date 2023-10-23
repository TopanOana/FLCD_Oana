//
// Created by oanam on 10/23/2023.
//

#include "HashTable.h"

template<class T>
int HashTable<T>::hashFunction(T element) {
    int sum = 0;

    for (char i : element){
        sum += (int)i;
    }

    return sum % size;
}

template<class T>
HashTable<T>::HashTable() {
    table = vector<Entry<T>>(size);
}

template<class T>
int HashTable<T>::position(T element) {
    int hashValue = hashFunction(element);
    while (element != table[hashValue].token && table[hashValue].nextPosition != -1){
        hashValue = table[hashValue].nextPosition;
    }

    if (element == table[hashValue].token)
        return hashValue;
    else{
        if (table[hashValue].token == ""){
            table[hashValue].token = element;
            table[hashValue].nextPosition = -1;
            return hashValue;
        }
        else {
            int newPosition = addValue(element);
            table[hashValue].nextPosition = newPosition;
            return newPosition;
        }
    }
}

template<class T>
int HashTable<T>::nextEmptyPosition() {
    for (int i = 0 ; i < table.size() ; i++){
        if ( table[i].token == "")
            return i;
    }
}

template<class T>
int HashTable<T>::addValue(T element) {
    int newPosition = nextEmptyPosition();

    table[newPosition].token = element;
    table[newPosition].nextPosition = -1;

    return newPosition;
}

template<class T>
int HashTable<T>::removeValue(T element) {
    int position = containsValue(element);
    if (table[position].nextPosition == -1){
        table[position].token = "";
        return position;
    }
    else{
        int hashValue = hashFunction(element);

        while (table[hashValue].nextPosition != position){
            hashValue = table[hashValue].nextPosition;
        }

        table[hashValue].nextPosition = table[position].nextPosition;
        table[position].token = "";
        table[position].nextPosition = -1;
        return position;
    }
}

template<class T>
int HashTable<T>::containsValue(T element) {
    int hashValue = hashFunction(element);
    while (element != table[hashValue].token && table[hashValue].nextPosition != -1){
        hashValue = table[hashValue].nextPosition;
    }

    if(element == table[hashValue].token)
        return hashValue;
    return -1;
}

template<class T>
HashTable<T>::HashTable(HashTable &ht) {
    this->table = ht.table;
    this->size = ht.size;
}