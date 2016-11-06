#pragma once
#include "Grammars.hpp"
#include "../Variable.hpp"

namespace Grammars{

struct Input : qi::grammar<Iterator, Variable(), qi::space_type>
{
    Input();

    qi::rule<Iterator, Variable(), qi::space_type> start;
};

}
