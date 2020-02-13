//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DEFAULTSELECTCOMMAND_HPP
#define SPARQL_QUERY_DEFAULTSELECTCOMMAND_HPP

#include "AbstractSelectCommand.hpp"

class DefaultSelectCommand:public AbstractSelectCommand
{
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();
    }
};

#endif //SPARQL_QUERY_DEFAULTSELECTCOMMAND_HPP
