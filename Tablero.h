#pragma once
#ifndef TABLERO_H
#define TABLERO_H

#define CARACTER_FRUTA '@'

class Tablero
{
private:
    char** tablero;//Puntero a puntero a char para manejar la matriz bi dimensional de manera dinámica.
    int fruta[2]; //Arreglo Uni dimensional de 2 elementos para manejar las coordenadas de la fruta.
    int contador_frutas; //Contabiliza la cantidad de frutas generadas.
    bool fruta_comida; //Sirve para detectar si la fruta fue comida y si hay que crear una nueva fruta.
    int ancho;
    int alto;

public:
    Tablero();
    Tablero(int _ancho, int _alto);
    ~Tablero();

    void nueva_fruta();
    void dibujar_tablero(int** gusanito, int tamano_gusano, char caracter_gusano, int** gusanito2, int tamano_gusano2, char caracter_gusano2);
    int get_ancho();
    int get_alto();
    void get_fruta(int _fruta[2]); //Se recibe un arreglo de dos dimensiones por referencia para obtener las coordenadas de la fruta.
    void set_estado_fruta(bool _estado);
    void sleep(int t);
};

#endif // TABLERO_H
