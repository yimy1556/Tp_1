#define _POSIX_C_SOURCE 200809L
#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>


void probar_substr(){
	char* ver_final="matute\0";
	char* segundo = substr(ver_final+3, 300);
	printf("'%s'\n", segundo);
	free(segundo);
	printf("__FINAL DE PRUEBA SUBSTR___\n");

}
void probar_split(){
	//char* vacio= "";
	char* coma = ",";
	char** string = split("abc,matu,def\0", ',');
	for (int i = 0; string[i]!= NULL; ++i){
		printf("'%s'\n",string[i] );
	}
	free_strv(string);

	char** string_2 = split(coma, ',');
	int j = 0;
	for ( ; string_2[j]!=NULL; ++j){
		printf("'%s'\n",string_2[j] );
	}
	free_strv(string_2);
	string = split(",", ',');
	for (int k = 0; string[k]!= NULL; ++k){
		printf("'%s'\n",string[k] );
	}
	free_strv(string);
	string = split(",abc,matu,def", ',');
	for (int k = 0; string[k]!= NULL; ++k){
		printf("'%s'\n",string[k] );
	}
	free_strv(string);
    printf("###################################################\n");
    string = split("abc,matu,def,", ',');
	for (int k = 0; string[k]!= NULL; ++k){
		printf("'%s'\n",string[k] );
	}
	free_strv(string);
	string = split("", ',');
	for (int k = 0; string[k]!= NULL; ++k){
		printf("'%s'\n",string[k] );
	}
	free_strv(string);
	string = split(",", ',');
	for (int k = 0; string[k]!= NULL; ++k){
		printf("'%s'\n",string[k] );
	}
	free_strv(string);

}
void probar_join(){
	printf("__probar join______");
	char sep = '+';
	char **strvn = split("abc,def,ghi", ',');
	char *resultado = join(strvn, sep);
	printf("'%s'\n", resultado );
	free_strv(strvn);
	free(resultado);
/*
	char **palabras = split("Hola mundo", ' ');
	char *otro_resultado = join(palabras, ',');
	printf("%s\n", otro_resultado );
	free_strv(palabras);
	free(otro_resultado);*/
}
int main (){
	probar_substr();
	probar_split();
//	probar_join();
	return 0;
}
