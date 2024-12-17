//
// Created by Megumi on 16/12/2024.
//

#ifndef AVL_H
#define AVL_H
#include "NodoAVL.h"
#include <vector>


class AVL {
private:
    void insertar(NodoAVL *nuevoActivo, NodoAVL* &raiz);
    void eliminar(string id, NodoAVL* &raiz);
    int alturaMax(NodoAVL *nodo); // pasamos el nodo y retornamos la altura maxima del nodo
    int factorEquilibrio(NodoAVL *nodo); // altura hijo derecho - altura hijo izquierdo y no tiene & porque no se va a modificar
    void rotacionSimpleDerecha(NodoAVL *&nodo); // el simbolo & es para pasar la referencia del nodo y no una copia
    void rotacionSimpleIzquierda(NodoAVL *&nodo);
    void rotacionDobleDerecha(NodoAVL *&nodo);
    void rotacionDobleIzquierda(NodoAVL *&nodo);
    void listActivos(NodoAVL *nodo, vector<Activo *> &objetos);
    void escribirNodoDOT(NodoAVL *raiz, ofstream &archivo);
    NodoAVL *masDer(NodoAVL *&nodo);
    NodoAVL* buscarActivoPorId(string id, NodoAVL* raiz);


public:
    NodoAVL *raiz;

    AVL();

    void eliminarActivo(string id);
    void insertarActivo(Activo *nuevoActivo);
    void getActivos();
    void setDesc(string id, string nuevaDescripcion);
    void generarAVL(string nombreArchivo);



    bool esHoja(NodoAVL *nodo);

};



#endif //AVL_H
