#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <cstddef>

namespace sdizo {

class DisjointSet {
public:
    DisjointSet(size_t size);
    virtual ~DisjointSet();

    size_t find(size_t p);

    void unify(size_t a, size_t b);

private:
    size_t* data, *rank;
    size_t size;
};

};

#endif //DISJOINT_SET_HPP