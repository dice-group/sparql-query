#ifndef SPARQL_QUERY_DISTINCTSELECTNODE_HPP
#define SPARQL_QUERY_DISTINCTSELECTNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/SelectNodes/SelectNode.hpp"

#include <utility>

namespace Dice::sparql::Nodes::QueryNodes::SelectNodes {
    class DistinctSelectNode : public SelectNode {


    public:
        DistinctSelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables)
            : SelectNode(std::move(node),
                         std::move(selectVariables),
                         SelectModifier::DISTINCT) {
        }

        DistinctSelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables,
                           robin_hood::unordered_map<std::string, std::string> prefixes)
            : SelectNode(std::move(node),
                         std::move(selectVariables),
                         std::move(prefixes),
                         SelectModifier::DISTINCT) {
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::SelectNodes
#endif//SPARQL_QUERY_DISTINCTSELECTNODE_HPP
