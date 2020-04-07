#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

struct PC{
	int velocidad; //entre 1 y 3
	int anio; //entre 2000 y 2017
	int nucleos; //entre 1 y 4
	char *tipo_cpu; //valores del arreglo tipos
};

void verPC(struct PC compu);
void cargarPCs(struct PC *pCompus, char *pTipos, int n);
void mostrarPCs(struct PC *pCompus, int n);
void PCvieja(struct PC *pCompus, int n);
void PCveloz(struct PC *pCompus, int n);

int main(){
	srand(time(NULL));
	char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
	char *pTipos = &tipos[0][0];
	struct PC compus[MAX]; //arreglo de estructuras
	struct PC *pCompus = &compus[0]; //puntero al arreglo de estructuras
	unsigned int n;
	
	do{
		printf("Ingrese la cantidad de PCs (no mayor a %d): ", MAX); scanf("%d",&n);
	}while(n > MAX);
	printf("\n");
	
	cargarPCs(pCompus, pTipos, n);
	mostrarPCs(pCompus, n);
	PCvieja(pCompus, n);
	PCveloz(pCompus, n);
	
	return 0;
}

void verPC(struct PC compu){
/*
	printf("Velocidad de procesamiento: %d GHz\n",compu.velocidad);
	printf("Anio de fabricacion: %d\n",compu.anio);
	printf("Cantidad de nucleos: %d\n",compu.nucleos);
	printf("Tipo de procesador: %s\n",compu.tipo_cpu);
*/
	printf("Procesador %s, %d nucleos, %d GHz de procesamiento. Fabricada en %d\n",compu.tipo_cpu,compu.nucleos,compu.velocidad,compu.anio);
}

void cargarPCs(struct PC *pCompus, char *pTipos, int n){
	int i, aux;
	struct PC compu;
	
	for(i = 0; i < n; i++){
		compu = *pCompus;

		compu.velocidad = rand()%3 +1;
		compu.anio = rand()%18 +2000;
		compu.nucleos = rand()%4 +1;
		aux = (rand()%6)*10; //aleatorio entre 0 y 5, multiplicado por 10 por cantidad de caracteres en cada espacio x del arreglo tipos[x][10]
		compu.tipo_cpu = (pTipos+aux);
		
		*pCompus = compu;
		pCompus++;
	}
}

void mostrarPCs(struct PC *pCompus, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("Computadora #%d:\n",i+1);
		verPC(*pCompus);
		pCompus++;
		printf("\n");
	}
}

void PCvieja(struct PC *pCompus, int n){
	int i;
	struct PC vieja, compu;
	vieja.anio = 3000;
	
	for(i = 0; i < n; i++){
		compu = *pCompus;
		if(compu.anio < vieja.anio){
			vieja = compu;
		}
		pCompus++;
	}
	
	printf("\n\nLa computadora mas vieja es: \n");
	if(n != 0) verPC(vieja);
}

void PCveloz(struct PC *pCompus, int n){
	int i;
	struct PC veloz, compu;
	veloz.velocidad = 0;
	
	for(i = 0; i < n; i++){
		compu = *pCompus;
		if(compu.velocidad > veloz.velocidad){
			veloz = compu;
		}
		pCompus++;
	}
	
	printf("\n\nLa computadora mas veloz es: \n");
	if(n != 0) verPC(veloz);
}
