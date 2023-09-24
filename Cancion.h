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
    int reproducciones;
    int duracion;

public:
    Cancion(string nombre, string artista, int reproducciones, int duracion);
    Cancion();

    string getNombre() const;
    string getArtista();
    int getReproducciones();
    int getDuracion();

    void setNombre(string nombre);
    void setArtista(string artista);
    void setReproducciones(int reproducciones);
    void setDuracion(int duracion);

};


#endif //TALLER1_CANCION_H
