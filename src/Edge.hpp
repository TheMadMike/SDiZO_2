#ifndef EDGE_HPP
#define EDGE_HPP

#include <cstddef>

namespace sdizo {

template<typename T>
struct Edge {
    size_t start = 0, end = 0;
    T weight;
};

template<typename T>
struct AdjacentEdge {
    size_t next;
    T weight;
};

template <typename T>
bool operator < (Edge<T>& lhs, Edge<T>& rhs) {
    return lhs.weight < rhs.weight;
}

template <typename T>
bool operator > (Edge<T>& lhs, Edge<T>& rhs) {
    return lhs.weight > rhs.weight;
}

};

#endif //EDGE_HPP