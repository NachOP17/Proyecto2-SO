#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "listas.h"

void palindromo(lista *a, lista *b, listaStr **str, listaNum *hijos) {
	int longitud = length(a, b);
	int isPalindromo = 1;
	lista *t = a;
	lista *z = b;
	while ((t->letra == z->letra) && (longitud > 2)) {
		t = t->prox;
		z = z->prev;
		if (t->letra != z->letra) {
			isPalindromo = 0;
		}
		longitud -= 2;
	}
	
	if (cantidadDeHijos(hijos) <= 20) { 
		if ((isPalindromo) && (!esta(a, b, *str))) {
			agregarStr(a, b, str);
		} 
	} else {
		eliminarStr(str);
		printf("El directorio padre tiene mas de 20 hijos\n");
		exit(1);
	}
}

void recorrerString(lista *palabra, listaStr **str, listaNum *hijos) {
	lista *a = palabra;
	lista *b = palabra->prox->prox;
	int isPalindromo = 0;
	
	while (b) {
		if (a->letra == b->letra) {
			palindromo(a, b, str, hijos);
		}
		if (b->prox == NULL) {
			a = a->prox;
			b = a->prox->prox;
		} else {
			b = b->prox;
		}	
	}
}

int recorrerDirectorios(char directorio[], lista **p, listaStr **str, listaNum **hijos) {
	struct dirent *dentroDelDirectorio = NULL;
	struct dirent *aux;
	DIR *pdir = NULL;
	pdir = opendir(directorio);
	if (pdir == NULL) { // Si pdir no se inicializo correctamente o no existe el directorio
			printf("Aqui?");
			printf ("\nERROR! El directorio %s no existe\n", directorio);
			exit (3);
	}
	while (dentroDelDirectorio = readdir(pdir)) { // Mientras haya directorios internos
		if (dentroDelDirectorio == NULL) { // Si dentroDelDirectorio no se inicializo correctamente
				printf("O aca?\n");
				printf ("ERROR! El directorio %s no existe\n", dentroDelDirectorio->d_name);
				exit (3);
		}
		char DNUEVO[50] = "";
		if ((strcmp(dentroDelDirectorio->d_name,".")) && (strcmp(dentroDelDirectorio->d_name,".."))) {
			sumar(hijos);
			strcat(DNUEVO, directorio);
			strcat(DNUEVO, "/");
			strcat(DNUEVO, dentroDelDirectorio->d_name);
			agregar(p, dentroDelDirectorio->d_name);
			recorrerDirectorios(DNUEVO, p, str, hijos);
			if ((*p)->prox) {
				recorrerString(*p, str, *hijos);
			}
			eliminar(p);
		}
	}
	closedir(pdir);
}

int main(int argc, char *argv[]) {
	char palabra[20];
	lista *p = NULL;
	listaStr *str = NULL;
	listaNum *hijos = 0;
	recorrerDirectorios("./directoryTree", &p, &str, &hijos);
	printf("Los palindromos que se encontraron son los siguientes: \n");
	imprimirStr(str);
	eliminarStr(&str);
}
