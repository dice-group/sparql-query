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

    std::vector<std::vector<std::string>> generateSubscript() override {
        std::vector<std::vector<std::string>> subscript;
        subscript.push_back(std::vector<std::string>{"["});
        std::vector<std::vector<std::string>> nodeSubscript=node->generateSubscript();
        for(auto& subscriptElement : nodeSubscript)
            subscript.push_back(subscriptElement);
        subscript.push_back(std::vector<std::string>{"]"});

        return subscript;
    }

};

#endif //SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
