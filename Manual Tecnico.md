
# Manual Técnico para el Programa de Renta de Activos

Este manual describe cómo usar el programa de **Renta de Activos** para administrar usuarios y activos en un sistema basado en un menú interactivo. El programa está dividido en varias opciones de menú que permiten a los administradores y usuarios realizar diversas operaciones.

## Índice

- [Manual Técnico para el Programa de Renta de Activos](#manual-técnico-para-el-programa-de-renta-de-activos)
  - [Índice](#índice)
  - [Descripción General](#descripción-general)
  - [Funcionalidades Principales](#funcionalidades-principales)
    - [Menú Principal](#menú-principal)
      - [Flujo:](#flujo)
    - [Menú del Administrador](#menú-del-administrador)
    - [Menú del Usuario](#menú-del-usuario)
  - [Funciones Auxiliares](#funciones-auxiliares)
    - [Función para generar un código aleatorio](#función-para-generar-un-código-aleatorio)
    - [Función para limpiar la pantalla](#función-para-limpiar-la-pantalla)
    - [Función para leer una opción del menú](#función-para-leer-una-opción-del-menú)
  - [Operaciones de Usuario](#operaciones-de-usuario)
    - [Iniciar Sesión](#iniciar-sesión)
    - [Registrar Usuario](#registrar-usuario)
    - [Registrar Activo](#registrar-activo)
    - [Modificar Activo](#modificar-activo)
    - [Eliminar Activo](#eliminar-activo)
  - [Manejo de Errores](#manejo-de-errores)
  - [Requerimientos del Sistema](#requerimientos-del-sistema)

---

## Descripción General

Este programa simula un sistema de **renta de activos**, permitiendo a los administradores gestionar usuarios, activos, y transacciones. Los usuarios pueden registrarse, agregar activos, modificar y eliminar activos, entre otras operaciones. 

El sistema está dividido en dos tipos de roles: **Administrador** y **Usuario**, cada uno con un conjunto específico de permisos.

## Funcionalidades Principales

### Menú Principal

El menú principal ofrece dos opciones:

1. **Iniciar sesión**: Permite al usuario o administrador ingresar al sistema con su nombre de usuario y contraseña.
2. **Salir**: Cierra el programa.

#### Flujo:

- Ingresar al sistema.
- Si eres administrador, accederás al menú de administrador.
- Si eres un usuarios registrado, accederás al menú de usuario.

---

### Menú del Administrador

El administrador tiene acceso a varias opciones:

1. **Registrar Usuario**: Permite agregar un nuevo usuario al sistema.
2. **Reporte Matriz Dispersa**: Genera un reporte visual de la matriz dispersa de activos.
3. **Reporte Activos de un Departamento**: Muestra los activos de un departamento específico.
4. **Reporte Activos de una Empresa**: Muestra los activos de una empresa específica.
5. **Reporte Transacciones**: Genera un reporte de todas las transacciones realizadas.
6. **Reporte Activos de un Usuario**: Muestra los activos de un usuario específico.
7. **Activos rentados de un Usuario**: Muestra los activos rentados por un usuario específico.
8. **Cerrar Sesión**: Cierra la sesión del administrador.

---

### Menú del Usuario

El menú del usuario tiene las siguientes opciones:

1. **Agregar Activo**: Permite al usuario agregar un nuevo activo al sistema.
2. **Eliminar Activo**: Permite al usuario eliminar un activo.
3. **Modificar Activo**: Permite modificar los detalles de un activo registrado.
4. **Rentar Activo**: Permite al usuario rentar un activo disponible.
5. **Ver Activos Rentados**: Muestra los activos que el usuario tiene rentados.
6. **Mis Activos Rentados**: Muestra los activos que el usuario ha rentado anteriormente.
7. **Cerrar Sesión**: Cierra la sesión del usuario.

---

## Funciones Auxiliares

### Función para generar un código aleatorio

La función `generarCodigo(int longitud)` se utiliza para generar un código único para cada activo registrado. El código es una combinación aleatoria de caracteres alfanuméricos.

### Función para limpiar la pantalla

La función `limpiarPantalla()` limpia la pantalla de la consola, proporcionando una experiencia de usuario más limpia y organizada.

### Función para leer una opción del menú

La función `leerOpcion()` asegura que la entrada del usuario sea válida, repitiendo la solicitud hasta que se ingrese una opción numérica válida.

---

## Operaciones de Usuario

### Iniciar Sesión

1. El usuario debe ingresar su **nombre de usuario** y **contraseña**.
2. Si el usuario es **admin**, se le redirige al menú del administrador.
3. Si el usuario es válido en la base de datos, se le redirige al menú del usuario.

### Registrar Usuario

1. El administrador puede registrar un nuevo usuario proporcionando los detalles como el nombre completo, departamento, empresa y contraseña.
2. Si el usuario ya existe, se muestra un mensaje de error.

### Registrar Activo

1. El usuario puede registrar un activo proporcionando una descripción.
2. Un código único se genera automáticamente para el activo.

### Modificar Activo

1. El usuario puede modificar la descripción de un activo existente.

### Eliminar Activo

1. El usuario puede eliminar un activo proporcionando su ID.

---

## Manejo de Errores

Si se ingresan datos incorrectos o inválidos en cualquier paso, el programa solicitará al usuario que ingrese los datos correctamente. Si un usuario intenta realizar una acción fuera de su ámbito de permisos, se le mostrará un mensaje de error adecuado.

---

## Requerimientos del Sistema

- **Sistema Operativo**: Windows o Unix (Linux, macOS)
- **Compilador**: C++ compatible
- **Librerías**: C++ estándar, implementación de árboles AVL, manejo de matrices dispersas.

