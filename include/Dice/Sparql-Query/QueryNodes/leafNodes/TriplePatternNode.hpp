//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
#define SPARQL_QUERY_TRIPLEPATTERNNODE_HPP

#include "ILeafNode.hpp"
#include "Dice/Sparql-Query/TriplePatternElement.hpp"

#include <vector>

class TriplePatternNode:public ILeafNode
{
public:
    TriplePatternNode(std::vector<TriplePatternElement> elements)
    {
        this->elements=elements;
    }
    SelectQueryResult execute(const SelectQueryResult &previousQueryResult) override {
        //ToDo : the actual logic of querying the triple store must be implemented here
        return SelectQueryResult();
    }
//    std::vector<char> process() override
//    {
//        for(auto element: elements)
//        {
//
//        }
//    }

private:
    std::vector<TriplePatternElement> elements;

};


#endif //SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
