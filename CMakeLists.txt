cmake_minimum_required(VERSION 3.27)
project(PhoneDirectory)

set(CMAKE_CXX_STANDARD 20)

add_executable(PhoneDirectory main.cpp
        structures/nodes/NodeAVL.h
        structures/nodes/SimpleNode.h
        structures/nodes/DoubleNode.h
        structures/linkedList/LinkedList.h
        directory/Group.cpp
        directory/Group.h
        "structures/Hash/TableLL.h"
        "structures/Hash/Function.h"
        directory/Fields/Field.h
        structures/doubleLinkedList/DoubleLinkedList.h
        directory/Fields/FieldString.h
        directory/Fields/FieldInt.h
        directory/Fields/FieldChar.h
        structures/tree/TreeAVL.h
        utils/Export/DataManager.cpp
        utils/Export/DataManager.h
        utils/Graphs/GraphvizManager.cpp
        utils/Graphs/GraphvizManager.h
        structures/doubleLinkedList/DoubleListAVL.h
        structures/tree/TreeInteger.h
        structures/tree/Tree.h
)
