//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DEFAULTSELECTNODE_HPP
#define SPARQL_QUERY_DEFAULTSELECTNODE_HPP

#include "SelectNode.hpp"

class DefaultSelectNode : public SelectNode {

public:
    DefaultSelectNode(std::shared_ptr <IQueryNode> queryNode,std::vector<TripleVariable> selectVariables): SelectNode(queryNode, selectVariables) {
        this->selectModifier=SelectModifier::NONE;
    }

    DefaultSelectNode(std::shared_ptr <IQueryNode> queryNode,std::vector<TripleVariable> selectVariables,std::map<std::string ,std::string> prefixes): SelectNode(queryNode, selectVariables,prefixes) {
        this->selectModifier=SelectModifier::NONE;
    }
};

#endif //SPARQL_QUERY_DEFAULTSELECTNODE_HPP
