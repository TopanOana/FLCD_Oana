//
// Created by oanam on 10/27/2023.
//

#ifndef LAB2_SCANNER_H
#define LAB2_SCANNER_H


#include <fstream>
#include "../SymbolTable/SymbolTable.h"

class Scanner {
private:
    SymbolTable symbolTable; //1a
    std::vector<pair<string, int>> programmingInternalForm;
    std::vector<string> tokens;

    string regexForIdentifiers = "[a-zA-Z]{1}[a-zA-Z0-9]*";
    string regexForCharacterConstants = "\'[a-zA-Z0-9]{1}\'";
    string regexForStringConstants = "\"[a-zA-Z0-9]*\"";
    string regexForIntegerConstants = "([+-]?[1-9][0-9]*|0)";

    void populateTokens();

    int addTokenToPIF(string token, int lineNumber);

    void writeToOutputFiles();


public :
    Scanner();

    void scanningAlgorithm(string filepath);

};


#endif //LAB2_SCANNER_H
