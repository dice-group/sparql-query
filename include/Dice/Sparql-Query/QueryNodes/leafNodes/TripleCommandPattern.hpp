//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_TRIPLECOMMANDPATTERN_HPP
#define SPARQL_QUERY_TRIPLECOMMANDPATTERN_HPP

#include "ILeafCommand.hpp"

class TripleCommandPattern:public ILeafCommand
{
public:
    SelectQueryResult execute(const SelectQueryResult &previousQueryResult) override {
        //ToDo : the actual logic of querying the triple store must be implemented here
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_TRIPLECOMMANDPATTERN_HPP
