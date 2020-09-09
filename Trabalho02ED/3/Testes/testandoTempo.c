#include <stdio.h>
#include <stdlib.h>	
#include <math.h>
#include <time.h>

int main(void){
	srand(time(NULL));
  	clock_t t_inicio, t_fim;
  	int a=0;
    int n = 1000000;
    //time_t start, end;



  	t_inicio = clock();
  	//start = time(NULL);
    while(a<n){
      printf("%d", a);
      a++;
    }
  	//end = time(NULL);
  	t_fim = clock();

  	printf("\n");
  	printf("Tempo: %f ms\n",  (double)(t_fim - t_inicio)/(CLOCKS_PER_SEC) );
  	//printf("Tempo %f\n", difftime(end, start));
  	//printf("%f\n", (double) CLOCKS_PER_SEC );

	return 0;
}