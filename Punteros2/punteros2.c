#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLUT/glut.h>  //librerira para hacer graficas 
//https://www.youtube.com/watch?v=p1Q5WFT0PG4&list=PLmf8VEwtjl1pGSnNE6bRFdqpIL3VZDgpi&index=23

//Estructuras 
struct PuntoRep{
    int x;
    int y; 
};
typedef struct PuntoRep *Punto;

//Prototipos de las cabeceras 
void modifica(int numero);
void modifica2(int *ptrn);
void modifica3(struct PuntoRep *pptr);
int *crea(int n);
Punto crea2(int x, int y);


int main (void){

    //Paso por referencia 
    printf("\n\t********** PASO POR VALOR Y REFERENCIA **********\n");
    int n = 0;
    printf("\tEl valor de i es: %d\n",n);
    modifica(n);
    printf("\tTras hacer un paso por valor el contenido de n es: %d\n",n);
    printf("\tLa direccion de n es: %p\n",&n);
    modifica2(&n);
    printf("\tLa variable n despues de la modificacion por paso por referencia es: %d\n",n);

    //Punteros a estructuras 
    printf("\n\t********** PUNTEROS A ESTRUCTURAS **********\n");
    //asignamos valores a los apartados de las estructuras 
    struct PuntoRep p = {.x=3, .y=7};
    struct PuntoRep *pptr = NULL;
    printf("\tEl contenido de la variable p(struct) es:  (%d,%d)\n ", p.x,p.y);
    pptr = &p;  //apuntamos a la estructura 
    printf("\tEl contenido de pptr es: %p\n",pptr);
    //accedemos a la estructura a traves del puntero que apunta y cambiamos sus valores 
    pptr->x = 50;   
    pptr->y = 60; 
    printf("\tDespues de acceder a traves de (->) los valores son: (%d,%d)\n",p.x,p.y);
    modifica3(&p);
    printf("\tDespues de acceder a la estructura con una funcion el valor es: (%d,%d)\n",p.x,p.y);
    //Punteros y arrays 
    printf("\n\t********** PUNTEROS Y ARRAYS **********\n");
    int array[] = {1,2,3};
    int *parray = NULL;
    printf("\tMostramos el valor de array: %p\n",array);
    printf("\t&array[0] es: %p\n",&array[0]);
    parray = array; //esto apunta a la primera direccion del array 
    printf("\tEl contenido de parray es: %p\n",parray);
    *parray = 40; //coloca un 40 en el primer elemento del array 
    printf("\tEl valor del primer elemento del array ahora es: %d\n",array[0]);
    parray[1]=200; //asigna un 200 en la posicion 1 
    printf("\tEl valor del segundo elemento de array ahora es: %d\n",array[1]);
    //Punteros y Memoria dinamica  
    printf("\n\t********** PUNTEROS Y MEMORIA DINAMICA **********\n");
    int *ptrd = NULL;
    int n1 = 0; 
    ptrd = malloc(sizeof(int)); //reservame memoria para guardar un entero 
    *ptrd = 50;  //en la memoria que me has reservado almacename un 5
    n1 = *ptrd + 5; 
    printf("\tEl contenido de ptrd es: %p\n",ptrd);
    printf("\tEl valor de n es: %d\n",n1);
    free(ptrd);
     //Memoria dinamica y arrays   
    printf("\n\t********** MEMORIA DINAMICA Y ARRAYS **********\n");
    int *parray2 = NULL;
    parray2 = crea(5);  //la funcion crea devuelve un puntero a una zona de memoria 
    printf("\tLa direccion de memoria donde apunta parray2 es: %p\n",parray2);
    printf("\tLa posicion 3 del array de memoria dinamica es: %d\n",parray2[2]);
    free(parray2);
    printf("\n\t********** MEMORIA DINAMICA Y ESTRUCTURAS **********\n");
    Punto j = NULL;
    j=crea2(4,5);
    printf("\tLos valores del array en memoria dinamica son: (%d,%d)\n",j->x,j->y);
    free(j);


    

    return 0; 
}

//Funciones o Metodos a utilizar
//funcion paso por valor 
void modifica(int numero){
    numero = 100;
    //Con esto creamos una variable numero con un valor 100 pero el valor de n 
    //sigue siendo el mismo (0) 
}

//Funcion de paso por referencia que modifica el valor de una posicion de memoria pasada como argumento 
void modifica2(int *ptrn){
    printf("\tEl valor de ptrn es: %p\n", ptrn);
    *ptrn=100;
    //Recibe la direccion de memoria de una variable a la que apunta a esa direccion 
    //despues cambiamos el valor de esa direccion directamente en memoria 
}

//Funcion que modifica los valores de una estructurta por paso por referencia 
void modifica3(struct PuntoRep *pptr){
    pptr->x = 100;
    pptr->y = 200;
}

//Funcion puntero a entero, reserva un array de enteros de tamaño (n) y devolvernos la 
//direccion de ese primer byte del primer elemento 
int *crea(int n){
    int *ptr = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        ptr[i]=i*10;
    }
    return ptr;
}

//Funcion que crea un punto en memoria dinamica 
Punto crea2(int x, int y){
    Punto nuevo = malloc(sizeof(struct PuntoRep));
    nuevo->x=x;
    nuevo->y=y;
    return nuevo;
}