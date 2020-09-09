#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
	
	Lista* l1 = lst_cria();
	l1 = lst_insere(l1,6);
	l1 = lst_insere(l1,13);
	l1 = lst_insere(l1,25);
	l1 = lst_insere(l1,28);
	l1 = lst_insere(l1,40);
	l1 = lst_remove(l1,10);

/*
	l1 = lst_insere(l1,1);
	l1 = lst_insere(l1,2);
	l1 = lst_insere(l1,2);
	l1 = lst_insere(l1,3);	
*/	


	printf("Imprime lista l1:\n");
	lst_imprime(l1);
	printf("\nImprime lista l1 INVERTIDA:\n");
	lst_imprime_invertida_rec(l1);
	
	printf("\nNum. nós c/ info < que 22: %d\n", menores(l1,22));
	printf("O comprimento da lista é %d\n", comprimento(l1));
	printf("Soma dos valores dos nós %d\n", soma(l1));
	printf("Num. nós com val. perfeitos é %d\n\n", perfeito(l1));
	
	Lista* l2 = lst_cria();
	l2 = lst_insere(l2,28);
	l2 = lst_insere(l2,130);
	
	/*
	l2 = lst_insere(l2,2);
	l2 = lst_insere(l2,4);
	*/

	printf("Imprime lista l2:\n");
	lst_imprime(l2);


	Lista* l3 = lst_conc(l1,l2);
	printf("\nConcatenacao de duas listas l1 e l2:\n");
	lst_imprime(l3);
	
	
	l1=lst_diferenca(l1,l2);
	printf("\nDiferenca de duas lista l1 e l2:\n");
	lst_imprime(l1);
	
	lst_libera(l1);
	lst_libera(l2);
	lst_libera(l3);
	
	system("PAUSE");
	
	return 0;
}


