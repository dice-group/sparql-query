//
// Created by fakhr on 12.02.20.
//


#ifndef SPARQL_QUERY_SELECTQUERY_HPP
#define SPARQL_QUERY_SELECTQUERY_HPP

#include <memory>
#include "IQuery.hpp"
#include "SelectQueryResult.hpp"
#include "QueryNodes/SelectNodes/AbstractSelectNode.hpp"

class SelectQuery:public IQuery<SelectQueryResult>
{
private:
    std::shared_ptr<AbstractSelectNode> selectNode;
    std::unordered_map<std::string ,std::string> prefixes;

public:
    explicit SelectQuery( std::shared_ptr<AbstractSelectNode> selectNode)
    {
        this->selectNode=selectNode;
    }

    explicit SelectQuery( std::shared_ptr<AbstractSelectNode> selectNode,std::unordered_map<std::string ,std::string> prefixes)
    {
        this->selectNode=selectNode;
        this->prefixes=prefixes;
    }

    SelectQueryResult executeQuery(const ITripleStore &tripleStore) override {
        //ToDo : find what exactly we should pass
        return selectNode->execute(SelectQueryResult());
    }

    std::vector<std::vector<char>> generateOperands()
    {
        //ToDo
        std::vector<std::vector<std::string>> stringOperands= selectNode->generateOperands();
        std::unordered_map<std::string,char> labelMap;
        std::vector<std::vector<char>> operands;
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
        return operands;


        return operands;
    }

    std::vector<TripleVariable> getVariables()
    {
        return selectNode->getVariables();
    }

    std::vector<TriplePatternElement> getBgps()
    {
        return selectNode->getBgps();
    }

    std::unordered_map<std::string ,std::string> getPrefixes(){
        return this->prefixes;
    }


};

#endif //SPARQL_QUERY_SELECTQUERY_HPP
