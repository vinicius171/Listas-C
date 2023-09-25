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
  if(lista_vazia(*l)|| elem <= (*l)->valor) {
    struct no* n = (struct no*) malloc(sizeof(struct no));
    if(n == NULL)
      return 0;
    n->valor = elem;
    n->prox = *l;
    *l = n;
    return 1;
  }else{
    insere_lista(&(*l)->prox, elem);
  }
}

int remove_lista(ListaDin* l, int elem) {
if(lista_vazia(*l) || (*l) ->valor > elem)
  return 0;


if((*l)->valor == elem){
  struct no* aux = *l;
  *l = (*l)->prox;
  free(aux);
  return 1;
  }
  return remove_lista(&(*l)->prox, elem);
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
