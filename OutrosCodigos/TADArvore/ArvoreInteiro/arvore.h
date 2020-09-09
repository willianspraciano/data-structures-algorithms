typedef struct arvb ArvB;

ArvB* arvb_cria_vazia(void);

int arvb_vazia(ArvB* a);

ArvB* arvb_busca(ArvB *a,int c);

void arvb_imprime(ArvB *a);

ArvB* arvb_insere(ArvB *a, int c);

ArvB* arvb_remove(ArvB *a, int c);

void arvb_libera(ArvB *a);

int arvb_altura(ArvB *a);



