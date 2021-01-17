//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_BINDPATTERNNODE_HPP
#define SPARQL_QUERY_BINDPATTERNNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/leafNodes/LeafNode.hpp"
#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"

namespace Dice::sparql::Nodes::QueryNodes::LeafNodes {

    class BindPatternNode : public LeafNode {

    private:
        std::string expression;
        Variable var;

    public:
        BindPatternNode(std::string expression, Variable var) : expression(expression), var(var) {}

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::LeafNodes


#endif//SPARQL_QUERY_BINDPATTERNNODE_HPP
