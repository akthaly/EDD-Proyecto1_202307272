//
// Created by Megumi on 11/12/2024.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "Nodo.h"



class MatrizDispersa {
private:
    // Cabeceras Privadas
    Nodo *cabH; // Cabecera Horizontal
    Nodo *cabV; // Cabecera Vertical



    // Métodos Privados
    Nodo *cabHorizontal(std::string nomCabecera);
    Nodo *cabVertical(std::string nomCabecera);

    Nodo *insertarCabeceraH(std::string nomCabecera);
    Nodo *insertarCabeceraV(std::string nomCabecera);

    void insertarAlFinal(Usuario* nuevoUsuario, Nodo *cabH, Nodo *cabV);

public:

    MatrizDispersa();


    bool esVacia();


    void insertarUsuario(Usuario* nuevoUsuario, std::string cabH, std::string cabV);

};

#endif // MATRIZDISPERSA_H
