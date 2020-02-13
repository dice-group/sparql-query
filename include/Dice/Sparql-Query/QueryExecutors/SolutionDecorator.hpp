//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SOLUTIONDECORATOR_HPP
#define SPARQL_QUERY_SOLUTIONDECORATOR_HPP

#include <memory>

#include "IQueryExecutor.hpp"
#include "../SolutionModifiers/ISolutionModifier.hpp"


class SolutionDecorator : public IQueryExecutor
{
private:
    std::shared_ptr<IQueryExecutor> wrappee;
    std::shared_ptr<ISolutionModifier> queryModifier;
public:
    SolutionDecorator(std::shared_ptr<IQueryExecutor> queryExecutor,std::shared_ptr<ISolutionModifier> queryModifier)
    {
        wrappee=queryExecutor;
        this->queryModifier=queryModifier;
    }

    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        //ToDo : here the order of execution is defined ..need to be reviewd carfully for all types of modifiers and add another decoator type if needed
        SelectQueryResult queryResult= wrappee->execute(previousQueryResult);
        queryResult=queryModifier->modifyResult(queryResult);
        return queryResult;
    }

};

#endif //SPARQL_QUERY_SOLUTIONDECORATOR_HPP
