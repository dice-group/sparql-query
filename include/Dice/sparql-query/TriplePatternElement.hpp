//
// Created by fakhr on 29.04.20.
//

#ifndef SPARQL_QUERYGRAPH_TRIPLEPATTERNELEMENT_HPP
#define SPARQL_QUERYGRAPH_TRIPLEPATTERNELEMENT_HPP

#include <variant>

#include "TripleVariable.hpp"
#include <Dice/rdf_parser/RDF/Term.hpp>
namespace SparqlQueryGraph {
    class TriplePatternElement {
    public:
        using VarOrTerm = std::variant<TripleVariable, rdf_parser::store::rdf::Term>;
        std::array<VarOrTerm, 3> triplePattern;

    public:
        explicit TriplePatternElement(VarOrTerm element1, VarOrTerm element2, VarOrTerm element3) : triplePattern{
                element1, element2, element3} {};

        VarOrTerm getFirstElement() { return triplePattern.at(0); };

        VarOrTerm getSecondElement() { return triplePattern.at(1); };

        VarOrTerm getThirdElement() { return triplePattern.at(2); };

        VarOrTerm getFirstElement() const{ return triplePattern.at(0); };

        VarOrTerm getSecondElement() const{ return triplePattern.at(1); };

        VarOrTerm getThirdElement() const{ return triplePattern.at(2); };


        friend bool operator== (const TriplePatternElement &triple1, const TriplePatternElement &triple2)
        {
            return (triple1.getFirstElement() == triple2.getFirstElement() &&
                    triple1.getSecondElement() == triple2.getSecondElement() &&
                    triple1.getThirdElement() == triple2.getThirdElement());
        }

    };
}
#endif //SPARQL_QUERYGRAPH_TRIPLEPATTERNELEMENT_HPP
