typedef struct lista {
	char letra;
	struct lista *prox;
	struct lista *prev;
} lista;

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

void imprimir2(lista *a, lista *b) {
	lista *t = a;
	while (t != b->prox) {
		printf("%c", t->letra);
		t = t->prox;
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
