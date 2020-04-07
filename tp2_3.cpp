#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(NULL));
	int fil = 15, col = rand()%11 + 5; //numero aleatorio entre 5 y 15
	int matriz[fil][col], pares[fil];
	int i, j, aux;
	int *pMtr = &matriz[0][0], *pPar = &pares[0];
	
	for (i = 0; i < fil; i++){
		aux = 0;
		for (j = 0; j < col; j++){
			*pMtr = rand()%900 + 100; //numero aleatorio entre 100 y 999
			printf("%d ",*pMtr); //va escribiendo la matriz
			if(*pMtr%2 == 0){ //verifica si el numero es par
				aux++;
			}
			pMtr++; //se desplaza
		}
		*pPar = aux; //carga el arreglo de la cantidad de pares en cada fila
		pPar++;
		printf("\n");
	}
	
/*	
	for(i = 0; i < fil; i++){
		printf("\nPares en la fila %d: %d",i,pares[i]);
	}
*/
	
	return 0;
}
