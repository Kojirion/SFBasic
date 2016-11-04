#include "Grammars.hpp"
#include <map>
#include <vector>
#include <iostream>

struct Interpreter
{
    void Print(char a){std::cout << variables[a] << '\n';}

    void Input(char a){std::cin >> variables[a]; }

    void Add(std::vector<char> results){
        variables[results[0]] = variables[results[1]] + variables[results[2]];
    }

    std::map<char, int> variables;
};



int main(){
    PrintGrammar printGrammar;
    InputGrammar inputGrammar;
    AdditionGrammar additionGrammar;

    bool running(true);

    std::string line;

    while(running){
        std::getline(std::cin, line);
        std::cout << line << std::endl;
    }

}
