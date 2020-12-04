//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
#define SPARQL_QUERY_OPTIONALPATTERNNODE_HPP

#include "SpecialNode.hpp"

class OptionalPatternNode : public SpecialNode {
public:

    OptionalPatternNode(std::shared_ptr<ICommandNode> commandnode):SpecialNode(commandnode){};

    SelectQueryResult execute(const SelectQueryResult &previousQueryResult) override {
        SelectQueryResult queryResult = previousQueryResult;
        queryResult = node->execute(queryResult);
        //ToDo implement the logic here to perform : return queryResult=previousQueryResult-queryResult
        return queryResult;
    }
};

#endif //SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
