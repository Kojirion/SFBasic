#include <boost/test/unit_test.hpp>
#include <boost/spirit/include/qi.hpp>
#include "../Grammars.hpp"

BOOST_AUTO_TEST_CASE(Print)
{
    PrintGrammar grammar;

    std::vector<std::string> validLines = {
        "PRINT a",
        "PRINT b",
        "print a",
        "prInT a",
        "Print a",
        "  Print a"
    };

    using boost::spirit::qi::phrase_parse;
    using boost::spirit::qi::space;

    for (auto& line : validLines)
        BOOST_CHECK(phrase_parse(line.begin(), line.end(), grammar, space));
}
