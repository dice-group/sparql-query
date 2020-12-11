//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_ABSTRACTSELECTNODE_HPP
#define SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

#include <memory>
#include <vector>
#include "../ICommandNode.hpp"
#include "../../TripleVariable.hpp"


enum SelectModifier {
    NONE,
    DISTINCT,
    REDUCE
};

class AbstractSelectNode : public ICommandNode {

private:
    std::shared_ptr<IQueryNode> queryNode;

protected:
    std::vector<TripleVariable> selectVariables;
    SelectModifier selectModifier;



public:

    AbstractSelectNode(std::shared_ptr<IQueryNode> queryNode,std::vector<TripleVariable> selectVariables)
    {
        this->queryNode=queryNode;
        if(selectVariables.size()==1 && (std::find(selectVariables.begin(),selectVariables.end(),TripleVariable("*"))!=selectVariables.end()))
        {

        }
        else
            this->selectVariables=selectVariables;
    }



    std::vector<std::vector<std::string>> generateOperands() override {
        return queryNode->generateOperands();
    }


    std::vector<TripleVariable> getVariables()
    {
        return selectVariables;
    }


    std::vector<TriplePatternElement> getBgps()
    {
        return queryNode->getBgps();
    }

    SelectModifier getSelectModifier()
    {
        return this->selectModifier;
    }

};

#endif //SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

