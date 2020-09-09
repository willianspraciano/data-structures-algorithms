#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

int main(void){
	ArvB* arvA = arvb_cria_vazia();
	arvA=arvb_insere(arvA,3); 
	arvA=arvb_insere(arvA,5);
	arvA=arvb_insere(arvA,2);
	arvA=arvb_insere(arvA,4);
	arvA=arvb_insere(arvA,7);
	arvA=arvb_insere(arvA,0);
	arvA=arvb_remove(arvA,4);

	printf("Altura da arvore %d\n",arvb_altura(arvA));
	printf("Qtd folhas primos %d\n",folhas_primos(arvA));
	printf("Qtd de nos dois filhos %d\n",dois_filhos(arvA));
	printf("Nós igual altura %d\n",nos_iguais_altura(arvA));
	//printf("Altura da Arvore A eh %d\n", arvb_altura(arvA));
	



	ArvB* arvB = arvb_cria_vazia();
	arvB=arvb_insere(arvB,8);
	arvB=arvb_insere(arvB,9);
	arvB=arvb_insere(arvB,11);


	printf("Imprime Arvore 'A' em ordem simetirca: \n");
	arvb_imprime(arvA); //impressao em ordem simétrica
	printf("\n");
	printf("Imprime Arvore 'B' em ordem simetirca: \n");
	arvb_imprime(arvB); //impressao em ordem simétrica
	printf("\n");

	int comp = iguais(arvA,arvB);
	printf("arvores iguais %d\n",comp);
	printf("\n");

	arvb_libera(arvA);
	arvb_libera(arvB);


	system("PAUSE");
	return 0;
}