#ifndef SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
#define SPARQL_QUERY_TRIPLEPATTERNNODE_HPP

#include <utility>
#include <vector>

#include "Dice/sparql-query/Nodes/QueryNodes/leafNodes/LeafNode.hpp"


namespace Dice::sparql::Nodes::QueryNodes::LeafNodes {

    class TriplePatternNode : public LeafNode {

    private:
        std::vector<TriplePattern> elements;

    public:
        explicit TriplePatternNode(std::vector<TriplePattern> elements) {
            this->elements = std::move(elements);
        }


        std::vector<std::vector<std::string>> generateStringOperands() override {
            std::vector<std::vector<std::string>> operands{};
            for (TriplePattern &element : elements) {
                std::vector<std::string> patternOperands;
                if (std::holds_alternative<Variable>(element.subject()))
                    patternOperands.push_back(std::get<Variable>(element.subject()).getName());
                if (std::holds_alternative<Variable>(element.predicate()))
                    patternOperands.push_back(std::get<Variable>(element.predicate()).getName());
                if (std::holds_alternative<Variable>(element.object()))
                    patternOperands.push_back(std::get<Variable>(element.object()).getName());
                if (not patternOperands.empty())
                    operands.push_back(patternOperands);
            }

            return operands;
        }

        std::vector<TriplePattern> getBgps() override {
            return elements;
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::LeafNodes

#endif//SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
