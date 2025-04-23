#include <stdlib.h>
#include <string.h>
#include "requisicao.h"

// Corrigir nome da função para 'cria_requisicao' para corresponder ao teste.
Requisicao* cria_requisicao(const char *nome, int inscricao, const char *procedimento) {
    Requisicao *r = (Requisicao *)malloc(sizeof(Requisicao));
    if (r != NULL) {
        strncpy(r->nome, nome, sizeof(r->nome) - 1);
        r->nome[sizeof(r->nome) - 1] = '\0';

        r->inscricao = inscricao;

        strncpy(r->procedimento, procedimento, sizeof(r->procedimento) - 1);
        r->procedimento[sizeof(r->procedimento) - 1] = '\0';
    }
    return r;
}

// Libera a memória da requisição
void libera(Requisicao *r) {
    free(r);
}

// Corrigir o tipo de retorno para char* (já que é uma string)
char* get_nome(Requisicao *r) {
    return r->nome;  // Retorna uma string
}

int get_inscricao(Requisicao *r) {
    return r->inscricao;
}

// Corrigir o tipo de retorno para char* (já que é uma string)
char* get_procedimento(Requisicao *r) {
    return r->procedimento; // Retorna uma string
}
