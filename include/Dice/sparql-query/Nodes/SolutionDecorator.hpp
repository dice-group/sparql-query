//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SOLUTIONDECORATOR_HPP
#define SPARQL_QUERY_SOLUTIONDECORATOR_HPP

#include <memory>

#include "Dice/sparql-query/Nodes/Node.hpp"
#include "Dice/sparql-query/Nodes/SolutionModifiers/SolutionModifier.hpp"


namespace Dice::sparql::Nodes {

    /*
     * This class is used to add modifications to a query node at runtime.
     */
    class SolutionDecorator : public Node {
    private:
        std::shared_ptr<Node> wrappee;
        std::shared_ptr<SolutionModifiers::SolutionModifier> modifier;

    public:
        SolutionDecorator(std::shared_ptr<Node> node, std::shared_ptr<SolutionModifiers::SolutionModifier> modifier) {
            wrappee = node;
            this->modifier = modifier;
        }
        std::vector<sparql::TriplePattern> getBgps() override {
            auto result = modifier->modifyGetBgpsResult(wrappee->getBgps());
            return result;
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            auto result = modifier->modifyGenerateStringOperandsResult(wrappee->generateStringOperands());
            return result;
        }
    };
}// namespace Dice::sparql::Nodes
#endif//SPARQL_QUERY_SOLUTIONDECORATOR_HPP
