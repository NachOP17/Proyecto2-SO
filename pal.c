#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

char *recorrerDirectorios(char directorio[]) {
	struct dirent *sd;
	struct dirent *sd2;
	DIR *dir;
	dir = opendir(directorio);
	char hijos[20] = "";
	while (sd = readdir(dir)) {
		strcat(hijos, sd->d_name);
	}
	unsigned int numero = strlen(hijos);
	printf("Hijos: %s\n", hijos);
	if (numero > 3) {
		while (sd2 = readdir(dir)) {
			printf("%s", sd2->d_name);
			if ((sd2->d_name != ".") && (sd2->d_name != "..")) {
				strcat(directorio, "/");
				strcat(directorio, sd2->d_name);
				directorio = recorrerDirectorios(directorio);
			}
		}
	} else {
		closedir(dir);
		return directorio;
	}
}

int main(int argc, char *argv[]) {
	char palabra[20];
	printf("%s", recorrerDirectorios("./directoryTree"));
	printf("\n");
}

