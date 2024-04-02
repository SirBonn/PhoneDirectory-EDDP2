//
// Created by ADMIN on 28/03/2024.
//

#ifndef PHONEDIRECTORY_TREEAVL_H
#define PHONEDIRECTORY_TREEAVL_H

#include "string"
#include "../nodes/NodeAVL.h"

class TreeAVL {

private:
    std::string key;

public:

    TreeAVL(std::string key): key(key) {};


    std::string getKey() const {
        return key;
    }

};

#endif //PHONEDIRECTORY_TREEAVL_H
