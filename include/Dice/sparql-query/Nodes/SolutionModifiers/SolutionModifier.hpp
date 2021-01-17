//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_SOLUTIONMODIFIER_HPP
#define SPARQL_QUERY_SOLUTIONMODIFIER_HPP


namespace Dice::sparql::Nodes::SolutionModifiers {
    class SolutionModifier {

    public:
        virtual std::vector<sparql::TriplePattern> modifyGetBgpsResult(std::vector<sparql::TriplePattern>) = 0;

        virtual std::vector<std::vector<std::string>> modifyGenerateStringOperandsResult(std::vector<std::vector<std::string>>) = 0;
    };
}// namespace Dice::sparql::Nodes::SolutionModifiers

#endif//SPARQL_QUERY_SOLUTIONMODIFIER_HPP
