//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DEFAULTSELECTNODE_HPP
#define SPARQL_QUERY_DEFAULTSELECTNODE_HPP

#include "AbstractSelectNode.hpp"

class DefaultSelectNode : public AbstractSelectNode {

public:
    DefaultSelectNode(std::shared_ptr <IQueryNode> queryNode,std::vector<TripleVariable> selectVariables):AbstractSelectNode(queryNode,selectVariables) {
        this->selectModifier=SelectModifier::NONE;
    }
};

#endif //SPARQL_QUERY_DEFAULTSELECTNODE_HPP
