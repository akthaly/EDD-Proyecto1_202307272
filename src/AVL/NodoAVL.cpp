//
// Created by Megumi on 16/12/2024.
//

#include "../../includes/AVL/NodoAVL.h"

NodoAVL::NodoAVL(Activo *activo) {
    this->activo = activo;
    this->factEq = 0;
    this->izquierda = nullptr;
    this->derecha = nullptr;
}
