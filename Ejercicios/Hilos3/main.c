//Enunciado
//Realice un código en C usando la biblioteca pthread en el que dada una matriz Anxn se 
//obtengan dos vectores: a y b, ambos de tamaño n. El vector a contendrá los resultados 
//de las sumas de los elementos de las filas de A y el vector b de la multiplicación de 
//los elementos de las columnas. Utilice un hilo para cada par de filas y columnas.
//https://github.com/hendrixroa/posix-threads

//Librerias 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 3

//Variables globales 
int A[3][3]={{1,2,3},
             {4,5,6},
             {7,8,9}};

int a[3] = {0,0,0};
int b[3] = {1,1,1};

//Prototipos
void *SumMult(void *threadid);


int main(int argc, char const *argv[]){
    
    pthread_t threads[NUM_THREADS];
    int *taskids[NUM_THREADS];
    int rc;
    void *status; 
    long t; 

    //Creamos los hilos 
    for (t = 0; t < NUM_THREADS; t++){
        taskids[t] = (int *) malloc(sizeof(int));
		*taskids[t] = t;
		printf("Creando thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, SumMult,(void *) taskids[t]);
        if (rc){
            printf("Error al crear el hilo ret=%d\n",rc);
        }
    }
    //esperamos a que todos los hilos hayyan terminado 
    for (t = 0; t < NUM_THREADS; t++){
        rc = pthread_join(threads[t],&status);
        if (rc){
            printf("Error codigo revuelto es %d\n",rc);
            exit(-1);
        }
        printf("Main: Estado para el thread %ld: %ld\n",t,(long)status);
    }
    
    printf("Main: programa finalizado\n");
    printf("Todos los hilos han terminado de hacer sus ejecuciones\n");

    //Mostramos los vectores a y b 
    int p,q; 
    for (p = 0; p < NUM_THREADS; p++){
        printf("El vector suma es: %d\n",a[p]);
    }

    for (q = 0; q < NUM_THREADS; q++){
        printf("El vector mult es: %d\n",b[q]);
    }
    
    pthread_exit(NULL);
    

    return 0;
}

//Desarrollo de funciones 
void *SumMult(void *threadid){
    int *id_ptr, taskid;
    sleep(1);
    id_ptr = (int *) threadid;
    taskid = *id_ptr;
    int k,k1,k2,sum0=0,mult0=1,sum1=0,mult1=1,sum2=0,mult2=1;

    switch (taskid){
        case 0:
            for (k = 0; k < NUM_THREADS; k++){
                //suma las filas 
                sum0 = sum0 + A[0][k];
                //multiplica las columnas
                mult0 = mult0 * A[k][0];
            }
            a[0] = sum0;
            b[0] = mult0;
            break;
        case 1: 
            for(k1=0;k1<NUM_THREADS;k1++){
                sum1 = sum1 + A[1][k1];
                mult1 = mult1*A[k1][1];
            }
            a[1] = sum1;
            b[1] = mult1;
            break;
		case 2:	
            for(k2=0;k2<NUM_THREADS;k2++){
                sum2 = sum2 + A[2][k2];
                mult2 = mult2*A[k2][2];
            }
            a[2] = sum2;
            b[2] = mult2;
            break;	
    }
    pthread_exit((void *) threadid);
}