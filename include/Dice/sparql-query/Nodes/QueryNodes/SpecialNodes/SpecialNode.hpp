//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SPECIALNODE_HPP
#define SPARQL_QUERY_SPECIALNODE_HPP

#include <vector>
#include <memory>

#include "Dice/sparql-query/Nodes/QueryNodes/QueryNode.hpp"

namespace Dice::SPARQL::Nodes::QueryNodes::SpecialNodes {
    class SpecialNode : public QueryNode {
    protected:
        std::shared_ptr<ICommandNode> node;

    public:
        SpecialNode(std::shared_ptr<ICommandNode> commandnode) {
            node = commandnode;
        }
    };
}
#endif //SPARQL_QUERY_SPECIALNODE_HPP
