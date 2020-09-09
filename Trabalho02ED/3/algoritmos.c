#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"


void bubbleSort(int *v, int n){
	int i, j, temp;
	for(i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			if(v[j]> v[j+1]){
				temp = v[j]; // Troca
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}

void insertionSort(int *v, int n){
   int i, aux, j;
   for (i = 1; i < n; i++){
       j = i;
       while (v[j] < v[j-1] && j > 0){
           aux = v[j];
           v[j]= v[j-1];
           v[j-1] = aux;
           j = j-1;
       }
   }

}

void quickSort(int *v, int n){
	if(n>1){
		int x = v[0];
		int a =1;
		int b = n-1;
		while(1){
			while(a<n && v[a] <=x){
				a++;
			}
			while(v[b]>x){
				b--;
			}

			if(a<b){
				int temp = v[a];
				v[a] = v[b];
				v[b] = temp;
				a++;
				b--;
			}else{
				break;
			}
		}
		v[0] = v[b];
		v[b] = x;
		quickSort(v,b);
		quickSort(&v[a], n-a);
	}
}



//============/ INICIO DAS FUNÇÕES DO MERGESORT /=============/

// ordena o vetor v[0..n-1] 
void mergeSort(int *v, int n) {
	mergeSort_ordena(v, 0, n-1);
}

// ordena o vetor v[esq..dir] 
void mergeSort_ordena(int *v, int esq, int dir) {
	if (esq == dir){
		return;
	}
	int meio = (esq + dir) / 2;
	mergeSort_ordena(v, esq, meio);
	mergeSort_ordena(v, meio+1, dir);
	mergeSort_intercala(v, esq, meio, dir);
	return;
}

// intercala os vetores v[esq..meio] e v[meio+1..dir]
void mergeSort_intercala(int *v, int esq, int meio, int dir) {
	int i, j, k;
	int a_tam = meio - esq + 1;
	int b_tam = dir - meio;
	int *a = (int*) malloc(sizeof(int) * a_tam);
	int *b = (int*) malloc(sizeof(int) * b_tam);
	for (i = 0; i < a_tam; i++) a[i] = v[i+esq];
	for (i = 0; i < b_tam; i++) b[i] = v[i+meio+1];
	
	for (i = 0, j = 0, k = esq; k <= dir; k++) {
		if (i == a_tam) v[k] = b[j++];
		else if (j == b_tam) v[k] = a[i++];
		else if (a[i] < b[j]) v[k] = a[i++];
		else v[k] = b[j++];
	}
	
	free(a); 
	free(b);
}


//============/ FIM DAS FUNÇÕES DO MERGESORT /=============/



//============/ INICIO DAS FUNÇÕES DO HEAPSORT /=============/

void max_heapfy(int *v, int i, int *t_heap){
	int l = (2*i + 1); 
	int r = (2*i + 2);
	int maior;
	int aux;
	
	if( (l <= *t_heap) && (v[l] > v[i]) ){
		maior = l;
	}else{
		maior = i;
	}

	if( (r <= *t_heap) && (v[r] > v[maior]) ){
		maior = r;
	}

	if(maior != i){
		aux = v[i];
		v[i] = v[maior];
		v[maior] = aux;
		max_heapfy(v, maior, t_heap);
	}

}

void build_max_heap(int *v, int n, int *t_heap){
	//*t_heap = n-1;
	for(int i = ((n-1)/2); i >= 0 ; i--){
		max_heapfy(v, i, t_heap);
	}
}

void heapSort(int *v, int n){ //'n' é o tamanho do vetor 
	int t_heap = n-1; //Como é usado vetores e não uma estrutura de heap, o tamanho do heap é, inicialmente igual ao tamanho do vetor -1
	int aux;
	build_max_heap(v,n, &t_heap);
	for(int i = (n-1); i > 0; i--){
		
		aux = v[i];
		v[i] = v[0];
		v[0]=aux;
		
		t_heap--;
		max_heapfy(v,0,&t_heap);
	}
}

//============/ FIM DAS FUNÇÕES DO HEAPSORT /=============/


//=============/ INICIO FUNÇÕES AUXILIARES /==============//
void aleatorio(int *v, int n){
  for (int i = 0; i < n; i++){
    v[i] = rand() % 999999;
  }
}

void troca(int *v, int *vaux, int n){
	for(int i=0; i < n; i++){
		vaux[i]=v[i];
	}
}

void imprime_vetor(int *v, int n){
	for (int i = 0; i < n; i++){
		printf("%d  ", v[i]);
	}
}
//==============/ FIM FUNÇÕES AUXILIARES /===============//