//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_COMPOSITEPATTERNCOMMAND_HPP
#define SPARQL_QUERY_COMPOSITEPATTERNCOMMAND_HPP

#include <vector>
#include <memory>
#include "../ICommandNode.hpp"


class CompositePatternCommand:public ICommandNode
{
protected:
    //ToDo find the best collection to use here(vector,list....)
    std::vector<std::shared_ptr<ICommandNode>> children;

public:
    void addChild(std::shared_ptr<ICommandNode> commandnode)
    {
        children.push_back(commandnode);
    }
};

#endif //SPARQL_QUERY_COMPOSITEPATTERNCOMMAND_HPP
