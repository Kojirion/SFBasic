#include "Interpreter.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

void Interpreter::Print(Variable v)
{
    std::cout << variables[v] << '\n';
}

void Interpreter::Input(Variable v)
{
    std::cin >> variables[v];
    std::cin.ignore(); //TOFIX: Yet this is unecessary and even wrong if interpreting from a stream
}

void Interpreter::Add(std::vector<Variable> results)
{
    variables[results[0]] = variables[results[1]] + variables[results[2]];
}

void Interpreter::interpretLine(std::__cxx11::string &line)
{
    namespace qi = boost::spirit::qi;

    auto it = line.begin();
    using std::placeholders::_1;
    auto r = qi::parse(it, line.end(),
                       inputGrammar[std::bind(&Interpreter::Input, this, _1)] |
            printGrammar[std::bind(&Interpreter::Print, this, _1)] |
            additionGrammar[std::bind(&Interpreter::Add, this, _1)]);

    if (!r){
        std::cout << "Error at \n" << std::string(it, line.end()) << std::endl;
    }
}

void Interpreter::interpret(std::istream &is, bool displayPrompt)
{
    if (displayPrompt)
        std::cout << "basic> " << std::flush;

    for (std::string line; std::getline(is, line);){
        qi::rule<Iterator> do_rule = "DO";
        qi::rule<Iterator> loop_rule = "LOOP";
        if (parse(line.begin(), line.end(), do_rule)){
            std::getline(is, line);
            std::vector<std::string> body;
            while (!parse(line.begin(), line.end(), loop_rule)){
                body.push_back(line);
                std::getline(is, line);
            }
            while (true){ //condition goes here
                for (auto bodyline : body)
                    interpretLine(bodyline);
            }
            continue;
        }
        interpretLine(line);
        if (displayPrompt)
            std::cout << "basic> " << std::flush;
    }

    if (displayPrompt)
        std::cout << std::endl;
}
