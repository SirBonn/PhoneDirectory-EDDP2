#include <iostream>
#include <sstream>
#include <conio.h>
#include "string"
#include "directory/Field.h"
#include "directory/Group.h"

int main() {

    bool exit = false;
    while (!exit) {
        std::string entrada, entrada2;
        std::cout << "Ingrese el comando: ";
        std::getline(std::cin, entrada);
        std::cout << entrada2 << std::endl;
        std::istringstream iss(entrada);
        std::string action, sentence, groupName;
        iss >> action >> sentence >> groupName;

        if (action == "ADD" && sentence == "NEW-GROUP") {

            std::string token;
            Group newGroup(groupName);

            while (iss >> token) {
                if (token == "FIELDS") {
                    while (iss >> token && token != ");") {
                        std::string nombreCampo, tipoDato;
                        iss >> nombreCampo >> tipoDato;
                        if (tipoDato == "STRING" || tipoDato == "DATE") {
                            Field<std::string> campo(nombreCampo, tipoDato);
                            newGroup.addField(&campo);
                        } else if (tipoDato == "INTEGER") {
                            Field<int> campo(nombreCampo, tipoDato);
                            newGroup.addField(&campo);
                        } else if (tipoDato == "CHAR") {
                            Field<char> campo(nombreCampo, tipoDato);
                            newGroup.addField(&campo);
                        }
                    }
                    break;
                }
            }
            std::cout << "Se creo el nuevo grupo: " << newGroup.getGroupName() << std::endl;
            std::cout << "Cantidad de campos: " << newGroup.getCuantityFields() << std::endl;
            //agregarNuevoGrupo(groupKey, campos);

        } else if (action == "ADD" && sentence == "CONTACT") {

            std::cout<< "Se agrego un nuevo contacto." << std::endl;
            //agregarNuevoContacto();
        } else if (action == "EXIT" || action == "exit") {
            exit = true;
            return 0;
        } else {
            std::cout << "Comando no reconocido." << std::endl;
        }

        std::cout << "Presione una tecla para continuar...";
        getch();

    }

}
