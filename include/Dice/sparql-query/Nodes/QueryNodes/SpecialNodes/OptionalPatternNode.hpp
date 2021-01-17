//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
#define SPARQL_QUERY_OPTIONALPATTERNNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/SpecialNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class OptionalPatternNode : public SpecialNode {
    public:

        OptionalPatternNode(std::shared_ptr<QueryNode> queryNode) : SpecialNode(queryNode) {};


        std::vector<std::vector<std::string>> generateStringOperands() override {
            std::vector<std::vector<std::string>> operands;
            operands.push_back(std::vector<std::string>{"["});
            std::vector<std::vector<std::string>> nodeoperands = node->generateStringOperands();
            for (auto &subscriptElement : nodeoperands)
                operands.push_back(subscriptElement);
            operands.push_back(std::vector<std::string>{"]"});

            return operands;
        }

        std::vector<TriplePattern> getBgps() override {
            return node->getBgps();
        }

    };
}
#endif //SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
