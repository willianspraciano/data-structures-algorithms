#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//"Primeiro que entra ultimo que sai"]

typedef struct lista{
	int info;
	Lista *prox;
}Lista;


typedef struct pilha{
	Lista *prim;
}Pilha;

Pilha* pilha_cria(void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	if(p==NULL){
		printf("Memoria insuficiente\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

/*Função que adiciona elementos na pilha*/
void pilha_push(Pilha *p, int info){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;  /*l->prox vai apontar para o primeiro elemento*/
	p->prim = l; /*O primeiro elemento deixa de ser o atual e passa aser l*/

	//Uma fila normal já insere de uma forma que o ultimo elemento inserido
	//é o primeiro elemento da lista, então facilita ainda mais pra pilha, pois
	//assim A estrutura Pilha só precisa ser composta por um ponteiro pra lista
	//que aponta por primeiro elemento(que foi o ultimo que entrou)
}

int pilha_vazia(Pilha *p){
	return p->prim == NULL;
}

//Função para remover o primeiro elemento da pilha
int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

void pilha_imprime(Pilha *p){
	Lista *laux = p->prim;
	while(laux != NULL){
		printf("%d\n",laux->info);
		laux = laux->prox;
	}
}

void pilha_libera(Pilha *p){
	Lista *l = p->prim;
	Lista *laux;
	while(l != NULL){
		laux = l->prox;
		free(l);
		l = laux;
	}
	free(p);
}


//=======//AP1 2018.1 questão 3////=======//
//========================================//
void pilha_push_maior(Pilha *p, int info){
	if(p->prim == NULL || info > p->prim->info){ 
	//tem que ser nessa ordem porque se não ele vai fazer a d
	//ivisão de elementos nulos e vai dar falha de segmentação

		Lista *l = (Lista*)malloc(sizeof(Lista));
		if(l == NULL){
			printf("Memoria insuficiente!!!\n");
			exit(1);
		}
		l->info = info;
		l->prox = p->prim;
		p->prim = l;
	}
}

int pilha_pop_par(Pilha *p){
	if(p->prim == NULL){
		printf("Pilha vazia!!!!!!!!\n");
		exit(1);
	}else if ((p->prim->info)%2 != 0){
		printf("Nao eh Par\n");
		exit(1);
	}
		Lista *l = p->prim;
		p->prim = l->prox;
		int a = l->info;
		free(l);
		return a;
}

//========================================//
//========================================//