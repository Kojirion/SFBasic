#include <boost/test/unit_test.hpp>
#include <boost/spirit/include/qi.hpp>
#include "../Grammars/Expression.hpp"

BOOST_AUTO_TEST_CASE(Add)
{
    Grammars::Addition grammar;

    std::vector<std::string> validLines = {
        "s = a + b",
        "s=a+b",
        "s   = a     +b"
    };

    using boost::spirit::qi::parse;

    for (auto& line : validLines)
        BOOST_CHECK(parse(line.begin(), line.end(), grammar));
}
