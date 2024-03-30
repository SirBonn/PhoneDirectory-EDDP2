//
// Created by ADMIN on 24/03/2024.
//

#ifndef PHONEDIRECTORY_FUNCTION_H
#define PHONEDIRECTORY_FUNCTION_H


#include <string>
#include <iostream>

template<typename T>
class Function {

public:

    static int getIndex(std::string key, int size) {
        int index = 0;
        for (int i = 0; i < key.length(); i++) {
            index += key[i];
        }
        return index % size;
    }

    static int reIndexing(int index, int size) {
        return (index + 1) % size; //todo mejorar la funcion de reindexing
    }

};


#endif //PHONEDIRECTORY_FUNCTION_H
