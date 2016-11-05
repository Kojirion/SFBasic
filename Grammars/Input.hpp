#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"
#include "../Variable.hpp"

struct InputGrammar : qi::grammar<Iterator, Variable()>
{
    InputGrammar();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, Variable()> start;
};
