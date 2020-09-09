//função empilha paresde uma pilha p1 em uma pilha p2 usando vetores



Pilha* empilha_pares(Pilha* p1, Pilha* p2){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));

	Lista *laux = p1->prim;
	int i, tam;

	//CALCULANDO A QUANTIDADE DE PARES DA PILHA
	while(laux!=NULL){
		//printf("%d\n",laux->info);
		if((laux->info)%2 == 0){
			tam++;
		}
		laux = laux->prox;
	}

	
	//PASSANDO OS VALORES pares DE p1->prim PARO O VETOR
	int v[tam];
	laux=p1->prim;
	i=0;
	while(laux != NULL || i<tam){
		if((laux->info)%2 == 0){
			v[i] = laux->info;
			laux = laux->prox;
			i++;
		}else{
			laux=laux->prox;
		}
	}


//	//=========AREA DE TESTES=============
//	printf("\n\nImprimindo vetor NAO ordenado\n");
//	for(i=0; i != tam; i++){
//		printf("%d\n",v[i] );
//	}
//	printf("Terminou de imprimir vetor NAO ordenado\n\n");
//	//=========AREA DE TESTES=============


	//ORDENANDO O VETOR EM ORDEM CRESCENTE
	int vaux,j;
	int cont =0;
	//while(cont < tam){
	for(j=1; j < tam; j++){
		for(i=0; i < tam; i++){
			if(v[i] > v[j]){
				vaux= v[i];
				v[i] = v[j];
				v[j] = vaux; 
			}
		}
		//cont++;
	}

//
//	//=========AREA DE TESTES=============
//	printf("\n\nImprimindo vetor ordenado\n");
//	for(i=0; i != tam; i++){
//		printf("%d\n",v[i] );
//	}
//	printf("Terminou de imprimir vetor ordenado\n\n");
//	//=========AREA DE TESTES=============



	p=p2;
	for(i=0; i != tam; i++){
		pilha_push(p, v[i]);
	}

	return p;
}
