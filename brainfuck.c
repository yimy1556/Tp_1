#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAN_INICIAL 25
#define DESPLAZAR_PTR '>' 
#define RETROSEDER_PTR '<'
#define SIGUIENTE_VALOR_PTR '+'
#define ANTERIOR_VALOR_PTR '-'
#define IMPRIMIR '.'
#define INGRESAR ','
#define INICIO_CICLO '['
#define FIN_CICLO ']'

int main(int argc, char *argv[]){ if(argc > 2){
    if (argc > 2){
        fprintf(stderr,"%s","Cantidad erronea de parametros\n");
        return -1;
    }

    FILE* archivo = (argc == 1)? stdin : fopen(argv[1],"r");
    
    if(!archivo){
        fprintf(stderr,"%s","archivo fuente inaccesible\n");
        return -1;
    }

    unsigned char* vector_referencia = calloc(0,CAN_INICIAL * sizeof(unsigned char));
    char* texto;
    size_t* tam = NULL;
    pila_t* pila_ciclos = pila_crear();
    getline(&texto,tam,archivo);
    size_t poc_ref = 0;
    size_t cont = 0;
    do{
        switch(texto[cont]){
            case IMPRIMIR : printf("%c",vector_referencia[poc_ref]);
                break;
            case INGRESAR : scanf("%c",vector_referencia[poc_ref]); 
                break;
            case INICIO_CICLO : pila_apilar(pila_ciclos ,poc_ref);
                break;
            case FIN_CICLO : if(!vector_referencia) pila_desapilar(pila_ciclos);
                             else
                                 poc_ref = (size_t)pila_ver_tope(pila_ciclos);  
                break;
        }
    }while(cont < strlen(texto));



    fclose(archivo);
    return 0;
}
