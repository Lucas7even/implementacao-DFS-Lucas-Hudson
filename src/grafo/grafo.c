#include "grafo.h"
#include <stdlib.h>

Grafo *criarGrafo() {
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    if (g != NULL) {
        inicializarListaAdj(g->listaAdj);
        inicializarMatrizAdj(g->matrizAdj);
    }
    return g;
}

bool inserirAresta(Grafo *g, int origem, int destino) {
    if (g == NULL) return false;
    if (origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) {
        return false;
    }

    inserirArestaMatriz(g->matrizAdj, origem, destino);

    No *novo = criarNo(destino);
    if (novo == NULL) return false;

    novo->proximo = g->listaAdj[origem];
    g->listaAdj[origem] = novo;

    return true;
}

bool existeAresta(Grafo *g, int origem, int destino) {
    if (g == NULL) return false;
    return existeArestaMatriz(g->matrizAdj, origem, destino);
}

void destruirGrafo(Grafo *g) {
    if (g != NULL) {
        destruirListaAdj(g->listaAdj);
        free(g);
    }
}
