//
// Lista de reproduccion
//

#include "ListaNodoCircularDoble.h"

ListaNodoCircularDoble::ListaNodoCircularDoble() {
    this->cabeza = nullptr;
    this->cantCanciones = 0;
}

void ListaNodoCircularDoble::mostrarCanciones(){
    if (cantCanciones == 0){
        cout << "N.A. | N.A. | N.A" << endl;
        cout << "N.A. | N.A. | N.A" << endl;
    }
    else{
        cout << "| "<< this->cabeza->getAnterior()->getCancion().getNombre();
        cout << " | " << this->cabeza->getCancion().getNombre();
        cout << " | " << this->cabeza->getSiguiente()->getCancion().getNombre() << " |" <<endl;
    }
    return;
}

void ListaNodoCircularDoble::agregar(Cancion& cancion) {
    NodoDobleCircular* nodo = new NodoDobleCircular(cancion);

    // Si no hay elementos
    if(this->cabeza == nullptr){
        this->cabeza = nodo;
        this->cabeza->setSiguiente(this->cabeza);
        this->cabeza->setAnterior(this->cabeza);
        return;
    }

    // Si solo hay 1 elemento
    if(this->cabeza->getSiguiente() == this->cabeza){
        this->cabeza->setAnterior(nodo);
        this->cabeza->setSiguiente(nodo);
        nodo->setSiguiente(this->cabeza);
        nodo->setAnterior(this->cabeza);
        this->cabeza = nodo;
        return;
    }

    // Si hay mas de 1 elemento
    NodoDobleCircular* aux = this->cabeza;
    while (aux->getSiguiente() != this->cabeza){
        aux = aux->getSiguiente();
    }

    aux->setSiguiente(nodo);
    nodo->setAnterior(aux);
    nodo->setSiguiente(this->cabeza);
    this->cabeza->setAnterior(nodo);
    this->cabeza = nodo;
    this->cantCanciones++;
    return;
}

void ListaNodoCircularDoble::eliminar(string nombreCancion) {
    // SI HAY 1 ELEMENTO
    if (this->cantCanciones == 1){
        this->cabeza = nullptr;
        this->cantCanciones--;
        return;
    }
    // SI EL NOMBRE COINCIDE CON EL DE LA CANCION CABEZA
    if (this->cabeza->getCancion().getNombre() == nombreCancion){
        // Quiero Crear auxiliar que llegue al ultimo Nodo (que apunta al final)
        NodoDobleCircular* aux = this->cabeza; // lo almaceno el head actual en un puntero
        NodoDobleCircular* borrar = this->cabeza; // lo almaceno el head actual en un puntero (para borrarlo)

        // Avanzo hasta el ultimo elemento
        while (aux->getSiguiente() != this->cabeza){
            aux = aux->getSiguiente();
        }
        // Cambio la referencia de la cabeza al siguiente de esa cabeza
        //El siguiente elemento del auxiliar (ultimo) será el siguiente de la cabeza
        aux->setSiguiente(this->cabeza->getSiguiente()); // al ultimo su Siguiente sera el siguiente del Head

        this->cabeza->getSiguiente()->setAnterior(aux); // el siguiente a la Cabeza su Anterior sera el ultimo

        this->cabeza = this->cabeza->getSiguiente(); // La cabeza ahora sera su Siguiente

        delete borrar; //borro el nodo que queria borrar al principio (antigua cabeza), y no el head actual ni el aux
        this->cantCanciones--;
        return;
    }
    // OTROS CASOS (Nodo a borrar entre medio de la lista)

    // Creo dos nodos auxiliares para eliminar el nodo que quiero eliminar
    NodoDobleCircular* aux = this->cabeza->getSiguiente();
    NodoDobleCircular* aux1 = this->cabeza;

    while (aux->getSiguiente() != this->cabeza){ // Voy avanzando en la lista con aux
        if (aux->getCancion().getNombre() == nombreCancion){ // Si el nombre de la cancion actual del aux coincide con el que busco

            aux1->setSiguiente(aux->getSiguiente()); //Le quito la referencia al nodo a eliminar
            aux->getSiguiente()->setAnterior(aux1); //Le quito la otra referencia al nodo a eliminar
            delete aux;
            this->cantCanciones--;
            return;
        }
        aux1 = aux; // Referencia Aux antiguo
        aux = aux->getSiguiente(); // Avanzo
    }

    aux1->setSiguiente(aux->getSiguiente());
    aux->getSiguiente()->setAnterior(aux1);
    this->cantCanciones--;
    return;
}

void ListaNodoCircularDoble::moverAnterior() {
    this->cabeza = this->cabeza->getAnterior();
    return;
}

void ListaNodoCircularDoble::moverSiguiente() {
    this->cabeza = this->cabeza->getSiguiente();
    return;
}


bool ListaNodoCircularDoble::buscarCancion(std::string nombre) {
    if(this->cabeza == nullptr){ // si la cabeza es nula
        return false;
    }

    NodoDobleCircular* actual = cabeza; //auxiliar par arecorrer la lista

    while(actual->getSiguiente() != this->cabeza){

        if(actual->getCancion().getNombre() == nombre){ //Comparo el nombre de la cancion del nodo actual sea igual a la entregada
            return true;
        }

        actual = actual->getSiguiente(); //Avanza el auxiliar al siguiente
    }
    return false; //retorna false si no lo encuentra
}


int ListaNodoCircularDoble::getCantCanciones() {
    return cantCanciones;
}

NodoDobleCircular* ListaNodoCircularDoble::getCabeza() {
    return cabeza;
}
