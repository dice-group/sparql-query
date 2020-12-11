//
// Created by fakhr on 12.02.20.
//


#ifndef SPARQL_QUERY_SELECTQUERY_HPP
#define SPARQL_QUERY_SELECTQUERY_HPP

#include <memory>
#include <map>
#include "SelectQueryResult.hpp"
#include "QueryNodes/SelectNodes/AbstractSelectNode.hpp"

class SelectQuery
{
private:
    std::shared_ptr<AbstractSelectNode> selectNode;
    std::map<std::string ,std::string> prefixes;
    std::unordered_map<std::string,char> labelMap;
    std::vector<std::vector<char>> operands;

    void generateOperands()
    {
        //ToDo
        std::vector<std::vector<std::string>> stringOperands= selectNode->generateOperands();
        char next_label='a';
        for(auto &operandsVector: stringOperands)
        {
            std::vector<char> localOperands;
            for(auto &operand: operandsVector)
            {
                if((operand == "[" )||(operand == "]")){
                    localOperands.push_back((char)operand[0]);
                }
                else {
                    if (labelMap.find(operand) == labelMap.end())
                        labelMap[operand] = next_label++;
                    localOperands.push_back(labelMap[operand]);
                }
            }
            operands.push_back(localOperands);
        }
    }

public:
    explicit SelectQuery( std::shared_ptr<AbstractSelectNode> selectNode)
    {
        this->selectNode=selectNode;
    }

    explicit SelectQuery( std::shared_ptr<AbstractSelectNode> selectNode,std::map<std::string ,std::string> prefixes)
    {
        this->selectNode=selectNode;
        this->prefixes=prefixes;
        generateOperands();
    }


    std::vector<char> getSubscriptResult()
    {
        std::vector<char> selectVariables;
        auto select_vars = selectNode->getVariables();
        if(select_vars.size() == 1 and select_vars[0] == TripleVariable("*")) {
            for(auto& label_pair : labelMap)
                selectVariables.push_back(label_pair.second);
        }
        else {
            for(auto &var:selectNode->getVariables())
                selectVariables.push_back(labelMap[var.getName()]);
        }
        return selectVariables;

    }

    std::vector<TripleVariable> getSelectVariables()
    {
        auto select_vars = selectNode->getVariables();
        if(select_vars.size() == 1 and select_vars[0] == TripleVariable("*")) {
            std::vector<TripleVariable> variables{};
            for(auto& label_pair : labelMap)
                variables.push_back(TripleVariable(label_pair.first));
            return variables;
        }
        else
            return select_vars;

    }

    std::vector<TriplePatternElement> getBgps()
    {
        return selectNode->getBgps();
    }

    std::map<std::string ,std::string> getPrefixes(){
        return this->prefixes;
    }

    SelectModifier getSelectModifier()
    {
        return selectNode->getSelectModifier();
    }

    std::vector<std::vector<char>> getOperands()
    {
        return this->operands;
    }



};

#endif //SPARQL_QUERY_SELECTQUERY_HPP
