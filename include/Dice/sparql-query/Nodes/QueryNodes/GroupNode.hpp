//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_GROUPNODE_HPP
#define SPARQL_QUERY_GROUPNODE_HPP

#include <vector>
#include <memory>

#include "Dice/sparql-query/Nodes/QueryNodes/QueryNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes {
    class GroupNode : public QueryNode {
    protected:
        //ToDo find the best collection to use here(vector,list....)
        std::vector<std::shared_ptr<QueryNode>> children;

    public:

        void addChild(std::shared_ptr<QueryNode> queryNode) {
            children.push_back(queryNode);
        }


        std::vector<std::vector<std::string>> generateStringOperands() override {
            std::vector<std::vector<std::string>> operands;
            for (auto &child:children) {
                std::vector<std::vector<std::string>> childOperands = child->generateStringOperands();
                for (auto &subscriptElement:childOperands)
                    operands.push_back(subscriptElement);
            }

            return operands;
        }

        std::vector<TriplePattern> getBgps() override {
            std::vector<TriplePattern> bgps;
            for (auto &child:children) {
                std::vector<TriplePattern> childBgps = child->getBgps();
                for (auto &elements:childBgps)
                    bgps.push_back(elements);
            }

            return bgps;
        }
    };
}

#endif //SPARQL_QUERY_GROUPNODE_HPP
