#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

//Prototipos 
void fun(int v[]);
void imprimir(int v[]);
void ordenar(int v[]);
void imprimirOrdenar(int v[]);
void introducir(int *v4);
void leer(int *v4);
void sorteo(int *v5);
void leerSorteo(int *v4);

int main(void){
    //array/vector de entros 
    //int v [] = {1,2,3,4,5};
    //array con 10 enteros 
    //int v1 [10]; 
    //int v2 [2]; 
    int v3 [10] = {3,8,5,6,2,1,7,9,4,0};
    
    //fun(v2);
    //imprimir(v2);
    //Ordenar vector de menos a mayor mediante una funcion 
    ordenar(v3);
    imprimirOrdenar(v3);
    //Arrays con punteros 
    int v4[3];
    introducir(v4);
    leer(v4);
    //Clacular las probabilidad de que salgan cada uno de los numeros de un dado con un vector usando punteros 
    //calcular con 10000 iteraciones 
    int v5 [] = {0,0,0,0,0,0};
    sorteo(v5);
    leerSorteo(v5);


    return 0;

}

//Funcion que recibe un vector de enteros y 
//que introduce datos en el vector v2
void fun(int v[]){
    for(int i=0; i<2; i++){
        printf("Introduce valores para el vector: \n");
        scanf("%d",&v[i]);
    }
}

void imprimir(int v[]){
    for(int i=0; i<2; i++){
        printf("%d\n",v[i]);
    }
}

void imprimirOrdenar(int v[]){
    for(int i=0; i<10; i++){
        printf("%d\n",v[i]);
    }
}

void ordenar(int v[]){
    int aux; 
    for(int i=0; i<10;i++){
        for(int j=i; j<10; j++){
            if(v[i] > v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void introducir(int *v4){
    for(int i=0; i<3; i++){
        printf("Introduce valores en posicion %d: ",i);
        //para escribir no hace falta poner * o &
        scanf("%d",(v4+i));
    }
}

void leer(int *v4){
    for(int i=0; i<3; i++){
        printf("%d\n",*(v4+i));
    }
}

void sorteo(int *v5){
    int aux; 
    srand(time(NULL));
    for(int i=0; i<10000; i++){
        aux = rand()%6;
        switch(aux){
            case 0:{
                *(v5+aux)+= 1;  //suma 1 a la posicion 0 del contador 
                break; 
            }
            case 1:{
                *(v5+aux)+= 1;  //suma 1 a la posicion 0 del contador 
                break; 
            }
            case 2:{
                *(v5+aux)+= 1;  //suma 1 a la posicion 0 del contador 
                break; 
            }
            case 3:{
                *(v5+aux)+= 1;  //suma 1 a la posicion 0 del contador 
                break; 
            }
            case 4:{
                *(v5+aux)+= 1;  //suma 1 a la posicion 0 del contador 
                break; 
            }
            case 5:{
                *(v5+aux)+= 1;  //suma 1 a la posicion 0 del contador 
                break; 
            }
        }
    }
}

void leerSorteo(int *v4){
    float x; 
    for(int i=0; i<6 ; i++){
        x=(*(v4+i)*100)/10000.0;
        printf("La probabilidad de que el numero %d salga es de: %f\n",i+1,x);
    }
}


/*

    //rellenamos de valores el vector v1
    for(int i=0; i<10; i++){
        printf("Dale valor al vector en la posicion %d\n",i);
        //damos valores al vector v1
        scanf("%d",&v1[i]);
    }
    //leemos los valores del v1
    for(int i=0; i<10;i++){
        printf("%d\n",v1[i]);
    }

*/