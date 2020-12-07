//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_ABSTRACTSELECTNODE_HPP
#define SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

#include <memory>
#include <vector>
#include "../ICommandNode.hpp"
#include "../../TripleVariable.hpp"

/**
 * the stucture here follows template method pattern
 */
class AbstractSelectNode : public ICommandNode {

private:
    std::shared_ptr<IQueryNode> queryNode;
    std::vector<std::vector<char>> operands;

protected:
    std::vector<TripleVariable> selectVariables;



private:

    SelectQueryResult executeSubCommand(const SelectQueryResult& previousQueryResult)
    {
        SelectQueryResult queryResult=queryNode->execute(previousQueryResult);
        return queryResult;
    }


protected:
    virtual SelectQueryResult executeSelect(const SelectQueryResult& previousQueryResult)=0;


public:

    AbstractSelectNode(std::shared_ptr<IQueryNode> queryNode,std::vector<TripleVariable> selectVariables)
    {
        this->queryNode=queryNode;
        this->selectVariables=selectVariables;
    }


     SelectQueryResult execute(const SelectQueryResult& previousQueryResult) final
    {
        SelectQueryResult queryResult= executeSubCommand(previousQueryResult);
        queryResult=(queryResult);
        return queryResult;
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

};

#endif //SPARQL_QUERY_ABSTRACTSELECTNODE_HPP

