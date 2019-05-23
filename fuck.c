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


bool valido(int caracter){
    return(caracter == DESPLAZAR_PTR || caracter == RETROSEDER_PTR || caracter == SIGUIENTE_VALOR_PTR || caracter == ANTERIOR_VALOR_PTR );
}

int accion(int caracter){
    if(caracter == DESPLAZAR_PTR && caracter == SIGUIENTE_VALOR_PTR) return 1;
    return -1;
}
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
    long poc_archivo;
    pila_t* pila_ciclos = pila_crear();
    int texto = 0;
    size_t poc_ref = 0;

    do{
        texto = fgetc(archivo);

        switch(texto){
            case IMPRIMIR : printf("%c",vector_referencia[poc_ref]);
                break;
            case INGRESAR : scanf("%c",&vector_referencia[poc_ref]); 
                break;
            case INICIO_CICLO : poc_archivo = ftell(archivo);
                                pila_apilar(pila_ciclos ,&poc_archivo);
                break;
            case FIN_CICLO : if(!vector_referencia) pila_desapilar(pila_ciclos);
                             else
                                 fseek(archivo,(long)pila_ver_tope(pila_ciclos)-1,SEEK_SET);  
                break;
        }
    }while(!feof(archivo));


    fclose(archivo);
    return 0;
}
