//
// Created by fakhr on 17.01.21.
//

#ifndef SPARQL_QUERY_GRAPHPATTERNNODE_HPP
#define SPARQL_QUERY_GRAPHPATTERNNODE_HPP

#include <variant>

#include "Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/SpecialNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class GraphPatternNode : public SpecialNode {
    private:
        std::variant<Variable, rdf::URIRef> content;

    public:
        GraphPatternNode(std::shared_ptr<QueryNode> queryNode, Variable var) : SpecialNode(std::move(queryNode)) {
            content = var;
        };

        GraphPatternNode(std::shared_ptr<QueryNode> queryNode, rdf::URIRef iri) : SpecialNode(std::move(queryNode)){
           content = iri
         };

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes

#endif//SPARQL_QUERY_GRAPHPATTERNNODE_HPP
