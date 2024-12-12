//
// Created by Megumi on 6/12/2024.
//
#pragma once
#include <iostream>
using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

class Usuario {

    private:
        // Aquí solo van los atributos

        string nombre;
        string contraseña;

    public:
        Usuario(string nombre, string contraseña);

        Usuario();

        ~Usuario();

        //Metodos
        void agregarActivo();
        void eliminarActivo();
        void modificarActivo();
        void rentarActivo();
        void activosRentados();
        void misActivosRentados();

        // setters y getters
        void setNombre(string nombre);
        void setContraseña(string contraseña);

        string getNombre();

};


#endif //USUARIO_H
