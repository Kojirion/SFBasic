#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"
#include "../Variable.hpp"

namespace Grammars{

struct Print : qi::grammar<Iterator, Variable()>
{
    Print();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, Variable()> start;
};

}
