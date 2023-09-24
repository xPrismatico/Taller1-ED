//
// Created by srfue on 23/09/2023.
//

#include "Cancion.h"

Cancion::Cancion(string nombre, string artista, int reproducciones, int duracion) {
    this->nombre = nombre;
    this->artista = artista;
    this->reproducciones = reproducciones;
    this->duracion = duracion;
}

Cancion::Cancion() {
}

string Cancion::getNombre() const {
    return nombre;
}
string Cancion::getArtista() {
    return artista;
}
int Cancion::getReproducciones() {
    return reproducciones;
}
int Cancion::getDuracion() {
    return duracion;
}


void Cancion::setNombre(string nombre) {
    this->nombre = nombre;
}
void Cancion::setArtista(string artista){
    this->artista = artista;
}
void Cancion::setReproducciones(int reproducciones) {
    this->reproducciones = reproducciones;
}
void Cancion::setDuracion(int duracion) {
    this->duracion = duracion;
}

