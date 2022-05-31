#include "Sort.hpp"
#include "Edge.hpp"

namespace sdizo {

template<typename T>
void merge(T array[], size_t begin, size_t middle, size_t end);

template<typename T>
void mergeSort(T array[], size_t begin, size_t end) {
    if((begin >= end) || (array == nullptr))
        return;

    size_t middle = (begin + end) / 2;
    mergeSort<T>(array, begin, middle);
    mergeSort<T>(array, middle+1, end);
    merge<T>(array, begin, middle, end);

}

template<typename T>
void merge(T array[], size_t begin, size_t middle, size_t end) {
    size_t bufferSize = end - begin + 1;
    T* buffer = new T[bufferSize];

    /*  indexes for iterating over 
     *  the left and right halves of the array
     */
    size_t left = begin, right = middle+1;

    size_t bufferIndex = 0;

    while( (left <= middle) && (right <= end) ) {

        if(array[left] < array[right]) {
            buffer[bufferIndex] = array[left];
            ++left;
        } else {
            buffer[bufferIndex] = array[right];
            ++right;
        }

        ++bufferIndex;
    }

    while(left <= middle) {
        buffer[bufferIndex] = array[left];
        ++left;
        ++bufferIndex;
    }

    while(right <= end) {
        buffer[bufferIndex] = array[right];
        ++right;
        ++bufferIndex;
    }

    for(size_t i = 0; i < bufferSize; ++i) {
        array[begin + i] = buffer[i];
    }

    delete[] buffer;
}

template void merge<Edge<int>>(Edge<int>[], size_t, size_t, size_t);
template void mergeSort<Edge<int>>(Edge<int>[], size_t, size_t);

template void merge<int>(int[], size_t, size_t, size_t);
template void mergeSort<int>(int[], size_t, size_t);

};