#include "lista-dinamica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ListaDin cria_lista() {
  ListaDin l = (ListaDin) malloc(sizeof(struct no));
  l->prox = NULL;

  return l;
}

int lista_vazia(ListaDin l) {
  return l->prox == NULL;
}

// int tamanho_lista(ListaDin l) {
//   return l->valor;
// }
//
int obtem_valor_lista(ListaDin l, int i, Bebida* elem) {
  struct no* aux = l->prox;
  while(aux != NULL && i > 0) {
    aux = aux->prox;
    i--;
  }

  if(aux == NULL)
    return 0;

  *elem = aux->valor;
  return 1;
}

int insere_lista(ListaDin l, Bebida elem) {
  struct no* n = (struct no*) malloc(sizeof(struct no));
  if(n == NULL)
    return 0;

  n->valor = elem;
  n->prox = l->prox;
  l->prox = n;
  return 1;
}

int remove_lista(ListaDin l, const char* nome_bebida) {
  if(lista_vazia(l))
    return 0;

  struct no* aux1 = l;
  while(aux1->prox != NULL && strcmp(aux1->prox->valor.nome, nome_bebida) != 0)
    aux1 = aux1->prox;

  if(aux1->prox == NULL)
    return 0;

  struct no* aux2 = aux1->prox;
  aux1->prox = aux2->prox;
  free(aux2);

  return 1;
}

void destroi_lista(ListaDin* l) {
  struct no* aux1 = *l;
  while(aux1 != NULL) {
    struct no* aux2 = aux1;
    aux1 = aux1->prox;
    free(aux2);
  }
  *l = NULL;
}

