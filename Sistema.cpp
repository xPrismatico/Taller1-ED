//
// Created by srfue on 23/09/2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Sistema.h"
#include "ListaNodoCircularDoble.h"
#include <vector>

Sistema::Sistema(ListaNodoCircularDoble listaReproducciones, vector<Cancion*> listaCanciones) {
    this->listaReproducciones = listaReproducciones;
    this->listaCanciones = listaCanciones;
}

Sistema::Sistema() {
}

void Sistema::menu() {
    lecturaArchivo();

    string Respuesta;

    while (true){
        cout << ".:.:.:.:.: WINAMP .:.:.:.:.:" << endl;
        cout << "|" << endl;
        cout << ".:.:.:.:.: MENU .:.:.:.:.:" << endl;
        cout << "[1] Anterior" << endl;
        cout << "[2] Siguiente" << endl;
        cout << "[3] Agregar" << endl;
        cout << "[4] Eliminar" << endl;
        cout << "[5] Salir" << endl;

        cout << "Ingrese una opcion:";
        cin >> Respuesta;

        if(Respuesta == "1") {
            //Anterior(); FALLO DE MEMORIA
        }
        else if(Respuesta == "2"){
            //Siguiente();
        }
        else if(Respuesta == "3") {
            Agregar();
        }
        else if(Respuesta == "4") {
            eliminar();
        }
        else if(Respuesta == "5") {
            salir();
            return;
        }
        else {
            cout << "\n[!] Ingrese una opcion valida! \n" << endl;
        }
    }
}


void Sistema::Anterior() {
    this->listaReproducciones.moverAnterior();
}

void Sistema::Siguiente() {
    this->listaReproducciones.moverSiguiente();
}

void Sistema::Agregar() {
    string opcion;
    bool respuesta2 = false;

    while (respuesta2 == false){
        cout << ".:.:.:.:.: MENU AGREGAR .:.:.:.:.:" << endl;
        cout << "[1] Agregar una cancion al sistema" << endl;
        cout << "[2] Agregar una cancion a la lista de reproduccion" << endl;
        cout << "[3] Volver al menu anterior" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        string nombreCancion;
        if(opcion == "1"){
            // Nombre
            string nombreArtista;
            cout << "Ingresa el nombre del Artista (si son mas de 1, separarlos por comas ','):  ";
            cin >> nombreArtista;

            //
            int reproducciones;
            cout << "Ingresa la cantidad de reproducciones:  ";
            cin >> reproducciones;

            int duracionMin;
            cout << "Ingresa solo los minutos de duracion de la cancion:  ";
            cin >> duracionMin;

            int duracionSeg;
            cout << "Ingresa solo los segundos de duracion de la cancion:  ";
            cin >> duracionSeg;

            string duracion;
        }

        else if(opcion == "2"){
            cout << "Ingresa el nombre de la cancion:  ";
            cin >> nombreCancion;

            if(this->listaReproducciones.buscarCancion(nombreCancion) == true){
                cout << "La cancion ya se encuentra en la lista de reproduccion" << endl;
                return;
                }

            //nombre,artista,reproducciones,duracion

            //for(int i = 0; i < listaCancion.size(); i++){

            //}
        }

        else if(opcion == "3"){
            return;
        }
        else{
            cout << "[!] Ingresa una opcion valida !" << endl;
        }
    }


}

void Sistema::eliminar() {
    string nombreEliminar;

    NodoDobleCircular* actual = listaReproducciones.getCabeza();

    if(actual == nullptr){
        cout << "[!] la lista esta vacia"<< endl;
        return;
    }

    while(actual->getSiguiente() != listaReproducciones.getCabeza()){
        cout << "Nombre"<<actual->getCancion().getNombre()<< endl;
        cout << "Artista"<<actual->getCancion().getArtista()<< endl;
        cout << "Reproducciones"<<actual->getCancion().getReproducciones()<< endl;
        cout << "Duracion"<<actual->getCancion().getDuracion()<< endl;

        actual = actual->getSiguiente();
    }


    cout << "Ingresa el nombre de la cancion a eliminar:  ";
    cin >> nombreEliminar;

    if(this->listaReproducciones.buscarCancion(nombreEliminar) == true){
        this->listaReproducciones.eliminar(nombreEliminar);
    }
    else{
        cout<<"El nombre ingresado no esta en la lista"<<endl;
    }

}

void Sistema::salir() {
    cout << "Has salido del reproductor correctamente.";
}


void Sistema::lecturaArchivo() {
    ifstream archivo;

    archivo.open("musica.txt"); // Abrir TXT

    //ABRI EL ARCHIVO

    // Error si no está
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<< endl;
        exit(1);
    }

    // Recorrer linea por linea
    int tamanio = 0;
    string linea;
    //VOY A CREAR EL VECTOR DE CANCIONES


    //CREADO

    while (getline(archivo, linea)) {
        string nombre, artista;
        int reproducciones, duracion;

        stringstream input_ss(linea);

        getline(input_ss, nombre, ';');
        getline(input_ss, artista, ';');
        input_ss >> reproducciones;
        input_ss.ignore();
        input_ss >> duracion;

        //GUARDO ESPACIO DE MEMORIA PARA UNA CANCION NUEVA

        // Crear una nueva Cancion y agregarla al vector
        Cancion* nuevaCancion = new Cancion(nombre, artista, reproducciones, duracion);

        this->listaCanciones.push_back(nuevaCancion);
        //CANCION AÑADIDA AL VECTOR
    }
    archivo.close();

    // Canciones almacenadas en el vectorCanciones

    // Imprimir los nombres de las canciones
    for (const Cancion* cancion : this->listaCanciones) {
        cout << "Nombre de la cancion: " << cancion->getNombre() << endl;
    }
    /*
    // Liberar la memoria de las canciones al terminar
    for (Cancion* cancion : this->listaCanciones) {
        delete cancion;
    }
    */

}