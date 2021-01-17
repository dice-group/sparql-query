//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DEFAULTSELECTNODE_HPP
#define SPARQL_QUERY_DEFAULTSELECTNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/SelectNodes/SelectNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SelectNodes {
    class DefaultSelectNode : public SelectNode {

    public:
        DefaultSelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables)
                : SelectNode(node, selectVariables) {
            this->selectModifier = SelectModifier::NONE;
        }

        DefaultSelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables,
                          robin_hood::unordered_map<std::string, std::string> prefixes) : SelectNode(node, selectVariables,
                                                                                    prefixes) {
            this->selectModifier = SelectModifier::NONE;
        }
    };
}

#endif //SPARQL_QUERY_DEFAULTSELECTNODE_HPP
