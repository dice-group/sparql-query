//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_FILTERPATTERNCOMMAND_HPP
#define SPARQL_QUERY_FILTERPATTERNCOMMAND_HPP


#include "ILeafCommand.hpp"
#include "../QueryModifiers/ResultModifiers/FilterModifier.hpp"

class FilterPatternCommand:public ILeafCommand
{
private:
    FilterModifier filterModifier;
public:
    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
        return filterModifier.modifyResult(previousQueryResult);
    }
};

#endif //SPARQL_QUERY_FILTERPATTERNCOMMAND_HPP
