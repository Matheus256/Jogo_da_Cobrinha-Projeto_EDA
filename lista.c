#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criar(LISTA *lst, int tam_MAX){
  lst->MAX = tam_MAX;
  lst->pos = 0;
  lst->arr = (NO*) malloc(sizeof(NO)*tam_MAX);
  if (!lst->arr){
    printf("Erro! Sem espaço na memória.\n");
    exit(1);
  }
}

void inserir_v2(LISTA *lst, NO elemento){
  if (lst->pos >= lst->MAX)
    redimensionar(lst, 2*lst->MAX);
  lst->arr[lst->pos].x = elemento.x;
  lst->arr[lst->pos].y = elemento.y;
  lst->pos++;
}

void inserir(LISTA *lst, NO no){
  if (lst->pos >= lst->MAX){
    printf("Tamanho limite atingido.\n");
    exit(1);
  }
  lst->arr[lst->pos] = no;
  lst->pos++;
}

int tamanho(LISTA *lst){
  return lst->pos;
}

//Essa função foi usada apenas para testes
void imprimir(LISTA *lst){
  if (lst->pos > 0){
    int i;
    printf("[ ");
    for (i = 0; i < lst->pos - 1; i++)
      printf("(%d,%d), ",lst->arr[i].x, lst->arr[i].y);
    printf("(%d,%d) ]\n", lst->arr[i].x, lst->arr[i].y);
  }
  else
    printf("[]\n");
}

void redimensionar(LISTA *lst, int MAX){
  if (MAX < lst->pos){
    printf("Tamanho insuficiente\n");
    exit(1);
  }
  else {
    NO *pointer = (NO*) malloc(sizeof(NO)*MAX);
    if (!(pointer)){
      printf("Não foi possível alocar memoria\n");
      exit(1);
    }
    for (int i = 0; i < lst->pos; i++){
      pointer[i].x = lst->arr[i].x;
      pointer[i].y = lst->arr[i].y;
    }
    free(lst->arr);
    lst->arr = pointer;
    lst->MAX = MAX;
  }
}
