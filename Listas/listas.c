#include <stdio.h>
#include <stdlib.h>


//Definimos una estructura de tipo nodo 
typedef struct nodo{
    int dato; 
    struct nodo *siguiente; 
}NODO;

//Cabeceras de las funciones ***********************
NODO* CreaNodo(int dato);
int InsertaInicio(NODO **cabeza, int dato);
void imprimirLista(NODO *cabeza);
int InsertaFinal(NODO **cabeza, int dato);
int EstaVacia(NODO *cabeza);
int ExisteElemento(NODO *cabeza, int dato);

//FUNCION PRINCIPAL **************************
int main(void){
    //creamos un nodo vacio 
    NODO *cabeza = NULL;

    InsertaInicio(&cabeza,5); 
    InsertaInicio(&cabeza,4); 
    InsertaFinal(&cabeza,6);
    imprimirLista(cabeza);

    
}


//Funcion que crea y devuelve un nuevo nodo 
NODO *CreaNodo(int dato){
    NODO *nuevo = NULL;
    nuevo = (NODO*)malloc(sizeof(NODO));
    if(nuevo != NULL){
        nuevo -> dato=dato;
        nuevo -> siguiente =NULL;
    }
    return nuevo;
}

//Funcion que inserta en el inicio 
int InsertaInicio(NODO **cabeza, int dato){
    NODO *nuevo = NULL; 
    nuevo = CreaNodo(dato);
    if(nuevo != NULL){
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        return 1; 
    }

    return 0; //en caso de que no haya insertado el nodo
}

//Funcion que inserta al final de la lista 
int InsertaFinal(NODO **cabeza, int dato){
    NODO *nuevo = NULL, *naux = *cabeza;

    nuevo = CreaNodo(dato);
    if(nuevo != NULL){
        while(naux->siguiente != NULL){
            naux = naux->siguiente;
        }
        naux->siguiente=nuevo;
        return 1; 
    }
    return 0; 
    
}

//Funcino que comprueba si una lista esta vacia 
int EstaVacia(NODO *cabeza){
    if(cabeza == NULL){
        return 1;
    }else{
        return 0; 
    }
}

//Funcion que comprueba si existe un elemento en la lista 
int ExisteElemento(NODO *cabeza, int dato){
    //creamos un puntero auxiliar que apunte  a la cabeza 
    NODO *naux =  cabeza; 
    //mientras se recorran los elementos de la lista y hay 
    while (naux != NULL){
        if(naux->dato == dato){
            return 1; 
        }
        naux = naux->siguiente;
    }
    return 0; 
    
}

//Funcion que recorre la lista de nodos 
void imprimirLista(NODO *cabeza){
    NODO *naux = cabeza;

    while (naux != NULL){
        printf("%d \n",naux->dato);
        naux = naux->siguiente;
    }
     
}