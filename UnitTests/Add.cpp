#include <boost/test/unit_test.hpp>
#include <boost/spirit/include/qi.hpp>
#include "../Grammars.hpp"

BOOST_AUTO_TEST_CASE(Add)
{
    AdditionGrammar grammar;

    std::vector<std::string> validLines = {
        "s = a + b"
    };

    using boost::spirit::qi::phrase_parse;
    using boost::spirit::qi::space;

    for (auto& line : validLines)
        BOOST_CHECK(phrase_parse(line.begin(), line.end(), grammar, space));
}
