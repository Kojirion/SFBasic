#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"
#include "../Variable.hpp"

struct PrintGrammar : qi::grammar<Iterator, Variable()>
{
    PrintGrammar();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, Variable()> start;
};
