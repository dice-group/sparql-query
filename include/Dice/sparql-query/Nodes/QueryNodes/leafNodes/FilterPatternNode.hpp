//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_FILTERPATTERNNODE_HPP
#define SPARQL_QUERY_FILTERPATTERNNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/leafNodes/LeafNode.hpp"
#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"

namespace Dice::sparql::Nodes::QueryNodes::LeafNodes {
    class FilterPatternNode : public LeafNode {

    private:
        //ToDo maybe we need to create a special class instead of a string
        std::string constraint;

    public:
        FilterPatternNode(std::string constraint) : constraint(constraint) {}

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::LeafNodes

#endif//SPARQL_QUERY_FILTERPATTERNNODE_HPP
