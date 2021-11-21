#include <iostream>
#include "Tablero.h"
#include "Gusanito.h"
using namespace std;

int main()
{
    
    int rows, cols;
    cout << "Ingresa el número de filas: ";
    cin >> rows;
    cout << "Ingresa el número de columnas: ";
    cin >> cols;
    
    Tablero mi_tablero(rows, cols); //SE CREA EL OBJETO TABLERO
    Gusanito gusanito1; //SE CREA EL OBJETO GUSANITO
    gusanito1.set_x_maximo(mi_tablero.get_ancho());
    gusanito1.set_y_maximo(mi_tablero.get_alto());

    Gusanito gusanito2('2');
    gusanito2.set_x_maximo(mi_tablero.get_ancho());
    gusanito2.set_y_maximo(mi_tablero.get_alto());


    bool continuar = true;

    
    while (continuar) {
    
        
        int fruta[2];
       
        cout << "\033[H\033[2J\033[3J" << endl;

        mi_tablero.dibujar_tablero(gusanito1.get_gusanito(), gusanito1.get_tamano_gusano(), gusanito1.get_caracter_gusano(), gusanito2.get_gusanito(), gusanito2.get_tamano_gusano(), gusanito2.get_caracter_gusano2());
        mi_tablero.get_fruta(fruta);
        gusanito1.set_fruta(fruta);
        gusanito2.set_fruta(fruta);
        gusanito2.mover_gusano2();
        gusanito2.desplazar_gusano(AVANCE_ARRIBA2, AVANCE_ABAJO2,AVANCE_DERECHA2,AVANCE_IZQUIERDA2);  
        if (gusanito2.verificar_fruta_comida()) {
            gusanito2.crecer_gusano(AVANCE_ARRIBA2, AVANCE_ABAJO2,AVANCE_DERECHA2,AVANCE_IZQUIERDA2);
            mi_tablero.set_estado_fruta(true);
        }
        
        gusanito1.mover_gusano();  
        gusanito1.desplazar_gusano(AVANCE_ARRIBA, AVANCE_ABAJO,AVANCE_DERECHA,AVANCE_IZQUIERDA);
        if (gusanito1.verificar_fruta_comida()) {
            gusanito1.crecer_gusano(AVANCE_ARRIBA, AVANCE_ABAJO,AVANCE_DERECHA,AVANCE_IZQUIERDA);
            mi_tablero.set_estado_fruta(true);
        }
        
        

        if (continuar==true) continuar = !gusanito1.detectar_colision();
        if (continuar== true) continuar = !gusanito2.detectar_colision();
         

    }
    
    std::cout << "Gusanito murio" << std::endl;
    return 0;
}
