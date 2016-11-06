#pragma once
#include "Grammars.hpp"
#include "../Variable.hpp"

namespace Grammars{

struct Addition : qi::grammar<Iterator, std::vector<Variable>(), qi::space_type>
{
    Addition();

    qi::rule<Iterator, std::vector<Variable>(), qi::space_type> start;
};

}
