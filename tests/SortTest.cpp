#include <catch2/catch.hpp>
#include "../src/Sort.hpp"
#include "../src/Edge.hpp"

using namespace sdizo;

TEST_CASE("Sorting an array", "[mergeSort]") {

    int array[3] = {3, 2, 1};

    mergeSort(array, 0, 2);

    SECTION("should sort an array of integers in an ascending order") {
        for(size_t i = 0; i < 3; ++i) {
            REQUIRE(array[i] == static_cast<int>(i + 1));
        }
    }

    SECTION("should do nothing with a nullptr") {
        REQUIRE_NOTHROW(mergeSort<int>(nullptr, 0, 1));
    }

    array[0] = 4;

    SECTION("should do nothing when begin >= end") {
        REQUIRE_NOTHROW(mergeSort(array, 1, 0));
        REQUIRE(array[0] == 4);
    }

    Edge<int> edges[] = {{0, 1, 3}, {0, 2, 2}, {0, 3, 1}};
    
    SECTION("should sort an array of edges in an ascending order") {
        REQUIRE_NOTHROW(mergeSort(edges, 0, 2));
        for(size_t i = 0; i < 3; ++i) {
            REQUIRE(edges[i].weight == static_cast<int>(i + 1));
        }
    }
}