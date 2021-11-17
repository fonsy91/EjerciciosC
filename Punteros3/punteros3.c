#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CABECERAS 
void MostrarVec(int v[]); 

int main(int argc, char const *argv[]){
    
    int array[] = {1,23,31,42,50};
    int *ptr; 
    //apuntamos al prmier elemento del array 
    ptr = array;

    for (int i = 0; i < 5; i++){
        printf("array[%d] = %d\n",i,array[i]);
        //sumamos 0,1,2... al puntero es decir esta avanzando por la memoria y accediendo a su contenido 
        //printf("ptr + %d = %d\n",i, *(ptr+i));
        //printf("ptr + %d = %d\n",i, *ptr++);
        printf("ptr + %d = %d\n",i, *(++ptr));
        
    }
    printf("\n");
    int array2[] = {1,2,3,4,5};
    int *p;
    p = array2; //p = &array2[0]
    MostrarVec(array2);
    printf("\n");
    *p = 10;
    MostrarVec(array2);
    printf("\n");
    *(p+1) = 20;    //En la siguiente posicion donde aapunta le agrego un 20
    MostrarVec(array2);
    printf("\n");
    //printf("%d\n",*(++p));
    /*
    Diferencias de: *p++, (*p)++, ++p, ++*p
        *p++ : primero toma el valor de contenido donde apunta y despues apunta al siguiente 
        (*p)++ : primero obtiene el primer valor y despues lo incrementa en 1 
        ++p: primero incrementa el puntero p en 1 (apunta al segundo elemento) y luego sacar el valor 

    */
    //printf("*p++ = %d\n", *p++);
    printf("El valor ahora es: %d",*p);
    printf("(*p)++ = %d",(*p)++);
    
    


     

    return 0;
}

//FUNCIONES 
void MostrarVec(int v[]){
    printf("Los valores del vector actualmente son: ");
    for(int i=0; i<5; i++){
        printf("%d ",v[i]);
    }
}
