//
// Created by srfue on 23/09/2023.
//

#ifndef TALLER1_LISTANODOCIRCULARDOBLE_H
#define TALLER1_LISTANODOCIRCULARDOBLE_H
#include "NodoDobleCircular.h"

class ListaNodoCircularDoble {

private:
    NodoDobleCircular* cabeza;
    int cantCanciones;

public:
    ListaNodoCircularDoble();

    void mostrarCanciones();
    void agregar(Cancion& cancion);
    void eliminar(int posCancion);

    void moverAnterior();
    void moverSiguiente();

    bool mostrarLista();
    bool buscar(int posicion);

    int getCantCanciones();
    NodoDobleCircular* getCabeza();

};


#endif //TALLER1_LISTANODOCIRCULARDOBLE_H
