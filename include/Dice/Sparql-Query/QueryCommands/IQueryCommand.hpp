//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_IQUERYCOMMAND_HPP
#define SPARQL_QUERY_IQUERYCOMMAND_HPP

#include "../SelectQueryResult.hpp"

class IQueryCommand
{
public:
    virtual SelectQueryResult executeCommand(SelectQueryResult previousQueryResult)=0;
};
#endif //SPARQL_QUERY_IQUERYCOMMAND_HPP
