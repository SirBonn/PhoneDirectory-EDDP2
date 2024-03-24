//
// Created by ADMIN on 23/03/2024.
//

#include "Group.h"


void Group::addField(Field<int> *field) {
    integerFields.add(field);
}

Field<int> *Group::getIntField() {
    return integerFields.getFirst();
}

void Group::addField(Field<std::string> *field) {
    stringFields.add(field);
}

Field<std::string> *Group::getStrField() {
    return stringFields.getFirst();
}

void Group::addField(Field<char> *field) {
    charFields.add(field);
}

Field<char> *Group::getCharField() {
    return charFields.getFirst();
}

bool Group::isEmpty() {
    return integerFields.isEmpty() && stringFields.isEmpty() && charFields.isEmpty();
}

int Group::getCuantityFields() {
    return integerFields.getSize() + stringFields.getSize() + charFields.getSize();
}

std::string Group::getGroupName() {
    return groupKey;
}

void Group::setGroupName(std::string groupName) {
    this->groupKey = groupName;
}

bool Group::isIntFieldEmpty() {
    return integerFields.isEmpty();
}

bool Group::isCharFieldEmpty() {
    return charFields.isEmpty();
}

bool Group::isStrFieldEmpty() {
    return stringFields.isEmpty();
}







