//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
#define SPARQL_QUERY_TRIPLEPATTERNNODE_HPP

#include "ILeafNode.hpp"

class TriplePatternNode:public ILeafNode
{
public:
    SelectQueryResult execute(const SelectQueryResult &previousQueryResult) override {
        //ToDo : the actual logic of querying the triple store must be implemented here
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
