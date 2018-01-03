#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "listas.h"

void palindromo(lista *a, lista *b) {
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
	
	if (isPalindromo) {
		imprimir2(a, b);
		printf(" es un palindromo\n");
	} else {
		printf(" no hay palindromos\n");
	}
}

void recorrerString(lista *palabra) {
	// printf("En la rama ");
	// imprimir(palabra);
	// printf(", ");
	lista *a = palabra;
	lista *b = palabra->prox->prox;
	int isPalindromo = 0;
	
	while (b) {
		if (a->letra == b->letra) {
			palindromo(a, b);
			if (b->prox == NULL) {
				a = a->prox;
				b = a->prox->prox;
			} else {
				b = b->prox;
			}
		} else {
			if (b->prox == NULL) {
				a = a->prox;
				b = a->prox->prox;
			} else {
				b = b->prox;
			}
		}
	}
}



void recorrerDirectorios(char directorio[], lista **p) {
	struct dirent *dentroDelDirectorio = NULL;
	DIR *pdir = NULL;
	pdir = opendir(directorio);
	char hijos[20] = "";
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
			strcat(DNUEVO, directorio);
			agregar(p, dentroDelDirectorio->d_name);
			strcat(hijos, dentroDelDirectorio->d_name);
			strcat(DNUEVO, "/");
			strcat(DNUEVO, dentroDelDirectorio->d_name);
			recorrerDirectorios(DNUEVO, p);
			if((*p)->prox){
				recorrerString(*p);
			}
			eliminar(p);
		}
	}

	closedir(pdir);
}

int main(int argc, char *argv[]) {
	char palabra[20];
	lista *p = NULL;
	recorrerDirectorios("./directoryTree", &p);
	printf("\n");
}
