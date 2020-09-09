typedef struct filap FilaP;

FilaP* filap_cria(); //cria uma fila de prioridade vazia

void max_heapfy(FilaP *f, int i);

int heap_maximum(FilaP* f); //devolve o elemento de maior prioridade da fila

int heap_extract_max(FilaP* f); //devolve o elemento de maior prioridade e o retira da fila

void heap_increase_key(FilaP* f, int ind, int chave); //modifica a prioridade de determinado elemento no índice ind na fila (apenas se chave for maior)

void max_heap_insert(FilaP* f, int chave); //insere um novo elemento na fila com prioridade chave

void filap_imprime(FilaP* f); //Função que imprime o vetor de 0 até o tamanho-do-heap-1

