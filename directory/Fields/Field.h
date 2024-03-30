//
// Created by ADMIN on 26/03/2024.
//

#ifndef PHONEDIRECTORY_FIELD_H
#define PHONEDIRECTORY_FIELD_H

#include <string>

class Field {

protected:
    std::string fieldName;
    std::string fieldType;

public:

    //constructors
    Field(std::string fieldName, std::string fieldType) : fieldName(fieldName), fieldType(fieldType) {};

    //methods
    std::string getKey() {
        return fieldName;
    }

    std::string getFieldType() {
        return fieldType;
    }

    ~Field() = default;


};

#endif //PHONEDIRECTORY_FIELD_H
