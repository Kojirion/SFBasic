#include "Expression.hpp"
#include <boost/spirit/include/qi.hpp>

namespace Grammars{

Addition::Addition():
    base_type(start)
{
    start = qi::char_ >> arbitrarySpace >> "=" >> arbitrarySpace >> qi::char_ >> arbitrarySpace >> "+" >> arbitrarySpace >> qi::char_;
}

}
