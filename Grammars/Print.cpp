#include <boost/spirit/include/qi.hpp>
#include "Print.hpp"

PrintGrammar::PrintGrammar():
    base_type(start)
{
    start = arbitrarySpace >> qi::no_case["PRINT "] >> arbitrarySpace >> qi::char_;
}
