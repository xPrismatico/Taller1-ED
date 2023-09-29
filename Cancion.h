//
// Created by srfue on 23/09/2023.
//

#ifndef TALLER1_CANCION_H
#define TALLER1_CANCION_H
using namespace std;
#include <iostream>
#include <string>

class Cancion {

private:
    string nombre;
    string artista;
    string reproducciones;
    string duracion;

public:
    Cancion(string nombre, string artista, string reproducciones, string duracion);
    Cancion();

    string getNombre() const;
    string getArtista();
    string getReproducciones();
    string getDuracion();

    void setNombre(string nombre);
    void setArtista(string artista);
    void setReproducciones(string reproducciones);
    void setDuracion(string duracion);

};
#endif //TALLER1_CANCION_H
