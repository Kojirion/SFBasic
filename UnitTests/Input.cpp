#include <boost/test/unit_test.hpp>
#include <boost/spirit/include/qi.hpp>
#include "../Grammars/Input.hpp"

BOOST_AUTO_TEST_CASE(Input)
{
    Grammars::Input grammar;

    std::vector<std::string> validLines = {
        "INPUT a",
        "INPUT b",
        "input a",
        "iNpuT a",
        "Input a",
        " INPUT a",
        "Input  a"
    };

    namespace qi = boost::spirit::qi;

    for (auto& line : validLines)
        BOOST_CHECK(qi::phrase_parse(line.begin(), line.end(), grammar, qi::space));

    std::vector<std::string> invalidLines = {
        "INPUTa",
        "fINPUT a",
        "INPUT"
    };

    for (auto& line : invalidLines)
        BOOST_CHECK(!qi::phrase_parse(line.begin(), line.end(), grammar, qi::space));
}
