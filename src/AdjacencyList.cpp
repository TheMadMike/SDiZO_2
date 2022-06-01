#include "AdjacencyList.hpp"
#include <cmath>

namespace sdizo {

template <typename T>
AdjacencyList<T>::AdjacencyList()
:list(nullptr) {

}

template <typename T>
AdjacencyList<T>::~AdjacencyList() {
    delete[] list;
}

template <typename T>
void AdjacencyList<T>::addEdge(size_t start, size_t end, T weight) {
    size_t maxVertices = std::max(std::max(start, end) + 1, vertices);
    
    if(maxVertices > vertices) {
        auto buffer = new List<AdjacentEdge<T>>[maxVertices];
        for(size_t i = 0; i < vertices; ++i) {
            buffer[i] = list[i];
        }
        delete[] list;
        list = buffer;
    }

    list[start].pushBack({end, weight});

    vertices = maxVertices;
}

template <typename T>
void AdjacencyList<T>::addUndirectedEdge(size_t a, size_t b, T weight) {
    addEdge(a, b, weight);
    addEdge(b, a, weight);
}

template <typename T>
List<AdjacentEdge<T>>& AdjacencyList<T>::getAdjacentEdges(size_t vertex) {
    return list[vertex];
}

template class AdjacencyList<int>;

};