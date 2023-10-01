//
// Created by srfue on 23/09/2023.
//

#ifndef TALLER1_SISTEMA_H
#define TALLER1_SISTEMA_H
#include "Cancion.h"
#include "ListaNodoCircularDoble.h"

class Sistema {
private:
    ListaNodoCircularDoble listaReproducciones;
    Cancion *listaCanciones;
    int tamanioActual;

public:
    //Sistema(ListaNodoCircularDoble listaReproducciones, Cancion* listaCanciones);
    Sistema();

    void lecturaArchivo();

    void menu();
    void Anterior();
    void Siguiente();
    void Agregar();
    void eliminar();
    void salir();
    void guardarArchivo();

};


#endif //TALLER1_SISTEMA_H
