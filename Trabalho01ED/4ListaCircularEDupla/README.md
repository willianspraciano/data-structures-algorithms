<h1 align="center">
  Trabalho 01
</h1>

## 4ª Questão

Implemente os Tipos Abstratos de Dados (TAD) “lista_circular.h” e “lista_dupla.h” (ver slides sobre Listas Circulares e Duplamente Encadeadas).

A seguir, execute os seguintes programas.

```sh
#include <stdio.h>
#include<stdlib.h>
#include "lista_circular.h"

int main(void){

	int maior;

	ListaCirc* l = lst_circ_cria();
	l = lst_circ_insere(l,10);
	l = lst_circ_insere(l,13);
	l = lst_circ_insere(l,25);
	l = lst_circ_insere(l,29);
	l = lst_circ_insere(l,40);

	printf("Antes de remover o 10:\n");
	lst_circ_imprime(l);

	l = lst_circ_remove(l,10);
	printf("Depois de remover o 10:\n");
	lst_circ_imprime(l);
	
	lst_circ_libera(l);

	//system("PAUSE");
	return 0;
}
```

```sh
#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

int main(void){

	int maior;

	ListaDupla* l = lst_dupl_cria();

	l = lst_dupl_insere(l,10);
	l = lst_dupl_insere(l,13);
	l = lst_dupl_insere(l,25);
	l = lst_dupl_insere(l,29);
	l = lst_dupl_insere(l,40);
	
	printf("Lista completa:\n");
	lst_dupl_imprime(l);

	l = lst_dupl_remove(l,10);
	printf("Lista depois do 10 ter sido removido:\n");
	lst_dupl_imprime(l);

	lst_dupl_libera(l);

	//system("PAUSE");
	return 0;
}
```