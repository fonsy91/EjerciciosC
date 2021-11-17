//LIBRERIAS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

#define N 1000
#define N1 10

//DESARROLLO DE FUNCIONES 
//metodo de Serie de Lebinz a proximacion a pi: 1-1/3+1/5-1/7+1/9...=pi/4
void serieLebinz(){
    float s=0; 
    int signo=1, k;
    for ( k= 0; k < N; k++){
        s=s+1.0/(2*k+1)*signo;
        signo = signo-signo;  
    }
    printf("Aproximacion de pi con %d terminos \n%f\n ",N,4*s);
}

//conversion de un numeros a su caracter codigo ASCII 
void conversionCarac(){
    unsigned char num; //variable sin signo con rango [0,255] no tiene numeros negativos 
    num = 90; 
    while (num<=100){
        printf("El numero %d es equivalente a %c en codigo ASCII\n",num,num);
        num++;
    }
}

//Comprueba si es un numero primo 
void esPrimo(){
    int i,x; 
    printf("Introduzca un numero: ");
    scanf("%d",&x);
    if (x<=0){
        printf("El numero es negativo\n");
    }else{
        if (x==1){
            printf("El numero es primo\n"); 
        }else{
            i=2;
            while (x%i != 0){
                //saltamos los numeros que no son primos
                i++; 
            }
            if (x == i){
                printf("El numero es primo\n"); 
            }else{
                printf("El numero no es primo\n");
            }   
        }
    }
}

//Conversor de segundos 
void converSegundos(){
    int num,dias,hor,minu,seg; 
    printf("Introduzca los segundos: ");
    scanf("%d",&num); 
    //conversiones 
    dias = (num/86400);
    hor=((num-dias*86400)/3600);  
    minu=((num - (hor*3600+dias*86400)) / 60);  
    seg=num-(dias*86400+hor*3600+minu*60);  
    printf("%ddias %dh %dm %ds\n" ,dias,hor,minu,seg);  
}

//Numero aleatorio
void aleatorio(){
    int numero,cantidad,contador; 
    int hora = time(NULL);
    srand(hora); 
    //recogemos la cantidad de numeros que quiere el usuario 
    printf("Ingrese la cantidad de numeros que desea generar: "); 
    scanf("%d",&cantidad); 
    //Generamos un ciclo con la cantidad de veces indicada 
    for (contador  = 0; contador < cantidad; contador++){
        numero = rand()%100;
        printf("%d \n",numero);
    }
}

//Vector de 10 componentes y mostrarlo 
void vector(){
    float v[N1]; 
    int i; 
    //leemos el vector 
    for ( i = 0; i < N1; i++){
        printf("\nV[%d]?: ",i+1);
        scanf("%f",&v[i]);
    }
    //mostramos el vector 
    for (i = 0; i < N1; i++){
        printf("\nV[%d]=%f",i+1,v[i]);
    }
}

//Encriptacion de un texto
void encriptar(){
    char ch;
    int n=1;
    getchar();
    printf("Introduzca los caracteres.\n");
    printf("Pulse ^Z para finalizar.\n");
    while ((ch = getchar()) != EOF){
        if (ch == '\n'){
            printf("%c",ch);
        }else{
            printf("%c",ch+n);
        }
        
    }
     
}