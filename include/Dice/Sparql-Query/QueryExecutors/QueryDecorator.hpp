//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SELECTCOMMANDDECORATOR_HPP
#define SPARQL_QUERY_SELECTCOMMANDDECORATOR_HPP

#include "IQueryExecutor.hpp"
#include <memory>

class QueryDecorator : public IQueryExecutor
{
protected:
    std::shared_ptr<IQueryExecutor> wrappee;
public:
    QueryDecorator(std::shared_ptr<IQueryExecutor> queryExecutor)
    {
        wrappee=queryExecutor;
    }
};

#endif //SPARQL_QUERY_SELECTCOMMANDDECORATOR_HPP
