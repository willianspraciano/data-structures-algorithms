
void inverte(Fila* f){
	Lista *laux = f->ini;
	int cont=0;

	if(laux == NULL){
		printf("Lista vazia!!!\n");
		exit(1);
	}

	while(laux != NULL){
		cont++;
		laux = laux->prox;
	}

	int i, v[cont];
	laux = f->ini;

	for(i=cont; i !=0 ;i--){
		v[i-1]=laux->info;
		laux=laux->prox;
	}

	laux=f->ini;
	for(i=0; i != cont; i++){
		laux->info = v[i];
		laux=laux->prox;
	}

}
