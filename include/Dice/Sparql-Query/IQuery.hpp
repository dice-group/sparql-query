//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_IQUERY_HPP
#define SPARQL_QUERY_IQUERY_HPP

#include "ITripleStore.hpp"
z
template <typename QueryResultType>
class IQuery
{
public:
    virtual QueryResultType executeQuery(const ITripleStore& tripleStore)=0;
};

#endif //SPARQL_QUERY_IQUERY_HPP
