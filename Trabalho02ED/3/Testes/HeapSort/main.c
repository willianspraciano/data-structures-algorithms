#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

int main(){

  Heap* h = heap_cria();
  heap_preenche(h);
  //int vetor[10] = {6,7,2,1,5,0,8,3,4,9};
  printf("Vetor desordenado:\n");
  heap_imprime(h);


  printf("\nHeapSort:\n");
  heapSort(h);
  heap_imprime(h);


  //system ("PAUSE");
  return 0;
}

