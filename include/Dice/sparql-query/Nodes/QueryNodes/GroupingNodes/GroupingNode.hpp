//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_GROUPINGNODE_HPP
#define SPARQL_QUERY_GROUPINGNODE_HPP

#include <memory>
#include <vector>

#include "Dice/sparql-query/Nodes/QueryNodes/QueryNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes {
    class GroupingNode : public QueryNode {
    protected:
        //ToDo find the best collection to use here(vector,list....)
        std::vector<std::shared_ptr<QueryNode>> children;

    public:
        void addChild(std::shared_ptr<QueryNode> queryNode) {
            children.push_back(queryNode);
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes

#endif//SPARQL_QUERY_GROUPINGNODE_HPP
