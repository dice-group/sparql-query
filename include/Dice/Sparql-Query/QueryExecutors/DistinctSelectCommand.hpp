//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DISTINCTSELECTCOMMAND_HPP
#define SPARQL_QUERY_DISTINCTSELECTCOMMAND_HPP

#include "AbstractSelectCommand.hpp"

class DistinctSelectCommand:public AbstractSelectCommand
{
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_DISTINCTSELECTCOMMAND_HPP
