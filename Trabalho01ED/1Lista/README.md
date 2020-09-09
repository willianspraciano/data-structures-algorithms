<h1 align="center">
  Trabalho 01
</h1>

## 1ª Questão

Implemente o Tipo Abstrato de Dados (TAD) “lista.h” e acrescente as seguintes funções:

- **a)** função que tenha como valor de retorno o comprimento de uma lista encadeada, isto é, que calcule o número de nós de uma lista. Essa função deve obedecer ao protótipo:

		int comprimento(Lista* l);

- **b)** função para retornar o número de nós da lista que possuem o campo *info* com valor menor que *n*. Essa função deve obedecer ao protótipo:

		int menores(Lista* l, int n);

- **c)** função para somar os valores do campo *info* de todos os nós. Essa função deve obedecer ao protótipo:

		int soma(Lista* l);

- **d)** função para retornar o número de nós da lista que possuem o campo *info* com número perfeito (um número **perfeito** é igual à soma de seus divisores, exceto o próprio número. Por exemplo, 6=1+2+3). Essa função deve obedecer ao protótipo: 

		int perfeito(Lista* l);

- **e)** função para criar uma **nova** lista que é a concatenação de uma lista *l2* no final de uma lista *l1*. Essa função deve obedecer ao protótipo:

		Lista* lst_conc(Lista* l1, Lista* l2);

- **f)** função que faça a diferença de duas listas *L1* e *L2* (ou seja, que retire de *L1* os elementos que estão em *L2* ). Por exemplo, se lista *L1* → 3 → 7 → 2 → 4 → // e lista *L2* → 7 → 9 → //, a lista *L1* modificada deve ser *L1* → 3 → 2 → 4 → //. Essa função deve obedecer ao protótipo:
        
		Lista* lst_diferença(Lista* l1, Lista* l2);

A seguir, execute o seguinte programa.

```sh
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
	
	//system("PAUSE");
	
	return 0;
}
```