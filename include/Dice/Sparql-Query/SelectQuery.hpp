//
// Created by fakhr on 12.02.20.
//


#ifndef SPARQL_QUERY_SELECTQUERY_HPP
#define SPARQL_QUERY_SELECTQUERY_HPP

#include <memory>
#include "IQuery.hpp"
#include "SelectQueryResult.hpp"
#include "QueryNodes/SelectNodes/AbstractSelectNode.hpp"

class SelectQuery:public IQuery<SelectQueryResult>
{
private:
    std::shared_ptr<IQueryNode> queryExecutor;
public:
    explicit SelectQuery( std::shared_ptr<AbstractSelectNode> queryExecutor)
    {
        this->queryExecutor=queryExecutor;
    }

    SelectQueryResult executeQuery(const ITripleStore &tripleStore) override {
        //ToDo : find what exactly we should pass
        return queryExecutor->execute(SelectQueryResult());
    }
};

#endif //SPARQL_QUERY_SELECTQUERY_HPP
