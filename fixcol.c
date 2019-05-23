#include "strutil.h"                                      
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    if(argc > 3) return 1;
    FILE* archivo = fopen(argv[1],"r"); 
    size_t cantidad = atoi(argv[2]);
    int texto;
    while (!feof(archivo)){
        for (size_t i = 0; i < cantidad; i++) {
            texto = fgetc(archivo);
            if(texto == '\n' || texto == EOF) break;
            printf("%c",texto);
        }
        if(texto != EOF) printf("\n");
    }
    
    
    
    
    
    
    
    
    /*size_t cantidad_1 = 0;
    ssize_t leidos = getline(&texto,&cantidad_1,archivo);
    while(leidos != -1){ 
        char* parte = substr(texto,cantidad); 
        printf("%s\n",parte);
        free(parte);
        parte = substr(texto + cantidad,strlen(texto));
        printf("%s\n",parte);
        free(parte);
        leidos = getline(&texto,&cantidad_1,archivo);
    }*/
    fclose(archivo);       
}



