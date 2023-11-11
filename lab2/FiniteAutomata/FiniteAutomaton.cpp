//
// Created by oanam on 11/10/2023.
//

#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "FiniteAutomaton.h"

using namespace std;

void FiniteAutomaton::readFromFile() {
    ifstream inputStream;
    inputStream.open(this->filepath);

    //read all states
    char states[100];
    inputStream.getline(states, 100);
    int i = 0;
    while (i < strlen(states) ) {
        if (states[i] != ',') {
            string aux = "";
            aux.push_back(states[i]);
            this->states.push_back(aux);
        }
        i++;
    }

    //read alphabet
    char alphabet[1024];
    inputStream.getline(alphabet, 1024);
    for (int j = 0; j < strlen(alphabet) ; j++) {
        if (alphabet[j] != ',') {
            string aux = "";
            aux.push_back(alphabet[j]);
            this->alphabet.push_back(aux);
        }
    }

    char initialState[2];
    inputStream.getline(initialState, 2);
    this->initial_state = initialState;

    char finalstates[100];
    inputStream.getline(finalstates, 100);
    for (int j = 0; j < strlen(finalstates); j++) {
        if (finalstates[j] != ',') {
            string aux = "";
            aux.push_back(finalstates[j]);
            this->final_states.push_back(aux);
        }
    }


    char transition[100];
    while (inputStream.getline(transition, 100)) {
        string initial, value, final;
        initial.push_back(transition[0]); //first character is source state
        // second character is ,
        value.push_back(transition[2]); // third character is value of transition
        // fourth character is =
        final.push_back(transition[4]); // fifth character is destination state
        Transition aux;
        aux.source_state = initial;
        aux.value = value;
        aux.destination_state = final;
        this->transitions.push_back(aux);
    }

    inputStream.close();

}

void FiniteAutomaton::displayElements() {
    cout << "States: ";
    for (const auto &item: this->states) {
        cout << item << " ";
    }

    cout << "\nAlphabet: ";
    for (const auto &item: this->alphabet) {
        cout << item << " ";
    }

    cout << "\nInitial state: " << this->initial_state;

    cout << "\nFinal states: ";
    for (const auto &item: this->final_states) {
        cout << item << " ";
    }

    cout << "\nTransitions:\n";
    for (const auto &item: this->transitions) {
        cout << "(" << item.source_state << "," << item.value << ") = " << item.destination_state << "\n";
    }

}

bool FiniteAutomaton::checkSequence(std::string sequence) {
    if (sequence.empty()){
        if (std::find(final_states.begin(), final_states.end(),initial_state) != final_states.end()) // if the sequence is empty and the initial state is also a final one
            return true;
        return false;
    }


    //starting from initial state
    string currentState = this->initial_state;

    //going through the sequence
    for (char i : sequence){
        //get transition from current state to any other state with value sequence[i]
        string value ;
        value.push_back(i);
        Transition currentTransition = findTransitionBySourceAndValue(currentState,value);
        if (currentTransition.source_state.empty()){
            return false;
        }
        currentState = currentTransition.destination_state;
    }

    if (std::find(final_states.begin(), final_states.end(),currentState) != final_states.end())
        return true;

    return false;
}

Transition FiniteAutomaton::findTransitionBySourceAndValue(std::string source, std::string value) {
    for (const auto &item: this->transitions){
        if (item.source_state == source && item.value == value)
            return item;
    }
    return Transition();
}
