//
// Created by ADMIN on 23/03/2024.
//

#include "Group.h"
#include "../structures/tree/TreeInteger.h"

int Group::getCuantityFields() {
    return tableAVL->getsize();
}

std::string Group::getGroupName() {
    return groupKey;
}

void Group::setGroupName(std::string groupName) {
    this->groupKey = groupName;
}


std::string Group::getKey() {
    return groupKey;
}

void Group::addField(Field field) {
    fields->add(&field);
    if(field.getFieldType() == "INTEGER"){
        TreeInteger* treeInteger = new TreeInteger(field.getKey());
        tableAVL->insert(treeInteger);
    }
//    tableAVL->insert(new TreeAVL<Field>(field.getKey(), field.getFieldType()));
}


TableLL<TreeAVL<Field>> *Group::getTableAVL() {
    return tableAVL;
}

LinkedList<Field>* Group::getFields() {
    return fields;
}
