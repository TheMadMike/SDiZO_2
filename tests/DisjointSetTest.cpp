#include <catch2/catch.hpp>

#include "../src/DisjointSet.hpp"

using namespace sdizo;

TEST_CASE("Unify and find", "[DisjointSet]") {
    DisjointSet set(10);

    for(size_t i = 0; i < 9; ++i) {
        set.unify(i, i+1);
    }
    SECTION("should have the same root after unifying all") {
        for(size_t i = 0; i < 9; ++i) {
            REQUIRE(set.find(i) == set.find(i + 1));
        }
    }
}