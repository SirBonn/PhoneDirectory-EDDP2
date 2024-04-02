//
// Created by ADMIN on 28/03/2024.
//

#ifndef PHONEDIRECTORY_GRAPHVIZMANAGER_H
#define PHONEDIRECTORY_GRAPHVIZMANAGER_H

#include <fstream>
#include <string>
#include <iostream>

class GraphvizManager {

private:

    std::string dotCode = "";
    std::string fileName;
    std::string unionNode = "";

public:


        GraphvizManager(std::string fileName) : fileName(fileName) {
            dotCode = "digraph G {\n";
        }

        void addNode(std::string node) {
            dotCode += node + "\n";
        }

        void addEdge(std::string edge) {
            dotCode += edge + "\n";
        }

        void generateGraph() {
            dotCode += unionNode += "}";
            std::ofstream file("../"+fileName + ".dot");
            file << dotCode;
            file.close();
            std::string command = "dot -Tpng ../" + fileName + ".dot -o ../" + fileName + ".png";
            system(command.c_str());
        }

        void showGraph() {
            std::string command = "xdg-open ../" + fileName + ".png";
            system(command.c_str());
        }

        void clearGraph() {
            dotCode = "graph G {\n";
        }

        void addNode(std::string node, std::string label, std::string color, std::string shape) {
            dotCode += node + " [label=\"" + label + "\", color=\"" + color + "\", shape=" +shape+"]\n";
        }


        void addEdge(std::string edge, std::string label, std::string color) {
            dotCode += edge + " [label=\"" + label + "\", color=\"" + color + "\"]\n";
        }

        void addUnionNode(std::string nodeA, std::string nodeB) {
            unionNode += nodeA + " -> " + nodeB + "\n";
        }

};


#endif //PHONEDIRECTORY_GRAPHVIZMANAGER_H
