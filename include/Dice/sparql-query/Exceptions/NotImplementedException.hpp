//
// Created by fakhr on 17.01.21.
//

#ifndef SPARQL_QUERY_NOTIMPLEMENTEDEXCEPTION_HPP
#define SPARQL_QUERY_NOTIMPLEMENTEDEXCEPTION_HPP

#include <exception>
namespace Dice::sparql::internal::Exceptions {
    class NotImplementedException : public std::exception {
    public:
        [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
            return "This functionality is not implemented yet";
        }
    };
}// namespace Dice::sparql::internal::Exceptions
#endif//SPARQL_QUERY_NOTIMPLEMENTEDEXCEPTION_HPP
