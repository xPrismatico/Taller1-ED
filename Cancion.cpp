//
// Clase Cancion
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


