//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DISTINCTSELECTNODE_HPP
#define SPARQL_QUERY_DISTINCTSELECTNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/SelectNodes/SelectNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SelectNodes {
    class DistinctSelectNode : public SelectNode {


    public:
        DistinctSelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables)
                : SelectNode(node, selectVariables) {
            this->selectModifier = SelectModifier::DISTINCT;
        }

        DistinctSelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables,
                           robin_hood::unordered_map<std::string, std::string> prefixes) : SelectNode(node, selectVariables,
                                                                                     prefixes) {
            this->selectModifier = SelectModifier::DISTINCT;
        }
    };
}
#endif //SPARQL_QUERY_DISTINCTSELECTNODE_HPP
