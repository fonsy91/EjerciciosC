#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"



int main(int argc, char const *argv[]){
    
    //https://www.youtube.com/watch?v=ZbLP6o7Q03U&list=PLFOSJTssMYJZmuic5tGla8O_wGXPEm00g&index=3
    
    /*
    //Primer Programa de programando en C calculadora  
    bool entrar = true;
    int salir; 
    do{
        menu();
        printf("\tPulsa (8) si quieres salir de la aplicacion sino (9): ");
        scanf("%d",&salir);
        if(salir == 8){
            entrar = false;
        }
    } while (entrar);
    */    

   //Segundo programa Adivinanzas
   //adivinar(); 

    //Tercer programa Alumnos 
    //almacenar();

    //Cuarto Simulacion de cajero 
    //menuBanco();

    /*
    fprintf: es como printf pero en vez de salida por teclado lo hace en un archivo 
    sprintf: como printf pero en vez de volcar por salida estandar lo hace por otra cadena de caracteres, se 
            puede usar para hacer cadenas de caracteres compuestas, pero puede dar errores de tamaño y cargarte las variables es mejor snprintf
    snprintf:   
    */

   FILE *fp = fopen("pruebas.txt","w");
   int valor = 50;
   fprintf(fp,"El resultado es: %d\n",valor);
   fclose(fp);

   char output[80];
   int dia= 9, mes=3, anio= 1991;
   //Estoy volcando toda esta cadena en output
   sprintf(output,"Mi cumpleaños es %d-%d-%d\n",dia,mes,anio);
   printf("%s",output);

    return 0;
}






