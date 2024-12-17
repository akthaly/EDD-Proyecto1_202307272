//
// Created by Megumi on 16/12/2024.
//

#include <fstream>
#include <string>
#include "includes/AVL/AVL.h"

void generarDOT(NodoAVL* raiz, std::ofstream& archivo) {
    if (raiz == nullptr) return;

    if (raiz->izquierda != nullptr) {
        archivo << "\"" << raiz->activo->id << "\" -> \"" << raiz->izquierda->activo->id << "\";\n";
        generarDOT(raiz->izquierda, archivo);
    }

    if (raiz->derecha != nullptr) {
        archivo << "\"" << raiz->activo->id << "\" -> \"" << raiz->derecha->activo->id << "\";\n";
        generarDOT(raiz->derecha, archivo);
    }
}

void generarArbolGraphviz(AVL* arbol, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    archivo << "digraph AVL {\n";
    archivo << "    node [shape=circle];\n";

    generarDOT(arbol->raiz, archivo);

    archivo << "}\n";
    archivo.close();

    string comando = "dot -Tpng " + nombreArchivo + " -o arbol_202307272.png";
    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << "La imagen ha sido generada exitosamente: arbol_202307272.png" << endl;
    } else {
        cout << "Error al generar la imagen con Graphviz." << endl;
    }
}
