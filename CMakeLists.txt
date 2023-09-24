cmake_minimum_required(VERSION 3.26)
project(Taller1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Taller1 main.cpp
        Cancion.cpp
        Cancion.h
        NodoDobleCircular.cpp
        NodoDobleCircular.h
        ListaNodoCircularDoble.cpp
        ListaNodoCircularDoble.h
        Sistema.cpp
        Sistema.h
        cmake-build-debug/musica.txt
)
