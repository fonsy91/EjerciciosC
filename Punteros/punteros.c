#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Compilar  un programa usamos: gcc -Wall -o program program.c
//Ejecutar: ./program 

//Cabeceras de funciones del programa 
void intercambia(int *x, int *y);

int main (void){
    int a=7, b=8;

    printf("La direccion de memoria de 'a' es: %p\n",&a);
    printf("La direccion de memoria de 'b' es: %p\n",&b);

    printf("a=%d b=%d\n",a,b);
    intercambia(&a,&b);
    printf("a=%d b=%d\n",a,b);

    //**************************************
    int *p;
    int m[100];

    p = &m[0];
    m[0]=4;
    printf("El valor es: %d\n", *p);
    
    //***************************************
    int c=8;
    int *pc;

    pc=&c;  //pc esta apuntando a c
    printf("El puntero pc contiene: %p\n", pc); //escibe lo que contiene la variable puntero (direccion de memoria donde apunta)
    printf("El valor apuntado por pc es: %d\n", *pc);  //escribe lo que contiene donde apunta 
    *pc=50;
    printf("Cambiamos el valor e imprimimos: %d\n",*pc);

    //************************
    int v[5]={1,2,3,4,5};
    int *ptr;
    ptr=v; //apuntamos al primer elemento del vector 
    for(int i=0; i<6; i++){
        printf("\n%d",*ptr+i);
    }

    //Para char no es recomendable usar scanf ya que solo coge la frase hasta que hay un espacio 
    char vector [13];
    printf("\nIntroduce una frase: ");
    fgets(vector,13,stdin);
    printf("El contenido del vector es: %s\n",vector);
    fflush(stdin);


    //Comparacion de dos cadenas. Siempre que se pidan mas de dos cosas por teclado es mejor usar fflush 
    char cad1 [5];
    char cad2 [5];
    printf("Introduce una cadena: ");
    fgets(cad1,5,stdin);
    printf("Introduce una segunda cadena: ");
    fflush(stdin); //limpiamos el buffer
    fgets(cad2,5,stdin); 
    if(strcmp(cad1,cad2)== 0){ //strcmp devuelve 0 si son iguales 
        printf("Las dos cadenas son iguales\n");
    }else{
        printf("Las dos cadenas son diferentes\n");
    }

}

//Funciones del programa 
//x recibe la direccion de memoria de (a) e y recibe la direccion de memoria de (b)
void intercambia(int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z; 
}