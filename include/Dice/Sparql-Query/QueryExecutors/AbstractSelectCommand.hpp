//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SELECTCOMMAND_HPP
#define SPARQL_QUERY_SELECTCOMMAND_HPP

#include <memory>
#include <vector>
#include "IQueryCommand.hpp"
#include "../TripleVariable.hpp"

/**
 * the stucture here follows template method pattern
 */
class AbstractSelectCommand : public IQueryCommand {

private:
    std::shared_ptr<IQueryExecutor> queryExecutor;
    std::vector<TripleVariable> patternVariables;

    SelectQueryResult executeSubCommand(const SelectQueryResult& previousQueryResult)
    {
        SelectQueryResult queryResult=queryExecutor->execute(previousQueryResult);
        return queryResult;
    }

protected:
    virtual SelectQueryResult executeSelect(const SelectQueryResult& previousQueryResult)=0;

public:
     SelectQueryResult execute(const SelectQueryResult& previousQueryResult) final
    {
        SelectQueryResult queryResult= executeSubCommand(previousQueryResult);
        queryResult=(queryResult);
        return queryResult;
    }

};

#endif //SPARQL_QUERY_SELECTCOMMAND_HPP

