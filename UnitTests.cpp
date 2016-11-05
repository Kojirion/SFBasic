#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>
#include "Grammars.hpp"

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

BOOST_AUTO_TEST_CASE(InputOutput)
{
    PrintGrammar printGrammar;
    InputGrammar inputGrammar;
    AdditionGrammar additionGrammar;

    std::vector<std::string> lines = {
        "INPUT a",
        "s = a + b",
        "PRINT s"
    };

    using boost::spirit::qi::parse;

    BOOST_CHECK(parse(lines[0].begin(), lines[0].end(), inputGrammar));
    BOOST_CHECK(parse(lines[1].begin(), lines[1].end(), additionGrammar));
    BOOST_CHECK(parse(lines[2].begin(), lines[2].end(), printGrammar));
}
