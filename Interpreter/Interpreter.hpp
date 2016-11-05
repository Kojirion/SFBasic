#pragma once
#include "../Grammars/Input.hpp"
#include "../Grammars/Print.hpp"
#include "../Grammars/Expression.hpp"
#include <map>

struct Interpreter
{
    void Print(Variable v);
    void Input(Variable v);
    void Add(std::vector<Variable> results);

    void interpretLine(std::string& line);

    void interpret(std::istream& is, bool displayPrompt);

    Grammars::Print printGrammar;
    Grammars::Input inputGrammar;
    Grammars::Addition additionGrammar;

    std::map<Variable, int> variables;
};
