#include "lista.h"
#include <stdlib.h>

No *criarNo(int vertice) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo != NULL) {
        novo->vertice = vertice;
        novo->proximo = NULL;
    }
    return novo;
}

void inicializarListaAdj(No *lista[]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        lista[i] = NULL;
    }
}

void destruirListaAdj(No **lista) {
    if (lista == NULL) return;

    for (int i = 0; i < MAX_VERTICES; i++) {
        No *atual = lista[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        lista[i] = NULL;
    }
}
