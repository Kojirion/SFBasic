#pragma once
#include "Grammars.hpp"
#include "../Variable.hpp"

namespace Grammars{

struct Print : qi::grammar<Iterator, Variable(), qi::space_type>
{
    Print();

    qi::rule<Iterator, Variable(), qi::space_type> start;
};

}
