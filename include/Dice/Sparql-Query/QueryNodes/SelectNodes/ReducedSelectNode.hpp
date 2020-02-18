//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_REDUCEDSELECTNODE_HPP
#define SPARQL_QUERY_REDUCEDSELECTNODE_HPP


#include "AbstractSelectNode.hpp"

class ReducedSelectNode:public AbstractSelectNode
{
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_REDUCEDSELECTNODE_HPP
