#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"
#include "../Variable.hpp"

namespace Grammars{

struct Addition : qi::grammar<Iterator, std::vector<Variable>()>
{
    Addition();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, std::vector<Variable>()> start;
};

}
