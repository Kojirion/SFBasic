#pragma once
#include "../Grammars/Input.hpp"
#include "../Grammars/Print.hpp"
#include "../Grammars/Expression.hpp"
#include <map>

class Interpreter
{
public:
    void interpret(std::istream& is, bool displayPrompt);

private:
    void interpretLine(std::string& line);

    void Print(Variable v);
    void Input(Variable v);
    void Add(std::vector<Variable> results);

    std::map<Variable, int> variables;
};
