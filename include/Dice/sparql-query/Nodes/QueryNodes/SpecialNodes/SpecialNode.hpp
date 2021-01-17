//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SPECIALNODE_HPP
#define SPARQL_QUERY_SPECIALNODE_HPP

#include <vector>
#include <memory>

#include "Dice/sparql-query/Nodes/QueryNodes/QueryNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class SpecialNode : public QueryNode {
    protected:
        std::shared_ptr<QueryNode> node;

    public:
        SpecialNode(std::shared_ptr<QueryNode> queryNode) {
            node = queryNode;
        }
    };
}
#endif //SPARQL_QUERY_SPECIALNODE_HPP
