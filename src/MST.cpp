#include "MST.hpp"
#include "DisjointSet.hpp"
#include "Sort.hpp"

namespace sdizo {

IncidenceMatrix<int> MST::kruskal(IncidenceMatrix<int> graph) {
    size_t vertexCount = graph.getVerticesNumber();
    size_t edgeCount = graph.getEdgesNumber();

    auto edges = graph.getAllEdges();
    // sort all of the vertices in an ascending order
    mergeSort<Edge<int>>(edges, 0, edgeCount - 1);

    IncidenceMatrix<int> mst = IncidenceMatrix<int>();
    DisjointSet ds(vertexCount);

    for(size_t i = 0; i < edgeCount; ++i) {
        size_t a = ds.find(edges[i].start);
        size_t b = ds.find(edges[i].end);
        if(a != b) {
            mst.addEdge(edges[i].start, edges[i].end, edges[i].weight);
            ds.unify(edges[i].start, edges[i].end);
        }
    }

    return mst;
}

IncidenceMatrix<int> MST::prim(IncidenceMatrix<int> graph) {

}

};