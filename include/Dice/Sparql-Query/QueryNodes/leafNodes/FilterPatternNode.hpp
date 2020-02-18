//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_FILTERPATTERNNODE_HPP
#define SPARQL_QUERY_FILTERPATTERNNODE_HPP

#include "../ICommandNode.hpp"

class FilterPatternNode:public ILeafNode
{
public:
    SelectQueryResult execute(const SelectQueryResult &previousQueryResult) override {
        //ToDo : the actual logic must be implemented here
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_FILTERPATTERNNODE_HPP
