//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_GROUPPATTERNCOMMAND_HPP
#define SPARQL_QUERY_GROUPPATTERNCOMMAND_HPP

#include "CompositePatternCommand.hpp"

class GroupPatternCommand:public CompositePatternCommand
{

public:
    SelectQueryResult executeCommand(SelectQueryResult previousQueryResult) override {
        //ToDo implement the logic here
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_GROUPPATTERNCOMMAND_HPP
