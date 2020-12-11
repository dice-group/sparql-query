//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_MINUSPATTERNNODE_HPP
#define SPARQL_QUERY_MINUSPATTERNNODE_HPP

#include "SpecialNode.hpp"

namespace SparqlQueryGraph::Nodes::GraphNodes {
    class MinusPatternNode : public SpecialNode {
    public:

        MinusPatternNode(std::shared_ptr<ICommandNode> commandnode) : SpecialNode(commandnode) {};

    };
}
#endif //SPARQL_QUERY_MINUSPATTERNNODE_HPP
