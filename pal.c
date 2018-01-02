#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "listas.h"

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
			printf("%s\n", DNUEVO);
			recorrerDirectorios(DNUEVO, p);
			imprimir(*p);
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
