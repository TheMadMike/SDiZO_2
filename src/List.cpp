#include "List.hpp"
#include "Edge.hpp"

namespace sdizo {

template<typename T>
List<T>::List() {
    head = nullptr;
    last = nullptr;
    size = 0UL;
}

template<typename T>
List<T>::List(const List<T>& copy) 
:List(){
    size = copy.size;

    Element* copyIterator = copy.head;
    Element* iterator = head;
    while(copyIterator->next != nullptr) {
        iterator->next = new Element;
        iterator->next->value = copyIterator->value;

        iterator->next->previous = iterator;
        copyIterator = copyIterator->next;
        iterator = iterator->next;
    }

    last = iterator;

}

template<typename T>
List<T>::~List() {
    while(head != nullptr) {
        Element* ptr = head;
        head = head->next;
        delete ptr;
    }
}

template<typename T>
void List<T>::pushFront(T value) {
    if(head == nullptr) {
        head = new Element;
        head->value = value;
        last = head;
        size += 1;
        return;
    }

    Element* element = new Element;
    element->value = value;
    element->next = head;
    element->previous = nullptr;
    head->previous = element;
    head = element;

    size += 1;
}

template<typename T>
void List<T>::pushBack(T value) {
    if(head == nullptr) {
        head = new Element;
        head->value = value;
        last = head;
        size += 1;
        return;
    }

    Element* element = new Element;
    element->value = value;
    element->next = nullptr;
    element->previous = last;
    last->next = element;
    element->previous = last;
    last = element;

    size += 1;
}

template<typename T>
void List<T>::set(size_t index, T value) {
    if(index >= size) {
        return;
    }

    if(head == nullptr) {
        head = new Element;
        head->value = value;
        head->previous = nullptr;
        head->next = nullptr;
        last = head;
        size += 1;
        return;
    }
    
    Element* iterator = head;
    for(size_t i = 0; i < index; ++i) {
        iterator = iterator->next;
    }

    if(iterator != nullptr) {
        Element* previous = iterator->previous;
        Element* element = new Element;
        element->value = value;
        
        if(previous != nullptr) {
            previous->next = element;
        }

        element->previous = previous;
        element->next = iterator;
        iterator->previous = element;

        ++size;
    }
}

template<typename T>
T& List<T>::get(size_t index) {
    Element* iterator = head;
    for(size_t i = 0; i < index; ++i) {
        iterator = iterator->next;
    }

    return iterator->value;
}

template<typename T>
T List<T>::popBack() {
    Element* element = last;
    if(element == nullptr) {
        return T();
    }

    if(element == head) {
        head = nullptr;
        last = nullptr;
    }

    else if(element->previous == head) {
        last = head;
    }

    last = element->previous;
    if(last != nullptr) {
        last->next = nullptr;
    }

    T value = element->value;

    --size;
    delete element;

    return value;
}

template<typename T>
T List<T>::popFront() {
    if(head == nullptr) {
        return T();
    }

    Element* element = head;
    head = element->next;
    if(head != nullptr) {
        head->previous = nullptr;
    } else {
        last = nullptr;
    }

    T value = element->value;

    --size;
    delete element;

    return value;
}

template<typename T>
void List<T>::operator = (const List<T>& copy) {
    if(copy.head == nullptr) {
        size = 0UL;
        return;
    }

    size = copy.size;

    Element* copyIterator = copy.head;
    head = new Element;
    head->value = copyIterator->value;
    Element* iterator = head;
    while(copyIterator->next != nullptr) {
        copyIterator = copyIterator->next;
        iterator->next = new Element;
        iterator->next->value = copyIterator->value;

        iterator->next->previous = iterator;
        iterator = iterator->next;
    }

    last = iterator;
}

template class List<AdjacentEdge<int>>;

};