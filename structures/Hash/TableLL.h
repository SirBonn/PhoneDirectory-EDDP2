//
// Created by ADMIN on 24/03/2024.
//

#ifndef PHONEDIRECTORY_TABLELL_H
#define PHONEDIRECTORY_TABLELL_H


#include "Function.h"
#include "../../directory/Group.h"
#include "../doubleLinkedList/DoubleLinkedList.h"

template<typename T>
class TableLL {

private:
    int size;
    int cuantity;
    DoubleLinkedList<T> *buckets;

public:

//constructors
    TableLL(int size) : size(size), cuantity(0) {

        buckets = new DoubleLinkedList<T>();
        //buckets = new T[size];
        buckets->createFixize(size);
    };

    void insert(T *element) {

        int index = Function<T>::getIndex(element->getKey(), size);
        DoubleNode<T> *temp = buckets->searchIndex(index);

        while (temp->getData() != NULL) {
            std::cout << "Element already exists" << std::endl;
            index = Function<T>::reIndexing(index, size);
            temp = buckets->searchIndex(index);
        }

        std::cout << "Index: " << index << std::endl;\
        temp->setData(element);
        std::cout << "Element inserted succesfuly" << std::endl;
        cuantity++;
        analizeHash();
    }

    void analizeHash() {
        if (cuantity >= (size * 0.6)) {
            std::cout << "Rehashing..." << std::endl;
            size = size * 2;
            this->buckets->increaseSize(size);
        }
    }

    T* searchKey(std::string key) {
        int index = Function<T>::getIndex(key, size);
        DoubleNode<T> *temp = buckets->searchIndex(index);

        while (temp->getData() != NULL) {

            if (temp->getData()->getKey() == key) {

                std::cout << "Element found" << std::endl;
                return temp->getData();
            }
            index = Function<T>::reIndexing(index, size);
            temp = buckets->searchIndex(index);
        }
        std::cout << "Element not found" << std::endl;
        return NULL;
    }

    int getsize() {
        return size;
    }


    ~TableLL() {
        for (int i = 0; i < size; i++) {
            if (buckets[i] != nullptr) {
                delete buckets[i];
            }
        }
    }

};


#endif //PHONEDIRECTORY_TABLELL_H
