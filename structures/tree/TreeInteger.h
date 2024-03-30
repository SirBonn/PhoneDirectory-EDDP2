//
// Created by ADMIN on 29/03/2024.
//

#ifndef PHONEDIRECTORY_TREEINTEGER_H
#define PHONEDIRECTORY_TREEINTEGER_H

#include <string>
#include "TreeAVL.h"

class TreeInteger: public TreeAVL<int>{

private:
    std::string key;
public:

    TreeInteger(std::string key) : TreeAVL<int>(key), key(key) {

    };

//    void remove(int *data, std::string key) {
//        treeAvl->remove(data, key);
//    }
//
//    int *search(std::string key) {
//        return treeAvl->search(key);
//    }


};

#endif //PHONEDIRECTORY_TREEINTEGER_H
