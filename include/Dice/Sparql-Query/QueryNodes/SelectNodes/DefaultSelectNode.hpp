//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DEFAULTSELECTNODE_HPP
#define SPARQL_QUERY_DEFAULTSELECTNODE_HPP

#include "AbstractSelectNode.hpp"

class DefaultSelectNode : public AbstractSelectNode {
protected:
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();

    }

public:
    DefaultSelectNode(std::shared_ptr <IQueryNode> queryNode):AbstractSelectNode(queryNode) {}
};

#endif //SPARQL_QUERY_DEFAULTSELECTNODE_HPP
