#include <stdio.h>
#include <stdlib.h>
#include "filaprio.h"

int main(void){

	FilaP* fp = filap_cria();
	max_heap_insert(fp,34);
	max_heap_insert(fp,11);
	max_heap_insert(fp,45);
	max_heap_insert(fp,78);
	max_heap_insert(fp,92);
	max_heap_insert(fp,66);

	printf("Fila de priridades ANTES das alteracoes: \n");
	filap_imprime(fp);


	printf("Prioridade: %d\n", heap_maximum(fp));
	
	int a = heap_extract_max(fp);
	printf("Prioridades:%d e %d\n", a, heap_maximum(fp));

	//filap_imprime(fp);

	//no slide o professor declara a varival 'a' duas vezes*
	int a2 = heap_extract_max(fp);
	printf("Prioridade: %d e %d\n", a2, heap_maximum(fp));

	//filap_imprime(fp);

	heap_increase_key(fp,2,200);
	printf("Elem. maior prioridade: %d\n", heap_maximum(fp));

	printf("\nFila de prioridades DEPOIS das alteracoes:\n");
	filap_imprime(fp);

	//system("PAUSE");
	return 0;
}