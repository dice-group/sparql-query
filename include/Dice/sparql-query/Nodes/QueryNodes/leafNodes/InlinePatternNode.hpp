//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_INLINEPATTERNNODE_HPP
#define SPARQL_QUERY_INLINEPATTERNNODE_HPP

#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"
#include "Dice/sparql-query/Nodes/QueryNodes/leafNodes/LeafNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::LeafNodes {
    class InlinePatternNode : public LeafNode {

    private:
        //ToDo maybe we need to create a special class instead of a string
        std::string dataBlock;

    public:
        InlinePatternNode(std::string dataBlock) : dataBlock(dataBlock) {}

        std::vector<sparql::TriplePattern> getBgps() override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::LeafNodes

#endif//SPARQL_QUERY_INLINEPATTERNNODE_HPP
