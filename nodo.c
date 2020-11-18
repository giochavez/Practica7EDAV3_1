#include <stdlib.h>
#include <string.h>

#include "nodo.h"
//Para cuando queramos agregar nodo en medio de la corrida del programa, llamamos a crearNodo

Nodo *crearNodo(int tam, void *dirInfo) {
    Nodo *pNodo;
    pNodo = malloc(sizeof(Nodo));
    pNodo->informacion = malloc(tam);
    memcpy(pNodo->informacion,dirInfo,tam);
    pNodo->siguiente = NULL;
    return pNodo;
}
