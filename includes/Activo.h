//
// Created by Megumi on 16/12/2024.
//

# include <iostream>
using namespace std;

#ifndef ACTIVO_H
#define ACTIVO_H


class Activo {
private:

    string descripcion;


public:
    Activo();
    Activo(string id, string descripcion);
    string id;

    string getId();
    string getDescripcion();
    void setDescripcion(string desc);
};

#endif //ACTIVO_H
