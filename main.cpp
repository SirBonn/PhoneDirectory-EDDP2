#include <iostream>
#include <sstream>
#include <algorithm>
#include "string"
#include "directory/Group.h"
#include "structures/Hash/TableLL.h"
#include "directory/Field.h"
#include "structures/tree/TreeInteger.h"
#include "structures/tree/TreeString.h"
#include "structures/tree/TreeChar.h"
#include "utils/Export/DataManager.h"


int main() {

    TableLL<Group> *table = new TableLL<Group>(5);
    bool exit = false;

    while (!exit) {
        std::string entrada;
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
        std::cout << "Ingrese el comando: ";
        std::getline(std::cin, entrada);
        std::replace(entrada.begin(), entrada.end(), '(', ' ');
        std::replace(entrada.begin(), entrada.end(), ')', ' ');
        std::replace(entrada.begin(), entrada.end(), '=', ' ');
        std::replace(entrada.begin(), entrada.end(), ',', ' ');
        std::replace(entrada.begin(), entrada.end(), ';', ' ');
        std::istringstream iss(entrada);
        std::string action, sentence, groupName, token;
        iss >> action >> sentence >> groupName;

        if (action == "ADD" && sentence == "NEW-GROUP") {

            Group *newGroup = new Group(groupName);

            while (iss >> token) {
                if (token == "FIELDS") {
                    while (iss >> token) {
                        std::string nombreCampo, tipoDato;
                        iss >> tipoDato;
                        if (tipoDato == "STRING" || tipoDato == "DATE") {
                            Field *campo = new Field(token, tipoDato);
                            newGroup->addField(campo);
                        } else if (tipoDato == "INTEGER") {
                            Field *campo = new Field(token, tipoDato);
                            newGroup->addField(campo);
                        } else if (tipoDato == "CHAR") {
                            Field *campo = new Field(token, tipoDato);
                            newGroup->addField(campo);
                        }
                    }
                    break;
                }
            }

            std::cout << "Se creo el nuevo grupo: " << newGroup->getGroupName() << std::endl;
            std::cout << "Cantidad de campos: " << newGroup->getCuantityFields() << std::endl;
            table->insert(newGroup);


        } else if (action == "ADD" && sentence == "CONTACT") {

            iss >> token;
            std::string nombreContacto = token;
            Group *groupSearched = table->searchKey(nombreContacto);
            SimpleNode<Field> *node = groupSearched->getFields()->gethead();
            std::string content = "", firstField = "";
            iss >> token;
            if (token == "FIELDS") {
                TableLL<TreeAVL> *fieldTable = groupSearched->getTableAVL();
                while (iss >> token && token != ");") {
                    content += token + ", ";
                    if (firstField == "") {
                        firstField = token;
                    }

                    while (node != nullptr) {

                        Field *field = node->getData();
                        if (field->getFieldType() == "STRING") {

                            TreeString *treeas = static_cast<TreeString *>(fieldTable->searchKey(
                                    field->getKey()));
                            treeas->insert(new std::string(token));

                        } else if (field->getFieldType() == "INTEGER") {
                            int num;
                            std::istringstream(token) >> num;
                            TreeInteger *treeas = static_cast<TreeInteger *>(fieldTable->searchKey(
                                    field->getKey()));
                            treeas->insert(new int(num));
                        } else if (field->getFieldType() == "CHAR") {
//
                            TreeChar *treeas = static_cast<TreeChar *>(fieldTable->searchKey(
                                    field->getKey()));
                            treeas->insert(new char(token[0]));
                        }
                        node = node->getPtr();
                    }

                }
            }
            DataManager::createFolder(nombreContacto, content, firstField);
        } else if (action == "FIND" && sentence == "CONTACT") {

            iss >> token;
            std::string nombreContacto = token;
            std::string *key;
            Group *groupSearched = table->searchKey(nombreContacto);
            SimpleNode<Field> *node = groupSearched->getFields()->gethead();
            iss >> token;
            if (token == "CONTACT-FIELD") {
                TableLL<TreeAVL> *fieldTable = groupSearched->getTableAVL();
                while (iss >> token && token != ");") { //token pasa a ser el valor del campo
                    std::string value;
                    iss >> value;
                    while (node != nullptr) {

                        Field *field = node->getData();

                        if (field->getKey() == token) {
                            if (field->getFieldType() == "STRING") {

                                TreeString *treeas = static_cast<TreeString *>(fieldTable->searchKey(
                                        field->getKey()));

                                key = treeas->searchValueKey(&value);

                            } else if (field->getFieldType() == "INTEGER") {
                                int num;
                                std::istringstream(value) >> num;
                                TreeInteger *treeas = static_cast<TreeInteger *>(fieldTable->searchKey(
                                        field->getKey()));
                                key = treeas->searchValueKey(&num);

                            } else if (field->getFieldType() == "CHAR") {
                                //
                                TreeChar *treeas = static_cast<TreeChar *>(fieldTable->searchKey(
                                        field->getKey()));
                                key = treeas->searchValueKey(&value[0]);
                            }

                        }
                        node = node->getPtr();
                    }

                    SimpleNode<Field> *node = groupSearched->getFields()->gethead();

                    TableLL<TreeAVL> *fieldTable = groupSearched->getTableAVL();

                    while (node != nullptr) {

                        Field *field = node->getData();
                        if (field->getFieldType() == "STRING") {

                            TreeString *treeas = static_cast<TreeString *>(fieldTable->searchKey(
                                    field->getKey()));
                            std::cout << field->getKey() << ": " << treeas->searchkey(key)->getData() << std::endl;

                        } else if (field->getFieldType() == "INTEGER") {
                            int num;
                            std::istringstream(token) >> num;
                            TreeInteger *treeas = static_cast<TreeInteger *>(fieldTable->searchKey(
                                    field->getKey()));
                            std::cout << field->getKey() << ": " << treeas->searchkey(key)->getData() << std::endl;
                        } else if (field->getFieldType() == "CHAR") {
//
                            TreeChar *treeas = static_cast<TreeChar *>(fieldTable->searchKey(
                                    field->getKey()));
                            std::cout << field->getKey() << ": " << treeas->searchKey(key)->getData() << std::endl;
                        }
                        node = node->getPtr();
                    }

                }
            }

        } else if (action == "GRAPH" && (groupName == "TABLES" || groupName == "TABLE")) {
            if (sentence == "ALL") {
                table->printHashtable(table);
            } else {
                Group *groupSearched = table->searchKey(sentence);
                if (groupSearched == NULL) {
                    std::cout << "No se encontro el grupo." <<
                              std::endl;
                } else {
                    GraphvizManager *graphvizManager = new GraphvizManager(groupSearched->getKey());
                    groupSearched->printGroup(graphvizManager);
                    graphvizManager->generateGraph();
                }
            }
            table->printHashtable(table);
        } else if (action == "EXIT" || action == "exit") {
            exit = true;
            return 0;
        } else {
            std::cout << "Comando no reconocido." <<
                      std::endl;
        }

        std::cout << "Presione una tecla para continuar...";
        getch();

    }

}
