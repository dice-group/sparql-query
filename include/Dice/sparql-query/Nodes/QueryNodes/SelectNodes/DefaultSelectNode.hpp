#ifndef SPARQL_QUERY_DEFAULTSELECTNODE_HPP
#define SPARQL_QUERY_DEFAULTSELECTNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/SelectNodes/SelectNode.hpp"

#include <utility>

namespace Dice::sparql::Nodes::QueryNodes::SelectNodes {
    class DefaultSelectNode : public SelectNode {

    public:
        DefaultSelectNode(std::shared_ptr<Node> node,
                          std::vector<Variable> selectVariables)
            : SelectNode(std::move(node),
                         std::move(selectVariables),
                         SelectModifier::NONE) {
        }

        DefaultSelectNode(std::shared_ptr<Node> node,
                          std::vector<Variable> selectVariables,
                          robin_hood::unordered_map<std::string, std::string> prefixes)
            : SelectNode(std::move(node),
                         std::move(selectVariables),
                         std::move(prefixes),
                         SelectModifier::NONE) {
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::SelectNodes

#endif//SPARQL_QUERY_DEFAULTSELECTNODE_HPP
