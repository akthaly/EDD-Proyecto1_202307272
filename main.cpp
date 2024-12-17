#include <iostream>
#include <cstdlib>
#include <ctime>
#include "includes/MatrizDispersa/MatrizDispersa.h"
#include "includes/Usuario.h"
#include "includes/Activo.h"
#include "includes/AVL/AVL.h"

using namespace std;


MatrizDispersa *matriz;


void menuPrincipal();

void menuAdmin();

void menuUsuario(const string &nombre);

void iniciarSesion();

void registrar();

void registrarActivo(Nodo *usuario);

void eliminarActivo(Nodo *usuario);

void modificarActivo(Nodo *usuario);

void imprimirAVL();

// Función para generar un código aleatorio
string generarCodigo(int longitud) {
    const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string codigo;
    for (int i = 0; i < longitud; ++i) {
        int indice = rand() % caracteres.length();
        codigo += caracteres[indice];
    }
    return codigo;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
        system("clear");
#endif
}

int leerOpcion() {
    int opcion;
    while (!(cin >> opcion)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada no valida. Por favor, ingrese un numero: ";
    }
    return opcion;
}

void menuPrincipal() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Salir\n";
        cout << "Ingrese una opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                iniciarSesion();
                break;
            case 2:
                cout << "Gracias por usar nuestro sistema. Hasta pronto.\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}

void menuAdmin() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "%%%%%%%%%%%%%%%%%%%% Administrador %%%%%%%%%%%%%%%%%%%%%\n";
        cout << "1. Registrar Usuario\n";
        cout << "2. Reporte Matriz Dispersa\n";
        cout << "3. Reporte Activos de un Departamento\n";
        cout << "4. Reporte Activos de una Empresa\n";
        cout << "5. Reporte Transacciones\n";
        cout << "6. Reporte Activos de un Usuacio.\n";
        cout << "7. Activos rentados de un Usuacio.\n";
        cout << "8. Cerrar Sesion\n";
        cout << "Ingrese una opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                cout << "Generando reporte de Matriz Dispersa...\n";
                matriz->generarImagenMatriz("matrizDispersa");
                break;
            case 3:
                cout << "Reporte de activos de un departamento...\n";
                break;
            case 4:
                cout << "Reporte de activos de una empresa...\n";
                break;
            case 5:
                cout    << "Reporte de transacciones...\n";
                break;
            case 6:
                cout << "Reporte de activos de un usuario...\n";
                imprimirAVL();
                break;
            case 7:
                cout << "Activos rentados de un usuario...\n";
                break;
            case 8:
                cout << "Cerrando sesion...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
        if (opcion != 8) {
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 8);
}

void imprimirAVL() {
    limpiarPantalla();
    cout << "%%%%%%%%%%%%%%%%%%%% Reporte de Activos %%%%%%%%%%%%%%%%%%%%%\n";
    cout << "Ingrese el nombre del usuario: ";
    string username;
    cin >> username;

    auto usuarioEncontrado = matriz->buscarUsuario(username);
    if (usuarioEncontrado != nullptr) {
        usuarioEncontrado->nuevoUsuario->avlActivos.generarAVL("avl_usuario.dot");
    }

}

void menuUsuario(Nodo *usuario) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "%%%%%%%%%%%%%%% Bienvenido, " << usuario->nuevoUsuario->getNombre() << " %%%%%%%%%%%%%%%\n";
        cout << "1. Agregar Activo\n";
        cout << "2. Eliminar Activo\n";
        cout << "3. Modificar Activo\n";
        cout << "4. Rentar Activo\n";
        cout << "5. Ver Activos Rentados\n";
        cout << "6. Mis Activos Rentados\n";
        cout << "7. Cerrar Sesion\n";
        cout << "Ingrese una opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                cout << "Agregar Activo...\n";
            registrarActivo(usuario);
            break;
            case 2:
                cout << "Eliminar Activo...\n";
            eliminarActivo(usuario);
            break;
            case 3:
                cout << "Modificar Activo...\n";
            modificarActivo(usuario);
            break;
            case 4:
                cout << "Rentar Activo...\n";
            //rentarActivo(usuario);
            break;
            case 5:
                cout << "Ver Activos Rentados...\n";
            //mostrarActivosRentados(usuario);
            break;
            case 6:
                cout << "Mis Activos Rentados...\n";
            //istarMisActivosRentados(usuario);
            break;
            case 7:
                cout << "Cerrando sesion...\n";
            break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }

        if (opcion != 7) {
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 7);
}


void modificarActivo(Nodo *usuario) {
    limpiarPantalla();
    cout <<
            "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Modificar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "-------------------" << "Activos disponibles de:" << usuario->nuevoUsuario->getNombre() <<
            "-------------------\n";
    usuario->nuevoUsuario->avlActivos.getActivos();
    cout <<
            "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\n";
    string id, nuevaDescripcion;
    cout << "Ingrese el ID del activo a modificar: ";
    cin >> id;
    cout << "Ingrese la nueva descripcion: ";
    cin >> nuevaDescripcion;


    usuario->nuevoUsuario->avlActivos.setDesc(id, nuevaDescripcion);
    cout << "Activo modificado exitosamente.\n";
    cout << "Presione Enter para regresar al menu...";
    cin.ignore();
    cin.get();
}

void eliminarActivo(Nodo *usuario) {
    limpiarPantalla();
    cout <<
            "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Eliminar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "-------------------" << "Activos disponibles de:" << usuario->nuevoUsuario->getNombre() <<
            "-------------------\n";
    usuario->nuevoUsuario->avlActivos.getActivos();
    cout <<
            "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\n";
    string id;
    cout << "Ingrese el ID del activo a eliminar: ";
    cin >> id;

    usuario->nuevoUsuario->eliminarActivo(id);
    cout << "Activo eliminado exitosamente.\n";
    cout << "Presione Enter para regresar al menu...";
    cin.ignore();
    cin.get();
}

void registrarActivo(Nodo *usuario) {
    limpiarPantalla();
    cout << "%%%%%%%%%%%%%%%%%%%% Registrar Activo %%%%%%%%%%%%%%%%%%%%%\n";
    int longitud = 15;
    string descripcion;;
    string id = generarCodigo(longitud);
    cout << "Su ID es: " << id << endl;
    cout << "Ingrese la descripcion del activo: ";
    cin >> descripcion;

    Activo *nuevoActivo = new Activo(id, descripcion);
    usuario->nuevoUsuario->agregarActivo(nuevoActivo);
    cout << "Activo registrado exitosamente.\n";
    cout << "Presione Enter para regresar al menu...";
    cin.ignore();
    cin.get();
}

void iniciarSesion() {
    limpiarPantalla();
    cout << "%%%%%%%%%%%%%%%%%%%% Iniciar Sesion %%%%%%%%%%%%%%%%%%%%%\n";
    string username, contraseña;
    cout << "Nombre: ";
    cin >> username;
    cout << "Contraseña: ";
    cin >> contraseña;

    if (username == "admin" && contraseña == "admin") {
        cout << "Bienvenido Administrador.\n";
        menuAdmin();
    } else if (matriz != nullptr && matriz->iniciarSesion(username, contraseña)) {
        cout << "Sesion iniciada correctamente.\n";
        auto usuarioEncontrado = matriz->buscarUsuario(username);
        if (usuarioEncontrado != nullptr) {
            menuUsuario(usuarioEncontrado);
        }
    } else {
        cout << "Error: Usuario o contraseña incorrecta.\n";
    }
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void registrar() {
    limpiarPantalla();
    cout << "%%%%%%%%%%%%%%%%%%%% Registrar Usuario %%%%%%%%%%%%%%%%%%%%%\n";
    string username, nombreCompleto, contraseña, departamento, empresa;

    cout << "Ingrese el username: ";
    cin >> username;
    cout << "Ingrese el nombre completo: ";
    cin.ignore();
    getline(cin, nombreCompleto);
    cout << "Ingrese la contraseña: ";
    cin >> contraseña;
    cout << "Ingrese el departamento: ";
    cin >> departamento;
    cout << "Ingrese la empresa: ";
    cin >> empresa;

    if (matriz->verificarExistenciaUsuario(username, departamento, empresa)) {
        cout << "Error: El usuario ya existe.\n";
    } else {
        Usuario *nuevoUsuario = new Usuario(username, nombreCompleto, contraseña);
        matriz->insertarUsuario(nuevoUsuario, departamento, empresa);
        cout << "Usuario registrado exitosamente.\n";
    }

    cout << "Presione Enter para regresar al menu...";
    cin.ignore();
    cin.get();
}

int main() {
    srand(time(nullptr));
    matriz = new MatrizDispersa();
    menuPrincipal();
    delete matriz;
    return 0;
}
