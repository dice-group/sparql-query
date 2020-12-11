//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_ABSTRACTSELECTNODE_HPP
#define SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

#include <memory>
#include <vector>
#include "../ICommandNode.hpp"
#include "../../TripleVariable.hpp"

namespace SparqlQueryGraph::Nodes::SelectNodes {
    enum SelectModifier {
        NONE,
        DISTINCT,
        REDUCE
    };

    class SelectNode : public ICommandNode {

    private:
        std::shared_ptr<IQueryNode> queryNode;
        std::map<std::string, std::string> prefixes;
        std::unordered_map<std::string, char> labelMap;
        std::vector<std::vector<char>> operands;
        std::vector<TripleVariable> selectVariables;


    protected:
        SelectModifier selectModifier;


    private:

        std::vector<std::vector<std::string>> generateStringOperands() override {
            return queryNode->generateStringOperands();

        }

        void generateOperands() {
            //ToDo double check
            std::vector<std::vector<std::string>> stringOperands = this->generateStringOperands();
            char next_label = 'a';
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

        SelectNode(std::shared_ptr<IQueryNode> queryNode, std::vector<TripleVariable> selectVariables) {
            this->queryNode = queryNode;
            this->generateOperands();
            if (selectVariables.size() == 1 &&
                (std::find(selectVariables.begin(), selectVariables.end(), TripleVariable("*")) !=
                 selectVariables.end())) {
                for (auto &label_pair : labelMap)
                    this->selectVariables.push_back(TripleVariable(label_pair.first));
            } else
                this->selectVariables = selectVariables;

        }

        SelectNode(std::shared_ptr<IQueryNode> queryNode, std::vector<TripleVariable> selectVariables,
                   std::map<std::string, std::string> prefixes) : SelectNode(queryNode, selectVariables) {
            this->prefixes = prefixes;
        }


        std::vector<std::vector<char>> getOperands() {
            return this->operands;
        }

        std::vector<char> getSubscriptResult() {
            std::vector<char> subscriptResult;
            for (auto &var:selectVariables)
                subscriptResult.push_back(labelMap[var.getName()]);
            return subscriptResult;

        }

        std::vector<TriplePatternElement> getBgps() {
            return queryNode->getBgps();
        }

        SelectModifier getSelectModifier() {
            return this->selectModifier;
        }

        std::vector<TripleVariable> getSelectVariables() {
            return selectVariables;
        }

        std::map<std::string, std::string> getPrefixes() {
            return this->prefixes;
        }

        std::vector<TripleVariable> getVariables() {
            return selectVariables;
        }

    };
}
#endif //SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

