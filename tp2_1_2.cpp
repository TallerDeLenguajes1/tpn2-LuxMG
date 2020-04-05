#include<stdio.h>
#define N 4
#define M 5

int main(){
	int aux;
	double mt[N][M], *pMt = &mt[0][0];
	
	for(aux = 0; aux<(M*N); aux++){
		printf("%lf ", *pMt);
		pMt++;
		if(aux%N == N-1){ //de esta forma diferencia las filas
			printf("\n");
		}
	}
	
	return 0;
}
