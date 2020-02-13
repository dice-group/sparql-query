//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SELECTCOMMAND_HPP
#define SPARQL_QUERY_SELECTCOMMAND_HPP

#include <memory>
#include <vector>
#include "IQueryCommand.hpp"
#include "../TripleVariable.hpp"
class SelectCommand : public IQueryCommand {

private:
    std::shared_ptr<IQueryExecutor> queryExecutor;
    std::vector<TripleVariable> patternVariables;

public:
    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override
    {
        SelectQueryResult queryResult=queryExecutor->execute(previousQueryResult);
        //ToDo : implement the logic of the selecting here
        return queryResult;
    }

};

#endif //SPARQL_QUERY_SELECTCOMMAND_HPP

