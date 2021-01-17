//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_REDUCEDSELECTNODE_HPP
#define SPARQL_QUERY_REDUCEDSELECTNODE_HPP


#include "Dice/sparql-query/Nodes/QueryNodes/SelectNodes/SelectNode.hpp"

namespace Dice::SPARQL::Nodes::QueryNodes::SelectNodes {
    class ReducedSelectNode : public SelectNode {

    public:
        ReducedSelectNode(std::shared_ptr<Node> node, std::vector<TripleVariable> selectVariables)
                : SelectNode(node, selectVariables) {
            this->selectModifier = SelectModifier::REDUCE;
        }

        ReducedSelectNode(std::shared_ptr<Node> node, std::vector<TripleVariable> selectVariables,
                          std::map<std::string, std::string> prefixes) : SelectNode(queryNode, selectVariables,
                                                                                    prefixes) {
            this->selectModifier = SelectModifier::REDUCE;
        }
    };
}
#endif //SPARQL_QUERY_REDUCEDSELECTNODE_HPP
