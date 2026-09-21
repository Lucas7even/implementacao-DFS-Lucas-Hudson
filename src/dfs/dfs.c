#include "dfs.h"
#include <stdlib.h>

DFS *inicializarDFS() {
    DFS *dfs = (DFS *)malloc(sizeof(DFS));
    if (dfs != NULL) {
        dfs->tempo = 0;
        for (int i = 0; i < MAX_VERTICES; i++) {
            dfs->ante[i] = -1;
            dfs->i[i] = 0;
            dfs->f[i] = 0;
            dfs->cor[i] = BRANCO;
        }
    }
    return dfs;
}

void destruirDFS(DFS *dfs) {
    if (dfs != NULL) {
        free(dfs);
    }
}

void dfs_visit_matriz(DFS *dfs, int u, Grafo *g) {
    dfs->cor[u] = CINZA;
    dfs->tempo++;
    dfs->i[u] = dfs->tempo;

    for (int v = 0; v < MAX_VERTICES; v++) {
        if (g->matrizAdj[u][v]) {
            if (dfs->cor[v] == BRANCO) {
                dfs->ante[v] = u;
                dfs_visit_matriz(dfs, v, g);
            }
        }
    }

    dfs->cor[u] = PRETO;
    dfs->tempo++;
    dfs->f[u] = dfs->tempo;
}

void dfs_start_matriz(DFS *dfs, Grafo *g, int s) {
    if (dfs == NULL || g == NULL) return;

    for (int i = 0; i < MAX_VERTICES; i++) {
        dfs->cor[i] = BRANCO;
        dfs->ante[i] = -1;
        dfs->i[i] = 0;
        dfs->f[i] = 0;
    }
    dfs->tempo = 0;
  
    if (s >= 0 && s < MAX_VERTICES && dfs->cor[s] == BRANCO) {
        dfs_visit_matriz(dfs, s, g);
    }

    for (int u = 0; u < MAX_VERTICES; u++) {
        if (dfs->cor[u] == BRANCO) {
            dfs_visit_matriz(dfs, u, g);
        }
    }
}

void dfs_visit_lista(DFS *dfs, int u, Grafo *g) {
    dfs->cor[u] = CINZA;
    dfs->tempo++;
    dfs->i[u] = dfs->tempo;

    No *atual = g->listaAdj[u];
    while (atual != NULL) {
        int v = atual->vertice;
        if (dfs->cor[v] == BRANCO) {
            dfs->ante[v] = u;
            dfs_visit_lista(dfs, v, g);
        }
        atual = atual->proximo;
    }

    dfs->cor[u] = PRETO;
    dfs->tempo++;
    dfs->f[u] = dfs->tempo;
}

void dfs_start_lista(DFS *dfs, Grafo *g, int s) {
    if (dfs == NULL || g == NULL) return;

    for (int i = 0; i < MAX_VERTICES; i++) {
        dfs->cor[i] = BRANCO;
        dfs->ante[i] = -1;
        dfs->i[i] = 0;
        dfs->f[i] = 0;
    }
    dfs->tempo = 0;

    if (s >= 0 && s < MAX_VERTICES && dfs->cor[s] == BRANCO) {
        dfs_visit_lista(dfs, s, g);
    }

    for (int u = 0; u < MAX_VERTICES; u++) {
        if (dfs->cor[u] == BRANCO) {
            dfs_visit_lista(dfs, u, g);
        }
    }
}
