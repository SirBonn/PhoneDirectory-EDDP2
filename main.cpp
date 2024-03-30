#include <iostream>
#include <sstream>
#include <algorithm>
#include "string"
#include "directory/Group.h"
#include "structures/Hash/TableLL.h"
#include "directory/Fields/Field.h"
#include "directory/Fields/FieldInt.h"
#include "directory/Fields/FieldChar.h"
#include "directory/Fields/FieldString.h"


class FieldString;

int main() {

    TableLL<Group> *table = new TableLL<Group>(5);
    bool exit = false;

    while (!exit) {
        std::string entrada;
        std::cout << "Ingrese el comando: ";
        std::getline(std::cin, entrada);
        std::replace(entrada.begin(), entrada.end(), '(', ' ');
        std::replace(entrada.begin(), entrada.end(), ')', ' ');
        std::replace(entrada.begin(), entrada.end(), ',', ' ');
        std::istringstream iss(entrada);
        std::string action, sentence, groupName, token;
        iss >> action >> sentence >> groupName;

        if (action == "ADD" && sentence == "NEW-GROUP") {

            Group *newGroup = new Group(groupName);

            while (iss >> token) {
                if (token == "FIELDS") {
                    while (iss >> token && token != ");") {
                        std::string nombreCampo, tipoDato;
                        iss >> tipoDato;
                        if (tipoDato == "STRING" || tipoDato == "DATE") {
                            FieldString campo(token, tipoDato);
                            newGroup->addField(campo);
                        } else if (tipoDato == "INTEGER") {
                            FieldInt campo(token, tipoDato);
                            newGroup->addField(campo);
                        } else if (tipoDato == "CHAR") {
                            FieldChar campo(token, tipoDato);
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

            if (token == "FIELDS") {
                while (iss >> token && token != ");") { //token pasa a ser el valor del campo

                    while (node != nullptr) {

                        Field *field = node->getData();
                        TreeAVL<Field> *tree = groupSearched->getTableAVL()->searchKey(field->getKey());
                        tree->insert(token);
                        node = node->getPtr();

                    }
                    TableLL<TreeAVL<Field>> *tableAvl = table->searchKey(nombreContacto)->getTableAVL();

                }
            }


        } else if (action == "FIND" && sentence == "CONTACT") {

            std::cout << "Bsucando contacto." << std::endl;

        } else if (action == "EXIT" || action == "exit") {
            exit = true;
            return 0;
        } else {
            std::cout << "Comando no reconocido." << std::endl;
        }

//        std::cout << "Presione una tecla para continuar...";
//        getch();

    }

}
