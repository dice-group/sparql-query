//
// Created by fakhr on 12.02.20.
//
#include "IQuery.hpp"
#include "SelectQueryResult.hpp"
#ifndef SPARQL_QUERY_SELECTQUERY_HPP
#define SPARQL_QUERY_SELECTQUERY_HPP

class SelectQuery:public IQuery<SelectQueryResult>
{
public:
    SelectQueryResult executeQuery(const ITripleStore &tripleStore) override {
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_SELECTQUERY_HPP
