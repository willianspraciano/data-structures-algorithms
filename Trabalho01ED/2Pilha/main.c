#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){

	int a;
	
	Pilha* p1 = pilha_cria();
	pilha_push(p1,10);
	pilha_push(p1,20);
	pilha_push(p1,25);
	pilha_push(p1,30);

	a = pilha_pop(p1);
	
	pilha_imprime(p1);
	printf("\nElemento no topo da pilha p1 é %d\n", topo(p1));
	printf("Qde elems impares na pilha é %d\n", impares(p1));

	Pilha* p2 = pilha_cria();
	pilha_push(p2,3);
	pilha_push(p2,4);

	p2 = empilha_pares(p1,p2);
	printf("Elementos pares de p1 empilhados em ordem crescente em p2: \n");
	pilha_imprime(p2);

	pilha_libera(p1);
	pilha_libera(p2);

	system("PAUSE");
	return 0;
}