//#define BOOST_TEST_MAIN
//#define BOOST_TEST_DYN_LINK
//#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>

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

struct PrintGrammar : grammar<Iterator>
{
    PrintGrammar(): base_type(start){
        start = "PRINT " >> char_[Print];
    }

    rule<Iterator> start;
};

struct InputGrammar : grammar<Iterator>
{
    InputGrammar(): base_type(start){
        start = "INPUT " >> char_[Input];
    }

    rule<Iterator> start;
};

struct AdditionGrammar : grammar<Iterator>
{
    AdditionGrammar() : base_type(start){
        addition = char_ >> " = " >> char_ >> " + " >> char_;
        start = addition[Add];
    }

    rule<Iterator> start;
    rule<Iterator, std::vector<char>()> addition;

};

//BOOST_AUTO_TEST_CASE(EventName)
//{
//    PrintGrammar grammar;

//    variables['a'] = 9;

//    std::string given("PRINT a");

//    bool success = boost::spirit::qi::parse(given.begin(), given.end(), grammar);

//    BOOST_CHECK(success);
//}

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

    success = boost::spirit::qi::parse(line_1.begin(), line_1.end(), inputGrammar);
    success = boost::spirit::qi::parse(line_2.begin(), line_2.end(), inputGrammar);
    success = boost::spirit::qi::parse(line_3.begin(), line_2.end(), additionGrammar);
    success = boost::spirit::qi::parse(line_4.begin(), line_2.end(), printGrammar);
}
