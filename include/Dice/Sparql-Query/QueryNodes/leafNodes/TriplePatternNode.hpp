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

    std::vector<std::vector<std::string>> generateSubscript() override {
        std::vector<std::vector<std::string>> subscript;
        for(TriplePatternElement& element:elements) {
            std::vector<std::string> operands;
            if (std::holds_alternative<TripleVariable>(element.getFirstElement()))
                operands.push_back(std::get<TripleVariable>(element.getFirstElement()).getName());
            if(std::holds_alternative<TripleVariable>(element.getSecondElement()))
                operands.push_back(std::get<TripleVariable>(element.getSecondElement()).getName());
            if(std::holds_alternative<TripleVariable>(element.getThirdElement()))
                operands.push_back(std::get<TripleVariable>(element.getThirdElement()).getName());
            subscript.push_back(operands);
        }

        return subscript;
    }


private:
    std::vector<TriplePatternElement> elements;

};


#endif //SPARQL_QUERY_TRIPLEPATTERNNODE_HPP
