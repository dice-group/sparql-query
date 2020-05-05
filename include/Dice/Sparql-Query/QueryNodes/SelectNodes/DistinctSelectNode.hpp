//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_DISTINCTSELECTNODE_HPP
#define SPARQL_QUERY_DISTINCTSELECTNODE_HPP

#include "AbstractSelectNode.hpp"

class DistinctSelectNode : public AbstractSelectNode {
protected:
    SelectQueryResult executeSelect(const SelectQueryResult &previousQueryResult) override {
        return SelectQueryResult();
    }

public:
    DistinctSelectNode(std::shared_ptr<IQueryNode> queryNode):AbstractSelectNode(queryNode) {}
};

#endif //SPARQL_QUERY_DISTINCTSELECTNODE_HPP
