//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_REDUCEDSELECTCOMMAND_HPP
#define SPARQL_QUERY_REDUCEDSELECTCOMMAND_HPP


#include "AbstractSelectCommand.hpp"

class ReducedSelectCommand:public AbstractSelectCommand
{
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_REDUCEDSELECTCOMMAND_HPP
