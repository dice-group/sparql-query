//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_ABSTRACTSELECTNODE_HPP
#define SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

#include <memory>
#include <vector>

#include <robin_hood.h>

#include "Dice/sparql-query/Nodes/QueryNodes/QueryNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::SelectNodes {

    enum SelectModifier {
        NONE,
        DISTINCT,
        REDUCE
    };

    class SelectNode : public QueryNode {

    private:
        std::shared_ptr<Node> node;
        robin_hood::unordered_map<std::string, std::string> prefixes;
        std::unordered_map<std::string, char> labelMap;
        std::vector<std::vector<char>> operands;
        std::vector<Variable> selectVariables;
        char next_label = 'a';


    protected:
        SelectModifier selectModifier;


    private:

        std::vector<std::vector<std::string>> generateStringOperands() override {
            return node->generateStringOperands();

        }

        void generateOperands() {
            //ToDo double check
            std::vector<std::vector<std::string>> stringOperands = this->generateStringOperands();
            for (auto &operandsVector: stringOperands) {
                std::vector<char> localOperands;
                for (auto &operand: operandsVector) {
                    //process OPTIONAL logic
                    if ((operand == "[") || (operand == "]")) {
                        localOperands.push_back((char) operand[0]);
                    } else {
                        if (labelMap.find(operand) == labelMap.end())
                            labelMap[operand] = next_label++;
                        localOperands.push_back(labelMap[operand]);
                    }
                }
                operands.push_back(localOperands);
            }

        }

    public:

        SelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables) {
            this->node = node;
            this->generateOperands();
            if (selectVariables.size() == 1 &&
                (std::find(selectVariables.begin(), selectVariables.end(), Variable("*")) !=
                 selectVariables.end())) {
                for (auto &label_pair : labelMap)
                    this->selectVariables.push_back(Variable(label_pair.first));
            } else
                this->selectVariables = selectVariables;

        }

        SelectNode(std::shared_ptr<Node> node, std::vector<Variable> selectVariables,
                   robin_hood::unordered_map<std::string, std::string> prefixes) : SelectNode(node, selectVariables) {
            this->prefixes = prefixes;
        }


        std::vector<std::vector<char>> getOperands() {
            return this->operands;
        }

        std::vector<char> getSubscriptResult() {
            std::vector<char> subscriptResult;
            for (auto &var:selectVariables)
            {
                if(labelMap.find(var.getName())!=labelMap.end())
                    subscriptResult.push_back(labelMap[var.getName()]);
                //process the case if the select variable is not on the variables insude the query
                else {
                    labelMap[var.getName()] = next_label++;
                    subscriptResult.push_back(labelMap[var.getName()]);
                }

            }
            return subscriptResult;

        }

        std::vector<TriplePattern> getBgps() {
            return node->getBgps();
        }

        SelectModifier getSelectModifier() {
            return this->selectModifier;
        }

        std::vector<Variable> getSelectVariables() {
            return selectVariables;
        }

        robin_hood::unordered_map<std::string, std::string> getPrefixes() {
            return this->prefixes;
        }

        std::vector<Variable> getVariables() {
            return selectVariables;
        }

    };
}
#endif //SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

