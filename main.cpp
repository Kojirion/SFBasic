#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>

#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

using boost::spirit::qi::grammar;
using boost::spirit::qi::rule;

using boost::spirit::qi::int_;
using boost::spirit::qi::lit;

using Iterator = std::string::iterator;

std::map<std::string, int> variables;

void F(int a){std::cout << a << '\n';}

struct PrintGrammar : grammar<Iterator, std::string()>
{
    PrintGrammar(): base_type(start){
        start = "PRINT " >> int_[F];
    }

    rule<Iterator, std::string()> start;
};

BOOST_AUTO_TEST_CASE(EventName)
{
    PrintGrammar grammar;

    std::string given("PRINT 5");

    bool success = boost::spirit::qi::parse(given.begin(), given.end(), grammar);

    BOOST_CHECK(success);
}
