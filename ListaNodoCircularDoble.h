//
// Lista de reproduccion
//

#ifndef TALLER1_LISTANODOCIRCULARDOBLE_H
#define TALLER1_LISTANODOCIRCULARDOBLE_H
#include "NodoDobleCircular.h"
#include <string>

class ListaNodoCircularDoble {

private:
    /**
     * Atributos de la clase lista nodo circular
     */
    NodoDobleCircular* cabeza;
    int cantCanciones;

public:

    /**
     * Constructor de la clase ListaNodoCircularDoble
     */
    ListaNodoCircularDoble();


    /**
     * Metodo para mostrar el nombre y artista de la cancion anterior, actual y siguiente de la listaReproduccion
     */
    void mostrarCanciones();


    /**
     * Metodo para agregar una cancion ingresada a la listaReproduccion mediante un nuevo nodo
     * @param cancion Cancion que se va a agregar a la listaReproduccion dentro de un Nodo nuevo
     */
    void agregar(Cancion& cancion);


    /**
     * Metodo para eliminar un nodo de la lista reproduccion segun su posicion en la lista
     * @param posCancion posicion del nodo a eliminar
     */
    void eliminar(int posCancion);


    /**
     * Metodo para mover referencia a la cabeza de la lista reproduccion al anterior nodo
     */
    void moverAnterior();


    /**
     * Metodo para mover la referencia a la cabeza de la lista reproduccion al siguiente nodo
     */
    void moverSiguiente();


    /**
     * Metodo para mostrar las canciones de la lista reproduccion
     * @return bool
     */
    bool mostrarLista();


    /**
     * Metodo para destruir cada nodo de la lista de reproduccion y liberar memoria
     */
    void destruirLista();


    /**
     * get cantidad de  canciones de la lista reproduccion
     * @return cantidad de canciones
     */
    int getCantCanciones();


    /**
     *
     * @return
     */
    NodoDobleCircular* getCabeza();

};


#endif //TALLER1_LISTANODOCIRCULARDOBLE_H
