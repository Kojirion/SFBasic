#include <boost/test/unit_test.hpp>
#include <boost/spirit/include/qi.hpp>
#include "../Grammars.hpp"

BOOST_AUTO_TEST_CASE(Input)
{
    InputGrammar inputGrammar;

    std::vector<std::string> validLines = {
        "INPUT a",
        "INPUT b",
        "input a",
        "iNpuT a",
        "Input a",
        " INPUT a"
    };

    using boost::spirit::qi::phrase_parse;
    using boost::spirit::qi::space;

    for (auto& line : validLines)
        BOOST_CHECK(phrase_parse(line.begin(), line.end(), inputGrammar, space));

    std::vector<std::string> invalidLines = {
        "INPUTa",
        "fINPUT a",
        "INPUT"
    };

    for (auto& line : invalidLines)
        BOOST_CHECK(!phrase_parse(line.begin(), line.end(), inputGrammar, space));
}