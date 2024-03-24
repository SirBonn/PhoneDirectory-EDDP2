//
// Created by ADMIN on 23/03/2024.
//

#ifndef PHONEDIRECTORY_GROUP_H
#define PHONEDIRECTORY_GROUP_H


#include <string>
#include "../structures/linkedList/linkedList.h"
#include "Field.h"

class Group {

private:
    std::string groupKey;
    LinkedList<Field<int>> integerFields;
    LinkedList<Field<std::string>> stringFields;
    LinkedList<Field<char>> charFields;
public:
    //constructors
    Group(std::string groupName) : groupKey(groupName) {};

    //methods
    void addField(Field<int> *field);

    Field<int> *getIntField();

    void addField(Field<std::string> *field);

    Field<std::string> *getStrField();

    void addField(Field<char> *field);

    Field<char> *getCharField();

    bool isEmpty();

    int getCuantityFields();

    bool isIntFieldEmpty();

    bool isStrFieldEmpty();

    bool isCharFieldEmpty();

    ~Group() = default;

    //getters and setters
    std::string getGroupName();

    void setGroupName(std::string groupName);

};


#endif //PHONEDIRECTORY_GROUP_H
