#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define m 4

int raizes (float a, float b, float c, float *x1, float *x2){
	int cont;
	
	float delta = b*b - 4*a*c;
	
	if(delta < 0){
		
		printf("Delta MENOR que zero. Não ha raizes reais\n");
		cont =0;

	} else if(delta == 0){
		
		printf("Delta IGUAL A zero. Ha apenas uma raiz real\n");
		*x1 = ( ( (-b) + sqrt(delta) )/(2*a) );
		*x2 = ( ( (-b) - sqrt(delta) )/(2*a) );
		cont = 1;
	
	}else{
	
		printf("Delta MAIOR que zero. Ha duas raizes reais\n");
		*x1 = ( ( (-b) + sqrt(delta) )/(2*a) );
		*x2 = ( ( (-b) - sqrt(delta) )/(2*a) );
		cont = 2;

	}

	return cont;
}

void calc_esfera (float r, float* area, float* volume){

	*area = 4*3.14*r*r;
	*volume = (4/3)*3.14*r*r*r;

}


void inverte (int n, int* vet){
	int vaux[n];
	int i;
	int j=n;
	for(i=0; i<n; i++){
		vaux[j-1] = vet[i];
		j--;
	}
	for (i=0; i<n; i++){
		vet[i] = vaux[i];
	}
}



int main(void){
	
//----- 1 QUESTÃO -----//
//---------------------//
	printf("\n\n1 QUESTAO:\n");
	float a = 1;
	float b = -4;
	float c = 5;

	float x1= 0.0;
	float x2= 0.0;

	int nraizes = raizes(a,b,c,&x1,&x2);
	printf("\nx1 = %.2f e x2 = %.2f\n\nNumero de raizes reais: %d\n", x1, x2, nraizes);

//---------------------//
//---------------------//


//----- 2 QUESTÃO -----//
//---------------------//
	printf("\n\n2 QUESTAO:\n");
	float area;
	float volume;
	calc_esfera(2, &area, &volume);
	printf("Area da esfera: %.2f e Volume da esfera: %.2f\n", area, volume);

//---------------------//
//---------------------//


//----- 3 QUESTÃO -----//
//---------------------//
	printf("\n\n3 QUESTAO:\n");
//	int n=4;
	int vet[m]={1,2,3,4};
	
	printf("Normal: ");;
	for(int i=0; i<4; i++){
		printf("%d ",vet[i]);
	}
	
	inverte (m, vet);
	
	printf("\nInvertido: ");;	
	for(int i=0; i<4; i++){
		printf("%d ",vet[i]);
	}



//---------------------//
//---------------------//


//----- 4 QUESTÃO -----//
//---------------------//
	printf("\n\n4 QUESTAO:\n");

//---------------------//
//---------------------//


//----- 5 QUESTÃO -----//
//---------------------//
	printf("\n\n5 QUESTAO:\n");

//---------------------//
//---------------------//	



	return 0;
}