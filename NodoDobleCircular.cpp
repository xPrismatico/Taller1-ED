//
// Created by srfue on 23/09/2023.
//
#include "Cancion.h"
#include "NodoDobleCircular.h"


NodoDobleCircular::NodoDobleCircular(Cancion& cancion){
    this->cancion = cancion;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}


void NodoDobleCircular::setCancion(Cancion& cancion) {
    this->cancion = cancion;
}

void NodoDobleCircular::setSiguiente(NodoDobleCircular* nodo) {
    this->siguiente = nodo;
}

void NodoDobleCircular::setAnterior(NodoDobleCircular* nodo) {
    this->anterior = nodo;
}



Cancion NodoDobleCircular::getCancion() {
    return this->cancion;
}

NodoDobleCircular* NodoDobleCircular::getSiguiente() {
    return this->siguiente;
}

NodoDobleCircular* NodoDobleCircular::getAnterior() {
    return this->anterior;
}