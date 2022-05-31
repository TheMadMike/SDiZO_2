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

    /**
     * @brief Insert an egde to the matrix
     * 
     * @param start start vertex
     * @param end end vertex
     * @param weight edge's weight
     */
    void addEdge(size_t start, size_t end, T weight);

    /**
     * @brief Remove an edge between start and end vertices
     * 
     * @param start start vertex
     * @param end end vertex
     */
    void removeEdge(size_t start, size_t end);

    /**
     * @brief Get the number of edges 
     */
    inline size_t getEdgesNumber() { return edges; }
    
    /**
     * @brief Get the number of vertices
     */
    inline size_t getVerticesNumber() { return vertices; }

    /**
     * @brief Get the incidence matrix
     * 
     * @return T** two-dimensional array of size V x E
     */
    inline T** getMatrix() { return matrix; }

    /**
     * @brief Swap to edges
     * 
     * @param a first edge index
     * @param b second edge index
     */
    void swapEdges(size_t a, size_t b);

    /**
     * @brief Get the edge by index
     */
    Edge<T> getEdge(size_t index);

    /**
     * @brief Get all of the edges
     * 
     * @return Edge<T>* edge array of size E
     */
    Edge<T>* getAllEdges();

    /**
     * @brief Find a first edge between start and end vertices
     */
    size_t findEdgeIndex(size_t start, size_t end);

    /**
     * @brief Print the incidence matrix (e.g. for debugging) 
     */
    void printMatrix();

    void operator = (const IncidenceMatrix<T>& rhs);

private:
    T** copyMatrix(size_t vertices, size_t edges);
    void deleteMatrix();

    T** matrix;

    size_t edges = 0, vertices = 0;
};

};


#endif //INCIDENCE_MATRIX_HPP