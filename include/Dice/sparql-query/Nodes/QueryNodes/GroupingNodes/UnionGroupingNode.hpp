#ifndef SPARQL_QUERY_UNIONGROUPINGNODE_HPP
#define SPARQL_QUERY_UNIONGROUPINGNODE_HPP


#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"
#include "Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/GroupingNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes {
    class UnionGroupingNode : public GroupingNode {

    public:
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }

        std::vector<TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes

#endif//SPARQL_QUERY_UNIONGROUPINGNODE_HPP
