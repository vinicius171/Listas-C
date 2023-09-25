#ifndef ITERADOR_H
#define ITERADOR_H

#include "lista-dinamica.h"

struct iterador {
  struct no* ptr;
};

typedef struct iterador* ListaDinIte;

ListaDinIte cria_iterador_lista(ListaDin l);
int tem_proximo_iterador(ListaDinIte it);
Bebida obtem_valor_iterador(ListaDinIte it);
void destroy_iterador_lista(ListaDinIte* it);

#endif

