#include <catch2/catch.hpp>
#include "../src/IncidenceMatrix.hpp"

using namespace sdizo;

TEST_CASE("Edge manipulation", "[IncidenceMatrix]") {
    auto graph = IncidenceMatrix<int>();

    graph.addEdge(0, 1, 1);

    SECTION("after adding an edge, vertex and edge count should increase") {

        REQUIRE(graph.getEdgesNumber() == 1);
        REQUIRE(graph.getVerticesNumber() == 2);
    }
    
    int** matrix = graph.getMatrix();

    SECTION("added edge should appear in the matrix") {
        REQUIRE(matrix[0][0] == 1);
        REQUIRE(matrix[1][0] == -1);
    }

    graph.removeEdge(0, 1);

    SECTION("after removing an edge, edge count should decrease") {
       
        REQUIRE(graph.getEdgesNumber() == 0);
    }

    SECTION("removing an unexisting edge should throw an exception") {
        REQUIRE_THROWS_AS(graph.removeEdge(0, 1), std::runtime_error);
    }

    auto copy = graph;
    SECTION("should properly copy the matrix") {
        
        for(size_t i = 0; i < copy.getVerticesNumber(); ++i) {
            for(size_t j = 0; j < copy.getEdgesNumber(); ++j) {
                REQUIRE(copy.getMatrix()[i][j] == graph.getMatrix()[i][j]);
            }
        }
    }

    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(0, 2, 3);

    SECTION("should return proper edge array") {
        Edge<int>* edges = graph.getAllEdges();
        size_t size = graph.getEdgesNumber();

        for(size_t i = 0; i < size; ++i) {
            REQUIRE(edges[i].weight == static_cast<int>(i+1));
        }    
    }

    SECTION("should swap edges") {
        graph.swapEdges(0, 1);
        REQUIRE(graph.getEdge(0).weight == 2);
        REQUIRE(graph.getEdge(1).weight == 1);
    }

}