//
// Created by ADMIN on 27/03/2024.
//

#ifndef PHONEDIRECTORY_FIELDINT_H
#define PHONEDIRECTORY_FIELDINT_H

#include "Field.h"

class FieldInt : public Field {

private:
    int value;

public:
    FieldInt(std::string fieldName, std::string fieldType) : Field(fieldName, fieldType) {};


    ~FieldInt() = default;

};

#endif //PHONEDIRECTORY_FIELDINT_H
