#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/qi_no_case.hpp>

using boost::spirit::qi::grammar;
using boost::spirit::qi::rule;

using boost::spirit::qi::int_;
using boost::spirit::qi::char_;
using boost::spirit::qi::no_case;

using boost::spirit::qi::space;

using Iterator = std::string::iterator;



struct PrintGrammar : grammar<Iterator, char()>
{
    PrintGrammar(): base_type(start){
        start = no_case["PRINT "] >> char_;
    }

    rule<Iterator, char()> start;
};

struct InputGrammar : grammar<Iterator, char()>
{
    InputGrammar(): base_type(start){
        start = no_case["INPUT "] >> char_;
    }

    rule<Iterator, char()> start;
};

struct AdditionGrammar : grammar<Iterator, std::vector<char>()>
{
    AdditionGrammar() : base_type(start){
        arbitrarySpace = *space;
        start = char_ >> arbitrarySpace >> "=" >> arbitrarySpace >> char_ >> arbitrarySpace >> "+" >> arbitrarySpace >> char_;
    }

    rule<Iterator> arbitrarySpace;
    rule<Iterator, std::vector<char>()> start;
};
