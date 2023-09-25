#include "lista-dinamica.h"
#include <stdlib.h>

ListaDin cria_lista() {
  return NULL;
}

int lista_vazia(ListaDin l) {
  return l == NULL;
}

int tamanho_lista(ListaDin l) {
  int tam = 0;
  struct no* aux = l;
  while(aux != NULL) {
    tam++;
    aux = aux->prox;
  }

  return tam;
}

int obtem_valor_lista(ListaDin l, int i, int* elem) {
  struct no* aux = l;
  while(aux != NULL && i > 0) {
    aux = aux->prox;
    i--;
  }

  if(aux == NULL)
    return 0;

  *elem = aux->valor;
  return 1;
}

int insere_lista(ListaDin* l, int elem) {
  struct no* n = (struct no*) malloc(sizeof(struct no));
  if(n == NULL)
    return 0;

  n->valor = elem;
  if(lista_vazia(*l) || elem <= (*l)->valor) {
    n->prox = *l;
    *l = n;
    return 1;
  }
  ListaDin aux = *l;
  while(aux->prox != NULL && aux->prox->valor < elem)
    aux = aux->prox;
  
  n->prox = aux->prox;
  aux->prox = n;
  return 1;
}

int remove_lista(ListaDin* l, int elem) {
  if(lista_vazia(*l))
    return 0;

  struct no* aux1 = *l;
  while(aux1->prox != NULL && aux1->prox->valor < elem)
    aux1 = aux1->prox;

  if(aux1->prox == NULL || aux1->prox->valor > elem)
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
