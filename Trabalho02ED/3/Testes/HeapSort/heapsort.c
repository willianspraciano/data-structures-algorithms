#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

#define MAX 10

struct heap{
	int v[MAX];
	int t_heap; //tamanho de heap
};

Heap* heap_cria(){
	Heap *h = (Heap*)malloc(sizeof(Heap));
	if(h==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	h->t_heap = 0;
	return h;
}

void heap_preenche(Heap *h){
	h->t_heap = 10;
 	h->v[0] = 6;
  	h->v[1] = 7;
  	h->v[2] =2;
  	h->v[3] =1;
  	h->v[4] =5;
  	h->v[5] =0;
  	h->v[6] =8;
  	h->v[7] =3;
  	h->v[8] =4;
  	h->v[9] =9;
}

void heap_imprime(Heap *h){
	for(int j=0; j<10; j++){
    	printf("%d ", h->v[j]);
  	}
}

//============/ INICIO DAS FUNÇÕES DO HEAPSORT /=============/
/*
void heapSort(int *a, int n) {
   int i = (n / 2), pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}
*/



void max_heapfy(Heap *h, int i){
	int l = (2*i + 1); 
	int r = (2*i + 2);
	int maior;
	int aux;
	
	if( (l <= h->t_heap) && (h->v[l] > h->v[i]) ){
		maior = l;
	}else{
		maior = i;
	}

	if( (r <= h->t_heap) && (h->v[r] > h->v[maior]) ){
		maior = r;
	}

	if(maior != i){
		aux = h->v[i];
		h->v[i] = h->v[maior];
		h->v[maior] = aux;
		max_heapfy(h, maior);
	}

}

void build_max_heap(Heap *h){
	h->t_heap = h->t_heap -1;
	for(int i = (MAX-1)/2; i >= 0 ; i--){
		max_heapfy(h, i);
	}
}

void heapSort(Heap *h){ //'n' é o tamanho do vetor 
	int aux;
	build_max_heap(h);
	for(int i = (MAX-1); i > 0; i--){
		
		aux = h->v[i];
		h->v[i] = h->v[0];
		h->v[0]=aux;
		
		h->t_heap--;
		max_heapfy(h,0);
	}
}
