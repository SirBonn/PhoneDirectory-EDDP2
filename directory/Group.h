//
// Created by ADMIN on 23/03/2024.
//

#ifndef PHONEDIRECTORY_GROUP_H
#define PHONEDIRECTORY_GROUP_H


#include <string>
#include "../structures/linkedList/linkedList.h"
#include "Field.h"
#include "../structures/Hash/TableLL.h"
#include "../structures/nodes/NodeAVL.h"
#include "../structures/tree/TreeAVL.h"


class Group {

private:
    std::string groupKey;
    LinkedList<Field> *fields;
    TableLL<TreeAVL> *tableAVL;

public:
    //constructors
    Group() = default;

    Group(std::string groupName) : groupKey(groupName) {
        fields = new LinkedList<Field>();
        tableAVL = new TableLL<TreeAVL>(5);
    };

    //methods

    void addField(Field *field);

    std::string getKey();

    bool fieldsEmpty();

    int getCuantityFields();

    void printGroup(GraphvizManager *graphvizManager);

    //destructor
    ~Group() {
        fields->~LinkedList();
    };

    //getters and setters
    std::string getGroupName();

    void setGroupName(std::string groupName);

    TableLL<TreeAVL> *getTableAVL();

    LinkedList<Field>* getFields();
};


#endif //PHONEDIRECTORY_GROUP_H
