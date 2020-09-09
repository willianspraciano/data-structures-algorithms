<h1 align="center">
  Trabalho 01
</h1>

## 3ª Questão

Implemente o Tipo Abstrato de Dados (TAD) “fila1.h” (implementação com vetor) e “fila2.h” (implementação com listas encadeadas) e acrescente as seguintes funções:

- **a)** função para retornar o número de elementos da fila com valor maior que *n*. Essa função deve obedecer ao protótipo:
				
		int qtd_maior(Fila* f, int n);

- **b)** função que inverta a ordem dos elementos da fila. Essa função deve obedecer ao protótipo:

		void inverte(Fila* f);

- **c)** função para retornar o número de elementos da fila que possuem o campo *info* com valor par. Essa função deve obedecer ao protótipo:

		int pares(Fila* f);
	
A seguir, execute o seguinte programa com as TAD's “fila1.h” e “fila2.h”

```sh
#include <stdio.h>
#include <stdlib.h>
#include "fila1.h" //executar também com “fila2.h”

int main(void){
	
	int a, qtd;
	
	Fila* f = fila_cria();
	fila_insere(f,10);
	fila_insere(f,20);
	fila_insere(f,30);
	fila_insere(f,40);
	fila_insere(f,50);

	printf("Fila NORMAL:\n");
	fila_imprime(f);
	
	inverte(f);
	printf("Fila INVERTIDA:\n");

	a = fila_remove(f);
	printf("O primeiro elemento da fila INVERTIDA (%d) foi removido!\n", a);
	fila_imprime(f);
	
	qtd=qtd_maior(f,20);
	printf("Núm. de elem. maiores que 20: %d\n", qtd);
	printf("Qtd. elementos pares na fila: %d\n", pares(f));
	
	fila_libera(f);
	//system("PAUSE");
	return 0;
}
```