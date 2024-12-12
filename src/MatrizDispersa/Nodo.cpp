//
// Created by Megumi on 11/12/2024.
//

#include "../../includes/MatrizDispersa/Nodo.h"

Nodo::Nodo( string nomCabecera) {
    this->nomCabecera = nomCabecera;
    this->nuevoUsuario = nullptr;
    this->sig = nullptr;
    this->ant = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}

Nodo::Nodo( Usuario nuevoUsuario) {
    this->nuevoUsuario = new Usuario(nuevoUsuario);
    this->sig = nullptr;
    this->ant = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}
