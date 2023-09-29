//
// Created by srfue on 23/09/2023.
//

#include "Cancion.h"

Cancion::Cancion(string nombre, string artista, string reproducciones, string duracion) {
    this->nombre = nombre;
    this->artista = artista;
    this->reproducciones = reproducciones;
    this->duracion = duracion;
}

Cancion::Cancion() {
}

// GETTERS
string Cancion::getNombre() const {
    return nombre;
}
string Cancion::getArtista() {
    return artista;
}
string Cancion::getReproducciones() {
    return reproducciones;
}
string Cancion::getDuracion() {
    return duracion;
}

// SETTERS
void Cancion::setNombre(string nombre) {
    this->nombre = nombre;
}
void Cancion::setArtista(string artista){
    this->artista = artista;
}
void Cancion::setReproducciones(string reproducciones) {
    this->reproducciones = reproducciones;
}
void Cancion::setDuracion(string duracion) {
    this->duracion = duracion;
}

