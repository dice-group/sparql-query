//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SOLUTIONDECORATOR_HPP
#define SPARQL_QUERY_SOLUTIONDECORATOR_HPP

#include <memory>

#include "Dice/sparql-query/Nodes/Node.hpp"
#include "Dice/sparql-query/Nodes/SolutionModifiers/SolutionModifier.hpp"

using namespace Dice::sparql::Nodes;

namespace Dice::sparql::Nodes {

    /*
     * This class is used to add additional behaviours to a query node in runtime. Each behaviour can be applied before or after the actual behaviour.
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

        std::vector<TriplePattern> getBgps() override {
            //ToDo

        }
    };
}
#endif //SPARQL_QUERY_SOLUTIONDECORATOR_HPP
