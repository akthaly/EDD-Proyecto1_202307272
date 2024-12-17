//
// Created by Megumi on 16/12/2024.
//

#include "../includes/Activo.h"

Activo::Activo(string id, string descripcion) {
    this->id = id;
    this->descripcion = descripcion;
}

string Activo::getDescripcion() {
    return descripcion;
}

string Activo::getId() {
    return id;
}

void Activo::setDescripcion(string desc) {
    this->descripcion = desc;
}
