#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

using boost::spirit::qi::grammar;
using boost::spirit::qi::rule;

using boost::spirit::qi::int_;
using boost::spirit::qi::char_;

using Iterator = std::string::iterator;

std::map<char, int> variables;

void Print(char a){std::cout << variables[a] << '\n';}

void Input(char a){std::cin >> variables[a]; }

void Add(std::vector<char> results){
    variables[results[0]] = variables[results[1]] + variables[results[2]];
}

struct PrintGrammar : grammar<Iterator, char()>
{
    PrintGrammar(): base_type(start){
        start = "PRINT " >> char_;
    }

    rule<Iterator, char()> start;
};

struct InputGrammar : grammar<Iterator, char()>
{
    InputGrammar(): base_type(start){
        start = "INPUT " >> char_;
    }

    rule<Iterator, char()> start;
};

struct AdditionGrammar : grammar<Iterator, std::vector<char>()>
{
    AdditionGrammar() : base_type(start){
        start = char_ >> " = " >> char_ >> " + " >> char_;
    }

    rule<Iterator, std::vector<char>()> start;
};

int main()
{
    PrintGrammar printGrammar;
    InputGrammar inputGrammar;
    AdditionGrammar additionGrammar;

    std::string line_1("INPUT a");

    std::string line_2("INPUT b");

    std::string line_3("s = a + b");

    std::string line_4("PRINT s");

    bool success;

    success = boost::spirit::qi::parse(line_1.begin(), line_1.end(), inputGrammar[Input]);
    success = boost::spirit::qi::parse(line_2.begin(), line_2.end(), inputGrammar[Input]);
    success = boost::spirit::qi::parse(line_3.begin(), line_2.end(), additionGrammar[Add]);
    success = boost::spirit::qi::parse(line_4.begin(), line_2.end(), printGrammar[Print]);
}
