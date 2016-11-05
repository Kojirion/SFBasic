#include "Expression.hpp"
#include <boost/spirit/include/qi.hpp>

AdditionGrammar::AdditionGrammar():
    base_type(start)
{
    start = qi::char_ >> arbitrarySpace >> "=" >> arbitrarySpace >> qi::char_ >> arbitrarySpace >> "+" >> arbitrarySpace >> qi::char_;
}
