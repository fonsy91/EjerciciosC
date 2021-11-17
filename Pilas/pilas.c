#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Estructura de tipo coche 
typedef struct coche{
    char matricula[10];
    int modelo;
    int color;
    int marca; 
}Coche;

//Estructura tipo nodo
typedef struct nodo{
    Coche *dato; 
    struct nodo *siguiente;
}Nodo;

//Estructura tipo pila 
typedef struct pila{
    Nodo *tope; //puntero que apunta a la cabeza de la pila 
    int total;  //indica el numero de nodos que hay en la pila inicialmente a cero 
}Pila;

//Declaracion de cabeceras ***************************************************
Coche *CrearCoche(char matricula[10], int modelo, int color, int marca);
Nodo *CreaNodo(Coche *coche);
Pila *CreaPilas();
int estaVacia(Pila *pila);
void insertar(Pila *pila, Nodo *nodo);
void imprimir(Pila *pila);
void eliminar(Pila *pila);

//FUNCION PRINCIPAL ************************
int main(void){

    Pila *p; 
    Coche *c1, *c2;
    Nodo *n, *n2;

    c1 = CrearCoche("A1234", 1991, 1, 1);
    c2 = CrearCoche("B1234", 2021, 2, 2);
    p = CreaPilas();
    n = CreaNodo(c1);
    n2 = CreaNodo(c2);
    insertar(p,n); //insertamos el primer nodo 
    insertar(p,n2);
    printf("Los elementos de la pila son los siguientes: \n");
    imprimir(p);
    printf("Eliminamos el primer elemento de la pila\n");
    eliminar(p);
    imprimir(p);

}
//FIN FUNCION PRINCIPAL ********************

//FUNCIONES DEL PROGRAMA *******************
//Como un constructor crea coches 
Coche *CrearCoche(char matricula[10], int modelo, int color, int marca){
    //Creamos espacio en memoria para un coche 
    Coche *aux = (Coche*) malloc(sizeof(Coche));
    //esta asignando el valor string de matricula a aux->matricula 
    strcpy(aux->matricula,matricula);
    aux->modelo = modelo;
    aux->color = color;
    aux->marca = marca;
    //devolvemos la referencia de aux 
    return aux;
}

//crea nodos 
Nodo *CreaNodo(Coche *coche){
    Nodo *aux = (Nodo*) malloc(sizeof(Nodo));
    aux->dato = coche;
    aux->siguiente = NULL; 
    return aux; 
}

//Crea Pila vacia 
Pila *CreaPilas(){
    Pila *aux = (Pila*) malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->total = 0;
    return aux; 
}

//Funciones para operar con pilas 
//1 si esta vacia y 0 no esta vacia 
int estaVacia(Pila *pila){
    //si total es cero esta vacia 
    if(pila->total == 0){
        return 1; 
    }else{
        return 0; 
    }
}

//Inserta nodos en la pila cada nodo tiene un dato de tipo coche y un puntero al siguiente nodo 
void insertar(Pila *pila, Nodo *aux){
    if(estaVacia(pila) == 1){
        pila->tope = aux; //el puntero apunta al nodo aux en caso de estar vacia la pila 
    }else{
        //Del nuevo nuevo nodo a insertar comogemos el puntero siguiente y apuntamos a tope es decir, a la cima 
        //de la pila en este momento en el ultimo elemento se estara apuntando con los punteros siguiente y tope, por 
        //ultimo cogeremos el puntero cima (tope) y hacemos que apunte el nuevo nodo aux que ahora sera la cima. 
        aux->siguiente = pila->tope;
        pila->tope = aux;
    }
    //incrementamos la variable total 
    pila->total++; 
}

//Recorre una pila
void imprimir(Pila *pila){
    //creamos una variable de tipo puntero a nodo que apunte a la cima de la pila 
    Nodo *aux = pila->tope; 
    while(aux != NULL){
        printf("- %s %d %d %d \n",aux->dato->matricula, aux->dato->modelo, aux->dato->color, aux->dato->marca);
        aux= aux->siguiente;
    }
}

//Desapila o elimina el primer elemento de una pila 
void eliminar(Pila *pila){
    Nodo *aux;
    aux = pila->tope; //aux apunta a la cabeza de la pila 
    pila->tope = aux->siguiente;  //El puntero tope apunta al siguiente elemento 
    free(aux);    //eliminamos aux
}