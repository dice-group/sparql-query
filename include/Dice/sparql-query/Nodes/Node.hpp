//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_NODE_HPP
#define SPARQL_QUERY_NODE_HPP

#include <vector>

#include "Dice/sparql-query/TriplePatternElement.hpp"

namespace Dice::SPARQL::Nodes{

class Node {
public:

    virtual std::vector<TriplePatternElement> getBgps() = 0;

    virtual std::vector<std::vector<std::string>> generateStringOperands() = 0;


};
}

#endif //SPARQL_QUERY_NODE_HPP
