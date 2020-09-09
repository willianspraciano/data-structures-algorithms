void bubbleSort(int *v, int n);

void insertionSort(int *v, int n);

void quickSort(int *v, int n); 


//===============/ INICIO DAS FUNÇÕES DO MERGESORT /==================/
void mergeSort(int *v, int n) ;
void mergeSort_ordena(int *v, int esq, int dir);
void mergeSort_intercala(int *v, int esq, int meio, int dir);
//================/ FIM DAS FUNÇÕES DO MERGESORT /===================/


//Link auxiliar para o heapsort: https://gist.github.com/alegume

//============/ INICIO DAS FUNÇÕES DO HEAPSORT /=============/
void max_heapfy(int *v, int i, int *t_heap);
void build_max_heap(int *v, int n, int *t_heap);
void heapSort(int *a, int n);
//============/ FIM DAS FUNÇÕES DO HEAPSORT /=============/


//=============/ INICIO FUNÇÕES AUXILIARES /==============//
void aleatorio(int *v, int n);
void troca(int *v, int *vaux, int n);
void imprime_vetor(int *v, int n);
//==============/ FIM FUNÇÕES AUXILIARES /===============//