#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct {
    char nome[40];
    int inscricao;
    char procedimento[10];
} Requisicao;

// Cria uma nova requisição
Requisicao* cria_requisicao(const char *nome, int inscricao, const char *procedimento);

// Corrigir tipo de retorno para 'char*' nas funções de acesso às strings
char* get_nome(Requisicao *r);

int get_inscricao(Requisicao *r);

char* get_procedimento(Requisicao *r);

// Libera a memória de uma requisição
void libera(Requisicao *r);

#endif
