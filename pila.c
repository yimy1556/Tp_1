#include "pila.h"
#include <stdlib.h>
#define VACIO 0
#define CAM_INICIAL 10
#define MODO_REDIMENSION 4
#define MOD_CAPACIDAD 2

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};
/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/
// ...

bool pila_redimensionar(pila_t* pila ,size_t nuevo_tamanio) {
    void** datos_nuevo = realloc(pila->datos,nuevo_tamanio * sizeof(void*));
    // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
    // En toda otra stuación significa que falló el realloc.
    if (!datos_nuevo) return false;
    pila->datos = datos_nuevo;
    pila->capacidad = nuevo_tamanio;
    return true;
}  

pila_t* pila_crear(void){
    pila_t *pila = malloc(sizeof(pila_t));
    if (!pila) return NULL;
    pila->datos = malloc(CAM_INICIAL * sizeof(void*));
    if (!pila->datos) {
        free(pila);
        return NULL;
    }
    pila->capacidad = CAM_INICIAL; 
    pila->cantidad  = VACIO;
    return pila;
}

void pila_destruir(pila_t* pila){
    free(pila->datos);
    free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
    return !pila->cantidad;
}

bool pila_apilar(pila_t *pila, void* valor){
    bool pudo_apilar = true;
    if (pila->cantidad == pila->capacidad) pudo_apilar = pila_redimensionar(pila ,(pila->capacidad * MOD_CAPACIDAD));
    if(pudo_apilar){
        pila->datos[pila->cantidad] = valor;
        pila->cantidad++;
    }
    return pudo_apilar;
} 

void* pila_ver_tope(const pila_t *pila){
    if (pila_esta_vacia(pila)) return NULL;
    return (pila->datos[(pila->cantidad) - 1]);
}

void* pila_desapilar(pila_t *pila){
    void* valor_tope = pila_ver_tope(pila);
    if(!pila_esta_vacia(pila)){
        pila->cantidad--;
        if ((pila->cantidad * MODO_REDIMENSION) == pila->capacidad) pila_redimensionar(pila ,(pila->capacidad / MOD_CAPACIDAD));
    }
        return valor_tope;
}
