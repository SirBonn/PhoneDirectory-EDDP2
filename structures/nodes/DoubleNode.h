//
// Created by ADMIN on 22/03/2024.
//

#ifndef PHONEDIRECTORY_DOUBLENODE_H
#define PHONEDIRECTORY_DOUBLENODE_H

template<typename T>
class DoubleNode {

private:
    T *data;
    int index;
    DoubleNode<T> *next;
    DoubleNode<T> *prev;
    DoubleNode<T> *ptr; //current

public:
    DoubleNode(T *_data) : data(_data), next(nullptr), prev(nullptr), ptr(nullptr) {}
    DoubleNode() : data(nullptr), next(nullptr), prev(nullptr), ptr(nullptr) {}

    //getters n setters

    int getIndex() {
        return index;
    }

    void setIndex(int _index) {
        index = _index;
    }

    T* getData() {
        return data;
    }

    void setData(T *_data) {
        data = _data;
    }

    DoubleNode<T> *getNext() {
        return next;
    }

    void setNext(DoubleNode<T> *_next) {
        next = _next;
    }

    DoubleNode<T> *getPrev() {
        return prev;
    }

    void setPrev(DoubleNode<T> *_prev) {
        prev = _prev;
    }

    DoubleNode<T> *getPtr() {
        return ptr;
    }

    void setPtr(DoubleNode<T> *_ptr) {
        ptr = _ptr;
    }

    ~DoubleNode() {
        delete data;
    }

};


#endif //PHONEDIRECTORY_DOUBLENODE_H
