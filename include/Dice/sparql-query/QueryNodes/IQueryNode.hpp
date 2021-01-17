//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_IQUERYNODE_HPP
#define SPARQL_QUERY_IQUERYNODE_HPP

#include "../TriplePatternElement.hpp"
#include <vector>

namespace SparqlQueryGraph::Nodes{

class IQueryNode {
public:

    virtual std::vector<TriplePatternElement> getBgps() = 0;

    virtual std::vector<std::vector<std::string>> generateStringOperands() = 0;


};
}

#endif //SPARQL_QUERY_IQUERYNODE_HPP
