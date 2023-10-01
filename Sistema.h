//
// Sistema
//

#ifndef TALLER1_SISTEMA_H
#define TALLER1_SISTEMA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "Cancion.h"
#include "ListaNodoCircularDoble.h"
#include <stdexcept>
#include <limits>
#include <string>
#include <cctype>

class Sistema {
private:
    /**
     * Atributos de la clase sistema
     */
    ListaNodoCircularDoble listaReproducciones;
    Cancion *listaCanciones;
    int tamanioActual;

public:

    /**
     * Constructor vacio de la clase sistema
     */
    Sistema();

    /**
     * Metodo que contiene la lectutra de archivo .txt
     */
    void lecturaArchivo();

    /**
     * Metodo que contiene el menu del sistema
     */
    void menu();

    /**
     * Metodo para devolverce a la cancion anterior
     */
    void Anterior();

    /**
     * Metodo para pasar a la siguiente cancion
     */
    void Siguiente();

    /**
     * Metodo para agregar una cacion a la lista de reproduccion
     */
    void Agregar();

    /**
     * Metodo para eliminar una cancion de la reproduccion
     */
    void eliminar();

    /**
     * Metodo que sobreescribe el .txt cuando acaba el sistema
     */
    void guardarArchivo();

};


#endif //TALLER1_SISTEMA_H
