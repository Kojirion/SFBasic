#include "Input.hpp"
#include <boost/spirit/include/qi.hpp>

InputGrammar::InputGrammar():
    base_type(start)
{
    start = arbitrarySpace >> qi::no_case["INPUT "] >> arbitrarySpace >> qi::char_;
}
