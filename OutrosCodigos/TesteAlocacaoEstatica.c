#include <stdio.h>
#include <stdlib.h>

float somatorio(int m, float v[]){
	float soma;
	int i;
	for (i=0; i<m; i++){
		soma +=  v[i];
	}
	return soma;
}

int main(void){
	int n;
	printf("Digite o tamanho do vetor\n");
	scanf("%d", &n);
	float v[n];
	//= {2.0, 3.0, 4.0};
	/*
	v[0]=2.0;
	v[1]=3.0;
	v[2]=4.0;
	*/
	for(int i=0; i!=n; i++){
		v[i]=i+1;
	}
	float s = somatorio(n,v);
	printf("Somatorio = %.1f, media = %.1f \n", s, s/n);


	return 0;
}