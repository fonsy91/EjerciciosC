//Librerias 
#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TopeAlumnos 10
#define TopeCursos 10


int main(int argc, char const *argv[]){

    eAlumno ListadoAlumnos[TopeAlumnos];
    eCurso ListadoCursos[TopeCursos];

    InicializarArrayAlumnos(ListadoAlumnos,TopeAlumnos);
    InicializarArrayCursos(ListadoCursos,TopeCursos);
    CargarAlumnosDePrueba(ListadoAlumnos,TopeAlumnos);
    CargarCursosDePrueba(ListadoCursos,TopeCursos);
    menu(ListadoAlumnos,TopeAlumnos,ListadoCursos,TopeCursos);

    return 0;
}
