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
	system("PAUSE");
	return 0;
}