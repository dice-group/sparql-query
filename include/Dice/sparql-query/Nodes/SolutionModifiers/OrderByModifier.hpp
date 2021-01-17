//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_ORDERBYMODIFIER_HPP
#define SPARQL_QUERY_ORDERBYMODIFIER_HPP


#include "Dice/sparql-query/Nodes/SolutionModifiers/SolutionModifier.hpp"

namespace Dice::sparql::Nodes::SolutionModifiers {
    class OrderByModifier : public SolutionModifier {
        std::vector<sparql::TriplePattern> modifyGetBgpsResult(std::vector<sparql::TriplePattern> vector) override {
            throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> modifyGenerateStringOperandsResult(std::vector<std::vector<std::string>> vector) override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::SolutionModifiers

#endif//SPARQL_QUERY_ORDERBYMODIFIER_HPP
