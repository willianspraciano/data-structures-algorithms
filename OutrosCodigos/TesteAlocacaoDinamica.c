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
	int n, i;
	float *v, s;
	printf("Escreva o tamanho do vetor:\n");
	scanf("%d", &n);
	v = (float*)malloc(n*sizeof(float));
	for(i=0; i<n; i++){
		//scanf("%f", &v[i]);
		v[i]=i+1;
	}
	s = somatorio(n, v);
	printf("Somatorio = %.1f, media = %.1f\n",s, s/n );

	return 0;
}