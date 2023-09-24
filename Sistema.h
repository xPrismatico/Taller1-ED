//
// Created by srfue on 23/09/2023.
//

#ifndef TALLER1_SISTEMA_H
#define TALLER1_SISTEMA_H
#include "Cancion.h"
#include "ListaNodoCircularDoble.h"
#include <vector>

class Sistema {
private:
    ListaNodoCircularDoble listaReproducciones;
    // Crear un vector de punteros a Cancion
    vector<Cancion*> listaCanciones;

public:
    Sistema(ListaNodoCircularDoble listaReproducciones, vector<Cancion*> listaCanciones);
    Sistema();

    void lecturaArchivo();

    void menu();
    void Anterior();
    void Siguiente();
    void Agregar();
    void eliminar();
    void salir();
};


#endif //TALLER1_SISTEMA_H
