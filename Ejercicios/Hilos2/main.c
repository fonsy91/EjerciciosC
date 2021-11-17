#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

//Prototipos
int aleatorio(int min, int max);
double obtenerTiempoActual();
void *funcion_hilo(void *arg);

//Estructura 
typedef struct arregloindices{
    int *arreglo; 
    int inicio;
    int final; 
}estructura;

int main(int argc, char const *argv[]){
    
    srand(time(NULL));
    //Comprobamos que se ingresan 3 argumentos: 1º: el ejecutor 2ºtamaño 3º numero de hilos
    if(argc != 3){
        printf("No se han introducido 3 argumentos");
    }
    
    int size = atoi(argv[1]);
    int num_hilos = atoi(argv[2]); 
    int *arreglo = NULL;
    int i; 
    //reservamos memoria dinamica para el arreglo 
    arreglo = (int *) malloc(size * sizeof(int));
    //rellenamos el arreglo con numeros aleatorios 
    for (i = 0; i < size; i++){
        int num = aleatorio(1,14);
        arreglo[i] = num;   
    }
    //Obtenemos el tiempo actual 
    double time1 = obtenerTiempoActual();
    
    //Creamos un arreglo de hilos
    pthread_t hilos[num_hilos];
    int j; 
    int razon = size/num_hilos; 
    int v = 0; 

    if (size % num_hilos == 0){ //numeros con division es exacta 
        for (j = 0; j < num_hilos; j++){
            //variable de tipo estructura 
            estructura *s_hilo = malloc(sizeof(estructura));
            s_hilo->arreglo= arreglo;
            s_hilo->inicio= v;
            v *= razon;
            s_hilo->final = v-1; 
            int status = pthread_create(&hilos[j],NULL,funcion_hilo,(void *)s_hilo);
            if (status < 0){
                fprintf(stderr,"Error al crear el hilo");
            }    
        }
    }else{
        //numeros con division no exacta 
        for (j = 0; j < num_hilos; j++){
            //variable de tipo estructura 
            estructura *s_hilo = malloc(sizeof(estructura));
            s_hilo -> arreglo=arreglo;
			s_hilo -> inicio=v;
			v += razon;
            if (v > size){
                s_hilo->final = size;
            }else{
                s_hilo->final = v;
            }
            v += 1;
            int status=pthread_create(&hilos[j],NULL,funcion_hilo,(void*)s_hilo);
			if(status<0){
				fprintf(stderr,"Error al crear el hilo");
			} 
        }
    }
     
    int h; 
    long total = 0; 
    for (h = 0; h < num_hilos; h++){
        void *retorno = malloc(sizeof(long));
        pthread_join(hilos[h],retorno);    
        total = total + *((long *) retorno); 
        free(retorno);
    }
    
    //printf ("La suma total es %lu\n",total);
    double time2 = obtenerTiempoActual();
	double final= time2-time1;
	//printf("%.9f\n",final);
	printf ("El tiempo final de ejecuccion es %.9f\n",final);
	free(arreglo);


    return 0;
}

//Desarrollo de funciones 
//Funcion que crea un numero aleatorio entre un min y un max
int aleatorio(int min, int max){
    return (rand() % (max-min+1)) + min; 
}

double obtenerTiempoActual(){
    //Estructura que contiene un intervalo dividido en segundos y nanosegundos 
    //time_t tv_sec; // seconds
    //long tv_nsec; // and nanoseconds
    struct timespec tsp; 
    clock_gettime(CLOCK_REALTIME,&tsp);

    double secs = (double) tsp.tv_sec;
    double nano = (double) tsp.tv_nsec/1000000000.0;
    return secs+nano; 
}

void *funcion_hilo(void *arg){
    estructura *argumentos = (estructura *) arg; 
    int i = 0; 
    int suma = 0; 
    for (i = argumentos->inicio; i <= argumentos->final; i++){
        suma = suma + argumentos->arreglo[i];
    }
    //printf ("La suma de este hilo es %d\n", suma);
	return (void *) (size_t) suma;
}