//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_GROUPPATTERNCOMMAND_HPP
#define SPARQL_QUERY_GROUPPATTERNCOMMAND_HPP

#include "CompositePatternCommand.hpp"

class GroupPatternCommand:public CompositePatternCommand
{

public:
    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        SelectQueryResult queryResult=previousQueryResult;
        for(auto child:children)
            queryResult=child->execute(queryResult);
        return queryResult;
    }
};

#endif //SPARQL_QUERY_GROUPPATTERNCOMMAND_HPP
