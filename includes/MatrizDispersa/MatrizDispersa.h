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

    void insertarAlFinal(Nodo *nuevoUsuario, Nodo *cabH, Nodo *cabV);
    void insertarAlFinalHorizontal(Nodo *nuevoUsuario, Nodo *cabH);
    void insertarAlFinalVertical(Nodo *nuevoUsuario, Nodo *cabV);
    void insertarAlMedioEnVertical(Nodo *nuevoUsuario, Nodo *vertical);
    void insertarAlMedioEnHorizontal(Nodo *nuevoUsuario, Nodo *horizontal);
    void insertarUsuarioProfuncidad(Nodo *nuevoUsuario, std::string cabH, std::string cabV);


    Nodo *busquedaDeNodo(std::string cabH, std::string cabV);

    Nodo *enCabH(Nodo *nodo);
    Nodo *enCabV(Nodo *nodo);

    bool masAbajo(Nodo *cabVer, string cabV); // Si la cabecera está más abajo de la que se va a insertar retorna true
    bool masDerecha(Nodo *cabHor, string cabH); // Si la cabecera está más a la derecha de la que se va a insertar retorna true

    bool verificarExt(std::string nombre);


    void reporte();

public:

    MatrizDispersa();


    bool esVacia();

    bool iniciarSesion(std::string username, std::string contraseña);
    void insertarUsuario(Usuario* nuevoUsuario, std::string cabH, std::string cabV);
    bool verificarExistenciaUsuario(std::string username, std::string cabHorizo, std::string cabVert);
    void generarImagenMatriz(const std::string& nombreArchivo);
    Nodo* buscarUsuario(string username);

};

#endif // MATRIZDISPERSA_H
