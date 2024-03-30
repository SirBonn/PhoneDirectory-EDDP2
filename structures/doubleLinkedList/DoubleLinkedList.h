//
// Created by ADMIN on 26/03/2024.
//

#ifndef PHONEDIRECTORY_DOUBLELINKEDLIST_H
#define PHONEDIRECTORY_DOUBLELINKEDLIST_H

#include "../nodes/DoubleNode.h"

template<typename T>
class DoubleLinkedList {

private:
    DoubleNode<T> *head;
    DoubleNode<T> *tail;
    DoubleNode<T> *ptr;
    int size;

public:

    DoubleLinkedList() : head(nullptr), tail(nullptr), ptr(nullptr), size(0) {}

    void createFixize(int size) {
        this->size = size;

        for (int i = 0; i < size; i++) {
            add(i);
        }

    }

    void increaseSize(int newSize) {

        for (int i = size; i < newSize; i++) {
            add(i);
            size++;
        }

    }

    void add(int i) {
        ptr = new DoubleNode<T>();
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


    DoubleNode<T> *searchIndex(int index) {

        if (size - index < index) {
            ptr = tail;

            while (ptr->getIndex() != index) {
                ptr = ptr->getPrev();
            }

        } else {
            ptr = head;

            while (ptr->getIndex() != index) {
                ptr = ptr->getNext();
            }

        }

        return ptr;
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

    ~DoubleLinkedList() {
        ptr = head;
        while (ptr != nullptr) {
            head = ptr;
            ptr = ptr->getNext();
            delete head;
        }
    }

};


#endif //PHONEDIRECTORY_DOUBLELINKEDLIST_H
