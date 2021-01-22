//
// Created by fakhr on 22.01.21.
//

#ifndef SPARQL_QUERY_GROUPINGNODEDECORATOR_HPP
#define SPARQL_QUERY_GROUPINGNODEDECORATOR_HPP


#include "Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/GroupingNode.hpp"


namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes {

    /*
     * This class adds behaviours to the group node(for now any number of filters)
     */
    class GroupingDecorator : public GroupingNode {

    private:
        std::shared_ptr<GroupingNode> wrappee;
    public:
        GroupingDecorator(std::shared_ptr<GroupingNode> wrappee):GroupingNode(){
            this->wrappee=wrappee;
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes


#endif//SPARQL_QUERY_GROUPINGNODEDECORATOR_HPP
