//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_REDUCEDSELECTNODE_HPP
#define SPARQL_QUERY_REDUCEDSELECTNODE_HPP


#include "AbstractSelectNode.hpp"

class ReducedSelectNode : public AbstractSelectNode {
protected:
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();
    }

public:
    ReducedSelectNode(std::shared_ptr<IQueryNode> queryNode,std::vector<TripleVariable> selectVariables):AbstractSelectNode(queryNode,selectVariables) {
        this->selectModifier=SelectModifier::REDUCE;
    }
};

#endif //SPARQL_QUERY_REDUCEDSELECTNODE_HPP
