//
// Created by ADMIN on 29/03/2024.
//

#ifndef PHONEDIRECTORY_TREEINTEGER_H
#define PHONEDIRECTORY_TREEINTEGER_H

#include <string>
#include "TreeAVL.h"

class TreeInteger : public TreeAVL {
private:
    NodeAVL<int> *root;
    NodeAVL<int> *newNode;
    NodeAVL<int> *scanner;
    NodeAVL<int> *parentAB;
    NodeAVL<int> *grandParentAB;
    NodeAVL<int> *childAB;
    NodeAVL<int> *grandChildAB;
    NodeAVL<int> *predecessor;
    std::string keySearcher;
    int size;

public:

    TreeInteger(std::string key) : TreeAVL(key) {
        root = nullptr;
        size = 0;
    }

    void updateFactors(NodeAVL<int> *node) {
        while (node != nullptr) {
//            node->updateHeight();
//            node->updateFactorEq();
            node = node->getParent();
        }
    }

    void balance(NodeAVL<int> *node) {
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

    void insert(int *data) {
        newNode = new NodeAVL<int>(std::move(data));
        newNode->setData(std::move(data));

        if (root == nullptr) {
            root = newNode;
            root->setParent(nullptr);
            size++;
        } else {
            scanner = root;
            while (true) {
                if (data[0] < scanner->getData()[0]) {
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

    void rotateLeft(NodeAVL<int> *node) {

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
        childAB->setParent(parentAB);
        childAB->setLeft(node);
        node->setParent(childAB);
        node->setRight(grandChildAB);
        if (grandChildAB != nullptr) {
            grandChildAB->setParent(node);
        }
//        node->updateHeight();
//        node->updateFactorEq();
//        childAB->updateHeight();
//        childAB->updateFactorEq();

    }

    void rotateRight(NodeAVL<int> *node) {

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
        childAB->setParent(parentAB);
        childAB->setRight(node);
        node->setParent(childAB);
        node->setLeft(grandChildAB);
        if (grandChildAB != nullptr) {
            grandChildAB->setParent(node);
        }
//        node->updateHeight();
//        node->updateFactorEq();
//        childAB->updateHeight();
//        childAB->updateFactorEq();

    }

    std::string* searchValueKey(int *value) {
        scanner = root;
        while (scanner != nullptr) {
            if (value == scanner->getData()) {
                return scanner->getKey();
            } else if (value < scanner->getData()) {
                scanner = scanner->getLeft();
            } else {
                scanner = scanner->getRight();
            }
        }
        return NULL;
    }


    NodeAVL<int> *searchkey(std::string *key) {
        scanner = root;
        while (scanner != nullptr) {
            if (key == scanner->getKey()) {
                return scanner;
            } else if (key < scanner->getKey()) {
                scanner = scanner->getLeft();
            } else {
                scanner = scanner->getRight();
            }
        }
        return nullptr;
    }

    void graphAVL(GraphvizManager *graphvizManager, std::string parentID) {
        graphInOrderHelper(root, graphvizManager);

        graphvizManager->addUnionNode(parentID, std::to_string(reinterpret_cast<uintptr_t>(root->getData())));

    }

    void graphInOrderHelper(NodeAVL<int>* node, GraphvizManager *graph) {
        if (node != nullptr) {

            graphInOrderHelper(node->getLeft(), graph);

            std::string nodeID = std::to_string(reinterpret_cast<uintptr_t>(node->getData()));
            //graph->addNode(nodeID, std::to_string(reinterpret_cast<uintptr_t>(node->getData())), "black", "circle");

            if (node->getRight() != nullptr) {
                std::string rightID =std::to_string(reinterpret_cast<uintptr_t>(node->getRight()->getData()));
                graph->addUnionNode(nodeID, rightID);
            }

            if (node->getLeft() != nullptr) {
                std::string leftID =std::to_string(reinterpret_cast<uintptr_t>(node->getLeft()->getData()));
                graph->addUnionNode(nodeID, leftID);
            }

            graphInOrderHelper(node->getRight(), graph);
        }
    }

};

#endif //PHONEDIRECTORY_TREEINTEGER_H
