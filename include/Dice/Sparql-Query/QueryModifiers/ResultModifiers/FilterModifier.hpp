//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_FILTERMODIFIER_HPP
#define SPARQL_QUERY_FILTERMODIFIER_HPP

#include "IResultModifier.hpp"

class FilterModifier:public IResultModifier
{
public:
    SelectQueryResult modifyResult(SelectQueryResult queryResult) override {
        //ToDo : implement the filter logic here
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_FILTERMODIFIER_HPP
