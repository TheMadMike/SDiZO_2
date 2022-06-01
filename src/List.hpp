#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>

namespace sdizo {

template<typename T>
class List {

public:
    List();
    List(const List<T>& copy);
    ~List();

    struct Element {
        T value;
        Element* previous = nullptr;
        Element* next = nullptr;
    };

    void pushFront(T value);
    void pushBack(T value);
    T popFront();
    T popBack();

    T& get(size_t index);
    void set(size_t index, T value);

    inline size_t getSize() { return size; }

    inline Element* getHead() { return head; }

    void operator = (const List<T>& copy);

private:
    Element* head, *last;
    size_t size;
};

};

#endif //LIST_HPP