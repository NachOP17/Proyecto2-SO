#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

char *recorrerDirectorios(char directorio[]) {
	struct dirent *dentroDelDirectorio = NULL;
	DIR *pdir = NULL;
	pdir = opendir(directorio);
	char hijos[20] = "";
	if (pdir == NULL) // if pdir wasn't initialised correctly
	{ // print an error message and exit the program
			printf("Aqui?");
			printf ("\nERROR! pdir could not be initialised correctly");
			exit (3);
	} // end if
	while (dentroDelDirectorio = readdir(pdir)) {
		if (dentroDelDirectorio == NULL) // if pent has not been initialised correctly
		{ // print an error message, and exit the program
				printf("O aca?\n");
				printf ("ERROR! pent could not be initialised correctly");
				exit (3);
		}
		char DNUEVO[50] = "";
		if ((strcmp(dentroDelDirectorio->d_name,".")) && (strcmp(dentroDelDirectorio->d_name,".."))){
			strcat(DNUEVO, directorio);
			strcat(hijos, dentroDelDirectorio->d_name);
			strcat(DNUEVO, "/");
			strcat(DNUEVO, dentroDelDirectorio->d_name);
			printf("%s\n", DNUEVO);
			recorrerDirectorios(DNUEVO);
		}
	}
	// unsigned int numero = strlen(hijos);
	// printf("Hijos: %s\n", hijos);
	// printf("Numero: %i\n", numero );

	// if (numero > 3) {
	// 	while (dentroDelDirectorio = readdir(pdir)) {
	// 		if (dentroDelDirectorio == NULL) // if pent has not been initialised correctly
	// 		{ // print an error message, and exit the program
	// 				printf("O aca?\n");
	// 				printf ("ERROR! pent could not be initialised correctly");
	// 				exit (3);
	// 		}
	// 		printf("%s", dentroDelDirectorio->d_name);
	// 		if ((dentroDelDirectorio->d_name != ".") && (dentroDelDirectorio->d_name != "..")) {
	// 			strcat(directorio, "/");
	// 			strcat(directorio, dentroDelDirectorio->d_name);
	// 			directorio = recorrerDirectorios(directorio);
	// 		}
	// 	}
	// } //else {
	// 	return directorio;
	// //}
	closedir(pdir);
}

int main(int argc, char *argv[]) {
	char palabra[20];
	printf("%s", recorrerDirectorios("./directoryTree"));
	printf("\n");
}
