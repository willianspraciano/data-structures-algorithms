#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void){
	ArvB* a = arvb_cria_vazia();
	if(arvb_vazia(a)){
		printf("Arvore vazia!!!\n");
	}
	a = arvb_insere(a,1);
	a = arvb_insere(a,2);
	a = arvb_insere(a,3);
	a = arvb_insere(a,4);
	a = arvb_insere(a,5);
	a = arvb_insere(a,6);
	a = arvb_insere(a,7);

	if(!arvb_vazia(a)){
		printf("Foram inseridos elemento na árvore!!!\n");
	}

	arvb_imprime(a);

	arvb_remove(a, 5);
	printf("O 5 foi removido da arvore\n");
	arvb_imprime(a);

	printf("A altura da arvore eh: %d\n", arvb_altura(a));

	arvb_libera(a);
	printf("Espaço na memoria liberado!!!\n");
	arvb_imprime(a);


	return 0;
}