#include <iostream>
#include <random>
#include <ctime>

#include "Tablero.h"

using namespace std;
//CONSTRUCTOR POR DEFECTO: SOLO INICIALIZA LA FUNCION RAND
Tablero::Tablero()
{
    srand(time(NULL));
}

//CONSTRUCTOR QUE RECIBE LAS DIMENSIONES DEL TABLERO CREA EL TABLERO CON BORDES MANTENIENDO EL AREA INTERNA CON LAS DIMENSIONES RECIBIDAS.
Tablero::Tablero(int _ancho, int _alto) {
    srand(time(NULL)); //SE INICIALIZA LA FUNCION RAND.
    ancho = _ancho;
    alto = _alto;
    //SE CREA EL TABLERO USANDO ASIGNACION DINAMICA DE MEMORIA.
    tablero = new char* [alto + 2]; //Sirve para crear un arreglo lineal de punteros a char.
    for (int i = 0; i < alto + 2; i++) {
        tablero[i] = new char[ancho + 2]; //Se crea dinamicamente cada fila de la matriz. con tantas columnas como ancho indica.
                                   // Finalmente se obtiene una matriz de dos dimensiones de alto x  ancho.
        for (int j = 0; j < ancho + 2; j++) {
            tablero[i][j] = ' '; //Este for se encarga de que se coloque un espacio en blanco en cada elemento de cada fila nueva que se cree.
        }
    }

    //SE DEFINEN LAS ESQUINAS DEL TABLERO SEGUN LA TABLA ASCII.
    tablero[0][0] = 201;
    tablero[0][ancho + 1] = 187;
    tablero[alto + 1][0] = 200;
    tablero[alto + 1][ancho + 1] = 188;

    //SE DIBUJAN LOS BORDES HORIZONTALES DEL TABLERO.
    for (int i = 1; i < ancho + 1; i++) {
        tablero[0][i] = 205;
        tablero[alto + 1][i] = 205;
    }

    //SE DIBUJAN LOS BORDES VERTICALES DEL TABLERO.
    for (int i = 1; i < alto + 1; i++) {
        tablero[i][0] = 186;
        tablero[i][ancho + 1] = 186;
    }
    fruta_comida = true;
    contador_frutas = 0;
}
//DESTRUCTOR VACIO
Tablero::~Tablero()
{}

//ESTE METODO GENERA UNA POSICION ALEATORIA DE LA FRUTA SI LA FRUTA YA FUE COMIDA
void Tablero::nueva_fruta() {
    if (fruta_comida == true) {
        fruta[0] = rand() % ancho + 1;
        fruta[1] = rand() % alto + 1;
        contador_frutas++;
        fruta_comida = false;
    }
}

//SE DIBUJA EL TABLERO LA FRUTA Y EL GUSANO
void Tablero::dibujar_tablero(int** gusanito, int tamano_gusano, char caracter_gusano, int** gusanito2, int tamano_gusano2, char caracter_gusano2) { //EL GUSANITO SE RECIBE COMO UN PUNTERO A PUNTERO DE ENTEROS
    char caracter = 0;
    char caracter2 = 0;
    nueva_fruta();
    cout << "Score: " << contador_frutas - 1 << endl;
    for (int i = 0; i < alto + 2; i++) {
        for (int j = 0; j < ancho + 2; j++) {
            for (int k = 0; k < tamano_gusano && caracter == 0; k++) { //SE UTILIZA PARA DIBUJAR EL GUSANITO
                if (j == gusanito[k][0] && i == gusanito[k][1]) {
                    caracter = caracter_gusano;
                    
                }
            }
            for (int k = 0; k < tamano_gusano2 && caracter2 == 0; k++) { //SE UTILIZA PARA DIBUJAR EL GUSANITO
                if (j == gusanito2[k][0] && i == gusanito2[k][1]) {
                    caracter = caracter_gusano2;
                }
            }
            if (j == fruta[0] && i == fruta[1] && caracter == 0) {
                caracter = CARACTER_FRUTA;
            }
            if (caracter == 0) {
                caracter = tablero[i][j];
            }
            
            cout << caracter;
            caracter = 0; //para resetear el caracter a 0
        }
        cout << endl;
    }
    sleep(15);
}


int Tablero::get_ancho() { //RETORNA EL VALOR DEL ATRIBUTO ANCHO
    return ancho;
}

int Tablero::get_alto() { //RETORNA EL VALOR DEL ATRIBUTO ALTO
    return alto;
}
void Tablero::get_fruta(int _fruta[2]) {
    //EL ARREGLO _FRUTA SE RECIBE X REFERENCIA. EL ACCESO A UN ARREGLO EXTERNO A LA CLASE
    //QUE SE MODIFICA EN EL METODO SE MODFICA TAMBIEN FUERA DE LA CLASE.
    _fruta[0] = fruta[0];
    _fruta[1] = fruta[1];
}

void Tablero::set_estado_fruta(bool _estado) { //ESTABLECE SI LA FRUTA FUE COMIDA O NO.
    fruta_comida = _estado;
}
void Tablero::sleep(int t) { //SE UTILIZA PARA GENERAR UNA PAUSA
    for (int i = 0; i < 1000000 * t; i++);
}
