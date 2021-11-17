#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

//Protoripo de funciones 
void *thread_routine(void *arg);

int main(int argc, char const *argv[]){
    //Compilacion: gcc main.c -pthread
    //Ejecucion. ./a.out <num de lineas>
    //creamos una variable de tipo hilo
    pthread_t thread1; 
    //convertimos el primer argumento a char con atoi
    int value = atoi(argv[1]);
    
    /*
    *Funcion que cre el hilo argumentos: 
    *1º: puntero a variable de tipo hilo
    *2º: atributos del hilo (NULL)
    *3º: rutina que se va a ejecutar cuando se cree el hilo 
    *4º argumentos del start rutine del hilo 
    *return 0 exito 
    */
   if (0 != pthread_create(&thread1,NULL, thread_routine,&value)){
       return -1; 
   }
   
   //Hacemos que el main se espere hasta que el hilo halla acabado 
   pthread_join(thread1,NULL);
    

    return 0;
}

//funcion que queremos que ejecute el hilo abre un fichero y escribe una linea x veces 
void *thread_routine(void *arg){
    //casteamos puntero generico a tipo entero y despues con * obtenemos el contenido 
    int nr_lines = *((int *)arg); 
    int fd; 
    char buffer[] = "Nueva linea \n";

    printf("El hilo comienza a ejecutarse...\n");
    for (int i = 0; i < nr_lines; i++){
        //abrimos un fichero
        fd = open("/Users/alfonsomunozcasado/Desktop/Lenguajes/LenguajeC_Entrevista/Ejercicios/Hilos/ejem.txt",O_WRONLY|O_APPEND);
        write(fd,buffer, sizeof(buffer)-1);
        close(fd);
    }
    return NULL;
}
