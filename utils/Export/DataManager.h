//
// Created by ADMIN on 28/03/2024.
//

#ifndef PHONEDIRECTORY_DATAMANAGER_H
#define PHONEDIRECTORY_DATAMANAGER_H

#include <iostream>
#include<string>
#include <fstream>
#include <filesystem>

#ifdef _WIN32

#include <direct.h> // Para Windows

#define mkdir _mkdir
#else
#include <sys/stat.h> // Para sistemas basados en Unix
#endif

using namespace std;
namespace fs = std::filesystem;

class DataManager {

public:

    static void create(string folderName) {

        if (
                fs::exists(folderName)
                &&
                fs::is_directory(folderName)
                ) {
            cout << "La carpeta ya existe." << endl;
        } else {
            cout << "La carpeta no existe." << endl;
            //Creamos la carpeta.
#ifdef _WIN32
            int folderCreated = mkdir(folderName.c_str());
#else
            int folderCreated = mkdir(folderName.c_str(), 0777); // Permisos en sistemas Unix
#endif

            if (folderCreated == 0) {
                cout << "Carpeta creada correctamente." << endl;
            } else {
                cout << "Error al crear la carpeta. Es posible que ya exista" << endl;
                //return 1;
            }
        }
    }

    static void createFolder(string path, string content, string nameFile) {

        create("../Groups");
        string folderName = "../Groups/" + path;
        create(folderName);

        // Crear un archivo de texto dentro de la carpeta
        string filePath = folderName + "/" + nameFile + ".txt";

        ofstream outputFile(filePath);

        if (outputFile.is_open()) {
            outputFile << content << endl;
            outputFile.close();
            cout << "Archivo de texto creado correctamente." << endl;
        } else {
            cout << "Error al crear el archivo de texto." << endl;
            //return 1;
        }

    }

};

#endif //PHONEDIRECTORY_DATAMANAGER_H
