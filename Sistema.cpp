
#include <iostream>
#include <fstream>
#include <sstream>
#include "Sistema.h"
#include "ListaNodoCircularDoble.h"
//#include <windows.h> // libreria para hacer un Sleep y esperar en una linea X milisegundos

/*
Sistema::Sistema(ListaNodoCircularDoble listaReproducciones, Cancion* listaCanciones, int cantCanciones) {
    this->listaReproducciones = listaReproducciones;
    this->listaCanciones = listaCanciones;
    this->cantCanciones = cantCanciones;
}
*/
Sistema::Sistema() {
}

void Sistema::menu() {
    lecturaArchivo();

    // MENU
    string Respuesta;
    while (true){
        cout << ".:.:.:.:.: WINAMP .:.:.:.:.:" << endl;
        listaReproducciones.mostrarCanciones();
        cout << ".:.:.:.:.: MENU .:.:.:.:.:" << endl;
        cout << "[1] Anterior" << endl;
        cout << "[2] Siguiente" << endl;
        cout << "[3] Agregar" << endl;
        cout << "[4] Eliminar" << endl;
        cout << "[5] Salir" << endl;

        cout << "Ingrese una opcion:";
        cin >> Respuesta;

        if(Respuesta == "1") {
            //Anterior();
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

    // MENU AGREGAR
    while (true){
        cout << ".:.:.:.:.: MENU AGREGAR .:.:.:.:.:" << endl;
        cout << "[1] Agregar una cancion al sistema" << endl;
        cout << "[2] Agregar una cancion a la lista de reproduccion" << endl;
        cout << "[3] Volver al menu anterior" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if(opcion == "1"){ // AGREGAR CANCION AL SISTEMA
            // Nombre Cancion
            string nombreCancion;
            cout << "Ingresa el nombre de la canción";
            cin >> nombreCancion;

            // Nombre Artista
            string nombreArtista;
            cout << "Ingresa el nombre del Artista (si son mas de 1, separarlos por comas ','):  ";
            cin >> nombreArtista;

            //Cant Reproducciones
            int reproducciones;
            cout << "Ingresa la cantidad de reproducciones:  ";
            cin >> reproducciones;

            // Duracion (min:seg)
            int duracion;
            cout << "Ingresa los minutos y segundos de duracion de la cancion en el formato (mm:ss):  ";
            cin >> duracion;

            //string duracion = (int)duracionMin + ":" + duracionSeg;


            //Cancion* agregarCancion = new Cancion(nombreCancion, nombreArtista, reproducciones, duracion);
            /*
            tamanio++;

            // Redimensionar listaCanciones con el Nuevo tamanio
            listaCanciones = (Cancion*)realloc(listaCanciones,tamanio*sizeof(Cancion));

            // Guardar nueva Cancion en la listaCanciones
            listaCanciones[tamanio-1] = *agregarCancion;
            */

            //Sleep(3000); // Se debe calcular a seguikndos y hacer la espera, se hace con la libreria #include <windows.h>
        }

        // AGREGAR CANCION A LA LISTA REPRODUCCIONES
        else if(opcion == "2"){
            string nombreCancion;
            cout << "Ingresa el nombre de la cancion:  ";
            cin >> nombreCancion;

            if(this->listaReproducciones.buscarCancion(nombreCancion) == true){ // compara que la cancion no se encuentre en la lista
                cout << "La cancion ya se encuentra en la lista de reproduccion" << endl;
                return;
            }
            for(int i=1; i<=tamanioActual-1; i++){
                if (listaCanciones[i].getNombre() == nombreCancion) { //compara el nombre de la cancion en la poscion tamanio con el entregado por pantalla
                    listaReproducciones.agregar(listaCanciones[i]); // agrega la cancion que esta en una lista a la otra
                    cout << "La cancion "<< listaReproducciones.getCabeza()->getCancion().getNombre() <<" ha sido agregada exitosamente." << endl;
                }
            }
        }
        else if(opcion == "3"){
            return;
        }
        else{
            cout << "\n[!] Ingresa una opcion valida !" << endl;
        }
    }

}

void Sistema::eliminar() {
    string nombreEliminar;
    NodoDobleCircular* actual = listaReproducciones.getCabeza();

    if(actual == nullptr){
        cout << "[!] La lista esta vacia"<< endl;
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


/**
 * LECTURA DE ARCHIVO
 */

void Sistema::lecturaArchivo() {
    ifstream archivo;
    archivo.open("musica.txt"); // Abrir TXT

    if(archivo.fail()){ // Error si no está
        cout<<"No se pudo abrir el archivo"<< endl;
        exit(1);
    }
    int tamanio = 10; // Tamaño inicial
    this->tamanioActual = 1; // Tamaño actual

    // CREAR ARREGLO DINAMICO listaCanciones
    listaCanciones = (Cancion*) malloc(tamanio*sizeof(Cancion)); // Guardo 10 espacios para las Canciones

    // RECORRER ARCHIVO LINEA POR LINEA
    string linea;
    while (getline(archivo, linea)) {
        string nombre;
        string artista;
        string reproducciones;
        string duracion;

        stringstream input_ss(linea); // TODO: Hacer otro stringstream para leer el String de duracion y partirlos por ':'
        //TODO: string como puntero o vector de char


        getline(input_ss, nombre, ';');
        getline(input_ss, artista, ';');
        getline(input_ss, reproducciones, ';');
        getline(input_ss, duracion, ';');
        //input_ss >> reproducciones;
        //input_ss.ignore(); // parara ignorar el ; y no asignarlo dentro del duracion
        //input_ss >> duracion;

        //getline(input_ss, reproduccionString, ';'); // lo mismo
        //getline(input_ss, duracionString, ';'); // duracionString

        //to_string() //dato pasarlo a a String
        //duracion = stoi(duracionString);
        //reproducciones = stoi(reproduString); // Siempre se lee en string y se pasa a int

        if (this->tamanioActual == tamanio){
            tamanio += 10; //+10 al tamaño
            // Redimensionar el arreglo
            listaCanciones = (Cancion*)realloc(listaCanciones,tamanio*sizeof(Cancion));
        }

        // Crear una nueva Cancion con los datos de la linea
        Cancion* nuevaCancion = new Cancion(nombre,artista,reproducciones,duracion);
        //cout << nombre << artista << reproducciones << duracion <<endl;

        //tamanio++; // Variable para aumentar tamaño de la lista para guardarle espacio
        // Redimensionar listaCanciones con el Nuevo tamanio
        //listaCanciones = (Cancion*)realloc(listaCanciones,tamanio*sizeof(Cancion));

        // Guardar nueva Cancion en la listaCanciones
        listaCanciones[tamanioActual] = *nuevaCancion; // SE CAE
        this->tamanioActual++; // Incrementa el tamaño actual
    }
    archivo.close();

    for (int i=1; i<=tamanioActual-1;i++){ // LAS POSICIONES DE listaCanciones PARTEN DE 1
        cout << "------------------" << endl;
        cout << i <<endl;
        cout << listaCanciones[i].getNombre() << endl;
        cout << listaCanciones[i].getArtista() << endl;
        cout << listaCanciones[i].getReproducciones() << endl;
        cout << listaCanciones[i].getDuracion()<< endl;
        cout << "-----------------" << endl;
    }
}