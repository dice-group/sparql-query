//
// Created by fakhr on 13.02.20.
//

#ifndef SPARQL_QUERY_LIMITMODIFIER_HPP
#define SPARQL_QUERY_LIMITMODIFIER_HPP

#include "Dice/sparql-query/Nodes/SolutionModifiers/SolutionModifier.hpp"
#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"

namespace Dice::sparql::Nodes::SolutionModifiers {
    class LimitModifier : public SolutionModifier {
    public:
        std::vector<sparql::TriplePattern> modifyGetBgpsResult(std::vector<sparql::TriplePattern> vector) override {
                throw internal::Exceptions::NotImplementedException();
        }
        std::vector<std::vector<std::string>> modifyGenerateStringOperandsResult(std::vector<std::vector<std::string>> vector) override {
            throw internal::Exceptions::NotImplementedException();
        }
    };
}

#endif//SPARQL_QUERY_LIMITMODIFIER_HPP
