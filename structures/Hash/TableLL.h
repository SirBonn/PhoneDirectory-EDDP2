//
// Created by ADMIN on 24/03/2024.
//

#ifndef PHONEDIRECTORY_TABLELL_H
#define PHONEDIRECTORY_TABLELL_H


#include "Function.h"
#include "../../directory/Group.h"
#include "../doubleLinkedList/DoubleLinkedList.h"
#include "../../utils/Graphs/GraphvizManager.h"

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

    T *searchKey(std::string key) {
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

    void printHashtable(TableLL<T> *hashtable) {
        GraphvizManager graph("HashTableGraph");


        for (int i = 0; i < hashtable->getsize(); i++) {
            DoubleNode<T> *currentNode = hashtable->buckets->searchIndex(i);

            while (currentNode != nullptr) {
                T *element = currentNode->getData();
                std::string key = "";

                if (element != NULL) {
                    key = element->getKey();
                    std::string nodeLabel =  key;
                    graph.addNode(nodeLabel, key, "lightblue", "box");

                    element->printGroup(&graph);
                    currentNode = currentNode->getNext();
                    break;
                } else {
                    std::string nodeLabel = "Node_" + i;
                    graph.addNode(nodeLabel, "empty", "red", "box");
                    currentNode = currentNode->getNext();
                    break;
                }

            }
        }

        graph.generateGraph();
    }

    int getCuantity() {
        return cuantity;
    }

    void getReportsGrop() {
        for (int i = 0; i < size; i++) {
            DoubleNode<T> *currentNode = buckets->searchIndex(i);
            if(currentNode->getData() != NULL) {
                std::cout<< "Nombre del grupo: " <<currentNode->getData()->getKey()<<std::endl;
                std::cout<< "Cantidad de campos en el grupo: "<<currentNode->getData()->getCuantityFields()<<std::endl;
                std::cout<<"--------------------------------------------"<<std::endl;
            }
        }
    }

    DoubleLinkedList<T> *getBuckets() {
        return buckets;
    }

    ~TableLL() {
        buckets->~DoubleLinkedList();
    }

};


#endif //PHONEDIRECTORY_TABLELL_H
