#include <stdlib.h>
#include "iterador.h"

ListaDinIte cria_iterador_lista(ListaDin l) {
  ListaDinIte it = (struct iterador*) malloc(sizeof(struct iterador));
  it->ptr = l;
  return it;
}

int tem_proximo_iterador(ListaDinIte it) {
  return it->ptr != NULL;
}

int obtem_valor_iterador(ListaDinIte it)
{
  int elem = it->ptr->valor;
  it->ptr = it->ptr->prox;
  return elem;
}

void destroy_iterador_lista(ListaDinIte* it) {
  free(*it);
  *it = NULL;
}
