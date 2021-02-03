#ifndef SPARQL_QUERY_FILTERINGDECORATOR_HPP
#define SPARQL_QUERY_FILTERINGDECORATOR_HPP


#include <utility>

#include "Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/GroupingDecorator.hpp"
#include "Dice/sparql-query/Exceptions/NotImplementedException.hpp"

namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes {

    /*
     * This class should implement the logic of filtering
     */
    class FilteringDecorator : public GroupingDecorator {

    private:
        //ToDo maybe we need to create a special class instead of a string
        std::string constraint;

    public:
        FilteringDecorator(std::shared_ptr<GroupingNode> wrappee, std::string constraint) : GroupingDecorator(std::move(wrappee)) {
            this->constraint = std::move(constraint);
        }

        std::vector<std::vector<std::string>> generateStringOperands() override {
            throw Dice::sparql::internal::Exceptions::NotImplementedException();
        }

        std::vector<TriplePattern> getBgps() override {
            throw Dice::sparql::internal::Exceptions::NotImplementedException();
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes

#endif//SPARQL_QUERY_FILTERINGDECORATOR_HPP
