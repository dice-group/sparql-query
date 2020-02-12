//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_IQUERYMODIFIER_HPP
#define SPARQL_QUERY_IQUERYMODIFIER_HPP

#include "../SelectQueryResult.hpp"

class IQueryModifier
{
public:
    virtual SelectQueryResult modifyResult(SelectQueryResult queryResult)=0;
};

#endif //SPARQL_QUERY_IQUERYMODIFIER_HPP
