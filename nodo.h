#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct nodo { //definimos a nodo quien tiene informacion, y una propiedad siguiente
    void *informacion;
    struct nodo *siguiente;
};

typedef struct nodo Nodo; //para no poner siempre struct nodo, solo definimos que cada que pongamos Nodo, es una estructura del tipo Nodo

Nodo *crearNodo(int tam, void *dirInfo); //Creamos nodo -> nodo.c

#endif // NODO_H_INCLUDED
