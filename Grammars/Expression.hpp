#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"

struct AdditionGrammar : qi::grammar<Iterator, std::vector<char>()>
{
    AdditionGrammar();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, std::vector<char>()> start;
};
