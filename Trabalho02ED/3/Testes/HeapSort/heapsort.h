typedef struct heap Heap;
Heap* heap_cria();
void heap_imprime(Heap *h);
void heap_preenche(Heap *h);

//============/ INICIO DAS FUNÇÕES DO HEAPSORT /=============/
void max_heapfy(Heap *h, int i);
void build_max_heap(Heap *h);
void heapSort(Heap *h);
//============/ FIM DAS FUNÇÕES DO HEAPSORT /=============/
