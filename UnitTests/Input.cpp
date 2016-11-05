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

    using boost::spirit::qi::parse;

    for (auto& line : validLines)
        BOOST_CHECK(parse(line.begin(), line.end(), grammar));

    std::vector<std::string> invalidLines = {
        "INPUTa",
        "fINPUT a",
        "INPUT"
    };

    for (auto& line : invalidLines)
        BOOST_CHECK(!parse(line.begin(), line.end(), grammar));
}
