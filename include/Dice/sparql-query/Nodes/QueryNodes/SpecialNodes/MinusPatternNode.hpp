//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_MINUSPATTERNNODE_HPP
#define SPARQL_QUERY_MINUSPATTERNNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/SpecialNode.hpp"
#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class MinusPatternNode : public SpecialNode {
    public:

        MinusPatternNode(std::shared_ptr<QueryNode> queryNode) : SpecialNode(queryNode) {};

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}
#endif //SPARQL_QUERY_MINUSPATTERNNODE_HPP
