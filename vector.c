#include "vector.h"
#include <stdbool.h>

void vector_destruir(vector_t* vector){
    free(vector->datos);
    vector->datos = NULL;
    free(vector);
}

bool vector_obtener(vector_t* vector, size_t pos, int* valor){
    if (pos < vector->tam){ 
        *valor = vector->datos[pos];
        return true;
    }
    return false;
}

bool vector_guardar(vector_t* vector, size_t pos, int valor){
    if (pos < vector->tam){ 
        vector->datos[pos] = valor;
        return true;
    }
    return false;
}


size_t vector_largo(vector_t* vector){
    return vector->tam;
}
// Funciones implementadas por la catedra.

vector_t* vector_crear(size_t tam) {
    vector_t* vector = malloc(sizeof(vector_t));

    if (vector == NULL) {
        return NULL;
    }
    vector->datos = malloc(tam * sizeof(int));

    if (tam > 0 && vector->datos == NULL) {
        free(vector);
        return NULL;
    }
    vector->tam = tam;
    return vector;
}

bool vector_redimensionar(vector_t* vector, size_t tam_nuevo) {
    int* datos_nuevo = realloc(vector->datos, tam_nuevo * sizeof(int));

    // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
    // En toda otra situación significa que falló el realloc.
    if (tam_nuevo > 0 && datos_nuevo == NULL) {
        return false;
    }
    vector->datos = datos_nuevo;
    vector->tam = tam_nuevo;
    return true;
}
