
#include <iostream>
#include <fstream>
#include <sstream>
#include "Sistema.h"
#include "ListaNodoCircularDoble.h"

Sistema::Sistema() {
}

void Sistema::menu() {
    lecturaArchivo();

    // MENU
    string Respuesta;
    while (true){
        cout << "\n.:.:.:.:.: WINAMP .:.:.:.:.:" << endl;
        listaReproducciones.mostrarCanciones();
        cout << ".:.:.:.:.: MENU .:.:.:.:.:" << endl;
        cout << "[1] Anterior" << endl;
        cout << "[2] Siguiente" << endl;
        cout << "[3] Agregar" << endl;
        cout << "[4] Eliminar" << endl;
        cout << "[5] Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> Respuesta;

        if(Respuesta == "1") {
            Anterior();
        }
        else if(Respuesta == "2"){
            Siguiente();
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
        cout << "\n.:.:.:.:.: MENU AGREGAR .:.:.:.:.:" << endl;
        cout << "[1] Agregar una cancion al sistema" << endl;
        cout << "[2] Agregar una cancion a la lista de reproduccion" << endl;
        cout << "[3] Volver al menu anterior" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        if(opcion == "1"){ // AGREGAR CANCION AL SISTEMA
            // Nombre Cancion
            string nombreCancion;
            cout << "\nIngresa el nombre de la cancion: ";
            cin >> nombreCancion;

            // Nombre Artista
            string nombreArtista;
            cout << "\nIngresa el nombre del Artista (si es mas de 1, separalos por comas ','): ";
            cin >> nombreArtista;

            // Cant Reproducciones
            string reproducciones;
            cout << "\nIngresa la cantidad de reproducciones: ";
            cin >> reproducciones;

            // Duracion (min:seg)
            string duracion;
            cout << "\nIngresa los minutos y segundos de duracion de la cancion en el formato (mm:ss): "; //TODO: Hacer que tenga que contener ':' si o si ??
            cin >> duracion;

            int minutos;
            int segundos;
            stringstream input_ss(duracion);
            input_ss >> minutos;
            input_ss.ignore();
            input_ss >> segundos;
            //int duracionInt = stoi(duracion);

            //to_string() //dato pasarlo a a String
            //duracion = stoi(duracionString);
            //reproducciones = stoi(reproduString); // Siempre se lee en string y se pasa a int
            //string duracion = (int)duracionMin + ":" + duracionSeg;


            Cancion* agregarCancion = new Cancion(nombreCancion, nombreArtista, reproducciones, duracion);

            tamanioActual++;
            // Redimensionar listaCanciones con el Nuevo tamanio
            listaCanciones = (Cancion*)realloc(listaCanciones,this->tamanioActual*sizeof(Cancion));
            // Guardar nueva Cancion en la listaCanciones
            listaCanciones[this->tamanioActual-1] = *agregarCancion;

            cout << "\nAgregando cancion al sistema... Espere unos segundos..." << endl;
            // TODO: Tiempo Espera : (60*minutos + segundos)/20 ); // Se debe calcular a seguindos y hacer la espera
            cout << "\nLa cancion ha sido agregada al sistema con exito!" << endl;
        }

        // AGREGAR CANCION A LA LISTA REPRODUCCIONES
        //TODO: Hacer que se IMPRIMAN las Canciones de listaCanciones (Sistema) que NO estan en listaReproducciones
        //TODO: Se agregan las canciones de la listaCanciones (sistema) SEGUN EL NUMERO DE SU POSICION, NO SEGUN SU NOMBRE (segun taller)
        else if(opcion == "2"){
            for (int i=1; i<tamanioActual;i++){
                cout << "\n[" << i << "]";
                cout << "Nombre: " <<listaCanciones[i].getNombre()<<endl;
                cout << "   Artista/s: " <<listaCanciones[i].getArtista()<<endl;
                cout << "   Cantidad de reproducciones: " <<listaCanciones[i].getReproducciones()<<endl;
                cout << "   Duracion: " <<listaCanciones[i].getDuracion()<<endl;
            }
            string nombreCancion;
            cout << "\nIngresa el nombre de la cancion: ";
            cin >> nombreCancion;
            if(this->listaReproducciones.buscarCancion(nombreCancion)){ // compara que la cancion no se encuentre en la lista
                cout << "\n[!] La cancion ya se encuentra en la lista de reproduccion\n" << endl;
                return;
            }

            // AGREGAR CANCION DE SISTEMA A REPRODUCCIONES
            for(int i=1; i<=tamanioActual; i++){
                if (listaCanciones[i].getNombre() == nombreCancion) { //compara el nombre de la cancion en la poscion tamanio con el entregado por pantalla
                    this->listaReproducciones.agregar(listaCanciones[i]); // agrega la cancion que esta en una lista a la otra
                    cout << "\nLa cancion "<< listaReproducciones.getCabeza()->getCancion().getNombre() <<" ha sido agregada exitosamente\n" << endl;
                    return;
                }
            }
            // NO ESTA EN LISTA CANCIONES (SISTEMA)
            cout << "\n[!] La cancion ingresada no se encuentra en el sistema!"<<endl;
        }
        else if(opcion == "3"){
            return;
        }
        else{
            cout << "\n[!] Ingresa una opcion valida !\n" << endl;
        }
    }

}

void Sistema::eliminar() {
    string nombreEliminar;
    NodoDobleCircular* actual = listaReproducciones.getCabeza();

    if(actual == nullptr){
        cout << "\n[!] La lista esta vacia\n"<< endl;
        return;
    }

    while(actual->getSiguiente() != listaReproducciones.getCabeza()){
        cout << "Nombre"<<actual->getCancion().getNombre()<< endl;
        cout << "Artista"<<actual->getCancion().getArtista()<< endl;
        cout << "Reproducciones"<<actual->getCancion().getReproducciones()<< endl;
        cout << "Duracion"<<actual->getCancion().getDuracion()<< endl;

        actual = actual->getSiguiente();
    }


    cout << "\nIngresa el nombre de la cancion a eliminar:  ";
    cin >> nombreEliminar;

    if(this->listaReproducciones.buscarCancion(nombreEliminar) == true){
        this->listaReproducciones.eliminar(nombreEliminar);
    }
    else{
        cout<<"\n[!] El nombre ingresado no esta en la lista\n"<<endl;
    }

}

void Sistema::salir() {
    cout << "\nHas salido del reproductor correctamente.\n";
}


/**
 * LECTURA DE ARCHIVO
 */

void Sistema::lecturaArchivo() {
    ifstream archivo;
    archivo.open("musica.txt"); // Abrir TXT

    if(archivo.fail()){ // Error si no está
        cout<<"\n[!] No se pudo abrir el archivo\n"<< endl;
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
        cout <<"["<<i<<"]"<< endl;
        cout << listaCanciones[i].getNombre() << endl;
        cout << listaCanciones[i].getArtista() << endl;
        cout << listaCanciones[i].getReproducciones() << endl;
        cout << listaCanciones[i].getDuracion()<< endl;
        cout << "-----------------" << endl;
    }
}