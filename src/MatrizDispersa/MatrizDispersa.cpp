//
// Created by Megumi on 11/12/2024.
//
#include "../../includes/MatrizDispersa/MatrizDispersa.h"

MatrizDispersa::MatrizDispersa() {
    this->cabH = nullptr;
    this->cabV = nullptr;
}

void MatrizDispersa::insertarUsuario(Usuario* nuevoUsuario, std::string cabH, std::string cabV) {
    Nodo *cabHor = nullptr;
    Nodo *cabVer = nullptr;

    if (esVacia()) {
         cabHor = insertarCabeceraH(cabH);
        cabVer = insertarCabeceraV(cabV);

        insertarAlFinal(nuevoUsuario, cabHor, cabVer);
    }
    // Si la matriz no está vacía
    cabHor = cabHorizontal(cabH);
    cabVer = cabVertical(cabV);

    // Si no existe la cabecera horizontal ni la vertical
    if (cabHor == nullptr && cabVer == nullptr) {
        cabHor = insertarCabeceraH(cabH);
        cabVer = insertarCabeceraV(cabV);

        insertarAlFinal(nuevoUsuario,cabHor, cabVer);

        return;
    }

    // Si no existe la cabecera horizontal pero sí la vertical
    if (cabHor == nullptr) {
        cabHor = insertarCabeceraH(cabH);
        insertarAlFinal(nuevoUsuario,cabHor, cabVer);

        return;
    }

    // Si no existe la cabecera vertical pero sí la horizontal
    if (cabVer == nullptr) {
        cabVer = insertarCabeceraV(cabV);
        insertarAlFinal(nuevoUsuario,cabHor, cabVer);

        return;
    }



}

void MatrizDispersa::insertarAlFinal(Usuario* nuevoUsuario, Nodo *cabH, Nodo *cabV) {
    Nodo *usuarioNuevo = new Nodo(*nuevoUsuario);

    Nodo *auxH = cabH;
    Nodo *auxV = cabV;

    while (auxH->abajo != nullptr) {
        auxH = auxH->abajo;
    }

    auxH -> abajo = usuarioNuevo;
    usuarioNuevo -> arriba = auxH;

    while (auxV -> sig != nullptr) {
        auxV = auxV -> sig;
    }

    auxV -> sig = usuarioNuevo;
    usuarioNuevo -> ant = auxV;
}


bool MatrizDispersa::esVacia() {
    // devuelve verdadero si la matriz está vacía (no hay nodos)
    return this->cabH == nullptr && this->cabV == nullptr;
}

Nodo *MatrizDispersa::cabHorizontal(std::string nomCabecera) {

    if (esVacia()) {
        return nullptr;
    }

    Nodo *aux = cabH;

    while (aux != nullptr) {
        if (aux -> nomCabecera == nomCabecera) {
            return aux;
        }
        aux = aux -> sig;
    }
    return nullptr;
}

Nodo *MatrizDispersa::insertarCabeceraH(std::string nomCabecera) {

    Nodo *nuevaCabecera = new Nodo(nomCabecera);

    if (this->cabH == nullptr) { //se puso this-> para que no haya ambigüedad con la variable cabH
        this->cabH = nuevaCabecera;
        return nuevaCabecera;
    }
    // este nodo auxiliar se crea después del if para no crear un registro de memoria innecesario
    Nodo *aux = cabH;
    // si la cabecera horizontal está vacía se inserta la nueva cabecera
    while (aux->sig != nullptr) aux = aux->sig;

    aux->sig = nuevaCabecera;
    nuevaCabecera->ant = aux;

    return nuevaCabecera;
}

Nodo *MatrizDispersa::insertarCabeceraV(std::string nomCabecera) {

    Nodo *nuevaCabecera = new Nodo(nomCabecera);

    if (this-> cabV == nullptr) { // se puso this-> para que no haya ambigüedad con la variable cabV
        this-> cabV = nuevaCabecera;
        return nuevaCabecera;
    }
    // este nodo auxiliar se crea después del If para no crear un registro de memoria innecesario
    Nodo *aux = cabV;
    // si la cabecera vertical está vacía se inserta la nueva cabecera
    while (aux->abajo != nullptr) aux = aux->abajo;

    aux->abajo = nuevaCabecera;
    nuevaCabecera->arriba = aux;

    return nuevaCabecera;
}


Nodo *MatrizDispersa::cabVertical(std::string nomCabecera) {
    if (esVacia()) {
        return nullptr;
    }

    Nodo *aux = cabV;

    while (aux != nullptr) {
        if (aux -> nomCabecera == nomCabecera) {
            return aux;
        }
        aux = aux -> abajo;
    }
    return nullptr;
}