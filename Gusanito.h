#pragma once
#ifndef GUSANITO_H
#define GUSANITO_H

#define TAMANO_MAXIMO 20
#define X_INICIAL 10
#define Y_INICIAL 5
#define X_INICIAL2 35
#define Y_INICIAL2 5
#define CARACTER_GUSANO 'O'
#define AVANCE_DERECHA   'd'
#define AVANCE_IZQUIERDA 'a'
#define AVANCE_ARRIBA    'w'
#define AVANCE_ABAJO     's'

#define CARACTER_GUSANO2 'S'
#define AVANCE_DERECHA2   'l'
#define AVANCE_IZQUIERDA2 'j'
#define AVANCE_ARRIBA2    'i'
#define AVANCE_ABAJO2     'k'

class Gusanito
{
private:
    int** gusanito; //Puntero a puntero char para manejar la matriz bi dimensional para las posiciones en 'X' y 'Y'del gusanito de  manera dinamica.
    int tamano_gusano;
    int x_maximo;
    int y_maximo;
    char direccion;
    int fruta[2];

public:
    Gusanito();
    Gusanito(int tamano_inicial);
    Gusanito(char num_gusano);
    ~Gusanito();

    void mover_gusano();
    void mover_gusano2();
    void desplazar_gusano(char arriba,char abajo,char derecha,char izquierda);
    bool verificar_fruta_comida();
    void crecer_gusano(char arriba,char abajo,char derecha,char izquierda);
    bool detectar_colision();
    void set_fruta(int _fruta[2]);
    int** get_gusanito(); //ESTE METODO SIRVE PARA DEVOLVER EL ARREGLO BIDIMENSIONAL DEL GUSANITO COMO PUNTERO A PUNTERO
    int get_tamano_gusano();
    char get_caracter_gusano();
    char get_caracter_gusano2();
    void set_x_maximo(int _x);//Son metodos para setear los limites de desplazamiento del gusano.
    void set_y_maximo(int _y);//Son metodos para setear los limites de desplazamiento del gusano.
    int get_x_maximo();
    int get_y_maximo();
};

#endif // GUSANITO_H
