#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ficeheros externos 
#include "prueba.h"

int main(){

    int x = 0; 

    prueba(&x);
    printf("El valor de x es: %d\n",x);

    return 0;
}