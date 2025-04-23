#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct No {
    Requisicao *req;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Estrutura;

// Cria a estrutura (fila)
Estrutura* create();

// Insere uma nova requisição na fila
void inserir(Estrutura *e, Requisicao *r);

// Remove a requisição mais antiga da fila
Requisicao* remover(Estrutura *e);

// Retorna o número de requisições na fila
int get_size(Estrutura *e);

// Libera a memória da estrutura inteira
void libera_estrutura(Estrutura *e);

#endif
