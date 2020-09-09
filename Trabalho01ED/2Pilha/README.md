<h1 align="center">
  Trabalho 01
</h1>

## 2ª Questão

Implemente o Tipo Abstrato de Dados (TAD) “pilha.h” usando Listas Encadeadas e acrescente as seguintes funções:

- **a)** função que receba uma pilha como argumento e retorne o valor armazenado em seu topo. Essa função deve obedecer ao protótipo:
				
		int topo(Pilha* p);
		
	Obs: Essa função não altera a pilha, apenas retorna uma cópia do valor armazenado no seu topo.

	<br>

- **b)** função para retornar o número de elementos da pilha que possuem o campo *info* com valor ímpar. Essa função deve obedecer ao protótipo:

		int impares(Pilha* p);

- **c)** função que verifique quais são os elementos pares de uma pilha *p1* e que os empilhe em **ordem crescente** em uma pilha *p2*. Essa função deve obedecer ao protótipo:

		Pilha* empilha_pares(Pilha* p1, Pilha* p2);
		
	Obs: a pilha *p1* não deve ser alterada.
	
A seguir, execute o seguinte programa.

```sh
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

	//system("PAUSE");
	return 0;
}
```