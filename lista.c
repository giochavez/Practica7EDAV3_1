#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "Heroe.h"

void iniciarLista(Lista *pLista, int tam) { //funcion que inicializa la lista
    pLista->tam = tam;
    pLista->inicio = NULL;
    pLista->fin = NULL;
}

int vacia(Lista *pLista) { //funcion que revisa que la lista este o no vacia
    if (pLista->inicio == NULL) {
        return 1;
    }
    return 0;
}

void agregarNodoInicio(Lista *pLista,void *pInfo) { //Agregamos los nodos al inicio de la lista (tipo pila)
    Nodo *pNodo;
    pNodo = crearNodo(pLista->tam,pInfo);
    if (vacia(pLista)==1) {
        pLista->inicio = pNodo;
        pLista->fin = pNodo;
        return;
    }
    pNodo->siguiente = pLista->inicio;
    pLista->inicio = pNodo;

}

void recorre(Lista *pLista, void (operacion) (Heroe *h) ) { // Recorremos la lista nodo por nodo hasta que nodo apunte a null
    Nodo *pNodo;

    if (vacia(pLista)==1) {
        printf("Lista vacia!\n");
        return;
    }
    pNodo = pLista->inicio;
    while (pNodo != NULL) {
        operacion(pNodo->informacion);
        pNodo = pNodo->siguiente;
    }

}

void *retiraNodoInicio(Lista *pLista) { //Borramos el nodo que este en la posicion inicio de la lista
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    res = pLista->inicio->informacion;
    q = pLista->inicio;
    pLista->inicio = q->siguiente;
    q=NULL;
    free(q);
    return res;
}

void *retiraNodoFinal(Lista *pLista) { //Retiramos el nodo que en su propiedad siguiente apunte a NULL
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    q = pLista->inicio;
    while (q->siguiente!=pLista->fin) {
        q = q->siguiente;
    }
    res = pLista->fin->informacion;
    free(pLista->fin);
    q->siguiente = NULL;
    pLista->fin = q;
    return res;
}

void *buscar(Lista *pLista,void *valor, int (igualdad) (void *d1,void *d2) ){ //Buscamos un valor en la lista
    Nodo *pNodo;

    pNodo = pLista->inicio;
    while(pNodo != NULL){
        if(igualdad(valor, pNodo->informacion)==1)
            return pNodo;
        pNodo = pNodo->siguiente;
    }
    return NULL;
}

int agregarNodoAntesDe(Lista *pLista,void *clave, void *antes, int (igualdad) (void *d1,void *d2)) { //Si lo que queremos es poner un valor antes del que buscamos, lo agregamos gracias a esta funcion
    Nodo *pNodo;
    Nodo *pAnterior;
	if (vacia(pLista)) {
        return 0;
    }
	if(igualdad(pLista->inicio->informacion, antes)==1){
		agregarNodoInicio(pLista, clave);
		return 1;
}
 	pAnterior = pLista->inicio;
	pNodo = pLista->inicio->siguiente;
		while(pNodo!=NULL){
		if(igualdad(pNodo->informacion, antes)==1){
			pAnterior->siguiente = crearNodo(pLista->tam, clave);
			pAnterior->siguiente->siguiente = pNodo;
			return 1;
		}
		pAnterior = pNodo;
		pNodo = pNodo->siguiente;
}
	return 0;
}
int comparaMayorVida(void *dato, Heroe *h) { //Primer dato mayor al segundo, comparamos las vidas de los personajes y retorna 1 si el primer dato es mayor al segundo, 0 si es menor.
    int *x, *y;
    x = &(h->vida);
    y = (int *)dato;
    if(*x>*y)
        return 1;
    return 0;
}
void menu() {
    system("cls");
    system("color 07");
    printf("       MEN%c DE H%cROES\n", 233, 144);
    printf("(1) Agregar H%croe.\n", 130);
    printf("(2) Mostrar h%croes.\n", 130);
    printf("(3) Mostrar h%croes mayores a...\n", 130);
    printf("(4) H%croe A ataca a H%croe B\n", 130, 130);
    printf("(0) SALIR\n");
}

int leerOpcion() {
    int respuesta;
    do {
        menu();
        printf("%cCu%cl es tu elecci%cn? ", 168, 160, 162);
        scanf("%d",&respuesta);
        if (respuesta<0 || respuesta>4) {
            printf("Hay un error en tu elecci%cn!\n", 162);
            printf("Valores s%clo entre 0 y 5 por favor\n", 162);
        }
    } while(respuesta<0 || respuesta>4);
    printf("\n");
    return respuesta;

}
void recorreVidaMayor(Lista *pLista, void *d1, int (comparacion)(void *d1, Heroe *h), void (operacion) (Heroe *h) ) { // Recorremos la lista nodo por nodo hasta que nodo apunte a null
    Nodo *pNodo;

    if (vacia(pLista)==1) {
        printf("Lista vac%ca!\n", 161);
        return;
    }
    pNodo = pLista->inicio;
    while (pNodo != NULL) {
        if(comparacion(d1, pNodo->informacion)==1)
            operacion(pNodo->informacion);
        pNodo = pNodo->siguiente;
    }
}

void ataqueAyB(Lista *pLista){
    char nombreA[100], nombreB[100];
    Nodo* nA;
    Nodo* nB;
    Nodo* nodo;
    Heroe* hA;
    Heroe* hB;
    nodo = pLista->inicio;
    printf("Ingresa el nombre del H%croe A:\n", 130);
    scanf("%s", nombreA);
    printf("Ingresa el nombre del H%croe B:\n", 130);
    scanf("%s", nombreB);
    printf("\n");
    system("PAUSE");
    nA = buscar(pLista, nombreA, igualdadHeroe);
    nB = buscar(pLista, nombreB, igualdadHeroe);
    hA = nA -> informacion;
    hB = nB -> informacion;
    if (hA->ataque >= hB->vida){
        printf("\n\nEl h%croe %s ha sido asesinado por %s\n", 130, hB->nombre, hA->nombre);
        system("PAUSE");
        //Si el nodo inicial concuerda con el nodo del heroe B
        if (nodo == nB){
            pLista->inicio = nB->siguiente;
            nB->siguiente = NULL;
            free(nB->informacion);
            free(nB);
            return;
        }
        //Si el heroe b no está en en el nodo inicial
        while (nodo->siguiente != nB){
            nodo = nodo->siguiente;
        }
        //Si el nodo B fuera el ultimo
        if (nB->siguiente == NULL){
            pLista->fin = nodo;
            free(nB->informacion);
            free(nB);
            return;
        }
        nodo->siguiente = nodo->siguiente->siguiente;
        nB->siguiente = NULL;
        free(nB->informacion);
        free(nB);
        return;
    }
    printf("\nA %s lo atac%c %s y ha sufrido %d puntos de da%co.", hB->nombre, 162, hA->nombre, hA->ataque, 164);
    hB->vida -= hA->ataque;
    printf("\nA %s le restan: %d puntos de vida\n", hB->nombre, hB->vida);
    system("PAUSE");
    return;
}
