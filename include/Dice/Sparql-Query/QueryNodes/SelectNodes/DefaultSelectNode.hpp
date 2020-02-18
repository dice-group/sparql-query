//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DEFAULTSELECTNODE_HPP
#define SPARQL_QUERY_DEFAULTSELECTNODE_HPP

#include "AbstractSelectNode.hpp"

class DefaultSelectNode:public AbstractSelectNode
{
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_DEFAULTSELECTNODE_HPP
