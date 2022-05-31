#include "DisjointSet.hpp"

namespace sdizo {

DisjointSet::DisjointSet(size_t size) 
:size(size) {
    data = new size_t[size];
    rank = new size_t[size];
    for(size_t i = 0; i < size; ++i) {
        data[i] = i;
        rank[i] = 0;
    }
}

DisjointSet::~DisjointSet() {
    delete[] data;
}

size_t DisjointSet::find(size_t p) {
    if(data[p] != p)
        data[p] = find(data[p]);

    return data[p];
}

void DisjointSet::unify(size_t a, size_t b) {
    size_t aRoot = this->find(a);
    size_t bRoot = this->find(b);
    
    if(aRoot == bRoot)
        return;
    
    if (rank[aRoot] < rank[bRoot]) {
        data[aRoot] = bRoot;
    }
    else if (rank[aRoot] > rank[bRoot]) {
        data[bRoot] = aRoot;
    }

    else {
        data[bRoot] = aRoot;
        rank[aRoot] += 1;
    }
}

};