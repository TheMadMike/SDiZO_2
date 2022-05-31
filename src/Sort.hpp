#ifndef SORT_HPP
#define SORT_HPP

#include <cstddef>

namespace sdizo {


/**
 * @brief Sorts an array in an ascending order
 * 
 * @param array a pointer to the array being sorted
 * @param begin the first index of the array
 * @param end the last index of the array
 */
template<typename T>
void mergeSort(T array[], size_t begin, size_t end);

};

#endif //SORT_HPP