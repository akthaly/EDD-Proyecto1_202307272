//
// Created by Megumi on 6/12/2024.
//

#include "../includes/Usuario.h"
using namespace std;

Usuario::Usuario(string nombre, string contraseña) {
    this->nombre = nombre;
    this->contraseña = contraseña;
}

Usuario::~Usuario() {
}

void Usuario::agregarActivo() {

}

void Usuario::eliminarActivo() {

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
void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

void Usuario::setContraseña(string contraseña) {
    this->contraseña = contraseña;
}


string Usuario::getNombre() {
    return nombre;
}

