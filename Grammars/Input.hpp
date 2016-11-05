#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"
#include "../Variable.hpp"

namespace Grammars{

struct Input : qi::grammar<Iterator, Variable()>
{
    Input();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, Variable()> start;
};

}
