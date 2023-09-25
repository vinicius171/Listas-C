#include <stdio.h>
#include <stdlib.h>
#include "lista-dinamica.h"
#include "iterador.h"

// void imprime_lista(ListaDin l) {
//   int tam = tamanho_lista(l);
//   int elem;
//   for(int i = 0; i < tam; i++) {
//     obtem_valor_lista(l, i, &elem);
//     printf("%d, ", elem);
//   }
//   printf("\n");
// }
//
void imprime_lista_it(ListaDin l) {
  ListaDinIte it = cria_iterador_lista(l);
  while(tem_proximo_iterador(it)) {
    Bebida elem = obtem_valor_iterador(it);
    printf("%s, %f, %f\n", elem.nome, elem.volume, elem.preco);
  }
  printf("\n");
  destroy_iterador_lista(&it);
}


void insere_elementos(ListaDin l, Bebida arr[], int n) {
  for(int i = 0; i < n; i++) {
    insere_lista(l, arr[i]);
  }
}

int main() {

  Bebida arr[] = {
    {"kaiser", 1000.0, 7.0},
    {"skol", 1000.0, 10.0},
    {"caracu", 1000.0, 15.0}
  };
  int n = 3;

  ListaDin l = cria_lista();
  imprime_lista_it(l);
  insere_elementos(l, arr, n);
  imprime_lista_it(l);
  remove_lista(l, "skol");
  imprime_lista_it(l);
  destroi_lista(&l);
  l = cria_lista();
  imprime_lista_it(l);
  destroi_lista(&l);

  return 0;
}
