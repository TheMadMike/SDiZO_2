#include <catch2/catch.hpp>
#include "../src/MST.hpp"

using namespace sdizo;

TEST_CASE("MST: Kruskal's algorithm", "[IncidenceMatrix]") {
    IncidenceMatrix<int> graph = IncidenceMatrix<int>();
    graph.addEdge(0, 2, 5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(1, 2, 1);

    auto mst = MST::kruskal(graph);

    REQUIRE(mst.getEdge(0).weight == 1);
    REQUIRE(mst.getEdge(1).weight == 2);
    REQUIRE(mst.getEdgesNumber() == 2);
}

TEST_CASE("MST: Prim's algorithm", "[IncidenceMatrix] ") {

}