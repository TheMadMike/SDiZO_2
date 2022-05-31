#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "IncidenceMatrix.hpp"

namespace sdizo {

class MST {

public:
    /**
     * @brief compute minimmum spanning tree with Kruskal's algorithm
     * 
     * @param graph 
     * @return IncidenceMatrix<int> output MST
     */
    static IncidenceMatrix<int> kruskal(IncidenceMatrix<int> graph);

    /**
     * @brief compute minnimum spanning tree with Prim's algorithm
     * 
     * @param graph input graph
     * @return IncidenceMatrix<int> output MST 
     */
    static IncidenceMatrix<int> prim(IncidenceMatrix<int> graph);
};

};

#endif //KRUSKAL_HPP