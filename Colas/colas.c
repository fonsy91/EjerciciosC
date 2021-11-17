#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct nodo{
    int dato; 
    struct nodo *siguiente;
}Nodo;

//cabeceras de las funciones 
void insertar(Nodo *frente, Nodo *fin, int n);
bool Colavacia(Nodo *frente);
void eliminar(Nodo *frente, Nodo *fin, int n);

//Funcion principal 
int main(void){
    //creamos los dos nodos importantes primero y ultimo de la cola fifo 
    Nodo *primero = NULL;
    Nodo *ultimo = NULL; 

    int dato; 
    printf("Introduzca un numero entero: ");
    scanf("%d",&dato); 
    insertar(primero, ultimo, dato);

}

//Funciones usadas *******************************
void insertar(Nodo *frente, Nodo *fin, int n){
    //reservamos memoria para un nuevo nodo 
    Nodo *nuevo_nodo = (Nodo*) malloc(sizeof(Nodo)); //reservamos espacio para el nodo
    nuevo_nodo->dato=n; //le damos un valor al campo valor del nodo 
    nuevo_nodo->siguiente = NULL;  //y el campo siguiente lo ponemos a null 
    //Comprobamos is la cola esta vacia 
    if(Colavacia(frente)){  //si lo esta 
        frente = nuevo_nodo; 
    }else{
        //si no lo esta lo ponemos al final 
        fin->siguiente=nuevo_nodo; 
    }
    fin=nuevo_nodo; 
    printf("\tDato %d insertado correctamente en la cola\n", n);

}

//Funcion para saber si una cola esta vacia  
bool Colavacia(Nodo *frente){
    //Si el condicional es cierto devuelve true sino false 
    return (frente == NULL)? true : false; 
}

void eliminar(Nodo *frente, Nodo *fin, int n){
    n=frente->dato;
    Nodo *aux = frente; 

    if(frente == fin){ //solo hay un elemento 
        frente = NULL;
        fin = NULL; 
    }else{
        frente=frente->siguiente;
    }

    free(aux);
}