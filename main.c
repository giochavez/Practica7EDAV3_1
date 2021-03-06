#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "Heroe.h"

int main(){

    Heroe unHeroe; //Creamos una estructura del tipo Heroe y le asignamos el nombre de unHeroe
    Lista misHeroes; //Creamos una estructura de tipo Lista doned estaran todos los heroes
    iniciarLista(&misHeroes, sizeof(Heroe));
    int k, opcion;
    //char atacante[100], atacado[100];

    do {
        opcion = leerOpcion(); /*definimos la existencia */
        switch (opcion) {
            case 1:
                system("cls"); //ESTA OPERACION LIMPIA LA PANTALLA para no amontonar las cosas al correr
                system("color 09"); //ESTA OPERACION CAMBIA LAS LETRAS DE COLOR para darle color a la vida e identificar cuando entramos y salimos de una operacion
                printf("Agregar H%croe:\n", 130);
                leerHeroe(&unHeroe); //Leemos heroe y lo que recibe es la direccion de unHeroe
                agregarNodoInicio(&misHeroes, &unHeroe); //Despues de leerlo agregamos el heroe al inicio de la lista
                break;
            case 2:
                system("cls");
                system("color 0E");
                printf("MOSTRANDO H%cROES:\n\n", 144);
                recorre(&misHeroes, imprime); //recorremos la lista de misHeroes y los imprimimos
                system("PAUSE");
                break;
            case 3:
                system("cls");
                system("color 0A");
                printf("Mostrar h%croes mayor a...\n", 130);
                printf("H%croes mayores a: ", 130); //Preguntamos al usuario a partir de que nivel de vida quiere ver los heroes
                scanf("%d", &k); //Le asignamos el nivel de vida a k
                printf("\nEstos son los h%croes arriba de %d de vida:\n", 130,k);
                recorreVidaMayor(&misHeroes, &k,  comparaMayorVida, imprime); //Recorremos la lista mientras comparamos las vidas (...)
                system("PAUSE");
                break; //(...)de los personajes y solo imprimimos los que cumplan con el hecho de ser mayores al dato ingresado por el usuario
            case 4:
                system("cls");
                system("color 0B");
                printf("H%cROES DE MAYOR A MENOR:\n\n", 130); //No sabia si queria ordenarlo de mayor a menor o solo los mayores a, así que hice ambas
                recorreParaAcomodo(&misHeroes,comparaVida,imprime); //Recorremos la lista, coparamos las vidas por burbuja, e imprimimos la lista final
                system("PAUSE");
                break;
            case 5:
                system("cls");
                system("color 0D");
                ataqueAyB(&misHeroes); //Recibe la lista de heroes para buscar a los oponentes
                system("PAUSE");
                break;
            case 0:
                system("cls");
                system("color 0C");
                printf("***************************************\n\n");
                printf("Hasta luego!!!!\n");
                printf("Gracias por usar el programa de H%croes\n", 130);
                printf("Hecho con colores y acentos, created by GIO\n\n");
                printf("***************************************\n\n");
               break;
            default: printf("Opci%cn no reconocida %d\n", 163, opcion);
               break;
        }
    } while(opcion != 0);
    return 0;
}

