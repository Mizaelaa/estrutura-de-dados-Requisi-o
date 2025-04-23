#include <stdlib.h>
#include "estrutura.h"

Estrutura* create() {
    Estrutura *e = (Estrutura *)malloc(sizeof(Estrutura));
    if (e != NULL) {
        e->inicio = NULL;
        e->fim = NULL;
        e->tamanho = 0;
    }
    return e;
}

void inserir(Estrutura *e, Requisicao *r) {
    if (e == NULL) return;

    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) return;

    novo->req = r;
    novo->prox = NULL;

    if (e->fim != NULL) {
        e->fim->prox = novo;
    } else {
        e->inicio = novo;
    }

    e->fim = novo;
    e->tamanho++;
}

Requisicao* remover(Estrutura *e) {
    if (e == NULL || e->inicio == NULL) return NULL;

    No *removido = e->inicio;
    Requisicao *r = removido->req;

    e->inicio = removido->prox;
    if (e->inicio == NULL) {
        e->fim = NULL;
    }

    free(removido);
    e->tamanho--;
    return r;
}

int get_size(Estrutura *e) {
    if (e == NULL) return 0;
    return e->tamanho;
}

void libera_estrutura(Estrutura *e) {
    if (e == NULL) return;

    No *atual = e->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        libera(temp->req); // função da requisicao.h
        free(temp);
    }
    free(e);
}
