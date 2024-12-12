#include <algorithm>
# include <iostream>
#include <cstdlib>
#include <ctime>
#include "includes/MatrizDispersa/MatrizDispersa.h"
using namespace std;

// Función para generar un código alfanumérico de longitud dada
string generarCodigo(int longitud) {
    const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string codigo;
    srand(time(nullptr)); // Inicializa la semilla para el generador de números aleatorios

    for (int i = 0; i < longitud; ++i) {
        int indice = rand() % caracteres.length();
        codigo += caracteres[indice];
    }

    return codigo;
}

void inicio();
void registrarse();

void menuAdmin() {
    int opcion;

    while (opcion != 10) {

        cout << "%%%%%%%%%%%%%%%%%%%% Administrador %%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "1. Registrar Usuario" << endl;
        cout << "2. Reporte Matriz Dispersa" << endl;
        cout << "3. Reporte Activos Disponibles de un Departamento" << endl;
        cout << "4. Reporte Activos Disponibles de una Empresa" << endl;
        cout << "5. Reporte Transacciones" << endl;
        cout << "6. Reporte Activos de un Usuario" << endl;
        cout << "7. Activos rentados por un Usuario" << endl;
        cout << "8. Ordenar Transacciones" << endl;
        cout << "9. Cerrar Sesion" << endl;

        cout << "Ingrese alguna de las siguientes opciones" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarse();
            break;
            case 2:
                cout << "Eliminar Activo \n";
            break;
            case 3:
                cout << "Modificar Activo" << endl;
            break;
            case 4:
                cout << "Rentar Activo" << endl;
            break;
            case 5:
                cout << "Activos Rentados" << endl;
            break;
            case 6:
                cout << "Mis Activos Rentados" << endl;
            break;
            case 7:
                cout << "Ordenar Transacciones" << endl;
            break;
            case 8:
                cout << "Ordenar Transacciones" << endl;
            break;
            case 9:
                inicio();
            default:
                cout << "Opcion no valida" << endl;
        }
    }

}

void menuUsuario() {
    int opcion;

    while (opcion != 8) {
        cout << "%%%%%%%%%%%%%%%%%%%% Nombre de Usuario %%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "1. Agregar Activo" << endl;
        cout << "2. Eliminar Activo" << endl;
        cout << "3. Modificar Activo" << endl;
        cout << "4. Rentar Activo" << endl;
        cout << "5. Activos Rentados" << endl;
        cout << "6. Mis Activos Rentados" << endl;
        cout << "7. Cerrar Sesion" << endl;

        cout << "Ingrese alguna de las siguientes opciones" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Agregar Activo" << endl;
            break;
            case 2:
                cout << "Eliminar Activo \n";
            break;
            case 3:
                cout << "Modificar Activo" << endl;
            break;
            case 4:
                cout << "Rentar Activo" << endl;
            break;
            case 5:
                cout << "Activos Rentados" << endl;
            break;
            case 6:
                cout << "Mis Activos Rentados" << endl;
            break;
            case 7:
                inicio();

            break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }

}

void iniciarSesion() {
    cout << "%%%%%%%%%%%%%%%%%%%% Iniciar Sesion %%%%%%%%%%%%%%%%%%%%%" << endl;
    string id;
    string contraseña;
    cout << "Ingrese su ID y contraseña" << endl;
    cout << "ID: ";
    cin >> id;
    cout << "Contraseña: ";
    cin >> contraseña;

    if (id == "admin" && contraseña == "admin") {
        cout << "Bienvenido administrador" << endl;
        menuAdmin();
    } else {
        cout << "Bienvenido " << id << endl;
        menuUsuario();
    }

}

void registrarse() {
    MatrizDispersa matriz;
    int longitud = 15;
    string nombre;
    string contraseña;
    string departamento;
    string empresa;
    string id = generarCodigo(longitud);
    cout << "Su ID es: " << id << endl;
    cout << "Ingrese su nombre:";
    cin >> nombre;
    cout << "Ingrese su contraseña:";
    cin >> contraseña;
    cout << "Ingrese su departamento:";
    cin >> departamento;
    cout << "Ingrese su empresa:";
    cin >> empresa;
    cout << "Registro exitoso" << endl;

    Usuario* usuario = new Usuario(nombre, contraseña);
    matriz.insertarUsuario(usuario, departamento, empresa);
    iniciarSesion();

}

void inicio() {
    int opcion;


    while (opcion != 4) {

        cout << "%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "1. Iniciar Sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;

        cout << "Ingrese alguna de las siguientes opciones" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                iniciarSesion();
            break;
            case 2:
                registrarse();
            break;
            case 3:
                cout << "Gracias por usar nuestro sistema" << endl;
                exit(0);
            default:
                cout << "Opcion no valida" << endl;
        }
    }
}

int main(){
    //inicio();

    MatrizDispersa matriz;
    Usuario* usuario1 = new Usuario("Juan", "1234");
    Usuario* usuario2 = new Usuario("Pedro", "1234");
    Usuario* usuario3 = new Usuario("Maria", "1234");

    matriz.insertarUsuario(usuario1, "Columna1", "Fila1");
    matriz.insertarUsuario(usuario2, "Columna2", "Fila2");
    matriz.insertarUsuario(usuario3, "Columna1", "Fila3");
}
