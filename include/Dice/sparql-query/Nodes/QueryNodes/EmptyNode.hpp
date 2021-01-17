//
// Created by fakhr on 07.01.21.
//

#ifndef SPARQL_QUERYGRAPH_EMPTYNODE_HPP
#define SPARQL_QUERYGRAPH_EMPTYNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/QueryNode.hpp"

namespace Dice::sparql::Nodes::::QueryNodes{

    /*
     * This class represent a node with an empty behaviour
     *
     */
    class EmptyNode : public QueryNode {
    public:
         std::vector<TriplePattern> getBgps() {
             std::vector<TriplePattern> emptyBgps;
             return emptyBgps;
         }

         std::vector<std::vector<std::string>> generateStringOperands() {
             std::vector<std::vector<std::string>> emptyStringOperands;
             return emptyStringOperands;
         }


    };
}
#endif //SPARQL_QUERYGRAPH_EMPTYNODE_HPP
