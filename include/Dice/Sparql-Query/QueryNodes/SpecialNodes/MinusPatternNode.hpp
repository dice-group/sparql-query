//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_MINUSPATTERNNODE_HPP
#define SPARQL_QUERY_MINUSPATTERNNODE_HPP

#include "SpecialNode.hpp"

class MinusPatternNode:public SpecialNode
{
public:

    MinusPatternNode(std::shared_ptr<ICommandNode> commandnode):SpecialNode(commandnode){};

    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        SelectQueryResult queryResult=previousQueryResult;
            queryResult=node->execute(queryResult);
        //ToDo implement the logic here to perform : return queryResult=previousQueryResult-queryResult
        return queryResult;
    }
};

#endif //SPARQL_QUERY_MINUSPATTERNNODE_HPP
