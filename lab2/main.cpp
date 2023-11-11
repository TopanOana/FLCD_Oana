#include <iostream>
#include <regex>
#include "Scanner/Scanner.h"
using namespace std;

int main() {
    Scanner scanner ;
    scanner.scanningAlgorithm("C:/Users/oanam/Desktop/LFTC/lab1a/p3.txt");

//    FiniteAutomaton finiteAutomaton("C:\\Users\\oanam\\Desktop\\LFTC\\lab2\\IdentifierFA.in");
//    finiteAutomaton.readFromFile();
//    finiteAutomaton.checkSequence("aaa");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
