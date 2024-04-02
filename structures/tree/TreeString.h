//
// Created by ADMIN on 31/03/2024.
//

#ifndef PHONEDIRECTORY_TREESTRING_H
#define PHONEDIRECTORY_TREESTRING_H

#include "../nodes/NodeAVL.h"
#include "TreeAVL.h"

class TreeString : public TreeAVL {
private:
    NodeAVL<std::string> *root;
    NodeAVL<std::string> *newNode;
    NodeAVL<std::string> *scanner;
    NodeAVL<std::string> *parentAB;
    NodeAVL<std::string> *grandParentAB;
    NodeAVL<std::string> *childAB;
    NodeAVL<std::string> *grandChildAB;
    NodeAVL<std::string> *predecessor;
    std::string keySearcher;
    int size;

public:


    TreeString(std::string key) : TreeAVL(key) {
        root = nullptr;
        size = 0;
    }

    void updateFactors(NodeAVL<std::string> *node) {
        while (node != nullptr) {
//            node->updateHeight();
//            node->updateFactorEq();
            node = node->getParent();
        }
    }

    void balance(NodeAVL<std::string> *node) {
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

    void insert(std::string *data) {
        newNode = new NodeAVL<std::string>(std::move(data));
        newNode->setData(std::move(data));

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

    void rotateLeft(NodeAVL<std::string> *node) {

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

    void rotateRight(NodeAVL<std::string> *node) {

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

    //search value in tree
    std::string* searchValueKey(std::string *value) {
        scanner = root;
        while (scanner != nullptr) {
            if (value == scanner->getData()) {
                return static_cast<std::string*>(scanner->getKey());
            } else if (value < scanner->getData()) {
                scanner = scanner->getLeft();
            } else {
                scanner = scanner->getRight();
            }
        }
        return NULL;
    }


    NodeAVL<std::string> *searchkey(std::string *key) {
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

    void graphInOrderHelper(NodeAVL<std::string>* node, GraphvizManager *graph) {
        if (node != nullptr) {

            graphInOrderHelper(node->getLeft(), graph);

            std::string nodeID =std::to_string(reinterpret_cast<uintptr_t>(node->getData()));
            //graph->addNode(nodeID, std::to_string(reinterpret_cast<uintptr_t>(node->getData())), "black", "circle");

            if (node->getRight() != nullptr) {
                std::string rightID = std::to_string(reinterpret_cast<uintptr_t>(node->getRight()));
                graph->addUnionNode(nodeID, rightID);
            }

            if (node->getLeft() != nullptr) {
                std::string leftID = std::to_string(reinterpret_cast<uintptr_t>(node->getLeft()));
                graph->addUnionNode(nodeID, leftID);
            }

            graphInOrderHelper(node->getRight(), graph);
        }


    }


};
#endif //PHONEDIRECTORY_TREESTRING_H
