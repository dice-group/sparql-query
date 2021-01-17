//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_MINUSPATTERNNODE_HPP
#define SPARQL_QUERY_MINUSPATTERNNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/SpecialNode.hpp"

namespace Dice::SPARQL::Nodes::QueryNodes::SpecialNodes {
    class MinusPatternNode : public SpecialNode {
    public:

        MinusPatternNode(std::shared_ptr<QueryNode> queryNode) : SpecialNode(queryNode) {};

    };
}
#endif //SPARQL_QUERY_MINUSPATTERNNODE_HPP
