//
// Created by ADMIN on 29/03/2024.
//

#ifndef PHONEDIRECTORY_DOUBLELISTAVL_H
#define PHONEDIRECTORY_DOUBLELISTAVL_H

#include "../nodes/NodeAVL.h"

template<typename T>
class DoubleListAVL {


private:
    NodeAVL<T> *head;
    NodeAVL<T> *tail;
    NodeAVL<T> *ptr;
    int size;

public:

    DoubleListAVL() : head(nullptr), tail(nullptr), ptr(nullptr), size(0) {}

    void createFixize(int size) {
        this->size = size;

        for (int i = 0; i < size; i++) {
            add(i);
        }

    }

    void increaseSize(int newSize) {

    }

    void add(int i) {
        ptr = new NodeAVL<T>();
        ptr->setIndex(i);

        if (head == nullptr) {
            head = ptr;
        } else {
            tail->setNext(ptr);
            ptr->setPrev(tail);
        }
        tail = ptr;
        head->setPrev(tail);
    }


    NodeAVL<T> *searchIndex(int index) {

        return nullptr;
    }

//    DoubleNode<T> *searchData(int index, std::string key) {
//        if (size - index < index) {
//            ptr = tail;
//
//            while (ptr->getData()->getKey() == key) {
//                ptr = ptr->getPrev();
//            }
//
//        } else {
//            ptr = head;
//
//            while (ptr->getData()->getKey() == key) {
//                ptr = ptr->getNext();
//            }
//
//        }
//
//        return ptr;
//    }

    ~DoubleListAVL() {

    }

};

#endif //PHONEDIRECTORY_DOUBLELISTAVL_H
