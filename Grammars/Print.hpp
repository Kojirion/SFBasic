#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"

struct PrintGrammar : qi::grammar<Iterator, char()>
{
    PrintGrammar();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, char()> start;
};
