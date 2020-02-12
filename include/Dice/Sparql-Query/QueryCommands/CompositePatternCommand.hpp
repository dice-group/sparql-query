//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_COMPOSITEPATTERNCOMMAND_HPP
#define SPARQL_QUERY_COMPOSITEPATTERNCOMMAND_HPP

#include <vector>
#include <memory>
#include "IQueryCommand.hpp"


class CompositePatternCommand:public IQueryCommand
{
private:
    //ToDo find the best collecion to use here(vector,list....)
    std::vector<std::shared_ptr<IQueryCommand>> children;

public:
    void addChild(std::shared_ptr<IQueryCommand> command)
    {
        children.push_back(command);
    }
};

#endif //SPARQL_QUERY_COMPOSITEPATTERNCOMMAND_HPP
