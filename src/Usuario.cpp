//
// Created by Megumi on 6/12/2024.
//

#include "../includes/Usuario.h"
#include "../includes/AVL/AVL.h"

using namespace std;

Usuario::Usuario(string username, string nombre, string contraseña) {
    this->username = username;
    this->nombre = nombre;
    this->contraseña = contraseña;
}

Usuario::~Usuario() {
}

void Usuario::agregarActivo(Activo *activo) {
    avlActivos.insertarActivo(activo);
    cout << "Activo agregado exitosamente al usuario " << nombre << ".\n";
}


void Usuario::eliminarActivo(string id) {
    avlActivos.eliminarActivo(id);
    cout << "Intento de eliminación del activo con ID " << id << " realizado.\n";
}


void Usuario::modificarActivo() {

}

void Usuario::rentarActivo() {

}

void Usuario::activosRentados() {

}

void Usuario::misActivosRentados() {

}

// setters y getters

string Usuario::getUsername() {
    return username;
}

string Usuario::getNombre() {
    return nombre;
}

string Usuario::getContraseña() {
    return contraseña;
}