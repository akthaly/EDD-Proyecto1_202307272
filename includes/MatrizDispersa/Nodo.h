//
// Created by Megumi on 11/12/2024.
//

#include <iostream>
#ifndef NODO_H
#define NODO_H
#include <string>
#include "../Usuario.h"

using namespace std;

class Nodo {

public:
        string nomCabecera;
        Usuario* nuevoUsuario;


        // Punteros
        Nodo *sig;
        Nodo *ant;

        Nodo *arriba;
        Nodo *abajo;

        Nodo *adelante;
        Nodo *atras;

        Nodo(string nomCabecera);

        Nodo(Usuario nuevoUsuario);

        ~Nodo();
};



#endif //NODO_H
