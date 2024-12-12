cmake_minimum_required(VERSION 3.30)
project(__EDD_Proyecto1_202307272)

set(CMAKE_CXX_STANDARD 23)

add_executable(__EDD_Proyecto1_202307272 main.cpp
        includes/Usuario.h
        src/Usuario.cpp
        includes/MatrizDispersa/Nodo.h
        src/MatrizDispersa/Nodo.cpp
        includes/MatrizDispersa/MatrizDispersa.h
        src/MatrizDispersa/MatrizDispersa.cpp
)
