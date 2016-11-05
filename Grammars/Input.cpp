#include "Input.hpp"
#include <boost/spirit/include/qi.hpp>

namespace Grammars{

Input::Input():
    base_type(start)
{
    start = arbitrarySpace >> qi::no_case["INPUT "] >> arbitrarySpace >> qi::char_;
}

}
