//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SOLUTIONDECORATOR_HPP
#define SPARQL_QUERY_SOLUTIONDECORATOR_HPP

#include <memory>

#include "Dice/sparql-query/Nodes/Node.hpp"
#include "Dice/sparql-query/Nodes/SolutionModifiers/SolutionModifier.hpp"

using namespace Dice::SPARQL::Nodes;

namespace Dice::SPARQL::Nodes {
    class SolutionDecorator : public Node {
    private:
        std::shared_ptr<Node> wrappee;
        std::shared_ptr<SolutionModifiers::SolutionModifier> modifier;
    public:
        SolutionDecorator(std::shared_ptr<Node> node, std::shared_ptr<SolutionModifiers::SolutionModifier> modifier) {
            wrappee = node;
            this->modifier = modifier;
        }

//    SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
//        //ToDo : here the order of execution is defined ..need to be reviewd carfully for all types of modifiers and add another decoator type if needed
//        SelectQueryResult queryResult= wrappee->execute(previousQueryResult);
//        queryResult=queryModifier->modifyResult(queryResult);
//        return queryResult;
//    }

        std::vector<std::vector<std::string>> generateStringOperands() override {
            //ToDo check the architecture to avoid this
            return std::vector<std::vector<std::string>>{{""}};
        }

        std::vector<TriplePatternElement> getBgps() override {
            //ToDo

        }
    };
}
#endif //SPARQL_QUERY_SOLUTIONDECORATOR_HPP
