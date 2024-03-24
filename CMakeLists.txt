cmake_minimum_required(VERSION 3.27)
project(PhoneDirectory)

set(CMAKE_CXX_STANDARD 20)

add_executable(PhoneDirectory main.cpp
        structures/nodes/NodeAVL.h
        structures/nodes/SimpleNode.h
        structures/nodes/DoubleNode.h
        directory/Field.h
        structures/linkedList/LinkedList.h
        directory/Group.cpp
        directory/Group.h
)
