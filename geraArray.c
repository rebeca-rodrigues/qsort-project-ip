#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *geraArray (int);
int *array;

void main (){
	int tamanhoArray = 0;
	int * minhaArray;

	//Usuário especifica tamanho da array
	printf("Qual tamanho da sua array? ");
	scanf(" %d", &tamanhoArray);
	
	//Gera array
	minhaArray = geraArray(tamanhoArray);
	
	//Imprime array
	printf ("\nSua array de %d elementos é:\n\n", tamanhoArray);
	for (int i=0; i < tamanhoArray; i++){
		printf("%d°: %d\n", (i+1), minhaArray[i]);
	}
}

int *geraArray (int tamanho){
	array = malloc (tamanho * sizeof(int));
	struct timespec tempo;
	clock_gettime(CLOCK_MONOTONIC, &tempo);
	
	srand (tempo.tv_nsec);
	for (int i=0; i<tamanho; i++){
		array[i] = rand();
	}
	return array;
}
