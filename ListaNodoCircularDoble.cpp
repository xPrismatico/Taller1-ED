//
// Lista de reproduccion
//

#include "ListaNodoCircularDoble.h"

ListaNodoCircularDoble::ListaNodoCircularDoble() {
    this->cabeza = nullptr;
    this->cantCanciones = 0;
}
//Listo
void ListaNodoCircularDoble::mostrarCanciones(){
    if (cantCanciones == 0){
        cout << "| N.A. | N.A. | N.A |" << endl;
        cout << "| N.A. | N.A. | N.A |" << endl;
        cout << "| <|-- |  []  | --|> |" << endl;
    }
    else{
        cout << "| "<< this->cabeza->getAnterior()->getCancion().getNombre();
        cout << " | " << this->cabeza->getCancion().getNombre();
        cout << " | " << this->cabeza->getSiguiente()->getCancion().getNombre() << " |" <<endl;
        cout << "| "<< this->cabeza->getAnterior()->getCancion().getArtista();
        cout << " | " << this->cabeza->getCancion().getArtista();
        cout << " | " << this->cabeza->getSiguiente()->getCancion().getArtista() << " |" <<endl;
        cout << "| <|-- |  []  | --|> |" << endl;
    }
    return;
}
//LISTO
void ListaNodoCircularDoble::agregar(Cancion& cancion) {
    NodoDobleCircular* nodo = new NodoDobleCircular(cancion);

    // Si no hay elementos
    if(this->cabeza == nullptr){
        this->cabeza = nodo;
        this->cabeza->setSiguiente(this->cabeza);
        this->cabeza->setAnterior(this->cabeza);
        this->cantCanciones++;
        return;
    }

    // Si solo hay 1 elemento
    if(this->cabeza->getSiguiente() == this->cabeza){
        this->cabeza->setAnterior(nodo);
        this->cabeza->setSiguiente(nodo);
        nodo->setSiguiente(this->cabeza);
        nodo->setAnterior(this->cabeza);

        this->cabeza = nodo;
        this->cantCanciones++;
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

//LISTO?
void ListaNodoCircularDoble::eliminar(int posCancion) {

    // SI SE INTENTA ELIMINAR ALGO FUERA DEL ARREGLO
    if (posCancion > this->cantCanciones || posCancion <= 0){
        return;
    }

    // SI HAY 1 ELEMENTO
    if (this->cantCanciones == 1){
        this->cabeza = nullptr;
        this->cantCanciones--;
        return;
    }

    // SI LA POS COINCIDE CON EL DE LA CANCION CABEZA
    if (posCancion == 1){
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

    int posActual = 1;
    while (aux->getSiguiente() != this->cabeza){ // Voy avanzando en la lista con aux
        posActual++; // parte en 2
        if (posActual == posCancion){
            aux1->setSiguiente(aux->getSiguiente()); //Le quito la referencia al nodo a eliminar
            aux->getSiguiente()->setAnterior(aux1); //Le quito la otra referencia al nodo a eliminar
            delete aux;
            this->cantCanciones--;
            return;
        }

        aux1 = aux; // Avanzo aux1 al aux (que es el siguiente al aux1)
        aux = aux->getSiguiente(); // Avanzo
    }
    aux1->setSiguiente(aux->getSiguiente());
    aux->getSiguiente()->setAnterior(aux1);
    this->cantCanciones--;
    delete aux;
    return;
}

//LISTO
void ListaNodoCircularDoble::moverAnterior() {
    if (this->cabeza == nullptr){
        cout << "\n[!] Error: No hay ninguna cancion en la lista de reproduccion\n";
        return;
    }
    if(cantCanciones == 1) {
        cout<< "\n[!] Error: La cancion ya esta en reproduccion\n";
        return;
    }
        // MOVER CABEZA A LA SIGUIENTE
    else {
        this->cabeza = this->cabeza->getAnterior();
        return;
    }
}

//LISTO
void ListaNodoCircularDoble::moverSiguiente() {
    if (this->cabeza == nullptr){
        cout << "\n[!] Error: No hay ninguna cancion en la lista de reproduccion\n";
        return;
    }
    if(cantCanciones == 1) {
        cout<< "\n[!] Error: La cancion ya esta en reproduccion\n";
        return;
    }

    // MOVER CABEZA A LA SIGUIENTE
    else {
        this->cabeza = this->cabeza->getSiguiente();
        return;
    }

}


//TODO: Arreglar! A veces no detecta que ya esta la cancion
/*
bool ListaNodoCircularDoble::buscarCancion(string nombre) {
    if(this->cabeza == nullptr){ // si la cabeza es nula
        return false; // NO ESTÁ
    }

    if(this->cabeza->getCancion().getNombre() == nombre){
        return true; // SI ESTÁ
    }

    NodoDobleCircular* actual = this->cabeza; //auxiliar par arecorrer la lista
    while(actual->getSiguiente() != this->cabeza){
        actual = actual->getSiguiente(); //Avanza el auxiliar al siguiente
        if(actual->getCancion().getNombre() == nombre){ //Comparo el nombre de la cancion del nodo actual sea igual a la entregada
            return true; // SI ESTÁ
        }
    }
    return false; //retorna false si no lo encuentra en la lista

}
*/
bool ListaNodoCircularDoble::mostrarLista() {
    //Si no hay elementos en la lista Reproduccion
    if (this->cabeza == nullptr){
        cout << "\n[!] Error: no se encuentran canciones en la lista de reproduccion\n" << endl;
        return false;
    }

    //Si solo hay 1 elemento
    if (cantCanciones == 1){
        cout <<"[1]"<< endl;
        cout << "Nombre: " << this->cabeza->getCancion().getNombre() << endl;
        cout << "Artista: " << this->cabeza->getCancion().getArtista() << endl;
        cout << "Reproducciones: " <<this->cabeza->getCancion().getReproducciones() << endl;
        cout << "Duracion: " << this->cabeza->getCancion().getDuracion() << endl;
        cout << "-----------------" << endl;
        return true;
    }

    // Si hay mas de 1 elemento
    int actual = 1;
    NodoDobleCircular* aux = this->cabeza; //auxiliar para recorrer la lista
    // PRINT CABEZA (aux apuntando a cabeza)
    cout <<"[1]"<< endl;
    cout << "Nombre: " << aux->getCancion().getNombre() << endl;
    cout << "Artista: " << aux->getCancion().getArtista() << endl;
    cout << "Reproducciones: " << aux->getCancion().getReproducciones() << endl;
    cout << "Duracion: " << aux->getCancion().getDuracion() << endl;
    cout << "-----------------" << endl;

    // Recorrer lista printeando cada elemento hasta el final
    while(aux->getSiguiente() != this->cabeza){
        // Print los datos del siguiente al aux
        actual++;
        cout <<"["<<actual<<"]"<< endl;
        cout << "Nombre: " << aux->getSiguiente()->getCancion().getNombre() << endl;
        cout << "Artista: " << aux->getSiguiente()->getCancion().getArtista() << endl;
        cout << "Reproducciones: " << aux->getSiguiente()->getCancion().getReproducciones() << endl;
        cout << "Duracion: " <<aux->getSiguiente()->getCancion().getDuracion()<< endl;
        cout << "-----------------" << endl;
        aux = aux->getSiguiente();
    }
    return true;
}

/*
int ListaNodoCircularDoble::mostrarPosicion() {
    // Si no hay elementos en la lista
    int posicion = 0;

    if (this->cabeza == nullptr){
        cout << "\n[!] Error: no se encuentran canciones en la lista de reproduccion\n" << endl;
        return posicion;
    }

    // Si solo hay 1 elemento
    if(this->cabeza->getSiguiente() == this->cabeza){
        posicion = 1;
        return posicion;
    }

    // Si hay mas de 1 elemento
    for(NodoDobleCircular* actual = this->cabeza; actual->getSiguiente() != this->cabeza; actual->getSiguiente())
        posicion++;
        actual = actual->getSiguiente(); //Avanza el auxiliar al siguiente
    }
    return false; //retorna false si no lo encuentra en la lista

}
*/

bool ListaNodoCircularDoble::buscar(int posicion){
    //Si la lista esta vacia
    if (cantCanciones == 0){
        return false;
    }

    //Recorrer lista hasta hallar la posi
    for(int i = 1; i <= cantCanciones; i++){
        if(i == posicion){
            return true;
        }
    }
    return false;
}

int ListaNodoCircularDoble::getCantCanciones() {
    return cantCanciones;
}

NodoDobleCircular* ListaNodoCircularDoble::getCabeza() {
    return cabeza;
}
