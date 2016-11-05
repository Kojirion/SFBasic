#include "ArbitrarySpace.hpp"
#include <boost/spirit/include/qi.hpp>

ArbitrarySpace::ArbitrarySpace(): base_type(start){
    start = *qi::space;
}
