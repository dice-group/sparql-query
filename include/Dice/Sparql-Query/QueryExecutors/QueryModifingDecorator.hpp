//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_QUERYMODIFIER_HPP
#define SPARQL_QUERY_QUERYMODIFIER_HPP

#include "QueryDecorator.hpp"
#include "../QueryModifiers/IQueryModifier.hpp"

class QueryModifingDecorator : public QueryDecorator
{
private:
    std::shared_ptr<IQueryModifier> queryModifier;
public:

    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        //ToDo : here the order of execution is defined ..need to be reviewd carfully for all types of modifiers and add another decoator type if needed
        SelectQueryResult queryResult= wrappee->execute(previousQueryResult);
        queryResult=queryModifier->modifyResult(queryResult);
        return queryResult;
    }
};

#endif //SPARQL_QUERY_QUERYMODIFIER_HPP
