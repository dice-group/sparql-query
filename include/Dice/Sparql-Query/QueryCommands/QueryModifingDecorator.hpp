//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_QUERYMODIFIER_HPP
#define SPARQL_QUERY_QUERYMODIFIER_HPP

#include "SelectCommandDecorator.hpp"
#include "../QueryModifiers/IQueryModifier.hpp"

class QueryModifingDecorator : public SelectCommandDecorator
{
private:
    std::shared_ptr<IQueryModifier> queryModifier;
public:

    SelectQueryResult executeCommand(SelectQueryResult previousQueryResult) override {
        return queryModifier->modifyResult(previousQueryResult);
    }
};

#endif //SPARQL_QUERY_QUERYMODIFIER_HPP
