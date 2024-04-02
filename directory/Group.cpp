//
// Created by ADMIN on 23/03/2024.
//

#include "Group.h"
#include "../structures/tree/TreeInteger.h"
#include "../structures/tree/TreeString.h"
#include "../structures/tree/TreeChar.h"

int Group::getCuantityFields() {
    return tableAVL->getCuantity();
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

void Group::addField(Field *field) {
    fields->add(field);
    if(field->getFieldType() == "INTEGER"){
        TreeInteger *treeInteger = new TreeInteger(field->getKey());
        tableAVL->insert(treeInteger);
    }else if(field->getFieldType() == "STRING"){
        TreeString *treeString = new TreeString(field->getKey());
        tableAVL->insert(treeString);
    } else if(field->getFieldType() == "CHAR"){
        TreeChar *treeChar = new TreeChar(field->getKey());
        tableAVL->insert(treeChar);
    }
}


TableLL<TreeAVL> *Group::getTableAVL() {
    return tableAVL;
}

LinkedList<Field>* Group::getFields() {
    return fields;
}

void Group::printGroup(GraphvizManager *graphvizManager) {

    //print group with graphviz
    SimpleNode<Field> *node = fields->gethead();

    while(node != nullptr){
        Field *field = node->getData();
        graphvizManager->addNode(field->getKey(), field->getKey(), "", "ellipse");
        graphvizManager->addUnionNode(groupKey, field->getKey());

        if(field->getFieldType() == "INTEGER"){
            TreeInteger *treeInteger = static_cast<TreeInteger *>(tableAVL->searchKey(field->getKey()));
            treeInteger->graphAVL(graphvizManager, field->getKey());
        }else if(field->getFieldType() == "STRING"){
            TreeString *treeString = static_cast<TreeString *>(tableAVL->searchKey(field->getKey()));
            treeString->graphAVL(graphvizManager, field->getKey());
        } else if(field->getFieldType() == "CHAR"){
            TreeChar *treeChar = static_cast<TreeChar *>(tableAVL->searchKey(field->getKey()));
            treeChar->graphAVL(graphvizManager, field->getKey());
        }

        node = node->getPtr();
    }

}
