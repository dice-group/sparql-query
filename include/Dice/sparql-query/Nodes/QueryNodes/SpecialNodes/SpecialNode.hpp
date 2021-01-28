#ifndef SPARQL_QUERY_SPECIALNODE_HPP
#define SPARQL_QUERY_SPECIALNODE_HPP

#include <memory>
#include <utility>
#include <vector>

#include "Dice/sparql-query/Nodes/QueryNodes/QueryNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class SpecialNode : public QueryNode {
    protected:
        std::shared_ptr<QueryNode> node;

    public:
        explicit SpecialNode(std::shared_ptr<QueryNode> queryNode) {
            node = std::move(queryNode);
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes
#endif//SPARQL_QUERY_SPECIALNODE_HPP
