#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "listas.h"

int palindromo(lista *palabra){
	lista *aux = palabra;
	char pString[1000] = "";
	char pString2[1000] = "";
	int i = 0, cont= 0;
	while(aux){
		pString[i]=aux->letra;
		aux=aux->prox;
		i++;
	}
	int j=strlen(pString);
	for(i=0; i<strlen(pString); i++){
			pString2[i] = pString[j-1];
			j--;
	}
	// printf("Palabra 1: %s\n",pString );
	// printf("Palabra 2: %s\n",pString2 );
	return strcmp(pString, pString2);
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
			//printf("%s\n", DNUEVO);
			recorrerDirectorios(DNUEVO, p);
			if((*p)->prox){
				printf("La palabra ");
				imprimir(*p);
				if(!palindromo(*p))
					printf(" es palindroma\n");
				else
					printf(" no es palindroma\n");
			}
			// imprimir(*p);
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
