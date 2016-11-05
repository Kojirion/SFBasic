#pragma once
#include "Grammars.hpp"

struct ArbitrarySpace : qi::grammar<Iterator>
{
    ArbitrarySpace();

    qi::rule<Iterator> start;
};
