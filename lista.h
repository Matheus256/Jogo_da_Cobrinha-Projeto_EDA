#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

//Imagine cada "no" como uma entrada de uma matriz, assim cada "no" deve possuir uma indicação da linha e outro da coluna
typedef struct {
  int x, y;
} NO ;

//Aqui definimos uma lista de no's
typedef struct {
  NO *arr;
  int pos, MAX;
} LISTA;

// Cabeçalhos
void criar(LISTA *lst, int tam_MAX);
void inserir(LISTA *lst, NO no);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

void redimensionar(LISTA *lst, int MAX);
void inserir_v2(LISTA *lst, NO elemento);

#endif
