//
// Clase NodoDobleCircular
//

#ifndef TALLER1_NODODOBLECIRCULAR_H
#define TALLER1_NODODOBLECIRCULAR_H

#include "Cancion.h"
#include <string>

class NodoDobleCircular{

private:
    /**
     * Atributos de la clase nodo
     */
    Cancion cancion;
    NodoDobleCircular* siguiente;
    NodoDobleCircular* anterior;

public:

    /**
     * Metodo para reemplazar la cancion de un nodo por otra cancion ingresada
     * @param cancion Nueva cancion se le establece al nodo que invoca este metodo
     */
    void setCancion(Cancion& cancion);


    /**
     * Metodo para establecer a un nodo ingresado como siguiente a otro nodo
     * @param nodo Nodo que se establece como el siguiente al nodo que invoca este metodo
     */
    void setSiguiente(NodoDobleCircular* nodo);


    /**
     * Metodo para establecer a un nodo ingresado como anterior a otro nodo
     * @param nodo Nodo que se establece como el anterior al nodo que invoca este metodo
     */
    void setAnterior(NodoDobleCircular* nodo);


    /**
     * Metodo para obtener la Cancion del nodo
     * @return Cancion
     */
    Cancion getCancion();


    /**
     * Metodo para obtener el nodo siguiente al nodo que invoca este metodo
     * @return NodoDobleCircular*
     */
    NodoDobleCircular* getSiguiente();


    /**
     * Metodo para obtener el nodo anterior al nodo que invoca este metodo
     * @return NodoDobleCircular*
     */
    NodoDobleCircular* getAnterior();


    /**
     * Constructor de la clase NodoDobleCiruclar
     * @param cancion Clase Cancion que se guarda en el NodoDobleCircular
     */
    NodoDobleCircular(Cancion& cancion);
};


#endif //TALLER1_NODODOBLECIRCULAR_H
