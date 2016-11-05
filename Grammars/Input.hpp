#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"

struct InputGrammar : qi::grammar<Iterator, char()>
{
    InputGrammar();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, char()> start;
};
