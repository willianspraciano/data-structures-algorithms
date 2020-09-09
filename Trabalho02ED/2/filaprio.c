#include <stdio.h>
#include <stdlib.h>
#include "filaprio.h"

#define MAX 10

struct filap{
	int v[MAX]; //guarda as prioridades
	int t_heap; //tamanho de heap
};



void max_heapfy(FilaP *f, int i){
	int l = (2*i + 1); 
	int r = (2*i + 2);
	/*
	Os filhos direito (r = 2*i+1) e esquerdo (l= 2*i+2) tem esses valores
	porque o vetor começa de 0, ou seja v[0,1,..,MAS-1] 
	*/
	int maior;
	int aux;
	
	if( (l <= f->t_heap) && (f->v[l] > f->v[i]) ){
		maior = l;
	}else{
		maior = i;
	}

	if( (r <= f->t_heap) && (f->v[r] > f->v[maior]) ){
		maior = r;
	}

	if(maior != i){
		aux = f->v[i];
		f->v[i] = f->v[maior];
		f->v[maior] = aux;
		max_heapfy(f, maior);
	}

}


FilaP* filap_cria(){
	FilaP *f = (FilaP*)malloc(sizeof(FilaP));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->t_heap = 0;
	return f;
}

int heap_maximum(FilaP* f){
	return f->v[0];
}


int heap_extract_max(FilaP* f){
	int max;
	if(f->t_heap < 1){
		printf("Erro: heap underflow\n");
		exit(1);
	}
	max = f->v[0];
	f->v[0] = f->v[ (f->t_heap-1) ]; //Aqui é (f->t_heap-1) e não só (f->t_heap) porque o vetor começa de 0, v[0,1,..MAX-1], ou seja quando o t_heap=1 o vetor só está ocupado na primeira posição v[0]
	f->t_heap = (f->t_heap - 1);
	max_heapfy(f, 0);
	return max;
}

void heap_increase_key(FilaP* f, int i, int chave){
	int aux;
	if (chave < f->v[i]){
		printf("Erro: Nova chave eh menor que a chave atual\n");
		exit(1);
	}
	f->v[i] = chave;
	while(i > 0 && f->v[(i-1)/2] < f->v[i]){
		aux = f->v[i];
		f->v[i] = f->v[(i-1)/2];
		f->v[(i-1)/2] = aux;
		
		i = (i-1)/2;

		/*
		  o Pai = (i-1)/2 porque o vetor começa de 0, ou seja v[0,1,...,MAX-1]
		*/	
	}
}

void max_heap_insert(FilaP* f, int chave){
	f->t_heap = (f->t_heap + 1);
	f->v[f->t_heap-1] = -99999; 
	heap_increase_key(f, f->t_heap-1, chave);
	/*
	  Fica v[f->t_heap - 1] porque o nosso vetor começa de 0, ou seja v[0...MAX-1], 
	  como t_heap é inicialmente 0, quando fazemos t_heap+1=0+1=1 logo para ocuparmos 
	  a primeira posição do vetor v[0] devemos escrever v[f->t_heap-1] = v[1-1] = v[0]
	*/
}

//Função que imprime o vetor de 0 até o tamanho-do-heap
void filap_imprime(FilaP* f){
	for (int i = 0; i < f->t_heap; i++){
		printf("%d ", f->v[i]);
	}
	printf("\n\n");
}