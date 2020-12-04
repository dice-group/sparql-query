//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_GROUPNODE_HPP
#define SPARQL_QUERY_GROUPNODE_HPP

#include <vector>
#include <memory>
#include "ICommandNode.hpp"


class GroupNode:public ICommandNode
{
protected:
    //ToDo find the best collection to use here(vector,list....)
    std::vector<std::shared_ptr<ICommandNode>> children;

public:
    void addChild(std::shared_ptr<ICommandNode> commandnode)
    {
        children.push_back(commandnode);
    }

    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        SelectQueryResult queryResult=previousQueryResult;
        for(auto child:children)
         queryResult=child->execute(queryResult);
        //ToDo implement the logic here to perform : return queryResult=previousQueryResult-queryResult
        return queryResult;
    }
};

#endif //SPARQL_QUERY_GROUPNODE_HPP
