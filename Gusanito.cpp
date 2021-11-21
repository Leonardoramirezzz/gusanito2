#include <iostream>
#include <conio.h>
#include "Gusanito.h"

//CONSTRUCTOR SIN PARAMETROS:INICIALIZA AL GUSANITO SOLO CON LA CABEZA.
Gusanito::Gusanito()
{
    tamano_gusano = 0;
    gusanito = new int* [TAMANO_MAXIMO + 1]; //CREO EL ARREGLO DE PUNTEROS DEL GUSANITO(se reserva espacio de memoria para almacenar tantos punteros a enteros como TAMANO_MAXIMO+1)
    gusanito[0] = new int[2]; //ARREGLO DE DOS ELEMENTOS YA QUE CONTAMOS CON X y Y CREAMOS LA CABEZA DE LA SERPIENTE
    gusanito[0][0] = X_INICIAL;
    gusanito[0][1] = Y_INICIAL;
    direccion = 0;
}


Gusanito::Gusanito(char num_gusano)
{
    tamano_gusano = 0;
    gusanito = new int* [TAMANO_MAXIMO + 1]; 
    gusanito[0] = new int[2]; 
    gusanito[0][0] = X_INICIAL2;
    gusanito[0][1] = Y_INICIAL2;
    direccion = 0;
}

//CONSTRUCTOR QUE RECIBE UN TAMAÑO INICIAL, INICIALIZA AL GUSANITO CON EL CUERPO DE TAMAÑO QUE INDIQUE LA VARIABLE _tamano_inicial.
Gusanito::Gusanito(int tamano_inicial)
{
    tamano_gusano = tamano_inicial;
    gusanito = new int* [TAMANO_MAXIMO + 1]; //CREO EL ARREGLO DE PUNTEROS DEL GUSANITO(se reserva espacio de memoria para almacenar tantos punteros a enteros como TAMANO_MAXIMO+1)
    gusanito[0] = new int[2]; //ARREGLO DE DOS ELEMENTOS YA QUE CONTAMOS CON X y Y CREAMOS LA CABEZA DE LA SERPIENTE
    for (int i = 1; i <= tamano_gusano; i++) {
        gusanito[i] = new int[2];//TANTOS BLOQUES DE CUERPO COMO EL tamano_gusano INDICA.
    }
    int cont = 0;
    for (int i = tamano_gusano; i >= 0; i--) { //SIRVE PARA DESPLAZAR LA CABEZA HACIA DELANTE DE LA POSICION INICIAL POR DEFECTO.
        gusanito[i][0] = X_INICIAL + cont++;
        gusanito[i][1] = Y_INICIAL;
    }
    direccion = AVANCE_DERECHA;

}

Gusanito::~Gusanito()
{
}

void Gusanito::mover_gusano() {
    char tecla;

    if (_kbhit()) {
        tecla = _getch(); 
        switch (tecla) { 
        case AVANCE_ARRIBA:
            if (direccion != AVANCE_ABAJO)
                direccion = AVANCE_ARRIBA;
            break;
        case AVANCE_ABAJO:
            if (direccion != AVANCE_ARRIBA)
                direccion = AVANCE_ABAJO;
            break;
        case AVANCE_DERECHA:
            if (direccion != AVANCE_IZQUIERDA)
                direccion = AVANCE_DERECHA;
            break;
        case AVANCE_IZQUIERDA:
            if (direccion != AVANCE_DERECHA)
                direccion = AVANCE_IZQUIERDA;
            break;
        }
    }
}


void Gusanito::mover_gusano2() {
    char tecla2;

    if (_kbhit()) { 
        tecla2 = _getch(); 
        switch (tecla2) { 
        case AVANCE_ARRIBA2:
            if (direccion != AVANCE_ABAJO2)
                direccion = AVANCE_ARRIBA2;
            break;
        case AVANCE_ABAJO2:
            if (direccion != AVANCE_ARRIBA2)
                direccion = AVANCE_ABAJO2;
            break;
        case AVANCE_DERECHA2:
            if (direccion != AVANCE_IZQUIERDA2)
                direccion = AVANCE_DERECHA2;
            break;
        case AVANCE_IZQUIERDA2:
            if (direccion != AVANCE_DERECHA2)
                direccion = AVANCE_IZQUIERDA2;
            break;
        }
    }
}

void Gusanito::desplazar_gusano(char arriba,char abajo,char derecha,char izquierda) {
    for (int i = tamano_gusano; i > 0; i--) { //Copiar de la cola hasta la cabeza el cuerpo del gusano
        gusanito[i][0] = gusanito[i - 1][0];
        gusanito[i][1] = gusanito[i - 1][1];
    }
    //DESPLAZA LA CABEZA EN LA DIRECCION QUE LE CORRESPONDE
    if (direccion == arriba)     gusanito[0][1]--; //COORDENADA Y DE LA CABEZA
    if (direccion == abajo)      gusanito[0][1]++; //COORDENADA Y DE LA CABEZA
    if (direccion == derecha)    gusanito[0][0]++; //COORDENADA X DE LA CABEZA
    if (direccion ==izquierda)   gusanito[0][0]--; //COORDENADA X DE LA CABEZA
}

bool Gusanito::verificar_fruta_comida() {
    if (gusanito[0][0] == fruta[0] && gusanito[0][1] == fruta[1]) {
        return true;
    }
    else {
        return false;
    }
}

//METODO PARA HACER CRECER EL GUSANO EN UNA POSICION CUANDO HA COMIDO UNA FRUTA.
void Gusanito::crecer_gusano(char arriba,char abajo,char derecha,char izquierda) {
    tamano_gusano++;
    gusanito[tamano_gusano] = new int[2]; //Agregando un nuevo segmento al gusano al final
    for (int i = tamano_gusano; i > 0; i--) { //Copiar de la cola hasta la cabeza el cuerpo del gusano
        gusanito[i][0] = gusanito[i - 1][0];
        gusanito[i][1] = gusanito[i - 1][1]; //Cuando el gusano come fruta crecera en 1 el gusano.
    }
    if (direccion == arriba)     gusanito[0][1]--; //COORDENADA Y DE LA CABEZA
    if (direccion == abajo)      gusanito[0][1]++; //COORDENADA Y DE LA CABEZA
    if (direccion == derecha)    gusanito[0][0]++; //COORDENADA X DE LA CABEZA
    if (direccion == izquierda)  gusanito[0][0]--; //COORDENADA X DE LA CABEZA
}


//DETECTA SI EL GUSANO A TOCADO LOS BORDES Y HA COLISIONADO.
bool Gusanito::detectar_colision() {
    bool auto_colision = false;
    for (int i = 1; i <= tamano_gusano; i++) {
        if (gusanito[0][0] == gusanito[i][0] && gusanito[0][1] == gusanito[i][1]) {
            auto_colision = true;
            break;
        }
    }
    return (gusanito[0][0] == 0 || gusanito[0][0] == x_maximo + 1 || gusanito[0][1] == 0 || gusanito[0][1] == y_maximo + 1 || auto_colision);
}

void Gusanito::set_fruta(int _fruta[2]) {
    fruta[0] = _fruta[0];
    fruta[1] = _fruta[1];
}

//ESTE METODO SIRVE PARA DEVOLVER EL ARREGLO BIDIMENSIONAL DEL GUSANITO COMO PUNTERO A PUNTERO
int** Gusanito::get_gusanito() {
    return gusanito;
}

int Gusanito::get_tamano_gusano() {
    return tamano_gusano + 1;
}

char Gusanito::get_caracter_gusano() {
    return CARACTER_GUSANO;
}

char Gusanito::get_caracter_gusano2() {
    return CARACTER_GUSANO2;
}

void Gusanito::set_x_maximo(int _x) {
    x_maximo = _x;
}

void Gusanito::set_y_maximo(int _y) {
    y_maximo = _y;
}

int Gusanito::get_x_maximo() {
    return x_maximo;
}

int Gusanito::get_y_maximo() {
    return y_maximo;
}
