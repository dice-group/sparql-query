//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_REDUCEDSELECTNODE_HPP
#define SPARQL_QUERY_REDUCEDSELECTNODE_HPP


#include "Dice/sparql-query/Nodes/QueryNodes/SelectNodes/SelectNode.hpp"

#include <utility>

namespace Dice::sparql::Nodes::QueryNodes::SelectNodes {
    class ReducedSelectNode : public SelectNode {

    public:
        ReducedSelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables)
            : SelectNode(std::move(node),
                         std::move(selectVariables),
                         SelectModifier::REDUCE) {
        }

        ReducedSelectNode(std::shared_ptr<Node> node,
                          std::vector<Variable> selectVariables,
                          robin_hood::unordered_map<std::string, std::string> prefixes)
            : SelectNode(std::move(node),
                         std::move(selectVariables),
                         std::move(prefixes),
                         SelectModifier::REDUCE) {
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::SelectNodes
#endif//SPARQL_QUERY_REDUCEDSELECTNODE_HPP
