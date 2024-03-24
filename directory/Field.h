//
// Created by ADMIN on 22/03/2024.
//

#ifndef PHONEDIRECTORY_FIELD_H
#define PHONEDIRECTORY_FIELD_H

#include <string>

template<typename T>
class Field {

private:
    std::string fieldName;
    std::string fieldType;
    T valueField;

public:

    //constructors
    Field(std::string fieldName, std::string fieldType): fieldName(fieldName), fieldType(fieldType){};

    //methods
    std::string getFieldName() {
        return fieldName;
    }

    void setFieldName(std::string fieldName) {
        this->fieldName = fieldName;
    }

    std::string getFieldType() {
        return fieldType;
    }

    void setFieldType(std::string fieldType) {
        this->fieldType = fieldType;
    }

    T getValueFieldStr() {
        return valueField;
    }

    void setValueFieldStr(T valueField) {
        this->valueField = valueField;
    }

    ~Field() = default;

};


#endif //PHONEDIRECTORY_FIELD_H
