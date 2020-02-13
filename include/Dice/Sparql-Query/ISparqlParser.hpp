//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_ISPARQLPARSER_HPP
#define SPARQL_QUERY_ISPARQLPARSER_HPP

#include "IQuery.hpp"
#include <string>

class ISparqlParser
{

    template <typename QueryType>
    IQuery<QueryType> parseQuery(std::string);
};


#endif //SPARQL_QUERY_ISPARQLPARSER_HPP

