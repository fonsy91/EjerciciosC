#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

//Variables globales 
struct alumno{
    char nombre[30];
    int edad; 
    float ingles, fisica; 
}alumno[5];    //indicamos que va a haber un maximo de 30 estructuras de tipo alumno 

//Dinero actual del banco 
int saldo_actual = 100;
int cantidad; 

//Desarrolo de las funciones publicas y privadas ****************************
//Funcion MENU 
void menu(){
    int opcion; 
    int num_a, num_b; 
    printf("\t1. Sumar\n");
    printf("\t2. Restar\n");
    printf("\t3. Multiplicar\n");
    printf("\t4. Dividir\n");
    printf("\nEliga una opcino: ");
    scanf("%d",&opcion);
    putchar('\n');
    printf("\tIntroduce el valor del primer numero: ");
    scanf("%d",&num_a);
    printf("\tIntroduce el valor del segundo numero: ");
    scanf("%d",&num_b);
    switch (opcion)
    {
    case 1: 
        sumar(num_a,num_b);
        break;
    case 2: 
        restar(num_a,num_b);
        break;
    case 3: 
        multiplicar(num_a,num_b);
        break; 
    case 4: 
        dividir(num_a,num_b);
        break; 

    default:
        printf("Opcion mal introducida");
        break;
    }
}

//Funcion que suma dos numero 
void sumar(int num_a, int num_b){
    printf("\tEl resultado de la suma es: %d\n",num_a+num_b);
}
//Funcion que resta dos numero 
void restar(int num_a, int num_b){
    printf("\tEl resultado de la resta es: %d\n",num_a-num_b);
}
//Funcion que multiplica dos numero 
void multiplicar(int num_a, int num_b){
    printf("\tEl resultado de la multiplicacion es: %d\n",num_a*num_b);
}
//Funcion que divide dos numeros 
void dividir(int num_a, int num_b){
    printf("\tEl resultado de la division es: %d\n",num_a/num_b);
}

//Desarrolo de funciones del ejercicio 2 
void adivinar(){
    srand(time(NULL));
    int random = 1+rand() % ((50+1)-1); //numero aleatorio entre 1 y 50
    int valor;
    printf("El numero aletorio es: %d\n",random);
    do{
        printf("\nIntroduce un numero: ");
        scanf("%d",&valor);
        //Le damos pistas 
        if(random < valor){
            printf("El numero aleatorio es menor a tu valor");
        }else if(random > valor){
            printf("El numero aleatorio es mayor a tu valor "); 
        }
        else{
            printf("La respuesta es correcta programa finalizado\n");
        }
    }while(random != valor);
}

//Funciones ejercicio 3
void almacenar(){
    //Limpiamos la memoria de nuestro buffer 
    fflush(stdin);
    int cantidad; 
    printf("Introduzca la cantidad de alumnos: ");
    scanf("%d",&cantidad);
    //Hacemos un for para almacenar en la estructura todos los datos 
    for(int i; i<cantidad; i++){
        printf("\nAlumno[%d] - Intro Nombre: ",i);
        scanf("%s",alumno[i].nombre);
        printf("\nAlumno[%d] - Intro Edad: ",i);
        scanf("%d",&alumno[i].edad);
        printf("\nAlumno[%d] - Intro Nota Ingles: ",i);
        scanf("%f",&alumno[i].ingles);
        printf("\nAlumno[%d] - Intro Nota Física: ",i);
        scanf("%f",&alumno[i].fisica);
    }
    //Mostramos los resultados por pantalla 
    for (int i = 0; i < cantidad; i++){
        printf("\nAlumno[%d] -Nombre: %s -Edad: %d -Clasificaciones(Ingles/Fisica): %f %f",i, alumno[i].nombre, alumno[i].edad, alumno[i].ingles, alumno[i].fisica);
    }
        
    printf("\n");
}

//Cuarto Simulacion de cajero ****************************
void menuBanco(){
    int opc;
    printf("\n1. Consultar saldo.");
    printf("\n2. Depositar.");
    printf("\n3. Retirar.");
    printf("\n4. Salir.");
    printf("Eliaga una opcion: ");
    scanf("%d",&opc);
    switch (opc){
    case 1:
        printf("\nSu saldo actual es: %d", saldo_actual);
        break;
    case 2: 
        printf("Cuanto saldo desdea despositar: ");
        scanf("%d",&cantidad);
        depositar(cantidad);
        break;
    case 3: 
        printf("Cuanto saldo desdea retiar: ");
        scanf("%d",&cantidad);
        retirar(cantidad);
        break;
    case 4: 
        break; 
    
    default:
        printf("\nOpcion no valida");
        break;
    }
}

void depositar(int cantidad){
    saldo_actual += cantidad; 
    printf("\nHas depositado exitosamente %d, su saldo actual es: %d", cantidad, saldo_actual);
}
void retirar(int cantidad){
    if(cantidad <= saldo_actual){
        saldo_actual -= cantidad; 
         printf("\nHas retirado exitosamente %d, su saldo actual es: %d", cantidad, saldo_actual);
    }else{
        printf("\nNo tienes suficinete saldo para retirar, el saldo actual es: %d",saldo_actual);
    }
    
}



