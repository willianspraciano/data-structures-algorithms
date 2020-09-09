#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define MAX 3

typedef struct pilha{
	int n;
	int v[MAX];
}Pilha;

Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if (p == NULL){
		printf("Memória insuficiente!!!\n");
		exit(1);
	}
	p->n = 0;
	return p;
}

//Função que adiciona um elemento no topo de uma pilha
void pilha_push(Pilha *p, int info){
	if(p->n == MAX){
		printf("Capacidade da pilha estourou!!!\n");
		exit(1);
	}
	p->v[p->n]=info;
	p->n = p->n+1;
}

void pilha_imprime(Pilha *p){
	int i;
	for(i = p->n-1; i>=0; i--){ //parece que não pode inserir elemento na posição v[n] 
		printf("%d\n", p->v[i]);
	}
}

void pilha_libera(Pilha* p){
	free(p);
}

int pilha_vazia(Pilha *p){
	return p->n == 0;
}

//Função que remove o elemento do topo de uma pilha
int pilha_pop(Pilha *p){
	int a;
	if(pilha_vazia(p)){
		printf("Pilha vazia!!!\n");
		exit(1);
	}

	a = p->v[p->n-1];
	p->n--;
	return a;
	/*Pelo que eu entendi essa função guarda o ultimo elemento da pilha em uma variavel a
	depois ela diminui o valor de n -- em que n é como se fosse um limite -- e por fim ela
	retorna a variavel a*/
}




