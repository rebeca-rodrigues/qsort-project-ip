#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <unistd.h>

int * array;
long getTime();
void geraArray (long, long), mostraArray (long), ordenaQSort (long), ordenaISort (long);
int cmpfunc (const void *, const void *);

void main () {
	//Variáveis para contar tempo de execução
	long tempoInicial, tempoFinal, tempoQSort, tempoISort, tamanhoArray, semente = 4104;
	
	//Usuário insere tamanho da array
	printf("\nPrograma de comparação dos tempos de execução do qsort e insertion sort.\n\nQual tamanho da sua array? ");
	scanf(" %lu", &tamanhoArray);
	
	//Gera array de numeros aleatorios
	geraArray(tamanhoArray, semente);
	printf("\nArray desordenada: \n");
	mostraArray(tamanhoArray);
	
	/*QSort*/
	tempoInicial = getTime();
	ordenaQSort(tamanhoArray);
	tempoFinal = getTime();
	tempoQSort = tempoFinal - tempoInicial;
	printf("\nOrdenação QSort: \n");
	mostraArray(tamanhoArray);
	printf("Tempo de execução do Qsort (em nanosec): %ld\n", tempoQSort);

	geraArray(tamanhoArray, semente); //Gera array novamente
	
	/*Insertion Sort*/
	tempoInicial = getTime();
	ordenaISort(tamanhoArray);
	tempoFinal = getTime();
	tempoISort = tempoFinal - tempoInicial;
	printf("\nOrdenação Insertion Sort: \n");
	mostraArray(tamanhoArray);
	printf("Tempo de execução do Insertion sort (em nanosec): %ld\n", tempoISort);
}

long getTime (){
	struct timespec t;
	long tempoNanosec=0;
	clock_gettime(CLOCK_MONOTONIC, &t);
	tempoNanosec = t.tv_sec*1000000000 + (t.tv_nsec);
	return tempoNanosec;
}


void geraArray (long tamanhoArray, long semente){
	array = malloc (tamanhoArray * sizeof(int));
	srand (semente);
	for (int i=0; i<tamanhoArray; i++){
		array[i] = rand();
	}
}

void mostraArray (long tamanhoArray){
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", array[i]);
	}
	//printf("\n 1° número: %d\n Último número: %d\n", array[0], array[tamanhoArray-1]);
}

void ordenaQSort (long tamanhoArray){
	qsort (array, tamanhoArray, sizeof(int), cmpfunc);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void ordenaISort (long tamanhoArray){
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
}
