#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

char *recorrerDirectorios(char directorio[]) {
	struct dirent *dentroDelDirectorio;
	DIR *dir;
	dir = opendir(directorio);
	char hijos[20] = "";
	while (dentroDelDirectorio = readdir(dir)) {
		strcat(hijos, dentroDelDirectorio->d_name);
	}
	unsigned int numero = strlen(hijos);
	printf("Hijos: %s\n", hijos);
	if (numero > 3) {
		while (dentroDelDirectorio = readdir(dir)) {
			printf("%s", dentroDelDirectorio->d_name);
			if ((dentroDelDirectorio->d_name != ".") && (dentroDelDirectorio->d_name != "..")) {
				strcat(directorio, "/");
				strcat(directorio, dentroDelDirectorio->d_name);
				directorio = recorrerDirectorios(directorio);
			}
		}
	} else {
		return directorio;
	}
	closedir(dir);
}

int main(int argc, char *argv[]) {
	char palabra[20];
	printf("%s", recorrerDirectorios("./directoryTree"));
	printf("\n");
}

