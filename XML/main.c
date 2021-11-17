//Solicitud de XML para la comunicacion con el servidor 
//https://aticleworld.com/create-an-xml-request-in-c-for-server-communication/
#include <stdio.h>
//bibilioteca para el tratamiento de archivos xml 
#include <expat.h>

//Prototipos
void start(void *userData, const char *name, const char *args[]);
void end(void *userData, const char name);
void value(void *userData, const char *val, int len);

int main(int argc, char const *argv[]){
    //https://techybook.in/c-cpp-xml-parsing-using-expat/
    //Este programa lee un archivo xml e imprime el nombre y el valor de cada etiqueta 

    //Creamos un nuevo objeto analizador con xml_ParserCreate
    XML_Parser parser = XML_ParserCreate(NULL);
    //Establecemos controladores para las etiquetas de inicio y finalizacion 
    XML_SetElementHandler(parser, start, end);
    //Configura el controlador para el texto 
    XML_SetCharacterDataHandler(parser,value);

    int len=0; 
    char val[1024] = {}; 
    FILE *fh = fopen("catalogo.xml","r");

    while (len = fread(val, sizeof val, sizeof(char), fh)){
        if (0 == XML_Parse(parser,val,len,len<1024)){
            //int code = XML_GetErrorCode(parser); 
            //const char *msg = (const char *)XML_ErrorString(code);
            //fprintf(stderr,"Error al parseear el codigo %d mensaje %s\n",code,msg);
            printf("Error  al parsear el codigo XML");
            break;
        }
        
    }
    
    XML_ParserFree(parser);



    return 0;
}

//Funciones del archivo 

void start(void *userData, const char *name, const char *args[]){
    printf("%s: ",name);
}

void end(void *userData, const char name){

}

void value(void *userData, const char *val, int len){
    int i; 
    char cpy[128] = {}; 
    for (i = 0; i < len; i++){
        cpy[i] = val[i];
    }
    cpy[i] = 0; 
    printf("%s",cpy); 
}

/*****************TEORIA*****************
 
int XML_Parse(XML_Parser parser, const char *s, int len, int isFinal)

-La función XML_Parse se usa para el análisis de caracteres entrantes en tiempo real Parse, el segundo parámetro es 
el puntero del búfer especificado por el usuario, el tercero es el número de bytes del contenido real en el búfer, y el 
último parámetro representa si el búfer ha terminado. Por ejemplo, el archivo XML a analizar es demasiado grande, pero la 
memoria es escasa y el búfer es pequeño. Puede leer el archivo en un bucle y luego lanzarlo al analizador. Antes de 
leer el archivo, el parámetro isFinal es FALSO, de lo contrario es VERDADERO.

*/