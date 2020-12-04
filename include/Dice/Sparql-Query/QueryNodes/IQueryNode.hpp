//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_IQUERYNODE_HPP
#define SPARQL_QUERY_IQUERYNODE_HPP

#include "../SelectQueryResult.hpp"

class IQueryNode
{
public:
    virtual SelectQueryResult execute(const SelectQueryResult& previousQueryResult)=0;

    virtual vector<std::string> process()=0;
};

#endif //SPARQL_QUERY_IQUERYNODE_HPP
