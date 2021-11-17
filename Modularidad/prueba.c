#include "prueba.h"

//Funcion privada solo pueden ser llamadas desde otras funciones de su mismo modulo 
static void privada(int *x){
    *x+=10;
}

//Funcion de prueba 
void prueba(int *x){
    *x+=5;
    privada(x); 
}

