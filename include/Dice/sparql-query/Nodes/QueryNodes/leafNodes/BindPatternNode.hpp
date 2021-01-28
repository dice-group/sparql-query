#ifndef SPARQL_QUERY_BINDPATTERNNODE_HPP
#define SPARQL_QUERY_BINDPATTERNNODE_HPP

#include <utility>

#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"
#include "Dice/sparql-query/Nodes/QueryNodes/leafNodes/LeafNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::LeafNodes {

    class BindPatternNode : public LeafNode {

    private:
        std::string expression;
        Variable var;

    public:
        BindPatternNode(std::string expression, Variable var) : expression(std::move(expression)), var(std::move(var)) {}

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::LeafNodes


#endif//SPARQL_QUERY_BINDPATTERNNODE_HPP
