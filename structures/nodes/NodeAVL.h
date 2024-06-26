//
// Created by ADMIN on 22/03/2024.
//

#ifndef PHONEDIRECTORY_NODEAVL_H
#define PHONEDIRECTORY_NODEAVL_H

#include <string>
#include <random>
#include <chrono>

template<typename T>
class NodeAVL {

private:

    T *data;
    std::string *key;
    NodeAVL<T> *left;
    NodeAVL<T> *right;
    NodeAVL<T> *parent;

    int factorEq;
    int heightLeft;
    int heightRight;

public:

//constructors

    NodeAVL(T *data) : data(data), left(nullptr), right(nullptr), parent(nullptr),
                       factorEq(heightRight - heightLeft), heightLeft(0),
                       heightRight(0) {
        key = generateKey();
    };

    //methods
    void updateFactorEq();

    void updateHeightLeft();

    void updateHeightRight();

    void updateHeight() {};

    //gettersNSetters
    T *getData() const {
        return data;
    };


    void setData(T *_data) {
        data = _data;
    };

    std::string *getKey() const {
        return key;
    };

    NodeAVL<T> *getLeft() const {
        return left;
    };

    void setLeft(NodeAVL<T> *_left) {
        left = _left;
    };

    NodeAVL<T> *getRight() const {
        return right;
    };

    void setRight(NodeAVL<T> *_right) {
        right = _right;
    };

    NodeAVL<T> *getParent() const {
        return parent;
    };

    void setParent(NodeAVL<T> *_parent) {
        parent = _parent;
    };

    int getFactorEq() const {
        return factorEq;
    };

    void setFactorEq(int _factorEq) {
        factorEq = _factorEq;
    };

    int getHeightLeft() const {
        return heightLeft;
    };

    void setHeightLeft(int _heightLeft) {
        heightLeft = _heightLeft;
    };

    int getHeightRight() const {
        return heightRight;
    };

    void setHeightRight(int _heightRight) {
        heightRight = _heightRight;
    };

     std::string* generateKey() {
        auto now = std::chrono::system_clock::now();
        auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        std::string key = "Key_" + std::to_string(timestamp);
        return &key;
    }

};


#endif //PHONEDIRECTORY_NODEAVL_H
