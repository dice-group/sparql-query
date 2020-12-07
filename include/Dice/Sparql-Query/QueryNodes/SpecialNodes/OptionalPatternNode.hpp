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

    std::vector<std::vector<std::string>> generateOperands() override {
        std::vector<std::vector<std::string>> operands;
        operands.push_back(std::vector<std::string>{"["});
        std::vector<std::vector<std::string>> nodeoperands=node->generateOperands();
        for(auto& subscriptElement : nodeoperands)
            operands.push_back(subscriptElement);
        operands.push_back(std::vector<std::string>{"]"});

        return operands;
    }

};

#endif //SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
