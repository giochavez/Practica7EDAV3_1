#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Heroe.h"

void leerHeroe(Heroe *h){ //Aqui el usuario agrega nombre, vida, ataque del heroe y queda registrada
    printf("Ingresa el nombre de tu heroe: ");
    scanf("%s", h->nombre);
    printf("Ingresa la vida del heroe: ");
    scanf("%d", &(h->vida));
    printf("Ingresa el nivel de ataque: ");
    scanf("%d", &(h->ataque));
    printf("\n");
}

void imprime(Heroe *h){ //imprimimos al heroe y todas sus caracteristicas
    printf("*********************\n\n");
    printf("Nombre: %s\n", h->nombre);
    printf("Vida: %d\n", h->vida);
    printf("Ataque: %d\n", h->ataque);
    printf("\n");
}

int igualdadHeroe(char* s, Heroe* h){ //Recibimos el nombre a comparar y los nombres de los heroes
    if (strcmp(s, h->nombre)==0) //Comparamos los nombres, letra por letra y si son iguales retornamos 1
        return 1;
    return 0; //si no son iguales retornamos 0
}
int comparaVida(Heroe *h1, Heroe *h2){
    if(h1->vida < h2->vida){ //Si el primer heroe es menor al segundo heroe retornamos 1
        return 1;
    }
    return 0;
}
