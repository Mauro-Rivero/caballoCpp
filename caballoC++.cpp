#include <math.h>
#include <iostream>
using namespace std;

//#include <tuple> PENSE ESTO PERO DESCONOZCO COMO OPERAR Y USARLO Y NO TENGO TIEMPO DE GOOGLEARLO

#define tam 8


void inicializarTablero (int tablero[][] , int columnaInicial , int filaInicial){
    int i,j;
    for(i = 0 ; i < tam ; i++){
        for(j=0 ; j < tam ; j++){
            tablero[i][j] = 0;
        }
    }
    tablero[columnaInicial][filaInicial] = 1;
}

//numero de salto tiene que ser = 2 antes de llamar a la funcion pq el salto 1 es la posicion inicial
void pasoBacktracking (int tablero[][] , int columnaActual , int filaActual , int numeroSalto){
    //caso de escape: el tablero fue completamente saltado O ya se intentaron todos los movimientos
    int nuevaColumna = 0;
    int nuevaFila = 0;
    int intento = 0;
    //Intento de "duplas" de coordenadas a suamr
    int posiblesMovimientosColumna[7]    = {  2, 2,  1, 1, -1, -1, -2, -2 };
    int posiblesMovimientosFila[7]       = { -1, 1, -2, 2,  2, -2, -1,  1 };

    while (tableroEstaSinTerminar(tablero) && intento < 8) { //condicion escape
        nuevaColumna = columnaActual + posiblesMovimientosColumna[intento];
        nuevaFila = filaActual + posiblesMovimientosFila[intento];

        if(puedeSaltarCaballo(tablero , nuevaColumna, nuevaFila)){
            tablero[nuevaColumna][nuevaFila] = numeroSalto;

            pasoBacktracking( tablero , nuevaColumna , nuevaFila , numeroSalto + 1)
        }

        intento += 1;
    }    
}

bool puedeSaltarCaballo(int tablero[][] , int nuevaColumna , int nuevaFila){
    return ((tablero[nuevaColumna][nuevaFila] == 0) && (nuevaColumna < tam && nuevaColumna >= 0) && (nuevaFila < tam && nuevaFila >= 0))
}

bool tableroEstaSinTerminar(int tablero[][]){ //esta sin terminar cuando alguna de sus celdas esta igual a cuando lo inicializamos (= 0)
    int i,j;
    for(i = 0 ; i < tam ; i++){
        for(j=0 ; j < tam ; j++){
            if(tablero[i][j] == 0){
                return true;
            }
        }
    }
    return false;
}

void mostrarTablero (int tablero[][]){ 
    int i,j;
    for(i = 0 ; i < tam ; i++){
        for(j=0 ; j < tam ; j++){
            cout << tablero[i][j]<< " | ";
        }
        cout<< "\n"; 
    }
}

int Main(){
    int tableroCaballo[tam][tam];
    int columnaInicial = 0;
    int filaInicial = 7; //asi empezamos en la "parte de abajo" del tablero
    inicializarTablero(tableroCaballo , columnaInicial , filaInicial);
    pasoBacktracking(tableroCaballo , columnaInicial , filaInicial , 2);
    mostrarTablero (tablero);

    return 0;
}