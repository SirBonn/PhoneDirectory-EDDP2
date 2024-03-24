//
// Created by ADMIN on 22/03/2024.
//

#ifndef PHONEDIRECTORY_LINKEDLIST_H
#define PHONEDIRECTORY_LINKEDLIST_H

#include "../nodes/SimpleNode.h"

template<typename T>
class LinkedList {

private:
    SimpleNode<T> *head;
    SimpleNode<T> *ptr;
    int size;

public:
    LinkedList() : head(nullptr), ptr(nullptr), size(0) {}

    ~LinkedList() {
        while (head != nullptr) {
            SimpleNode<T> *temp = head;
            head = head->getPtr();
            delete temp;
        }
    }

    void add(T *field) {
        SimpleNode<T> *newNode = new SimpleNode<T>(field);

        if (head == nullptr) {
            head = newNode;
        } else {
            ptr = head;
            while (ptr->getPtr() != nullptr) {
                ptr = ptr->getPtr();
            }
            ptr->setPtr(newNode);
        }
        size++;
    }

    T *getFirst() {
        if (head == nullptr) {
            return nullptr;
        }
        T *field = head->getData();
        SimpleNode<T> *temp = head;
        head = head->getPtr();
        delete temp;
        size--;
        return field;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }


};


#endif //PHONEDIRECTORY_LINKEDLIST_H
