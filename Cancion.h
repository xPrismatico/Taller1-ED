//
// Clase Cancion
//

#ifndef TALLER1_CANCION_H
#define TALLER1_CANCION_H
using namespace std;
#include <iostream>
#include <string>

class Cancion {

private:
    /**
     * Atributos de la clase cancion
     */
    string nombre;
    string artista;
    string reproducciones;
    string duracion;

public:
    /**
     *Constructor de la case cancion utilizado para crear canciones
     * @param nombre de la cancion
     * @param artista (artistas) de la cancion
     * @param reproducciones de la cancion
     * @param duracion de la cancion
     */
    Cancion(string nombre, string artista, string reproducciones, string duracion);

    /**
     *Constructor vacio de la clase cancion
     */
    Cancion();

    /**
     * get nombre
     * @return Nombre Artista
     */
    string getNombre() const;

    /**
     * get artista
     * @return Artista de la cancion
     */
    string getArtista();

    /**
     * get reproducciones
     * @return cantidad de reproducciones
     */
    string getReproducciones();

    /**
     * get duracion
     * @return Duracion de la cancion
     */
    string getDuracion();


};
#endif //TALLER1_CANCION_H
