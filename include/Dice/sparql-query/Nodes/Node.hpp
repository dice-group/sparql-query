#ifndef SPARQL_QUERY_NODE_HPP
#define SPARQL_QUERY_NODE_HPP

#include <vector>

#include <Dice/SPARQL/TriplePattern.hpp>

namespace Dice::sparql::Nodes {

    class Node {
    public:
        virtual std::vector<sparql::TriplePattern> getBgps() = 0;

        virtual std::vector<std::vector<std::string>> generateStringOperands() = 0;
    };
}// namespace Dice::sparql::Nodes

#endif//SPARQL_QUERY_NODE_HPP
