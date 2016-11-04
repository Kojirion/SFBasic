#include "Grammars.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <functional>

struct Interpreter
{
    void Print(char a){std::cout << variables[a] << '\n';}

    void Input(char a){
        std::cin >> variables[a];
        std::cin.ignore();
    }

    void Add(std::vector<char> results){
        variables[results[0]] = variables[results[1]] + variables[results[2]];
    }

    std::map<char, int> variables;
};

//TODO: a quit grammar

int main(){
    PrintGrammar printGrammar;
    InputGrammar inputGrammar;
    AdditionGrammar additionGrammar;

    Interpreter interpreter;

    bool running(true);

    std::string line;
    using boost::spirit::qi::parse;

    while(running){
        std::cout << "basic> " << std::flush;
        std::getline(std::cin, line);
        auto it = line.begin();
        using std::placeholders::_1;
        auto r = parse(it, line.end(), inputGrammar[std::bind(&Interpreter::Input, &interpreter, _1)]);
        if (!r){
            std::cout << "Error at \n" << std::string(it, line.end()) << std::endl;
        }
    }
}
