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

    using boost::spirit::qi::parse;
    using boost::spirit::qi::space;

    for (auto& line : validLines)
        BOOST_CHECK(parse(line.begin(), line.end(), grammar));

    std::vector<std::string> invalidLines = {
        "PRINTa",
        "fPRINta",
        "PRINT"
    };

    for (auto& line : invalidLines)
        BOOST_CHECK(!parse(line.begin(), line.end(), grammar));
}
