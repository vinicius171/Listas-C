#include <stdio.h>
#include <stdlib.h>
#include "lista-dinamica.h"
#include "iterador.h"

void imprime_lista(ListaDin l) {
  int tam = tamanho_lista(l);
  for(int i = 0; i < tam; i++) {
    int elem;
    obtem_valor_lista(l, i, &elem);
    printf("%d, ", elem);
  }
  printf("\n");
}

void imprime_lista_it(ListaDin l) {
  ListaDinIte it = cria_iterador_lista(l);
  while(tem_proximo_iterador(it)) {
    int elem = obtem_valor_iterador(it);
    printf("%d, ", elem);
  }
  printf("\n");
  destroy_iterador_lista(&it);
}


void insere_elementos(ListaDin* l, int arr[], int n) {
  for(int i = 0; i < n; i++) {
    insere_lista(l, arr[i]);
  }
}

int main() {

  int arr[] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
  int n = 11;

  ListaDin l = cria_lista();
  imprime_lista_it(l);
  insere_elementos(&l, arr, n);
  imprime_lista_it(l);
  remove_lista(&l, 8);
  imprime_lista_it(l);
  destroi_lista(&l);
  l = cria_lista();
  imprime_lista_it(l);
  destroi_lista(&l);

  return 0;
}
