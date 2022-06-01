#include <catch2/catch.hpp>
#include "../src/AdjacencyList.hpp"

using namespace sdizo;

TEST_CASE("Adjacency list edge manipulation", "[AdjacencyList]") {
    auto graph = AdjacencyList<int>();

    graph.addUndirectedEdge(0, 1, 1);

    SECTION("after adding an edge to an empty list, vertex count should increase") {
        REQUIRE(graph.getVerticesNumber() == 2);
    }

    SECTION("added edge should appear in the list") {
        REQUIRE(graph.getList()[0].get(0).next == 1);
        REQUIRE(graph.getList()[0].get(0).weight == 1);
        REQUIRE(graph.getList()[1].get(0).next == 0);
        REQUIRE(graph.getList()[1].get(0).weight == 1);
    }

    graph.addEdge(0, 2, 2);
    graph.addEdge(0, 3, 3);

    SECTION("should return adjacent edges") {
        auto& list = graph.getAdjacentEdges(0);

        REQUIRE(list.get(0).next == 1);
        REQUIRE(list.get(0).weight == 1);
        REQUIRE(list.get(1).next == 2);
        REQUIRE(list.get(1).weight == 2);
        REQUIRE(list.get(2).next == 3);
        REQUIRE(list.get(2).weight == 3);

        for(size_t i = 0; i < list.getSize(); ++i) {

        }
    }

    //graph.removeEdge(0, 1);

    SECTION("after removing an edge, edge count should decrease") {
       
        //REQUIRE(graph.getEdgesNumber() == 0);
    }

    SECTION("removing an unexisting edge should throw an exception") {
        //REQUIRE_THROWS_AS(graph.removeEdge(0, 1), std::runtime_error);
    }

    //auto copy = graph; //<----
    SECTION("should properly copy the list") {
        
        //for(size_t i = 0; i < copy.getVerticesNumber(); ++i) {
        //    for(size_t j = 0; j < copy.getEdgesNumber(); ++j) {
        //        REQUIRE(copy.getMatrix()[i][j] == graph.getMatrix()[i][j]);
        //    }
        //}
    }

    //graph.addEdge(0, 1, 1);
    //graph.addEdge(1, 2, 2);
    //graph.addEdge(0, 2, 3);

    SECTION("should return proper edge array") {
        //Edge<int>* edges = graph.getAllEdges();
        //size_t size = graph.getEdgesNumber();

        //for(size_t i = 0; i < size; ++i) {
        //    REQUIRE(edges[i].weight == static_cast<int>(i+1));
        //}    
    }

    SECTION("should swap edges") {
        //graph.swapEdges(0, 1);
        //REQUIRE(graph.getEdge(0).weight == 2);
        //REQUIRE(graph.getEdge(1).weight == 1);
    }

}