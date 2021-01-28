#include <gtest/gtest.h>

#include <Dice/RDF/ParseTerm.hpp>

#include <Dice/sparql-query/version.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/RegularGroupingNode.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/SelectNodes/DefaultSelectNode.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/OptionalPatternNode.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/leafNodes/TriplePatternNode.hpp>
#include <Dice/sparql-query/Nodes/SolutionDecorator.hpp>

#include <Dice/sparql-query/Nodes/SolutionModifiers/LimitModifier.hpp>
#include <Dice/sparql-query/Nodes/SolutionModifiers/OffsetModifier.hpp>
#include <Dice/sparql-query/Nodes/SolutionModifiers/OrderByModifier.hpp>

#include <Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/MinusPatternNode.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/ServicePatternNode.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/SpecialNodes/GraphPatternNode.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/UnionGroupingNode.hpp>

#include <Dice/sparql-query/Nodes/QueryNodes/leafNodes/BindPatternNode.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/FilteringDecorator.hpp>
#include <Dice/sparql-query/Nodes/QueryNodes/leafNodes/InlinePatternNode.hpp>

using namespace Dice::sparql::Nodes::QueryNodes::SelectNodes;
using namespace Dice::sparql::Nodes::QueryNodes;
using namespace Dice::sparql;
using namespace Dice;

TEST(Print_version, run) {
    std::cout << "sparql-query version" << Dice::sparql_query::version[0] << "."
                  << Dice::sparql_query::version[1] << "."
        << Dice::sparql_query::version[2]
        << std::endl;
}

TEST(subscriptGeneratingTests, basic1) {
    //creating 2 triple patterns and adding them into a node
    std::vector<TriplePattern> elements{TriplePattern{Variable{"?book"},rdf::parse_term("<dc:title>"),Variable("?title")},
                                               TriplePattern{Variable{"?book"},rdf::parse_term("<ns:price>"),Variable("?price")}
                                               };
    std::shared_ptr<LeafNodes::TriplePatternNode> triplePatternNode=std::make_shared<LeafNodes::TriplePatternNode>(elements);
    //creating 1 optional node which has 1 triple pattern inside it
    std::vector<TriplePattern> elements2{TriplePattern{Variable{"?book"},rdf::parse_term("<dc:title>"),Variable("?title")}};
    std::shared_ptr<LeafNodes::TriplePatternNode> triplePatternNode2=std::make_shared<LeafNodes::TriplePatternNode>(elements);
    std::shared_ptr<SpecialNodes::OptionalPatternNode> optionalNode1=std::make_shared<SpecialNodes::OptionalPatternNode>(triplePatternNode2);
    //group the 2 nodes
    std::shared_ptr<GroupingNodes::RegularGroupingNode> groupNode=std::make_shared<GroupingNodes::RegularGroupingNode>();
    groupNode->addChild(triplePatternNode);
    groupNode->addChild(optionalNode1);
    //
    std::vector<Variable> selectVariables{Variable{"book"},Variable{"nameY"},Variable{"nickY"}};
    std::shared_ptr<SelectNode> selectNode=std::make_shared<DefaultSelectNode>(groupNode, selectVariables);
    auto operands=selectNode->getOperands();
    auto variables=selectNode->getSelectVariables();
    auto bgps=selectNode->getBgps();
    std::cout<<"end";
}
