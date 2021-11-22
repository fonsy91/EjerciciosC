#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Desarrollo de funciones 
void menu(eAlumno listaA[], int tamA, eCurso listaC[], int tamC){
    int opcion1 = 0;
    int opcion2 = 0;
    int opcion3 = 0; 
    int FrecuenciaCursos[tamC];
    int cursoSeleccionado = -1; 
    int i; 

    for (i = 0; i < tamC; i++){
        FrecuenciaCursos[i] = 0; 
    }

    do{
        opcion1 = ObtenerEleccionDeMenu("\n\n  1 = menu de alumnos \n  2 = menu de cursos \n  3 = asignar cursos a alumnos \n  4 = reportes especiales \n  5 = salir  \n\n",1,5); 
        //tra elegir una opcion mostramos con cada case cada uno de sus submenus
        switch (opcion1){
            case 1: 
                do{
                    opcion2 = ObtenerEleccionDeMenu("\n\n  1 = alta \n  2 = modifica \n  3 = baja \n  4 = listar \n  5 = menu superior  \n\n",1,5);
                    switch (opcion2){
                        case 1:
                            CargarAlumno(listaA,tamA);
                            break;
                        case 2: 
                            ModificarAlumnos(listaA,tamA,listaC,tamC);
                            break; 
                        case 3: 
                            BorrarAlumnos(listaA,tamA,listaC,tamC);
                            break; 
                        case 4:
                            MostrarAlumnos(listaA,tamA,0,listaC,tamC); 
                            break;
                    }
                } while (opcion2 != 5);
                break;
            
            case 2:
                do{
                    opcion2 = ObtenerEleccionDeMenu("\n\n  1 = alta \n  2 = modifica \n  3 = baja \n  4 = listar \n  5 = menu superior  \n\n",1,5);
                    switch (opcion2){
                        case 1:
                            CargarCurso(listaC,tamC);
                            break;
                        case 2: 
                            ModificarCursos(listaC,tamC);
                            break; 
                        case 3: 
                            BorrarCursos(listaC,tamC);
                            break; 
                        case 4:
                            MostrarCursos(listaC,tamC,0);
                            break;
                    }
                } while (opcion2 != 5);
                break;
            case 3: 
                AsignarCursoAAlumno(listaA,tamA,listaC,tamC);
                break;
            case 4:
                do
            {
                opcion3 = ObtenerEleccionDeMenu("\n 1 = Nombres y cursos \n 2 = Listado de todos los cursos con sus alumnos asignados \n 3 = ingresando curso, mostrar alumnos asignados \n 4 = ingresando curso, contar alumnos \n 5 = Ingresando curso, promedio de nota2 de asignados \n 6 = Curso mas seleccionado \n\n 8 = menu superior\n",1,8);
                switch(opcion3)
                {
                case 1:
                    ListadoDeAlumnosConDescripCurso(listaA,tamA,listaC,tamC);
                    break;
                case 2:
                     ListadoCursoConTodosSusAlumnos(listaA,tamA,listaC,tamC);
                    break;
                case 3:
                    cursoSeleccionado = IngresandoCursoListarTodosSusAlumnos(listaA,tamA,listaC,tamC);
                    FrecuenciaCursos[cursoSeleccionado] ++;
                    break;
                case 4:
                    cursoSeleccionado = IngresandoCursoContarCantidadAlumnos(listaA,tamA,listaC,tamC);
                    FrecuenciaCursos[cursoSeleccionado] ++;
                    break;
                case 5:
                    cursoSeleccionado = IngresandoCursoPromedioDeNOTA2deAsignados(listaA,tamA,listaC,tamC);
                    FrecuenciaCursos[cursoSeleccionado] ++;
                    break;
                case 6:
                    MayorFrecuenciaCurso(FrecuenciaCursos,listaC,tamC);
                    break;
                }
            }
            while(opcion3 != 8);
                break; 
        }

    } while (opcion1 != 5);
    

}

//**************************************************************************************************
//**************************************************************************************************

int ObtenerEleccionDeMenu(char menu[], int desde, int hasta){
    int opcion; 
    int mal; 
    do{
        mal = 0; 
        printf("Elija numero del %d al %d",desde,hasta); 
        printf("%s",menu);
        opcion = inputInt("Teclee el numero: ");
        if (opcion < desde || opcion > hasta){
            mal = 1; 
            printf("Introduccion erronea vuelve a intentarlo\n"); 
        }
        return opcion;
    } while (mal);
    
}

int inputInt(char mensaje[]){
    int respuesta; 
    printf("%s",mensaje);
    scanf("%d",&respuesta);
    return respuesta; 
}

//
int CargarAlumno(eAlumno lista[], int tam){
    int indice = BuscarLibre(lista,tam);
    if (indice > -1){
        printf(" INGRESE DATOS PARA CARGAR AL ALUMNO\n");
        lista[indice].legajo = inputInt("Ingrese legajo: ");
        inputString(" Ingrese nombre: ",lista[indice].nombre,30);
        inputString(" Ingrese apellido: ",lista[indice].apellido,30);
        lista[indice].nota1 = inputInt(" Ingrese la nota del primer parcial: ");
        lista[indice].nota2 = inputInt(" Ingrese la nota del segundo parcial: ");
        lista[indice].promedio = (float)(lista[indice].nota1 + lista[indice].nota2)/2;
        lista[indice].idCurso = -1; 
        lista[indice].estado = 1; 
    }else{
        printf("No hay lugar para un nuevo alumno\n");
    }
    return indice; //plaza libre donde se ha ingresado el alumno 
}

//
int BuscarLibre(eAlumno lista[], int tam){
    int i; 
    int resultado = -1;
    for (i = 0; i < tam; i++){
        if (lista[i].estado == -1){
            resultado = i;
            break;  
        }
    }
    return resultado;
}

//
void inputString(char mensaje[], char salida[], int tam){
    printf("%s",mensaje);
    fflush(stdin);
    fgets(salida,tam,stdin);
    salida[strlen(salida)-1] = '\0';
    fflush(stdin);
}

//
void ModificarAlumnos(eAlumno lista[], int tam, eCurso listaC[], int tamC){
    int opcion; 
    int indice = 0; 
    int hasta = ContarOcupados(lista,tam);
    MostrarAlumnos(lista,tam,1,listaC,tamC);
    indice = ObtenerEleccionDeMenu("\n Ingrese numero de alumno ",0,hasta);
    opcion = ObtenerEleccionDeMenu("\n 1 - legajo\n 2 - Nombre \n 3 - Apellido \n 4 - Nota1 \n 5 - Nota2 \n 6 -  Cancelar \n", 1, 6);
    switch (opcion){
        case 1:
            lista[indice].legajo = inputInt("Ingrese nuevo legajo: ");
            break;
        case 2: 
            inputString("Ingrese nuevo nombre: ",lista[indice].nombre,30);
            break;
        case 3:
            inputString("Ingrese nuevo apellido : ", lista[indice].apellido,30);
            break;
        case 4:
            lista[indice].nota1 = inputInt("Ingrese nueva nota 1 : ");
            lista[indice].promedio = (float)(lista[indice].nota1 + lista[indice].nota2) / 2;
            break;
        case 5:
            lista[indice].nota2 = inputInt("Ingrese nueva nota 2 : ");
            lista[indice].promedio = (float)(lista[indice].nota1 + lista[indice].nota2) / 2;
            break;
    }
    
}

//
int ContarOcupados(eAlumno lista[], int tam){
    int i;
    int respuesta = 0; 
    for (i = 0; i < tam; i++){
        if (lista[i].estado == 1){
            respuesta++; 
        }
    }
    return respuesta;
}

//
int MostrarAlumnos(eAlumno lista[], int tam, int ConSubindices, eCurso listaC[], int tamC){
    int i;
    char nombreCurso[30];
    if (ConSubindices){
        printf("\n| %2s | %4s | %20s | %20s | %10s | %10s | %15s | %10s |\n","ID","LEG","NOMBRE","APELLIDO","NOTA1","NOTA2","PROMEDIO","CURSO");
        for (i = 0; i < tam; i++){
            NombreDeCursoPorId(listaC,tamC,lista[i].idCurso,nombreCurso);
            printf("| %2d | %4d | %20s | %20s | %10d | %10d | %15f | %10s |\n",i,
            lista[i].legajo,lista[i].nombre,lista[i].apellido,lista[i].nota1,lista[i].nota2,lista[i].promedio,nombreCurso);
        }   
    }else{
        printf("\n| %4s | %20s | %20s | %10s | %10s | %15s | %10s |\n","LEG.","NOMBRE","APELLIDO","NOTA1","NOTA2","PROMEDIO","CURSO");
        for(i=0;i<tam;i++)
        {
            if(lista[i].estado == 1)
            {
                NombreDeCursoPorID( listaC, tamC, lista[i].idCurso , nombreCurso);
                printf("| %4d | %20s | %20s | %10d | %10d | %15f | %10s |\n",lista[i].legajo,lista[i].nombre,
                lista[i].apellido,lista[i].nota1,lista[i].nota2,lista[i].promedio,nombreCurso);
            }
        }
    }
    
}

//
void NombreDeCursoPorId(eCurso listaC[], int tamC, int ID, char resultado[]){
    int i; 
    strcpy(resultado," ");
    for (i = 0; i < tamC; i++){
        if (listaC[i].estado == 1){
            if (listaC[i].idCurso == ID){
                strcpy(resultado,listaC[i].nombre);
                break;
            }   
        }   
    }
}

//
int ObtenerEleccionMenu(char menu[], int desde, int hasta){
    int opcion;
    int mal;
    do{
        mal = 0; 
        printf("Elija numero de %d a %d",desde,hasta);
        printf("%s",menu);
        opcion = inputInt("Teclee numero: ");
        if (opcion < desde || opcion > hasta){
            mal = 1; 
            printf("Introduccion erronea vuelve a intentarlo\n");
        }
    } while (mal);
    return opcion;
}

//
int BorrarAlumnos(eAlumno lista[], int tam, eCurso listaC[], int tamC){
    int indice = 0; 
    int hasta = ContarOcupados(lista,tam);
    MostrarAlumnos(lista,tam,1,listaC,tamC);
    indice = ObtenerEleccionDeMenu("\nIngrese numero de alumno ",0,hasta);
    lista[indice].estado = -1;
    
}

//
int CargarCurso(eCurso lista[], int tam){
    int indice = BuscarLibreCurso(lista,tam);
    if (indice > -1){
        printf(" INGRESE DATOS PARA CARGAR CURSO \n");
        lista[indice].idCurso = inputInt(" Ingrese ID: ");
        inputString(" Ingrese nombre: ",lista[indice].nombre,30);
        lista[indice].horas = inputInt(" Ingrese la cantidad de horas: ");
        lista[indice].estado = -1; 
        
    }
    
}

//
int BuscarLibreCurso(eCurso lista[], int tam){
    int i; 
    int resultado = -1;
    for (i = 0; i < tam; i++){
        if (lista[i].estado == -1){
            resultado = i; 
            break;
        }
    }
    return resultado; 
}

//
int ModificarCursos(eCurso lista[], int tam){
    int opcion;
    int indice = 0; 
    int hasta = ContarOcupadosCursos(lista,tam);
    MostrarCursos(lista,tam,1);
    indice = ObtenerEleccionDeMenu(" \n Ingrese numero de curso ",0, hasta);
    opcion = ObtenerEleccionDeMenu("\n 1 - id\n 2 - Nombre \n 3 - horas \n", 1, 3);
    switch(opcion)
    {
    case 1:
        lista[indice].idCurso = inputInt("Ingrese nuevo id : ");
        break;
    case 2:
        inputString("Ingrese nuevo nombre : ", lista[indice].nombre,30);
        break;
    case 3:
        lista[indice].horas = inputInt("Ingrese nueva cantidad de horas : ");
        break;
    }
   
}

//
int ContarOcupadosCursos(eCurso lista[], int tam){
    int i;
    int respuesta = 0;
    for ( i = 0; i < tam; i++){
        if (lista[i].estado == 1){
            respuesta++;
        }
    }
    return respuesta; 
}

//
int MostrarCursos(eCurso lista[], int tam, int ConSubindices){
    int i;
    if(ConSubindices)
    {
        printf("\n| %2s | %4s | %20s |%5s |\n","ID","COD.","NOMBRE","HORAS");
        for(i=0;i<tam;i++)
        {
            if(lista[i].estado == 1)
            {
                printf("| %2d | %4d | %20s | %5d |\n", i,lista[i].idCurso,lista[i].nombre,lista[i].horas);
            }
        }
    }
    else
    {
        printf("\n| %4s | %20s |%5s |\n","ID","COD.","NOMBRE","HORAS");
        for(i=0;i<tam;i++)
        {
            if(lista[i].estado == 1)
            {
                printf("| %4d | %20s | %5d |\n",lista[i].idCurso,lista[i].nombre,lista[i].horas);
            }
        }
    }
    
}

//
int BorrarCursos(eCurso lista[], int tam){
    int indice = 0;
    int hasta = ContarOcupadosCursos(lista,tam);
    MostrarCursos(lista,tam,1);
    indice = ObtenerEleccionDeMenu("\nIngrese numero de curso ",0,hasta);
    lista[indice].estado = -1;
    return indice; 
}

//
void AsignarCursoAAlumno(eAlumno listaA[], int tamA, eCurso listaC[], int tamC){
    int indiceAlumno; 
    int indiceCurso; 
    MostrarAlumnos(listaA,tamA,1,listaC,tamC);
    indiceAlumno = ObtenerEleccionDeMenu("Elija un alumno por su numero de ID ",0,ContarOcupados(listaA,tamA));
    MostrarCursos(listaC,tamC,1);
    indiceCurso = ObtenerEleccionDeMenu("Elija un CURSO por su numero de ID",0,ContarOcupadosCursos(listaC,tamC));
    listaA[indiceAlumno].idCurso = listaC[indiceCurso].idCurso; 
}

//
void ListadoDeAlumnosConDescripCurso(eAlumno listaA[], int tamA, eCurso listaC[], int tamC){
    int i;
    char nombreCurso[30] = " ";
    printf("\n| %20s | %20s |  %10s |\n","NOMBRE","APELLIDO", "CURSO");
    for (i = 0; i < tamA; i++){
        if(listaA[i].estado == 1)
            {
                NombreDeCursoPorID( listaC, tamC, listaA[i].idCurso , nombreCurso);
                printf("| %20s | %20s | %10s |\n",listaA[i].nombre,listaA[i].apellido,nombreCurso);
            }
    }
}

//
void ListadoCursoConTodosSusAlumnos(eAlumno listaA[], int tamA, eCurso listaC[], int tamC){
    int i;
    int j;

        for(i=0;i<tamC;i++){
            if(listaC[i].estado == 1){
                for(j=0;j<tamA;j++){
                    if(listaA[j].estado == 1 && listaA[j].idCurso == listaC[i].idCurso){
                        printf("| %20s | %20s | %20s | \n","CURSO","NOMBRE","APELLIDO");
                        printf("| %20s |%20s | %20s | \n",listaC[i].nombre,listaA[j].nombre,listaA[j].apellido);
                    }
                }
            }
        }
}

//
int IngresandoCursoListarTodosSusAlumnos(eAlumno listaA[], int tamA, eCurso listaC[], int tamC){
    int indice = 0;
    int j;
    int opcion = 0;
    int hasta = 0;
    int alguno = 0;
    MostrarCursos(listaC,tamC,1);
    hasta = ContarOcupadosCursos(listaC,tamC);
    indice = ObtenerEleccionDeMenu(" \n Ingrese numero de curso ",0, hasta);

    for(j=0;j<tamA;j++){
        if(listaA[j].estado == 1 && listaA[j].idCurso == listaC[indice].idCurso){
            alguno = 1;
            printf("| %20s | %20s | %20s | \n","CURSO","NOMBRE","APELLIDO");
            printf("| %20s |%20s | %20s | \n",listaC[indice].nombre,listaA[j].nombre,listaA[j].apellido);
        }
    }
    if(!alguno){
        printf("NO SE ENCONTRARON ALUMNOS ASIGNADOS A %s \n", listaC[indice].nombre);
    }
    return indice;
}

//
int IngresandoCursoContarCantidadAlumnos(eAlumno listaA[], int tamA, eCurso listaC[], int tamC){
    int indice = 0;
    int j;
    int opcion = 0;
    int hasta = 0;
    int alguno = 0;
    MostrarCursos(listaC,tamC,1);
    hasta = ContarOcupadosCursos(listaC,tamC);
    indice = ObtenerEleccionDeMenu(" \n Ingrese numero de curso ",0, hasta);

    for(j=0;j<tamA;j++){
        if(listaA[j].estado == 1 && listaA[j].idCurso == listaC[indice].idCurso){
            alguno ++;
        }
    }

    if(alguno){
        printf(" SE ENCONTRARON %d ALUMNOS ASIGNADOS A %s \n", alguno, listaC[indice].nombre);
    }
    else{
        printf("NO SE ENCONTRARON ALUMNOS ASIGNADOS A %s \n", listaC[indice].nombre);
    }
    return indice;
}

//
int IngresandoCursoPromedioDeNOTA2deAsignados(eAlumno listaA[], int tamA, eCurso listaC[], int tamC){
    int indice = 0;
    int j;
    int opcion = 0;
    int hasta = 0;
    int sumatoriaNota2 = 0;
    float promedioNota2 = 0.0;
    int cantidad = 0;
    MostrarCursos(listaC,tamC,1);
    hasta = ContarOcupadosCursos(listaC,tamC);
    indice = ObtenerEleccionDeMenu(" \n Ingrese numero de curso ",0, hasta);

    for(j=0;j<tamA;j++){
        if(listaA[j].estado == 1 && listaA[j].idCurso == listaC[indice].idCurso){
            sumatoriaNota2 += listaA[j].nota2;
            cantidad ++;
        }
    }

    if(cantidad == 0){
        printf(" No hay notas para contabilizar promedio \n" );
    }
    else{
        promedioNota2 = (float)(sumatoriaNota2 / cantidad);
        printf("Promedio de nota2 = %f por alumnos asignados a  %s \n", promedioNota2,listaC[indice].nombre);
    }
    return indice;
}

//
void MayorFrecuenciaCurso(int Frecuencia[], eCurso listaC[],int tamC){
    int max;
    int i;
    int subindice = 0;
    for(i=0;i<tamC;i++){
        if(i == 0 || Frecuencia[i] > max){
            max = Frecuencia[i];
            subindice = i;
        }
    }
    printf("\n EL CURSO MAS SELECCIONADO ES EL %s \n",listaC[subindice].nombre);
}

void InicializarArrayAlumnos(eAlumno lista[], int tam){
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado = -1;
    }
}

//=====================================================================================================================================

void InicializarArrayCursos(eCurso lista[], int tam){
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado = -1;
    }
}

int CargarAlumnosDePrueba(eAlumno lista[],int tam)
{
    int i = 0;
    lista[i].legajo = 1;strcpy(lista[i].nombre, "Alfa");strcpy(lista[i].apellido , "Beta");lista[i].nota1 = 7;lista[i].nota2 = 10;
    lista[i].estado = 1;lista[i].idCurso = 0;lista[i].promedio = (float)(lista[i].nota1 + lista[i].nota2) / 2;
    i = 1;
    lista[i].legajo = 3; strcpy(lista[i].nombre , "Gamma"); strcpy(lista[i].apellido,"Delta"); lista[i].nota1 = 8; lista[i].nota2 = 9;
    lista[i].estado = 1;lista[i].idCurso = -1;lista[i].promedio = (float)(lista[i].nota1 + lista[i].nota2) / 2;
    i = 2;
    lista[i].legajo = 6; strcpy(lista[i].nombre, "Epsilon"); strcpy(lista[i].apellido, "Zeta"); lista[i].nota1 = 6; lista[i].nota2 = 8;
    lista[i].estado = 1;lista[i].idCurso = -1;lista[i].promedio = (float)(lista[i].nota1 + lista[i].nota2) / 2;
    i = 3;
    lista[i].legajo = 8; strcpy(lista[i].nombre ,"Eta"); strcpy(lista[i].apellido,"Theta"); lista[i].nota1 = 5; lista[i].nota2 = 8;
    lista[i].estado = 1; lista[i].idCurso = 4;lista[i].promedio = (float)(lista[i].nota1 + lista[i].nota2) / 2;
    
}

int CargarCursosDePrueba(eCurso lista[],int tam)
{
    int i = 0;
    lista[i].idCurso = 0;strcpy(lista[i].nombre , "Java"); lista[i].horas = 7;lista[i].estado = 1;
    i = 1;
    lista[i].idCurso = 1;strcpy(lista[i].nombre , "C"); lista[i].horas = 17;lista[i].estado = 1;
    i = 2;
    lista[i].idCurso = 2;strcpy(lista[i].nombre , "C#"); lista[i].horas = 37;lista[i].estado = 1;
    i = 3;
    lista[i].idCurso = 3;strcpy(lista[i].nombre , "MS SQL Server"); lista[i].horas = 1;lista[i].estado = 1;
    i = 4;
    lista[i].idCurso = 4;strcpy(lista[i].nombre , "Python"); lista[i].horas = 1;lista[i].estado = 1;
    
}