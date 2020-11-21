#ifndef HEROE_H_INCLUDED
#define HEROE_H_INCLUDED

typedef struct{ //definimos la estructura de heroe
    char nombre[100];
    int vida;
    int ataque;
} Heroe;

void leerHeroe(Heroe *h);
void imprime(Heroe *h);
int comparaVida(Heroe *h1, Heroe *h2);
int igualdadHeroe(char* s, Heroe* h);

#endif // HEROE_H_INCLUDED
