//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_GROUPPATTERNNODE_HPP
#define SPARQL_QUERY_GROUPPATTERNNODE_HPP

#include "GroupNode.hpp"

class GroupPatternNode:public GroupNode
{

public:
    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        SelectQueryResult queryResult=previousQueryResult;
        for(auto child:children)
            queryResult=child->execute(queryResult);
        return queryResult;
    }
};

#endif //SPARQL_QUERY_GROUPPATTERNNODE_HPP
