#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void *malloc(size_t tamanio); 

//Prototipos
void intercambia(int *x, int *y);
void suma1(int *v);
int leerCantidad();
void leer(int cantidad, int *numeros);
void imprimir(int cantidad, int *numeros);

//PRINCIPAL*********************
int main(void){
    
    //PASO POR REFERENCIA Y VALOR 
    int a=2, b=3; 
    printf("\nLos valores son: a=%d y b=%d",a,b);
    intercambia(&a,&b);
    printf("\nLos valores son: a=%d y b=%d\n\n",a,b);
    //Pasamos por referencia un vector 
    int v[4]={1,2,3,4};
    for(int i=0; i<4; i++){
        printf("Los valores del vector son: %d\n",v[i]);
    }
    suma1(v);
    for(int i=0; i<4; i++){
        printf("Los valores del vector despues de Referencia: %d\n",v[i]);
    }


    //MEMORIA DINAMICA 
    int cantidad = leerCantidad();
    int *numeros = malloc(cantidad * sizeof(int)); //devuelve un puntero a la cantidad necesaria x por la cantidad de un entero 
    leer(cantidad,numeros);
    imprimir(cantidad,numeros);
    free(numeros);  

    return 0; 
}

//FUNCIONES *************************
//Funcion que intercambia los valores de las variables a y b
void intercambia(int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z; 
}

//suma 1 a todos los elementos de un vector 
void suma1(int *v){
    for(int i=0; i<4; i++){
        //printf("%d\n",*(v+i)+=1);
        *(v+i)+=1;
    }
}

//Funciones memoria dinamica 
int leerCantidad(){
    int cantidad;
    printf("¿Cuantos numeros vas a ingresar?: ");
    scanf("%d",&cantidad);  //guardamos el numero introducido en la variable cantidad 
    return cantidad; 
}

void leer(int cantidad, int *numeros){
    for(int i=0; i<cantidad; i++){
        //almacenamos directamente en memoria el los valores que vamos ingresando hasta un tope de cantidad 
        scanf("%d",&numeros[i]);
    }
}

void imprimir(int cantidad, int *numeros){
    for(int i=0; i<cantidad; i++){
        //accede a memoria donde estan guardados los numeros y les va sumando 1
        printf("Los numeros son: %d\n",numeros[i]+1);
    }
}