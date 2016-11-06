#include <boost/spirit/include/qi.hpp>
#include "Print.hpp"

namespace Grammars{

Print::Print():
    base_type(start)
{
    start = qi::no_case["PRINT "] >> qi::char_;
}

}
