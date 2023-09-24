//
// Created by srfue on 23/09/2023.
//

#ifndef TALLER1_NODODOBLECIRCULAR_H
#define TALLER1_NODODOBLECIRCULAR_H

#include "Cancion.h"
#include <string>

class NodoDobleCircular{

private:
    Cancion cancion;
    NodoDobleCircular* siguiente;
    NodoDobleCircular* anterior;
public:
    NodoDobleCircular(Cancion& cancion);

    void setCancion(Cancion& cancion);

    void setSiguiente(NodoDobleCircular* nodo);

    void setAnterior(NodoDobleCircular* nodo);

    Cancion getCancion();

    NodoDobleCircular* getSiguiente();

    NodoDobleCircular* getAnterior();
};


#endif //TALLER1_NODODOBLECIRCULAR_H
