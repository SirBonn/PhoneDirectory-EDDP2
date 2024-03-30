//
// Created by ADMIN on 22/03/2024.
//

#ifndef PHONEDIRECTORY_SIMPLENODE_H
#define PHONEDIRECTORY_SIMPLENODE_H

template<typename T>
class SimpleNode {
private:
    SimpleNode<T> *ptr;
    T *data;

public:
    //constructors
    SimpleNode(T *data): data(data), ptr(nullptr){};
    //getters n setters
    void setPtr(SimpleNode<T> *ptr) {
        this->ptr = ptr;
    }

    SimpleNode<T> *getPtr() {
        return ptr;
    }

    T *getData() {
        return data;
    }

    void setData(T *data) {
        this->data = data;
    }

    ~SimpleNode() = default;

};

#endif //PHONEDIRECTORY_SIMPLENODE_H
