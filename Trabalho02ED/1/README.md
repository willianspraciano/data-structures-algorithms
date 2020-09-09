<h1 align="center">
  Trabalho 02
</h1>

## 1ª Questão

Implemente a TAD “arvb.h” (Árvore Binária de Buscas) e acrescente as seguintes funções:

- **a)** função que retorne a quantidade de folhas de uma árvore binária de busca que possuem no campo *info* um número primo. Essa função deve obedecer ao protótipo:

		int folhas_primos(ArvB* a);

- **b)** função que retorne a quantidade de nós de uma árvore binária de busca que possuem os dois filhos (campos *dir* e *esq* diferentes de *NULL*). Essa função deve obedecer ao protótipo:

		int dois_filhos(ArvB* a);

- **c)** função que, dada uma árvore binária de busca, retorne a quantidade de nós cujas subárvores esquerda e direita tenham igual altura. Essa função deve obedecer ao protótipo:

		int nos_igual_altura(ArvB* a);

- **d)** função que compare se duas árvores binárias de busca são iguais. Essa função deve obedecer ao protótipo: 

		int iguais(ArvB* a, ArvB* b);

	Obs: 1 – verdadeiro; 0 – falso.

A seguir, execute o seguinte programa.

```sh
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


	//system("PAUSE");
	return 0;
}
```