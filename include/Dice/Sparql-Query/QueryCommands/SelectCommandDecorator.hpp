//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SELECTCOMMANDDECORATOR_HPP
#define SPARQL_QUERY_SELECTCOMMANDDECORATOR_HPP

#include "ISelectCommand.hpp"
#include <memory>

class SelectCommandDecorator : public ISelectCommand
{
private:
    std::shared_ptr<ISelectCommand> wrappee;
public:
    SelectCommandDecorator(std::shared_ptr<ISelectCommand> selectCommand)
    {
        wrappee=selectCommand;
    }
};

#endif //SPARQL_QUERY_SELECTCOMMANDDECORATOR_HPP
