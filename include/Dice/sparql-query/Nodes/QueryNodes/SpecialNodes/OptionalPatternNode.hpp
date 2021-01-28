#ifndef SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
#define SPARQL_QUERY_OPTIONALPATTERNNODE_HPP

#include <utility>

#include "Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/SpecialNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class OptionalPatternNode : public SpecialNode {
    public:
        explicit OptionalPatternNode(std::shared_ptr<QueryNode> queryNode) : SpecialNode(std::move(queryNode)){};


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
}// namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes
#endif//SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
