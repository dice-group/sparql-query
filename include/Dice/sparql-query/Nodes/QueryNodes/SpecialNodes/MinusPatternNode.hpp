#ifndef SPARQL_QUERY_MINUSPATTERNNODE_HPP
#define SPARQL_QUERY_MINUSPATTERNNODE_HPP

#include <utility>

#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"
#include "Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/SpecialNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class MinusPatternNode : public SpecialNode {
    public:
        MinusPatternNode(std::shared_ptr<QueryNode> queryNode) : SpecialNode(std::move(queryNode)){};

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes
#endif//SPARQL_QUERY_MINUSPATTERNNODE_HPP
