#pragma once
#include "Grammars.hpp"
#include "ArbitrarySpace.hpp"
#include "../Variable.hpp"

struct AdditionGrammar : qi::grammar<Iterator, std::vector<Variable>()>
{
    AdditionGrammar();

    ArbitrarySpace arbitrarySpace;
    qi::rule<Iterator, std::vector<Variable>()> start;
};
