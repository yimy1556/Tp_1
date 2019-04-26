#include "strutil.h"
#include "vector.h"
#include "pila.h"
#include "cola.h"

char *substr(const char *str, size_t n){
    vector_t* vector = vector_crear(n);
    if (!vector) return NULL;
    strncpy(vector->datos,str,n);
    return vector->datos;
}
