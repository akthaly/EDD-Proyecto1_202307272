//
// Created by Megumi on 16/12/2024.
//

#include "../../includes/AVL/AVL.h"
#include <fstream>
#include <iostream>


AVL::AVL() {
    this->raiz = nullptr; // siempre incializarlo en nulo para evitar errores
}

void AVL::insertarActivo(Activo *nuevoActivo) {
    NodoAVL *nodo = new NodoAVL(nuevoActivo);

    insertar(nodo, this->raiz);

}

void AVL::insertar(NodoAVL *nuevoActivo, NodoAVL *&raiz) {
    if (raiz == nullptr) {
        raiz = nuevoActivo;
        raiz->factEq = factorEquilibrio(raiz);

        return;
    }

    if (nuevoActivo->activo->id < raiz->activo->id) {
        insertar(nuevoActivo, raiz->izquierda); // si el id del nuevo activo es menor al id del activo de la raiz, insertamos en la izquierda
    } else {
        insertar(nuevoActivo, raiz->derecha); // si el id del nuevo activo es mayor al id del activo de la raiz, insertamos en la derecha
    }

    raiz->factEq = factorEquilibrio(raiz);

    if (raiz->factEq < -1) {
        if (raiz->izquierda->factEq > 0) {
            rotacionDobleDerecha(raiz);
            return;
        }
        rotacionSimpleDerecha(raiz);

        return;
    }

    if (raiz->factEq > 1) {
        if (raiz->derecha->factEq < 0) {
            rotacionDobleIzquierda(raiz);
            return;
        }

        rotacionSimpleIzquierda(raiz);
    }
}

int AVL::alturaMax(NodoAVL *nodo) {
    if (nodo == nullptr) return 0;

    int alturaIzquierda = alturaMax(nodo->izquierda);
    int alturaDerecha = alturaMax(nodo->derecha);

    return (alturaIzquierda > alturaDerecha) ? alturaIzquierda + 1 : alturaDerecha + 1;
}

int AVL::factorEquilibrio(NodoAVL *nodo) {
    return alturaMax(nodo->derecha) - alturaMax(nodo->izquierda);
}

void AVL::rotacionSimpleDerecha(NodoAVL *&nodo) {
    NodoAVL *aux = nodo->izquierda;
    nodo->izquierda = aux->derecha;
    aux->derecha = nodo;
    nodo = aux;

    nodo->factEq = factorEquilibrio(nodo);
    nodo->derecha->factEq = factorEquilibrio(nodo->derecha);
    if (nodo->izquierda == nullptr) return;
    nodo->izquierda->factEq = factorEquilibrio(nodo->izquierda);

}

void AVL::rotacionSimpleIzquierda(NodoAVL *&nodo) {
    NodoAVL *aux = nodo->derecha;
    nodo->derecha = aux->izquierda;
    aux->izquierda = nodo;
    nodo = aux;

    nodo->factEq = factorEquilibrio(nodo);
    nodo->izquierda->factEq = factorEquilibrio(nodo->izquierda);
    if (nodo->derecha == nullptr) return;
    nodo->derecha->factEq = factorEquilibrio(nodo->derecha);
}

void AVL::rotacionDobleDerecha(NodoAVL *&nodo) {
    rotacionSimpleIzquierda(nodo->izquierda);
    rotacionSimpleDerecha(nodo);
}

void AVL::rotacionDobleIzquierda(NodoAVL *&nodo) {
    rotacionSimpleDerecha(nodo->derecha);
    rotacionSimpleIzquierda(nodo);
}

bool AVL::esHoja(NodoAVL *node) {
    return node->izquierda == nullptr && node->derecha == nullptr;
}

NodoAVL *AVL::masDer(NodoAVL *&nodo) {
    if (nodo->derecha == nullptr) return nodo;

    return masDer(nodo->derecha);
}

void AVL::eliminar(string id, NodoAVL *&raiz) {

    if (raiz == nullptr) {
        cout << "No se encontro el activo" << endl;
        return;
    }
    if (id == raiz->activo->id) {
        // Si lo que encontramos es una hoja
        if (esHoja(raiz)) {
            raiz = nullptr;
            return;
        }

        // Cuando no es una hoja
        if (raiz->izquierda == nullptr) {
            raiz = raiz->derecha;
            return;
        }

        if (raiz->derecha == nullptr) {
            raiz = raiz->izquierda;
            return;
        }

        // Buscar el más a la derecha de el hijo izq
        NodoAVL *nodoDer = masDer(raiz->izquierda);
        raiz->activo = nodoDer->activo;

        eliminar(nodoDer->activo->id, raiz->izquierda);

        id = raiz->activo->id;

    }
    if (id < raiz->activo->id) {
        eliminar(id, raiz->izquierda);
    }

    if (id > raiz->activo->id){
        eliminar(id, raiz->derecha);
    }

    // volver a calcular el factor de equilibrio
    raiz->factEq = factorEquilibrio(raiz);
    if (raiz->factEq < -1) {
        if (raiz->izquierda->factEq > 0) {
            rotacionDobleDerecha(raiz);
            return;
        }
        rotacionSimpleDerecha(raiz);

        return;
    }

    if (raiz->factEq > 1) {
        if (raiz->derecha->factEq < 0) {
            rotacionDobleIzquierda(raiz);
            return;
        }

        rotacionSimpleIzquierda(raiz);
        return;
    }

}

void AVL::escribirNodoDOT(NodoAVL *raiz, ofstream &archivo) {
    if (raiz == nullptr) return;

    archivo << "    \"" << raiz->activo->id << "\""
            << " [label=\"" << raiz->activo->id << "\\nID del activo: " << raiz->activo->id << "\", shape=square, style=filled, "
            << "fillcolor=green, fontcolor=black, fontname=\"Arial\", fontsize=12, penwidth=2];\n";

    if (raiz->izquierda != nullptr) {
        archivo << "    \"" << raiz->activo->id << "\" -> \"" << raiz->izquierda->activo->id << "\" "
                << "[color=firebrick, penwidth=2];\n";
        escribirNodoDOT(raiz->izquierda, archivo);
    }

    if (raiz->derecha != nullptr) {
        archivo << "    \"" << raiz->activo->id << "\" -> \"" << raiz->derecha->activo->id << "\" "
                << "[color=royalblue, penwidth=2];\n";
        escribirNodoDOT(raiz->derecha, archivo);
    }
}

void AVL::generarAVL(string nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo DOT." << endl;
        return;
    }

    archivo << "digraph AVL {\n";
    archivo << "    node [fontname=\"Arial\", fontsize=12, shape=circle];\n";
    archivo << "    edge [fontsize=10, fontname=\"Arial\"];\n";

    escribirNodoDOT(this->raiz, archivo);

    archivo << "}\n";
    archivo.close();

    cout << "El archivo DOT ha sido generado exitosamente: " << nombreArchivo << endl;

    string comando = "dot -Tpng " + nombreArchivo + " -o avl_usuario.png";
    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << "La imagen ha sido generada exitosamente!" << endl;
    } else {
        cout << "Error al generar la imagen con Graphviz." << endl;
    }
}



void AVL::getActivos() {
    vector<Activo *> objetos;
    listActivos(this->raiz, objetos);

    for (Activo *obj : objetos) {
        cout << "ID: " << obj->id << "      Desc:" << obj->getDescripcion() << endl;

    }
}

void AVL::listActivos(NodoAVL *nodo, vector<Activo *> &objetos) {
    if (nodo == nullptr) return;

    listActivos(nodo->izquierda, objetos);
    objetos.push_back(nodo->activo);
    listActivos(nodo->derecha, objetos);
}

void AVL::setDesc(string id, string nuevaDescripcion) {
    NodoAVL *nodo = buscarActivoPorId(id, this->raiz);

    if (nodo != nullptr) {
        nodo->activo->setDescripcion(nuevaDescripcion);
        cout << "Descripción del activo con ID " << id << " ha sido actualizada." << endl;
    } else {
        cout << "Activo con ID " << id << " no encontrado." << endl;
    }
}

NodoAVL* AVL::buscarActivoPorId(string id, NodoAVL *raiz) {
    if (raiz == nullptr) {
        return nullptr;
    }

    if (id == raiz->activo->id) {
        return raiz;
    }

    if (id < raiz->activo->id) {
        return buscarActivoPorId(id, raiz->izquierda);
    } else {
        return buscarActivoPorId(id, raiz->derecha);
    }
}



void AVL::eliminarActivo(string id) {
    eliminar(id, this->raiz);
}
