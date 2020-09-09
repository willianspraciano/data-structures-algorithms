typedef struct arvb ArvB;


//Função do Slide do professor
ArvB* arvb_cria_vazia(void);

//Função do Slide do professor
int arvb_vazia(ArvB *a);

//Função do Slide do professor
ArvB* arvb_busca(ArvB* a, int c);

//Função do Slide do professor
void arvb_imprime(ArvB *a);

//Função do Slide do professor
ArvB* arvb_insere(ArvB* a, int c);

//Função do Slide do professor
ArvB* arvb_remove(ArvB *a, int c);

//Função do Slide do professor
void arvb_libera(ArvB* a);

//Função do Slide do professor
int arvb_altura(ArvB *a);



//===========================================================================//
//======================== FUNÇÕES DO 2º TRABALHO ED ========================//
//===========================================================================//

//QUESTÃOO 1, ITEM (a)
int folhas_primos(ArvB* a);


//QUESTÃO 1, ITEM (b)
int dois_filhos(ArvB* a);


//QUESTÃO 1, ITEM (c)
int nos_iguais_altura(ArvB* a);


//QUESTÃO 1, ITEM (d)
int iguais(ArvB* a, ArvB* b);

//===========================================================================//
//===========================================================================//
//===========================================================================//
