//
// Created by Megumi on 6/12/2024.
//
#pragma once
# include <iostream>
#include "../includes/AVL/AVL.h"
using namespace std;

#ifndef USUARIO_H
#define USUARIO_H


class Usuario {

private:
    // Aquí solo van los atributos
    string username;
    string nombre;
    string contraseña;



public:
    Usuario(string username, string nombre, string contraseña);
    AVL avlActivos;

    ~Usuario();

    //Metodos
    void agregarActivo(Activo *activo);
    void eliminarActivo(string id);
    void modificarActivo();
    void rentarActivo();
    void activosRentados();
    void misActivosRentados();


    string getNombre();
    string getContraseña();
    string getUsername();

};


#endif //USUARIO_H