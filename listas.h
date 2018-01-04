#include <string.h>

typedef struct lista {
	char letra;
	struct lista *prox;
	struct lista *prev;
} lista;

typedef struct listaNum {
	int valor;
	struct listaNum *prox;
} listaNum;

typedef struct listaStr {
	char str[20];
	struct listaStr *prox;
} listaStr;

int vacio(lista *p) {
	return (p == NULL);
}

void agregar(lista **p, char *x) {
	lista *t =  malloc(sizeof(lista));
	if (vacio(*p)) {
		t->letra = *x;
		t->prox = *p;
		*p =t;
	} else {
		t->letra = *x;
		t->prox = *p;
		(*p)->prev = t;
		*p = t;
	}
}

void eliminar(lista **p) {
	lista *t = *p;
	*p = (*p)->prox;
	// (*p)->prev = NULL;
	free(t);
}

void imprimir(lista *p) {
	if (!vacio(p)) {
		lista *t = p;
		while (t) {
			printf("%c", t->letra);
			t = t->prox;
		}
		//printf("\n");
	}
}

int length(lista *a, lista *b) {
	int i = 1;
	lista *t = a;
	while (t != b) {
			i++;
			t = t->prox;
	}
	return i;
}

void convertirEnString(lista *a, lista *b, char *palabra) {
	lista *aux = a;
	int i = 0;
	while (aux != b->prox) {
		palabra[i] = aux->letra;
		i++;
		aux = aux->prox;
	}
}

void agregarStr(lista *a, lista *b, listaStr **str) {
	char palabra[20] = "";
	convertirEnString(a, b, palabra);
	listaStr *t = malloc(sizeof(listaStr));
	strcpy(t->str, palabra);
	t->prox = *str;
	*str = t;
}

void eliminarStr(listaStr **str) {
	while (*str) {
		free(*str);
		*str = (*str)->prox;
	}
}

void imprimirStr(listaStr *str) {
	listaStr *t = str;
	while (t) {
		printf("%s\n", t->str);
		t = t->prox;
	}
}

int esta(lista *a, lista *b, listaStr *str) {
	listaStr *aux = str;
	char palabra[20] = "";
	convertirEnString(a, b, palabra);
	while (aux) {
		if (!strcmp(palabra, aux->str)) {
			return 1;
		}
		aux = aux->prox;
	}
	return 0;
}

void sumar(listaNum **p) {
	listaNum *t =  malloc(sizeof(listaNum));
	if (!(*p)) {
		t->valor = 1;
		t->prox = *p;
		*p =t;
	} else {
		t->valor = (*p)->valor + 1;
		t->prox = *p;
		*p =t;
	}
}

int cantidadDeHijos(listaNum *p) {
	return p->valor;
}
