//
// Created by Megumi on 11/12/2024.
//
#include "../../includes/MatrizDispersa/MatrizDispersa.h"
#include "../../includes/MatrizDispersa/Nodo.h"
#include <fstream>  // Para manejar archivos
#include <sstream>  // Para generar contenido de archivo
#include <cstdlib>  // Para usar la función system()


MatrizDispersa::MatrizDispersa() {
    this->cabH = nullptr;
    this->cabV = nullptr;
}

void MatrizDispersa::insertarUsuario(Usuario *nuevoUsuario, std::string cabH, std::string cabV) {
    Nodo *cabHor = nullptr;
    Nodo *cabVer = nullptr;

    Nodo *usuarioNuevo = new Nodo(*nuevoUsuario);
    // Se crea un nuevo nodo con el usuario que se va a insertar siempre desde acá para que no se duplique.

    // CASO 1
    if (esVacia()) {
        cabHor = insertarCabeceraH(cabH);
        cabVer = insertarCabeceraV(cabV);

        insertarAlFinal(usuarioNuevo, cabHor, cabVer);

        return;
    }

    // Si la matriz no está vacía
    cabHor = cabHorizontal(cabH);
    cabVer = cabVertical(cabV);

    // Si no existe la cabecera horizontal ni la vertical
    // CASO 2
    if (cabHor == nullptr && cabVer == nullptr) {

        cabHor = insertarCabeceraH(cabH);
        cabVer = insertarCabeceraV(cabV);

        insertarAlFinal(usuarioNuevo, cabHor, cabVer);

        return;
    }

    if (cabHor != nullptr && cabVer != nullptr) {
        insertarUsuarioProfuncidad(usuarioNuevo, cabH, cabV);
        return;
    }


    // Si no existe la cabecera horizontal pero sí la vertical
    //CASO 3
    if (cabHor == nullptr) {
        cabHor = insertarCabeceraH(cabH);
        insertarAlFinal(usuarioNuevo, cabHor, cabVer);

        return;
    }

    // Si no existe la cabecera vertical pero sí la horizontal
    //CASO 4
    if (cabVer == nullptr) {
        cabVer = insertarCabeceraV(cabV);
        insertarAlFinal(usuarioNuevo, cabHor, cabVer);

        return;
    }

    // CASO 5
    Nodo *tempH = cabHor->abajo;
    Nodo *usuarioCabV;
    bool abajo;

    while (tempH != nullptr) {
        usuarioCabV = enCabV(tempH);
        abajo = masAbajo(usuarioCabV, cabH);

        if (!abajo) break;

        tempH = tempH->abajo;
    }

    if (abajo) {
        insertarAlFinalHorizontal(usuarioNuevo, cabHor);
    } else {
        insertarAlMedioEnHorizontal(usuarioNuevo, tempH);
    }

    Nodo *tempV = cabVer->sig;
    Nodo *usuarioCabH;
    bool derecha = false;

    while (tempV != nullptr) {
        usuarioCabH = enCabH(tempV);
        derecha = masDerecha(usuarioCabH, cabV);

        if (!derecha) break;

        tempV = tempV->sig;
    }

    if (derecha) {
        insertarAlFinalVertical(usuarioNuevo, cabVer);
    } else {
        insertarAlMedioEnVertical(usuarioNuevo, tempV);
    }

}

Nodo* MatrizDispersa::busquedaDeNodo(std::string cabH, std::string cabV) {
    Nodo* cabeceraH = cabHorizontal(cabH);
    Nodo* cabeceraV = cabVertical(cabV);

    Nodo* actual = cabeceraH->abajo;
    while (actual != nullptr) {

        Nodo* temp = actual;
        while (temp != nullptr) {
            if (temp == cabeceraV) {
                return actual; // aqui encontré el nodo
            }
            temp = temp->ant;
        }
        actual = actual->abajo;
    }

    return nullptr;
}

bool MatrizDispersa::verificarExistenciaUsuario(std::string username, std::string cabHorizo, std::string cabVert) {
    Nodo* cabeceraH = cabHorizontal(cabHorizo);
    Nodo* cabeceraV = cabVertical(cabVert);

    if (cabeceraH == nullptr || cabeceraV == nullptr) {
        return false;
    }
    Nodo* nodoExistente = busquedaDeNodo(cabHorizo, cabVert);

    if (nodoExistente == nullptr) {
        return false;
    }
    if (nodoExistente) {
        if (verificarExt( username)) {
            return true;
        }
        return false;
    }
}

bool MatrizDispersa::verificarExt(std::string username) {
    Nodo* tempH = cabH;

    while (tempH != nullptr) {
        Nodo* tempV = tempH->abajo;

        while (tempV != nullptr) {
            Nodo* tempProfundidad = tempV;

            while (tempProfundidad != nullptr) {
                if (tempProfundidad->nuevoUsuario != nullptr) {
                    if (tempProfundidad->nuevoUsuario->getUsername() == username) {
                        return true;
                        }
                }
                tempProfundidad = tempProfundidad->atras;
            }

            tempV = tempV->sig;
        }
        tempH = tempH->sig;
    }

    return false;  // No se encontraron credenciales correctas.
}


void MatrizDispersa::insertarUsuarioProfuncidad(Nodo* nuevoUsuario, std::string cabH, std::string cabV) {

    Nodo* nodoExistente = busquedaDeNodo(cabH, cabV);

    if (!nodoExistente) {
        std::cerr << "Error: No hay nodo en la intersección de las cabeceras." << std::endl;
        return;
    }


    nuevoUsuario->adelante = nodoExistente;
    nuevoUsuario->atras = nodoExistente->atras;


    if (nodoExistente->atras != nullptr) {
        nodoExistente->atras->adelante = nuevoUsuario;
    }

    nodoExistente->atras = nuevoUsuario;
}


void MatrizDispersa::insertarAlFinal(Nodo *nuevoUsuario, Nodo *cabH, Nodo *cabV) {
    insertarAlFinalHorizontal(nuevoUsuario, cabH);
    insertarAlFinalVertical(nuevoUsuario, cabV);
}

void MatrizDispersa::insertarAlFinalHorizontal(Nodo *nuevoUsuario, Nodo *cabH) {
    Nodo *temp = cabH; // la cabH que se pasa por parametro

    while (temp->abajo != nullptr) {
        temp = temp->abajo;
    }

    temp->abajo = nuevoUsuario;
    nuevoUsuario->arriba = temp;
}

void MatrizDispersa::insertarAlFinalVertical(Nodo *nuevoUsuario, Nodo *cabV) {
    Nodo *temp = cabV; // la cabV que se pasa por parametro

    while (temp->sig != nullptr) {
        temp = temp->sig;
    }

    temp->sig = nuevoUsuario;
    nuevoUsuario->ant = temp;
}

void MatrizDispersa::insertarAlMedioEnVertical(Nodo *nuevoUsuario, Nodo *vertical) {
    vertical->ant->sig = nuevoUsuario;
    nuevoUsuario->sig = vertical;
    nuevoUsuario->ant = vertical->ant;
    vertical->ant = nuevoUsuario;
}

void MatrizDispersa::insertarAlMedioEnHorizontal(Nodo *nuevoUsuario, Nodo *horizontal) {
    horizontal->arriba->abajo = nuevoUsuario;
    nuevoUsuario->abajo = horizontal;
    nuevoUsuario->arriba = horizontal->arriba;
    horizontal->arriba = nuevoUsuario;
}

Nodo *MatrizDispersa::enCabH(Nodo *nodo) {
    Nodo *temp = nodo;
    while (temp->arriba != nullptr) {
        temp = temp->arriba;
    }
    return temp;
}

Nodo *MatrizDispersa::enCabV(Nodo *nodo) {
    Nodo *temp = nodo;
    while (temp->ant != nullptr) {
        temp = temp->ant;
    }
    return temp;
}

bool MatrizDispersa::masAbajo(Nodo *cabVer, string cabV) {
    Nodo *temp = cabVer;

    while (temp != nullptr) {
        if (temp->nomCabecera == cabV) {
            return true;
        }

        temp = temp->abajo;
    }

    return false;
}

bool MatrizDispersa::masDerecha(Nodo *cabHor, string cabH) {
    Nodo *temp = cabHor;

    while (temp != nullptr) {
        if (temp->nomCabecera == cabH) {
            return true;
        }

        temp = temp->sig;
    }

    return false;
}


bool MatrizDispersa::esVacia() {
    // devuelve verdadero si la matriz está vacía (no hay nodos)
    return this->cabH == nullptr && this->cabV == nullptr;
}

Nodo *MatrizDispersa::cabHorizontal(std::string nomCabecera) {
    if (esVacia()) {
        return nullptr;
    }

    Nodo *temp = cabH;

    while (temp != nullptr) {
        if (temp->nomCabecera == nomCabecera) {
            return temp;
        }
        temp = temp->sig;
    }
    return nullptr;
}

Nodo *MatrizDispersa::insertarCabeceraH(string nomCabecera) {
    Nodo *nuevaCabecera = new Nodo(nomCabecera);

    if (this->cabH == nullptr) {
        //se puso this-> para que no haya ambigüedad con la variable cabH
        this->cabH = nuevaCabecera;
        return nuevaCabecera;
    }
    // este nodo tempiliar se crea después del if para no crear un registro de memoria innecesario
    Nodo *temp = cabH;
    // si la cabecera horizontal está vacía se inserta la nueva cabecera
    while (temp->sig != nullptr) temp = temp->sig;

    temp->sig = nuevaCabecera;
    nuevaCabecera->ant = temp;

    return nuevaCabecera;
}

Nodo *MatrizDispersa::insertarCabeceraV(std::string nomCabecera) {
    Nodo *nuevaCabecera = new Nodo(nomCabecera);

    if (this->cabV == nullptr) {
        // se puso this-> para que no haya ambigüedad con la variable cabV
        this->cabV = nuevaCabecera;
        return nuevaCabecera;
    }
    // este nodo tempiliar se crea después del If para no crear un registro de memoria innecesario
    Nodo *temp = cabV;
    // si la cabecera vertical está vacía se inserta la nueva cabecera
    while (temp->abajo != nullptr) temp = temp->abajo;

    temp->abajo = nuevaCabecera;
    nuevaCabecera->arriba = temp;

    return nuevaCabecera;
}


Nodo *MatrizDispersa::cabVertical(std::string nomCabecera) {
    if (esVacia()) {
        return nullptr;
    }

    Nodo *temp = cabV;

    while (temp != nullptr) {
        if (temp->nomCabecera == nomCabecera) {
            return temp;
        }
        temp = temp->abajo;
    }
    return nullptr;
}

bool MatrizDispersa::iniciarSesion(std::string username, std::string contraseña) {

    Nodo* tempH = cabH;


    while (tempH != nullptr) {
        Nodo* tempV = tempH->abajo;


        while (tempV != nullptr) {
            Nodo* tempProfundidad = tempV;


            while (tempProfundidad != nullptr) {
                if (tempProfundidad->nuevoUsuario != nullptr) {

                    if (tempProfundidad->nuevoUsuario->getUsername() == username &&
                        tempProfundidad->nuevoUsuario->getContraseña() == contraseña) {
                        return true; // credenciales correctas
                        }
                }
                tempProfundidad = tempProfundidad->atras;
            }

            tempV = tempV->sig;
        }
        tempH = tempH->sig;
    }

    return false;
}

Nodo* MatrizDispersa::buscarUsuario(string username) {
    if (this->cabH == nullptr) {
        return nullptr;
    }

    Nodo* cabeceraHorizontalActual = this->cabH;


    while (cabeceraHorizontalActual != nullptr) {
        Nodo* nodoActual = cabeceraHorizontalActual->abajo;


        while (nodoActual != nullptr) {
            Nodo* nodoProfun = nodoActual;


            while (nodoProfun != nullptr) {
                if (nodoProfun->nuevoUsuario != nullptr) {

                    if (nodoProfun->nuevoUsuario->getUsername() == username) {
                        return nodoProfun;
                        }
                }
                nodoProfun = nodoProfun->atras;
            }
            nodoActual = nodoActual->abajo;
        }
        cabeceraHorizontalActual = cabeceraHorizontalActual->sig;
    }

    return nullptr;
}

void MatrizDispersa::generarImagenMatriz(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo); // Crear archivo .dot
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    archivo << "digraph MatrizDispersa {" << std::endl;
    archivo << "    rankdir=TB;" << std::endl; // Dirección del gráfico (Top-Bottom)
    archivo << "    node [shape=box, style=filled, color=lightblue];" << std::endl;

    // Generar nodos de cabeceras horizontales
    Nodo* tempH = this->cabH;
    while (tempH != nullptr) {
        archivo << "    \"" << tempH->nomCabecera << "\" [label=\"H: " << tempH->nomCabecera << "\"];" << std::endl;
        tempH = tempH->sig;
    }

    // Generar nodos de cabeceras verticales
    Nodo* tempV = this->cabV;
    while (tempV != nullptr) {
        archivo << "    \"" << tempV->nomCabecera << "\" [label=\"V: " << tempV->nomCabecera << "\"];" << std::endl;
        tempV = tempV->abajo;
    }

    // Generar conexiones horizontales
    tempH = this->cabH;
    while (tempH != nullptr) {
        if (tempH->sig != nullptr) {
            archivo << "    \"" << tempH->nomCabecera << "\" -> \"" << tempH->sig->nomCabecera << "\";" << std::endl;
        }
        tempH = tempH->sig;
    }

    // Generar conexiones verticales
    tempV = this->cabV;
    while (tempV != nullptr) {
        if (tempV->abajo != nullptr) {
            archivo << "    \"" << tempV->nomCabecera << "\" -> \"" << tempV->abajo->nomCabecera << "\";" << std::endl;
        }
        tempV = tempV->abajo;
    }

    // Generar nodos y conexiones de la matriz dispersa
    tempH = this->cabH;
    while (tempH != nullptr) {
        Nodo* temp = tempH->abajo;
        while (temp != nullptr) {
            archivo << "    \"" << temp->nomCabecera << "_" << temp << "\" [label=\"Nodo\"];" << std::endl;
            archivo << "    \"" << tempH->nomCabecera << "\" -> \"" << temp->nomCabecera << "_" << temp << "\";" << std::endl;
            temp = temp->abajo;
        }
        tempH = tempH->sig;
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo DOT generado: " << nombreArchivo << std::endl;
}