#include "IncidenceMatrix.hpp"
#include <stdexcept>
#include <cmath>

namespace sdizo {

template<typename T>
IncidenceMatrix<T>::IncidenceMatrix() 
:matrix(nullptr) {
}

template<typename T>
IncidenceMatrix<T>::IncidenceMatrix(const IncidenceMatrix& copy) 
:matrix(nullptr), edges(copy.edges), vertices(copy.vertices) {
    matrix = new T*[vertices];
    for(size_t i = 0; i < vertices; ++i) {
        matrix[i] = new T[edges];
        for(size_t j = 0; j < edges; ++j) {
            matrix[i][j] = copy.matrix[i][j];
        }
    }

}

template<typename T>
IncidenceMatrix<T>::~IncidenceMatrix() {
    deleteMatrix();
}

template<typename T>
void IncidenceMatrix<T>::addEdge(size_t start, size_t end, T weight) {
    size_t maxVertices = std::max(vertices, std::max(start, end) + 1);
    T** copy = copyMatrix(maxVertices, edges + 1);
    
    deleteMatrix();

    matrix = copy;
    
    ++edges;

    matrix[start][edges - 1] = weight;
    matrix[end][edges - 1] = -weight;

    vertices = maxVertices;
}

template<typename T>
void IncidenceMatrix<T>::removeEdge(size_t start, size_t end) {
    if(start >= vertices || end >= vertices) {
        throw std::out_of_range("Vertices out of range!");
    }

    for(size_t i = 0; i < edges; ++i) {
        if(std::abs(matrix[start][i]) == std::abs(matrix[end][i])) {
            swapEdges(i, edges - 1);
        }
    }

    T** copy = copyMatrix(vertices, edges - 1);

    deleteMatrix();

    matrix = copy;
    --edges;
}

template<typename T>
T** IncidenceMatrix<T>::copyMatrix(size_t newVertices, size_t newEdges) {
    T** copy = new T*[newVertices];
    for(size_t i = 0; i < newVertices; ++i) {
        copy[i] = new T[newEdges];
        if(i < this->vertices) {
            for(size_t j = 0; j < this->edges; ++j) {
                copy[i][j] = matrix[i][j];
            }
        }
    }

    return copy;
}

template<typename T>
void IncidenceMatrix<T>::swapEdges(size_t a, size_t b) {
    for(size_t i = 0; i < vertices; ++i) {
        T tmp = matrix[i][a];
        matrix[i][a] = matrix[i][b];
        matrix[i][b] = tmp;
    }
}

template<typename T>
void IncidenceMatrix<T>::deleteMatrix() {
    for(size_t i = 0; i < vertices; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

template class IncidenceMatrix<int>;


};