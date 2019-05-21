#include "strutil.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

int main(int argc, char *argv[]){
    if(argc < 4){
        char* texto = NULL;
        //char final[] = "\0"; 
        FILE* archivo = fopen(argv[1],"r");
        size_t cantidad = 0;
        //printf("%zu\n",cantidad);
        //ssize_t leidos = 
        ssize_t leidos = getline(&texto,&cantidad,archivo);
        printf("%zu\n",cantidad);
        printf("%zu\n",leidos);
        //fscanf(archivo,"%s\n",texto); 
        size_t len = strlen(texto);
        printf("%s\n",texto);
        printf("%zu\n",len);
        leidos = getline(&texto,&cantidad,archivo);
        printf("%zu\n",leidos);
        printf("%s\n",texto);

        printf("%s\n",texto);
free(texto);
        fclose(archivo);
        /*while(leidos != EOF){ 
            char* parte = substr(texto,cantidad);
            printf("%s\n",parte);
            free(parte);
            parte = substr(texto + cantidad,strlen(texto));
            printf("%s\n",parte);
            free(parte);
            free(texto);
            //leidos = getline(&texto,NULL,archivo);
            leidos = fscanf(archivo,"%s\n",texto);
        }*/
    }
    return 0;
}
