#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "algoritmos.h"

int main(){
  srand(time(NULL));
  clock_t t_inicio, t_fim;


  int *v, *vaux;
  int n;


  for (int i = 2; i < 7; i++){
    n = pow(10, i);
    v = (int*)malloc(sizeof(int)*n); //Alocação dinamica do vetor 'v'
    aleatorio(v,n); ///Cria um vetor aleatório

    vaux = (int*)malloc(sizeof(int)*n); //Alocação dinamica do vetor 'v'
    troca(v,vaux, n); //Coloca dos valores do vetor 'v' em 'vaux'

    printf("=========================================\n");
    printf("Para 10^%d\n", i);

    
    t_inicio = clock();
    bubbleSort(vaux, n);
    t_fim = clock();
    printf("Tempo do BubbleSort: %f ms\n",  (double)(t_fim - t_inicio)/(CLOCKS_PER_SEC/1000));
    troca(v,vaux, n);
    
    //Para a comparação ser justa, ao final de cada algoritimo de ordenação (depois que o vetor
    //já estiver ordenado), é passado novamente os valores originais do vetor 'v' para o vetor 
    //'vaux', assim os algoritmos ordenam sempre o mesmo vetor.
    

    t_inicio = clock();
    insertionSort(vaux, n);
    t_fim = clock();
    printf("Tempo do InsertionSort: %f ms\n",  (double)(t_fim - t_inicio)/(CLOCKS_PER_SEC/1000));
    troca(v,vaux, n);
    
    t_inicio = clock();
    quickSort(vaux, n);
    t_fim = clock();
    printf("Tempo do QuickSort: %f ms\n",  (double)(t_fim - t_inicio)/(CLOCKS_PER_SEC/1000));
    troca(v,vaux, n);

    t_inicio = clock();
    mergeSort(vaux, n);
    t_fim = clock();
    printf("Tempo do MergeSort: %f ms\n",  (double)(t_fim - t_inicio)/(CLOCKS_PER_SEC/1000));
    troca(v,vaux, n);


    t_inicio = clock();
    heapSort(vaux, n);
    t_fim = clock();
    printf("Tempo do HeapSort: %f ms\n",  (double)(t_fim - t_inicio)/(CLOCKS_PER_SEC/1000));
    //troca(v,vaux, n);
    
    free(v);
    free(vaux);

    printf("=========================================\n");;

  }


//TESTE SE OS ALGORITIMOS ESTÃO FUNCIONANDO
 
 /*
  int vetor[10] = {6,7,2,1,5,0,8,3,4,9};
  printf("Vetor desordenado:\n");
  for(int j=0; j<10; j++){
    printf("%d ", vetor[j]);
  }
*/
/*
  printf("\nBubbleSort:\n");
  bubbleSort(vetor, 10);
  for(int j=0; j<10; j++){
    printf("%d ", vetor[j]);
  }
*/

/*
  printf("\nInsertionSort:\n");
  insertionSort(vetor, 10);
  for(int j=0; j<10; j++){
    printf("%d ", vetor[j]);
  }  
*/
/*
  printf("\nquickSort:\n");
  quickSort(vetor, 10);
  for(int j=0; j<10; j++){
    printf("%d ", vetor[j]);
  }  
*/

/*
  printf("\nMergeSort:\n");
  mergeSort(vetor, 10);
  for(int j=0; j<10; j++){
    printf("%d ", vetor[j]);
  }

*/

/*
  printf("\nHeapSort:\n");
  heapSort(vetor, 10);
  for(int j=0; j<10; j++){
    printf("%d ", vetor[j]);
  }
*/

//TESTE DA FUNÇÃO troca(int *v, int *vaux, int n)
 /* 
  n = pow(10, 1);
  v = (int*)malloc(sizeof(int)*n);
  aleatorio(v,n);

  vaux = (int*)malloc(sizeof(int)*n);
  troca(v,vaux, n);
  printf("\nVetor aleatório:\n");
  imprime_vetor(vaux,n);
  
  heapSort(vaux, n);
  printf("\nVetor ordenado:\n");
  imprime_vetor(vaux,n);

  troca(v,vaux,n);
  printf("\nVetor volta a ser aleatório:\n");
  imprime_vetor(vaux,n);
*/

//TESTANDO COMO MEDIR O TEMPO
/*
    n = pow(10, 7);
    v = (int*)malloc(sizeof(int)*n); //Alocação dinamica do vetor 'v'
    aleatorio(v,n); ///Cria um vetor aleatório

    vaux = (int*)malloc(sizeof(int)*n); //Alocação dinamica do vetor 'v'
    troca(v,vaux, n); //Coloca dos valores do vetor 'v' em 'vaux'

    t_inicio = clock();
    insertionSort(vaux, n);
    t_fim = clock();
    printf("Tempo do insertionSort: %f ms\n",  (double)(t_fim - t_inicio)/(CLOCKS_PER_SEC/1000));
    troca(v,vaux, n);
*/
  //system ("PAUSE");
  return 0;
}

