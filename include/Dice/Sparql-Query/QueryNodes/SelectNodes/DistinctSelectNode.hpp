//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DISTINCTSELECTNODE_HPP
#define SPARQL_QUERY_DISTINCTSELECTNODE_HPP

#include "SelectNode.hpp"

class DistinctSelectNode : public SelectNode {


public:
    DistinctSelectNode(std::shared_ptr<IQueryNode> queryNode,std::vector<TripleVariable> selectVariables):SelectNode(queryNode,selectVariables) {
        this->selectModifier=SelectModifier::DISTINCT;
    }
};

#endif //SPARQL_QUERY_DISTINCTSELECTNODE_HPP
