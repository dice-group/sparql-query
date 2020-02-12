//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SELECTCOMMAND_HPP
#define SPARQL_QUERY_SELECTCOMMAND_HPP

#include <memory>
#include "ISelectCommand.hpp"

class SelectCommand:public ISelectCommand
{
private:
    std::shared_ptr<IQueryCommand> queryCommand;
};

#endif //SPARQL_QUERY_SELECTCOMMAND_HPP
