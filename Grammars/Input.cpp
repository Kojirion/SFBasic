#include "Input.hpp"
#include <boost/spirit/include/qi.hpp>

namespace Grammars{

Input::Input():
    base_type(start)
{
    start = qi::no_case["INPUT "] >> qi::char_;
}

}
