
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "Sistema.h"
#include "ListaNodoCircularDoble.h"

Sistema::Sistema() {
}

//LISTO?
void Sistema::menu(){
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
            guardarArchivo();

            cout << "\nHas salido del reproductor correctamente.\n";
            return;
        }
        else {
            cout << "\n[!] Error: Ingrese una opcion valida! \n" << endl;
        }
    }
}

//LISTO
void Sistema::Anterior() {
    this->listaReproducciones.moverAnterior();
}
//LISTO
void Sistema::Siguiente() {
    this->listaReproducciones.moverSiguiente();
}

//FALTA?
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

            //TODO: Validar STRING como ints minutos segundos
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
            int espera = (((60*minutos)+segundos)/20);
            sleep(espera);
            cout << "\nLa cancion ha sido agregada al sistema con exito!" << endl;
        }

        // AGREGAR CANCION A LA LISTA REPRODUCCIONES
        //TODO: Hacer que se IMPRIMAN las Canciones de listaCanciones (Sistema) que NO ESTAN AÚN en listaReproducciones
        else if(opcion == "2"){

            // IMPRIMIR LISTA CANCIONES DEL SISTEMA
            for (int i=1; i<tamanioActual;i++){
                cout << "\n[" << i << "]";
                cout << "Nombre: " <<listaCanciones[i].getNombre()<<endl;
                cout << "   Artista/s: " <<listaCanciones[i].getArtista()<<endl;
                cout << "   Cantidad de reproducciones: " <<listaCanciones[i].getReproducciones()<<endl;
                cout << "   Duracion: " <<listaCanciones[i].getDuracion()<<endl;
            }


            int posicionCancion;
            cout << "\nIngresa el numero de la posicion de la cancion que quieres agregar a la lista de reproduccion: ";
            cin >> posicionCancion;

            //TODO: Falta VALIDAR el int si se ingresa STRING

            if (posicionCancion >= tamanioActual || posicionCancion <= 0){
                cout << "\n[!] Error: La posicion ingresada no se encuentra en la lista!\n"<<endl;
            }

            // AGREGAR CANCION DE SISTEMA A REPRODUCCIONES
            for(int i=1; i<=tamanioActual-1; i++){
                if (i == posicionCancion) { //compara la posicion de la cancion actual con la entregado por pantalla
                    this->listaReproducciones.agregar(listaCanciones[posicionCancion]); // agrega la cancion que esta en una lista a la otra
                    cout << "\nLa cancion "<<"[" << posicionCancion << "] " << listaReproducciones.getCabeza()->getCancion().getNombre() <<" ha sido agregada exitosamente\n" << endl;
                    return;
                }
                //avanza
            }
        }

        // VOLVER AL MENU
        else if(opcion == "3"){
            return;
        }

        //OPCION NO VALIDA
        else{
            cout << "\n[!] Error: Ingresa una opcion valida !\n" << endl;
        }
    }

}
//LISTO
void Sistema::eliminar() {
    bool mostrar = this->listaReproducciones.mostrarLista(); //Muestra todas las canciones de la lista Reproduccion
    if (mostrar == false){
        return;
    }

    int posEliminar;
    cout << "\nIngresa el numero de la posicion de la cancion a eliminar: ";
    cin >> posEliminar;

    if (posEliminar > listaReproducciones.getCantCanciones() || posEliminar <= 0){
        cout << "\n[!] Error: La posicion ingresada no se encuentra en la lista!\n"<< endl;
    }

    this->listaReproducciones.eliminar(posEliminar); // elimino la cancion en esa posicion
}


// FALTA
void Sistema::guardarArchivo() {



    cout << "Se han guardado los cambios del archivo de musica"<< endl;
}


/**
 * LECTURA DE ARCHIVO
 */
//LISTO
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

        stringstream input_ss(linea); //Opcional: Hacer otro stringstream para leer el String de duracion y partirlos por ':'
        //Opcional: string como puntero o vector de char


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