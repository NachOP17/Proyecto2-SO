typedef struct lista {
	char letra;
	struct lista *prox;
} lista;

int vacio(lista *p) {
	return (p == NULL);
}

void agregar(lista **p, char *x) {
	lista *t =  malloc(sizeof(lista));
	t->letra = *x;
	t->prox = *p;
	*p =t;
}

void eliminar(lista **p) {
	lista *t = *p;
	*p = (*p)->prox;
	free(t);
}

void imprimir(lista *p) {
	if (!vacio(p)) {
		lista *t = p;
		while (t) {
			printf("%c", t->letra);
			t = t->prox;
		}
		printf("\n");
	}
}
