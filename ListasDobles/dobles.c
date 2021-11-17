#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct nodo{
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior; 
}NODO;

//Prototipo de funciones 
NODO *CrearNodo(int dato);
int InsertarInicio(NODO **cabeza, int dato);
int InsertarFinal(NODO **cabeza, int dato); 
void imprimirLista(NODO *cabeza);
int Eliminar(NODO **cabeza, int dato); 

int main(void){
    
    NODO *cabeza = NULL; 
    InsertarInicio(&cabeza,5);
    InsertarInicio(&cabeza,6);
    InsertarFinal(&cabeza,20);
    Eliminar(&cabeza,6);
    imprimirLista(cabeza);
    
}

//FUNCINOES************
NODO *CrearNodo(int dato){
    NODO *nuevo = NULL;
    nuevo = (NODO*) malloc(sizeof(NODO));
    if(nuevo != NULL){ //se a podido reservar la memoria 
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL; 
    }
    return nuevo; 
}

int InsertarInicio(NODO **cabeza, int dato){
    NODO * nuevo = NULL;
    nuevo = CrearNodo(dato); 
    //validamos si el nodo se ha creado 
    if(nuevo != NULL){
        nuevo->siguiente = *cabeza; 
        nuevo->anterior = NULL;     
        //si ya hay un dato 
        if(*cabeza != NULL){
            (*cabeza)->anterior = nuevo;
        }
        *cabeza=nuevo; 
        return 1; 
    }
    return 0;  //que no se inserto 
}

void imprimirLista(NODO *cabeza){
    NODO *aux = cabeza;
    while (aux != NULL){
        printf("%d \n",aux->dato);
        aux = aux->siguiente;
    }
    
}

int InsertarFinal(NODO **cabeza, int dato){
    NODO * nuevo = NULL, *aux= *cabeza; 

    nuevo=CrearNodo(dato);
    //validamos que se creo el nuevo nodo
    if(nuevo != NULL){
        while(aux->siguiente != NULL){
            //avanzamos hasta el ultimo elemento de la lista 
            aux=aux->siguiente; 
        }
        nuevo->anterior=aux;
        aux->siguiente=nuevo; 
        return 1; 
    }
    return 0; 
}

int Eliminar(NODO **cabeza, int dato){
    NODO *actual = *cabeza, *ant =NULL, *sig= NULL;
    while (actual != NULL){
        if(actual->dato == dato){
            if(actual == *cabeza){  //SI es el nodo cabeza
                *cabeza=actual->siguiente;
                if(actual->siguiente != NULL){
                    actual->siguiente->anterior = NULL;
                }
            }
            else if(actual->siguiente == NULL){    //si es el nodo final
                ant = actual->anterior;
                actual->anterior = NULL;
                ant->siguiente = NULL;
            }else{  //si es nodo intermedio
                ant=actual->anterior;
                actual->anterior = NULL;
                sig = actual->siguiente;
                actual->siguiente= NULL;
                ant->siguiente = sig;
                sig->anterior =ant;
            }
            free(actual);
            return 1; 
        }
        actual = actual->siguiente;
    }
    return 0; 
    
}