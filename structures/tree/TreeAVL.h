//
// Created by ADMIN on 28/03/2024.
//

#ifndef PHONEDIRECTORY_TREEAVL_H
#define PHONEDIRECTORY_TREEAVL_H

#include "string"
#include "../nodes/NodeAVL.h"

template<typename T>
class TreeAVL {

private:
    std::string key;

    NodeAVL<T> *root;
    NodeAVL<T> *newNode;
    NodeAVL<T> *scanner;
    NodeAVL<T> *parentAB;
    NodeAVL<T> *grandParentAB;
    NodeAVL<T> *childAB;
    NodeAVL<T> *grandChildAB;
    NodeAVL<T> *predecessor;
    std::string keySearcher;
    int size;
public:

    TreeAVL(std::string key) : root(nullptr), newNode(nullptr), scanner(nullptr), parentAB(nullptr), grandParentAB(nullptr),
                childAB(nullptr), grandChildAB(nullptr), predecessor(nullptr), size(0), key(key) {};

    void insert( T *data) {
        newNode = new NodeAVL<T>(data);
        newNode->setData(data);

        if (root == nullptr) {
            root = newNode;
            root->setParent(nullptr);
            size++;
        } else {
            scanner = root;
            while (true) {
                if (data < scanner->getData()) {
                    if (scanner->getLeft() == nullptr) {
                        scanner->setLeft(newNode);
                        newNode->setParent(scanner);
                        size++;
                        break;
                    } else {
                        scanner = scanner->getLeft();
                    }
                } else {
                    if (scanner->getRight() == nullptr) {
                        scanner->setRight(newNode);
                        newNode->setParent(scanner);
                        size++;
                        break;
                    } else {
                        scanner = scanner->getRight();
                    }
                }
            }
            updateFactors(scanner);
            balance(scanner);
        }
    }

    void updateFactors(NodeAVL<T> *node) {
        while (node != nullptr) {
            node->updateHeight();
            node->updateFactorEq();
            node = node->getParent();
        }
    }

    void balance(NodeAVL<T> *node) {
        while (node != nullptr) {
            if (node->getFactorEq() == 2 || node->getFactorEq() == -2) {
                if (node->getFactorEq() == 2) {
                    if (node->getRight()->getFactorEq() == 1) {
                        rotateLeft(node);
                    } else {
                        rotateRight(node->getRight());
                        rotateLeft(node);
                    }
                } else {
                    if (node->getLeft()->getFactorEq() == -1) {
                        rotateRight(node);
                    } else {
                        rotateLeft(node->getLeft());
                        rotateRight(node);
                    }
                }
            }
            node = node->getParent();
        }
    }

    void rotateLeft(NodeAVL<T> *node) {
        parentAB = node->getParent();
        childAB = node->getRight();
        grandChildAB = childAB->getLeft();
        if (parentAB != nullptr) {
            if (parentAB->getLeft() == node) {
                parentAB->setLeft(childAB);
            } else {
                parentAB->setRight(childAB);

            }
        } else {
            root = childAB;
        }
    }

    void rotateRight(NodeAVL<T> *node) {
        parentAB = node->getParent();
        childAB = node->getLeft();
        grandChildAB = childAB->getRight();
        if (parentAB != nullptr) {
            if (parentAB->getLeft() == node) {
                parentAB->setLeft(childAB);
            } else {
                parentAB->setRight(childAB);

            }
        } else {
            root = childAB;
        }
    }

    std::string getKey() const {
        return key;
    }
};

#endif //PHONEDIRECTORY_TREEAVL_H
