//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
#define SPARQL_QUERY_TRIPLEPATTERNNODE_HPP

#include "ILeafNode.hpp"
#include "Dice/Sparql-Query/TriplePatternElement.hpp"

#include <vector>

using namespace SparqlQueryGraph;

namespace SparqlQueryGraph::Nodes::GraphNodes {

    class TriplePatternNode : public ILeafNode {

    private:
        std::vector<TriplePatternElement> elements;

    public:
        TriplePatternNode(std::vector<TriplePatternElement> elements) {
            this->elements = elements;
        }


        std::vector<std::vector<std::string>> generateStringOperands() override {
            std::vector<std::vector<std::string>> operands;
            for (TriplePatternElement &element:elements) {
                std::vector<std::string> patternOperands;
                if (std::holds_alternative<TripleVariable>(element.getFirstElement()))
                    patternOperands.push_back(std::get<TripleVariable>(element.getFirstElement()).getName());
                if (std::holds_alternative<TripleVariable>(element.getSecondElement()))
                    patternOperands.push_back(std::get<TripleVariable>(element.getSecondElement()).getName());
                if (std::holds_alternative<TripleVariable>(element.getThirdElement()))
                    patternOperands.push_back(std::get<TripleVariable>(element.getThirdElement()).getName());
                operands.push_back(patternOperands);
            }

            return operands;
        }

        std::vector<TriplePatternElement> getBgps() override {
            return elements;

        }


    };
}

#endif //SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
