//
// Created by fakhr on 12.02.20.
//

#ifndef SPARQL_QUERY_IQUERY_HPP
#define SPARQL_QUERY_IQUERY_HPP

#include <unordered_map>
#include "ITripleStore.hpp"
template <typename QueryResultType>
class IQuery
{

private:
    std::unordered_map<std::string ,std::string> prefixes;

public:
    virtual QueryResultType executeQuery(const ITripleStore& tripleStore)=0;

    void setPrefixes(std::unordered_map<std::string ,std::string> prefixes){
        this->prefixes=prefixes;
    }

    std::unordered_map<std::string ,std::string> getPrefixes(){
        return this->prefixes;
    }


};

#endif //SPARQL_QUERY_IQUERY_HPP
