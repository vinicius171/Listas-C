#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

struct bebida {
  char nome[200];
  float volume;
  float preco;
};

typedef struct bebida Bebida;

struct no {
  Bebida valor;
  struct no* prox;
};

typedef struct no* ListaDin;

ListaDin cria_lista();
int lista_vazia(ListaDin l);
int tamanho_lista(ListaDin l);
int obtem_valor_lista(ListaDin l, int i, Bebida* elem);
int insere_lista(ListaDin l, Bebida elem);
int remove_lista(ListaDin l, const char* nome_bebida);
void destroi_lista(ListaDin* l);



#endif
