#ifndef INCIDENCE_MATRIX_HPP
#define INCIDENCE_MATRIX_HPP

#include "Edge.hpp"

namespace sdizo {

template<typename T>
class IncidenceMatrix {

public:
    IncidenceMatrix();
    IncidenceMatrix(const IncidenceMatrix& copy);
    virtual ~IncidenceMatrix();

    void addEdge(size_t start, size_t end, T weight);
    void removeEdge(size_t start, size_t end);

    inline size_t getEdgesNumber() { return edges; }
    inline size_t getVerticesNumber() { return vertices; }

    inline T** getMatrix() { return matrix; }

    void swapEdges(size_t a, size_t b);

    Edge<T> getEdge(size_t index);
    Edge<T>* getAllEdges();

    size_t findEdgeIndex(size_t start, size_t end);

    void printMatrix();

private:
    T** copyMatrix(size_t vertices, size_t edges);
    void deleteMatrix();

    T** matrix;

    size_t edges = 0, vertices = 0;
};

};


#endif //INCIDENCE_MATRIX_HPP