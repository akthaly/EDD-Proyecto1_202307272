//
// Created by Megumi on 16/12/2024.
//

#ifndef NODOAVL_H
#define NODOAVL_H
#include "../Activo.h"

class NodoAVL {
public:
    Activo *activo;
    int factEq;

    NodoAVL *izquierda;
    NodoAVL *derecha;

    NodoAVL(Activo *activo);
};


#endif //NODOAVL_H
