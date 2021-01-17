//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SPECIALNODE_HPP
#define SPARQL_QUERY_SPECIALNODE_HPP

#include <vector>
#include <memory>
#include "../ICommandNode.hpp"

namespace SparqlQueryGraph::Nodes::GraphNodes {
    class SpecialNode : public ICommandNode {
    protected:
        std::shared_ptr<ICommandNode> node;

    public:
        SpecialNode(std::shared_ptr<ICommandNode> commandnode) {
            node = commandnode;
        }
    };
}
#endif //SPARQL_QUERY_SPECIALNODE_HPP