//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_MINUSPATTERNCOMMAND_HPP
#define SPARQL_QUERY_MINUSPATTERNCOMMAND_HPP

#include "CompositePatternCommand.hpp"

class MinusPatternCommand:public CompositePatternCommand
{
public:
    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        SelectQueryResult queryResult=previousQueryResult;
        for(auto child:children)
            queryResult=child->execute(queryResult);
        //ToDo implement the logic here to perform : return queryResult=previousQueryResult-queryResult
        return queryResult;
    }
};

#endif //SPARQL_QUERY_MINUSPATTERNCOMMAND_HPP
