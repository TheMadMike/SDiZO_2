#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include "List.hpp"
#include "Edge.hpp"

namespace sdizo {

template<typename T>
class AdjacencyList {

public:

    AdjacencyList();
    virtual ~AdjacencyList();

    void addEdge(size_t start, size_t end, T weight);
    void addUndirectedEdge(size_t a, size_t b, T weight);
    //void removeEdge(size_t start, size_t end);
    List<AdjacentEdge<T>>& getAdjacentEdges(size_t vertex);

    inline List<AdjacentEdge<T>>* getList() { return list; }

    
    /**
     * @brief Get the number of vertices
     */
    inline size_t getVerticesNumber() { return vertices; }


private:
    size_t vertices = 0;
    List<AdjacentEdge<T>>* list;
};

};


#endif //ADJACENCY_LIST_HPP