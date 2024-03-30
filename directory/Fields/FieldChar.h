//
// Created by ADMIN on 27/03/2024.
//

#ifndef PHONEDIRECTORY_FIELDCHAR_H
#define PHONEDIRECTORY_FIELDCHAR_H

#include "Field.h"

class FieldChar : public Field {

private:
    char value;

public:
    FieldChar(std::string fieldName, std::string fieldType) : Field(fieldName, fieldType) {};

    ~FieldChar() = default;

};

#endif //PHONEDIRECTORY_FIELDCHAR_H
