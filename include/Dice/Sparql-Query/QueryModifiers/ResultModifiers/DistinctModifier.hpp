//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_DISTINCTMODIFIER_HPP
#define SPARQL_QUERY_DISTINCTMODIFIER_HPP

#include "IResultModifier.hpp"

class DistinctModifier:public IResultModifier
{
public:
    SelectQueryResult modifyResult(SelectQueryResult queryResult) override {
        //ToDo : this function must return a distinct query
        return queryResult;
    }
};

#endif //SPARQL_QUERY_DISTINCTMODIFIER_HPP
