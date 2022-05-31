#include "IncidenceMatrix.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <iomanip>

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
size_t IncidenceMatrix<T>::findEdgeIndex(size_t start, size_t end) {
    for(size_t i = 0; i < edges; ++i) {
        if(matrix[start][i] == -matrix[end][i]) {
            return i;
        }
    }

    throw std::runtime_error("Edge not found");
}

template<typename T>
void IncidenceMatrix<T>::removeEdge(size_t start, size_t end) {
    if(start >= vertices || end >= vertices) {
        throw std::out_of_range("Vertices out of range!");
    }

    size_t index = findEdgeIndex(start, end);
    swapEdges(index, edges - 1);

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
        //fill with zeros
        for(size_t j = 0; j < newEdges; ++j) {
            copy[i][j] = 0;
        }
    
        if(i < this->vertices) {
            for(size_t j = 0; j < this->edges; ++j) {
                copy[i][j] = matrix[i][j];
            }
        }
    }

    return copy;
}

template<typename T>
Edge<T> IncidenceMatrix<T>::getEdge(size_t index) {
    Edge<T> edge = {};
    size_t vertex = 0;
    
    while(vertex < vertices) {
        if(matrix[vertex][index] > 0) {
            edge.start = vertex;
            edge.weight = matrix[vertex][index];
        }

        if(matrix[vertex][index] < 0) {
            edge.end = vertex;
        }

        ++vertex;
    }

    return edge;
}

template<typename T>
Edge<T>* IncidenceMatrix<T>::getAllEdges() {
    Edge<T>* allEdges = new Edge<T>[edges];

    for(size_t i = 0; i < edges; ++i) {
        allEdges[i] = getEdge(i);
    }

    return allEdges;
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

template<typename T>
void IncidenceMatrix<T>::printMatrix() {
    
    std::cout << std::right << "V\\E:" << std::setw(3);  

    for(size_t i = 0; i < edges; ++i) {
        std::cout << std::right << i << std::setw(6);    
    }

    std::cout << '\n';

    for(size_t i = 0; i < vertices; ++i) {
        std::cout << std::right << i << std::setw(6);
        for(size_t j = 0; j < edges; ++j) {
            std::cout << std::right << matrix[i][j] << std::setw(6);
        }
        std::cout << '\n';
    }

}

template<typename T>
void IncidenceMatrix<T>::operator = (const IncidenceMatrix<T>& rhs) {
    if(matrix != nullptr)
        deleteMatrix();

    this->edges = rhs.edges;
    this->vertices = rhs.vertices;
    
    matrix = new T*[vertices];
    
    for(size_t i = 0; i < vertices; ++i) {
        matrix[i] = new T[edges];
        for(size_t j = 0; j < edges; ++j) {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

template class IncidenceMatrix<int>;


};