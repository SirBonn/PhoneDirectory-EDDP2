#include <iostream>
#include <sstream>
#include <algorithm>
#include <conio.h>
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
    std::string log = "";
    while (!exit) {
        std::string entrada;

        std::cout << "Bienvenido al sistema de directorio de contactos." << std::endl;
        std::cout << "------- Comandos disponibles ----- " << std::endl;
        std::cout << "-> ADD NEW-GROUP (nombreGrupo) FIELDS (nombreCampo1 tipoDato1, nombreCampo2 tipoDato2, ...);" << std::endl;
        std::cout << "-> ADD CONTACT (nombreGrupo) FIELDS (nombreCampo1 valorCampo1, nombreCampo2 valorCampo2, ...);" << std::endl;
        std::cout << "-> FIND CONTACT (nombreGrupo) CONTACT-FIELD (nombreCampo = valorCampo);" << std::endl;
        std::cout << "-> GRAPH ALL TABLES;" << std::endl;
        std::cout << "-> GRAPH TABLE (nombreGrupo);" << std::endl;
        std::cout << "-> VIEW REPORTS;" << std::endl;
        std::cout << "-> EXIT;" << std::endl;


        std::cout << "Ingrese el comando: ";
        std::getline(std::cin, entrada);
        log += entrada + "\n";
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
        } else if (action == "VIEW" && sentence == "REPORTS") {

            int option;
            bool tmpExit = true;
            while (tmpExit) {
                std::cout << "ingresa la opcion de reportes a ver:" << std::endl;
                std::cout << "1. Cantidad de grupos en el sistema" << std::endl;
                std::cout << "2. cantidad de campos por grupo" << std::endl;
                std::cout << "3. Log del sistema" << std::endl;
                std::cout << "0. Salir de reportes" << std::endl;
                std::cout << "Opcion --> ";
                std::cin >> option;

                switch (option) {
                    case 1:
                        std::cout << "------- Cantidad de grupos -------\n" << std::endl << table->getCuantity()
                                  << " de "
                                  << table->getsize();
                        std::cout << "Presione una tecla para continuar...";
                        getch();
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
                        break;
                    case 2:
                        std::cout << "\n\n------- Cantidad de campos por Grupo -------\n" << std::endl;
                        table->getReportsGrop();
                        std::cout << "Presione una tecla para continuar...";
                        getch();
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
                        break;
                    case 3:
                        std::cout << "------- LOG del sistema -------\n" << log << std::endl;
                        std::cout << "Presione una tecla para continuar...";
                        getch();
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
                        break;
                    case 0:
                        tmpExit = false;
                        break;
                    default:
                        std::cout << "Opcion no valida" << std::endl;
                        std::cout << "Presione una tecla para continuar...";
                        getch();
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
                        break;
                }


            }

        } else if (action == "EXIT" || action == "exit") {
            exit = true;
            return 0;
        } else {
            std::cout << "Comando no reconocido." <<
                      std::endl;
        }

        std::cout << "Presione una tecla para continuar...";
        getch();
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";

    }

}
