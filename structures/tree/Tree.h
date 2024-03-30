//
// Created by ADMIN on 30/03/2024.
//

#ifndef PHONEDIRECTORY_TREE_H
#define PHONEDIRECTORY_TREE_H

#include <string>

class Tree {

public:
    virtual void add(int *data, std::string key) = 0;
    virtual void remove(int *data, std::string key) = 0;

};


#endif //PHONEDIRECTORY_TREE_H
