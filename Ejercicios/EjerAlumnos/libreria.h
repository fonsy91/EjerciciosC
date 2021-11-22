
//Estructuras 
typedef struct{
    int legajo;
    char nombre[30];
    char apellido[30];
    int nota1;
    int nota2; 
    float promedio;
    int estado;
    int idCurso;
}eAlumno;

typedef struct{
    int idCurso;
    char nombre[30];
    int horas;
    int estado; 
}eCurso;

//Prototipos de las funciones 
void menu(eAlumno listaA[], int tamA, eCurso listaC[], int tamC);
int ObtenerEleccionDeMenu(char menu[], int desde, int hasta);
int inputInt(char mensaje[]);
int CargarAlumno(eAlumno lista[], int tam);
int BuscarLibre(eAlumno lista[], int tam);
void inputString(char mensaje[], char salida[], int tam);
void ModificarAlumnos(eAlumno lista[], int tam, eCurso listaC[], int tamC);
int ContarOcupados(eAlumno lista[], int tam);
int MostrarAlumnos(eAlumno lista[], int tam, int ConSubindices, eCurso listaC[], int tamC);
void NombreDeCursoPorId(eCurso listaC[], int tamC, int ID, char resultado[]);
int ObtenerEleccionMenu(char menu[], int desde, int hasta);
int BorrarAlumnos(eAlumno lista[], int tamp, eCurso listaC[], int tamC);
int CargarCurso(eCurso lista[], int tam);
int BuscarLibreCurso(eCurso lista[], int tam);
int ModificarCursos(eCurso lista[], int tam);
int ContarOcupadosCursos(eCurso lista[], int tam);
int MostrarCursos(eCurso lista[], int tam, int ConSubindices);
int BorrarCursos(eCurso lista[], int tam);
void AsignarCursoAAlumno(eAlumno listaA[], int tamA, eCurso listaC[], int tamC);
void ListadoDeAlumnosConDescripCurso(eAlumno listaA[], int tamA, eCurso listaC[], int tamC);
void ListadoCursoConTodosSusAlumnos(eAlumno listaA[], int tamA, eCurso listaC[], int tamC);
int IngresandoCursoListarTodosSusAlumnos(eAlumno listaA[], int tamA, eCurso listaC[], int tamC);
int IngresandoCursoContarCantidadAlumnos(eAlumno listaA[], int tamA, eCurso listaC[], int tamC);
int IngresandoCursoPromedioDeNOTA2deAsignados(eAlumno listaA[], int tamA, eCurso listaC[], int tamC);
void MayorFrecuenciaCurso(int Frecuencia[], eCurso listaC[],int tamC);
void InicializarArrayAlumnos(eAlumno lista[], int tam);
void InicializarArrayCursos(eCurso lista[], int tam);
int CargarAlumnosDePrueba(eAlumno lista[],int tam);
int CargarCursosDePrueba(eCurso lista[],int tam);

