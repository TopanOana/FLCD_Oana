//symboltable.cpp
//
// Created by oanam on 10/23/2023.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    hashTable = *new HashTable<string>();
}

int SymbolTable::position(string token) {
    return hashTable.position(token);
}

int SymbolTable::removeToken(string token) {
    return hashTable.removeValue(token);
}

int SymbolTable::addToken(string token) {
    return hashTable.addValue(token);
}
