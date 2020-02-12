//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_MINUSPATTERNCOMMAND_HPP
#define SPARQL_QUERY_MINUSPATTERNCOMMAND_HPP

#include "CompositePatternCommand.hpp"

class MinusPatternCommand:public CompositePatternCommand
{
public:
    SelectQueryResult executeCommand(SelectQueryResult previousQueryResult) override {
        //ToDo implement the logic here
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_MINUSPATTERNCOMMAND_HPP
