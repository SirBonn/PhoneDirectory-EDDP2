//
// Created by ADMIN on 27/03/2024.
//

#ifndef PHONEDIRECTORY_FIELDSTRING_H
#define PHONEDIRECTORY_FIELDSTRING_H

#include "Field.h"


class FieldString : public Field {

private:
std::string value;

public:
FieldString(std::string fieldName, std::string fieldType) : Field(fieldName, fieldType) {};
};

#endif //PHONEDIRECTORY_FIELDSTRING_H
