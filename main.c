#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <unistd.h>

long getTime();
int *geraArray (int, long);
void mostraArray (int *, long);
int *ordenaQSort (int *, long int);
int *ordenaISort (int *, long int);
int cmpfunc (const void *, const void *);
int *array;

void main () {
	//Variáveis para contar tempo de execução
	long tempoInicial, tempoFinal, tempoQSort, tempoISort, tamanhoArray, semente = 4104;
	
	//Usuário insere tamanho da array
	printf("\nPrograma de comparação dos tempos de execução do qsort e insertion sort.\n\nQual tamanho da sua array? ");
	scanf(" %lu", &tamanhoArray);
	
	//Gera array de numeros aleatorios com tamanho fornecido pelo usuário
	array = geraArray(tamanhoArray, semente);
	printf("\nArray desordenada: ");
	mostraArray(array, tamanhoArray);
	
	/*QSort*/
	tempoInicial = getTime();
	array = ordenaQSort(array, tamanhoArray);
	tempoFinal = getTime();
	tempoQSort = tempoFinal - tempoInicial;
	printf("\nOrdenação QSort: ");
	mostraArray(array, tamanhoArray);
	printf("Tempo de execução do Qsort (em nanosec): %ld\n", tempoQSort);
	
	array = geraArray(tamanhoArray, semente); //Gera array novamente
	
	/*Insertion Sort*/
	tempoInicial = getTime();
	array = ordenaISort(array, tamanhoArray);
	tempoFinal = getTime();
	tempoISort = tempoFinal - tempoInicial;
	printf("\nOrdenação Insertion Sort: ");
	mostraArray(array, tamanhoArray);
	printf("Tempo de execução do Insertion sort (em nanosec): %ld\n\n", tempoISort);	
	
}

long getTime (){
	struct timespec t;
	long tempoNanosec=0;
	clock_gettime(CLOCK_MONOTONIC, &t);
	tempoNanosec = t.tv_sec*1000000000 + (t.tv_nsec);
	return tempoNanosec;
}


int *geraArray (int tamanhoArray, long semente){
	array = malloc (tamanhoArray * sizeof(int));
	srand (semente);
	for (int i=0; i<tamanhoArray; i++){
		array[i] = rand();
	}
	return array;
}

void mostraArray (int * array, long tamanhoArray){
	/*
	printf("\nSua array é:\n\n");
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", arrayDesordenada[i]);
	}
	*/
	printf("\n 1° número: %d\n Último número: %d\n", array[0], array[tamanhoArray-1]);
}

int *ordenaQSort (int * array, long int tamanhoArray){
	qsort (array, tamanhoArray, sizeof(int), cmpfunc);
	return array;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int *ordenaISort (int * array, long int tamanhoArray){
	int i;
	for (int j=1; j<tamanhoArray; j++){
		int chave = array[j];
		i = j-1;
		while (i>=0 && array[i]>chave){
			array[i+1]=array[i];
			i=i-1;
		}
		array[i+1]=chave;
	}
	return array;
}
 
