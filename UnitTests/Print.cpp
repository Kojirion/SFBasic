#include <boost/test/unit_test.hpp>
#include <boost/spirit/include/qi.hpp>
#include "../Grammars/Print.hpp"

BOOST_AUTO_TEST_CASE(Print)
{
    Grammars::Print grammar;

    std::vector<std::string> validLines = {
        "PRINT a",
        "PRINT b",
        "print a",
        "prInT a",
        "Print a",
        "  Print a",
        "Print        a"
    };

    namespace qi = boost::spirit::qi;

    for (auto& line : validLines)
        BOOST_CHECK(qi::phrase_parse(line.begin(), line.end(), grammar, qi::space));

    std::vector<std::string> invalidLines = {
        "PRINTa",
        "fPRINta",
        "PRINT"
    };

    for (auto& line : invalidLines)
        BOOST_CHECK(!qi::phrase_parse(line.begin(), line.end(), grammar, qi::space));
}
