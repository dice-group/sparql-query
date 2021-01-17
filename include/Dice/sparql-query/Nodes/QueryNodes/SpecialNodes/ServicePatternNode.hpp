//
// Created by fakhr on 17.01.21.
//

#ifndef SPARQL_QUERY_SERVICEPATTERNNODE_HPP
#define SPARQL_QUERY_SERVICEPATTERNNODE_HPP

#include <variant>

#include "Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/SpecialNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class ServicePatternNode : public SpecialNode {
    private:
        std::variant<Variable, rdf::URIRef> content;
        bool isSilent;

    public:
        ServicePatternNode(std::shared_ptr<QueryNode> queryNode, Variable var, bool isSilent) : SpecialNode(std::move(queryNode)) {
            content = var;
            this->isSilent = isSilent;
        };

        ServicePatternNode(std::shared_ptr<QueryNode> queryNode, rdf::URIRef iri, bool isSilent) : SpecialNode(std::move(queryNode)) {
            content = iri;
            this->isSilent = isSilent;
        };

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes
#endif//SPARQL_QUERY_SERVICEPATTERNNODE_HPP
