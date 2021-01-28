#ifndef SPARQL_QUERY_GROUPINGNODEDECORATOR_HPP
#define SPARQL_QUERY_GROUPINGNODEDECORATOR_HPP


#include <utility>

#include "Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/GroupingNode.hpp"


namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes {

    /*
     * This class adds behaviours to the group node(for now any number of filters)
     * todo: this is a proposal how to handle e.g. filters
     */
    class GroupingDecorator : public GroupingNode {

    private:
        std::shared_ptr<GroupingNode> wrappee;

    public:
        explicit GroupingDecorator(std::shared_ptr<GroupingNode> wrappee) : GroupingNode() {
            this->wrappee = std::move(wrappee);
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes


#endif//SPARQL_QUERY_GROUPINGNODEDECORATOR_HPP
