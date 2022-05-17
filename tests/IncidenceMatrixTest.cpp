#include <catch2/catch.hpp>
#include "../src/IncidenceMatrix.hpp"

using namespace sdizo;

TEST_CASE("Adding and removing edges from the incidence matrix", "[IncidenceMatrix]") {
    auto graph = IncidenceMatrix<int>();

    graph.addEdge(0, 1, 1);

    SECTION("after adding an edge, vertex and edge count should increase") {

        REQUIRE(graph.getEdgeCount() == 1);
        REQUIRE(graph.getVertexCount() == 2);
    }
    
    int** matrix = graph.getMatrix();

    SECTION("added edge should appear in the matrix") {
        REQUIRE(matrix[0][0] == 1);
        REQUIRE(matrix[1][0] == -1);
    }

    graph.removeEdge(0, 1);

    SECTION("after removing an edge, edge count should decrease") {
       
        REQUIRE(graph.getEdgeCount() == 0);
    }

    SECTION("removing an unexisting edge should throw an exception") {
        REQUIRE_THROWS_AS(graph.removeEdge(0, 1), std::bad_array_new_length);
    }

    auto copy = graph;
    SECTION("should properly copy the matrix") {
        
        for(size_t i = 0; i < copy.getVertexCount(); ++i) {
            for(size_t j = 0; j < copy.getEdgeCount(); ++j) {
                REQUIRE(copy.getMatrix()[i][j] == graph.getMatrix()[i][j]);
            }
        }
    }

}