#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

using boost::spirit::qi::grammar;
using boost::spirit::qi::rule;

using boost::spirit::qi::int_;
using boost::spirit::qi::char_;

using Iterator = std::string::iterator;


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
