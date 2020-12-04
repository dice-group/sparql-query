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

    std::vector<std::string> generateSubscript() override {
        std::vector<std::string> subscript;
        for(TriplePatternElement& element:elements) {
            if (std::holds_alternative<TripleVariable>(element.getFirstElement()))
                subscript.push_back(std::get<TripleVariable>(element.getFirstElement()).getName());
            if(std::holds_alternative<TripleVariable>(element.getSecondElement()))
                subscript.push_back(std::get<TripleVariable>(element.getSecondElement()).getName());
            if(std::holds_alternative<TripleVariable>(element.getThirdElement()))
                subscript.push_back(std::get<TripleVariable>(element.getThirdElement()).getName());
        }

        return subscript;
    }


private:
    std::vector<TriplePatternElement> elements;

};


#endif //SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
