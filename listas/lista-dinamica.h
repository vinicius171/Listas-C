#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

struct no {
  int valor;
  struct no* prox;
};

typedef struct no* ListaDin;

ListaDin cria_lista();
int lista_vazia(ListaDin l);
int tamanho_lista(ListaDin l);
int obtem_valor_lista(ListaDin l, int i, int* elem);
int insere_lista(ListaDin* l, int elem);
int remove_lista(ListaDin* l, int elem);
void destroi_lista(ListaDin* l);

#endif
