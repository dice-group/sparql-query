//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_UNIONPATTERNNODE_HPP
#define SPARQL_QUERY_UNIONPATTERNNODE_HPP

namespace Dice::sparql::Nodes::QueryNodes::SpecialNodes {
    class UnionPatternNode : public SpecialNode {
    public:

        UnionPatternNode(std::shared_ptr<QueryNode> queryNode) : SpecialNode(queryNode) {};

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }

    };
}

#endif //SPARQL_QUERY_UNIONPATTERNNODE_HPP
