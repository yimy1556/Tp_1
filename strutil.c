#define _POSIX_C_SOURCE 200809L
#include "strutil.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool vector_redimensionar(char** datos ,size_t nuevo_tamanio){
    char** datos_nuevo = realloc(datos,nuevo_tamanio * sizeof(char*));
    if (!datos_nuevo) return false;
    datos = datos_nuevo;
    return true;                                                                                                        
}  

size_t cant_letras(char** vec){
    size_t cant_letras = 0;
    for (int i = 0; vec[i] != NULL ;i++){
        cant_letras += strlen(vec[i]) + 1;
    }
    return  cant_letras;
 }

char *substr(const char *str, size_t n){
    if(strlen(str) < n) n = strlen(str);
    char* palabra = malloc(n+1);
    strncpy(palabra,str,n+1);
    palabra[n] = '\0';
    return palabra;
}
size_t cantidad_sep(const char *str ,char sep){
    size_t cantidad_sep = 0;
    for (size_t i = 0;i <= strlen(str); ++i) {
        if(str[i] == sep) cantidad_sep++;            
    }
    return cantidad_sep;
}


char** split(const char *str, char sep){
    size_t cantidad = cantidad_sep(str,sep);
    printf("%zu\n",cantidad);
    char** vector_palabra = malloc(cantidad + 2);
    if(!vector_palabra) return NULL;
    size_t n_pal = 0, tam = 0, desp = 0;
    for (size_t i = 0; i <= strlen(str); ++i){
        if(str[i] != sep && str[i] != '\0') n_pal++;
        else {
            vector_palabra[tam] = substr(str + desp,n_pal);
            desp += n_pal + 1,tam++ ,n_pal = 0;
        }
    }
    vector_palabra[cantidad + 1] = NULL;

    //vector_redimensionar(palabra,tam + 2);
    return vector_palabra;
}

char *join(char **strv,char sep){
    char* palabra = malloc(cant_letras(strv) * sizeof(char));
    if(!palabra) return NULL;
    for (int i = 0;strv[i] != NULL;i++){
        strcat(palabra,strv[i]);
        if(strv[i+1] != NULL) strcat(palabra,&sep); 
    }
    return palabra;
}

void free_strv(char *strv[]){
    for (int i = 0; strv[i] != NULL; ++i){
        free(strv[i]);       
    }
    free(strv);
}

