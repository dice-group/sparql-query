//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_IQUERYNODE_HPP
#define SPARQL_QUERY_IQUERYNODE_HPP

#include "../SelectQueryResult.hpp"
#include <vector>

class IQueryNode
{
public:
    virtual SelectQueryResult execute(const SelectQueryResult& previousQueryResult)=0;

    virtual std::vector<std::string> generateSubscript()=0;

};

#endif //SPARQL_QUERY_IQUERYNODE_HPP
