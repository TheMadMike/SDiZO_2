#include "Sort.hpp"

namespace sdizo {

void merge(int array[], size_t begin, size_t middle, size_t end);

void mergeSort(int array[], size_t begin, size_t end) {
    if((begin >= end) || (array == nullptr))
        return;

    size_t middle = (begin + end) / 2;
    mergeSort(array, begin, middle);
    mergeSort(array, middle+1, end);
    merge(array, begin, middle, end);

}

void merge(int array[], size_t begin, size_t middle, size_t end) {
    size_t bufferSize = end - begin + 1;
    int* buffer = new int[bufferSize];

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

};