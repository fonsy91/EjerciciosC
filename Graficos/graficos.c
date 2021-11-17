#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLUT/glut.h>  //librerira para hacer graficas 

int main(int argc, char const *argv[]){
    // Fijar tamaño y posición inicial de las ventanas
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (0, 0);
    // Seleccionar modo de display: RGBA y doble buffer
    glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE);
    // Inicializar la librería GLUT
    glutInit (&argc, argv);


    return 0;
}
