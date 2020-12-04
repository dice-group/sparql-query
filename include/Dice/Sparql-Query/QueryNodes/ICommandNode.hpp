//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_ICOMMANDNODE_HPP
#define SPARQL_QUERY_ICOMMANDNODE_HPP

#include "IQueryNode.hpp"

class ICommandNode:public IQueryNode
{
public:
    //ToDo
    virtual std::vector<std::string> process(){};

    virtual std::vector<std::string> generateSubscript()=0;
};

#endif //SPARQL_QUERY_ICOMMANDNODE_HPP
