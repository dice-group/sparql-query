//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_REDUCEDSELECTNODE_HPP
#define SPARQL_QUERY_REDUCEDSELECTNODE_HPP


#include "SelectNode.hpp"

class ReducedSelectNode : public SelectNode {

public:
    ReducedSelectNode(std::shared_ptr<IQueryNode> queryNode,std::vector<TripleVariable> selectVariables):SelectNode(queryNode,selectVariables) {
        this->selectModifier=SelectModifier::REDUCE;
    }
};

#endif //SPARQL_QUERY_REDUCEDSELECTNODE_HPP
