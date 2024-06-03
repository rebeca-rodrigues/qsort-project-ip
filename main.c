#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <unistd.h>

#define Sleep(x) usleep((x)*1000000)
const float DELAY = 1;

#define BUFLEN 100

//Declaração de funções
long getTime();
int *geraArray (int, long);
int *ordenaQSort (int *, long int);
int *ordenaISort (int *, long int);
int cmpfunc (const void *, const void *);
int *array;
//void lerArquivo();
//int escreverArquivo();

void main () {
	//Variáveis para contar tempo de execução
	long tempoInicial = 0;
	long tempoFinal = 0;
	long semente = getTime();
	
	//Começo do programa
	printf("***********************************");
	printf("\nPrograma de comparação dos tempos de execução do qsort e insertion sort.\n\n");
	
	//Gera array de numeros aleatorios
	long int tamanhoArray = 0;
	int * arrayDesordenada;
	printf("Qual tamanho da sua array? ");
	scanf(" %lu", &tamanhoArray);
	arrayDesordenada = geraArray(tamanhoArray, semente);
	/*
	//Imprime array desordenada
	printf("\nSua array de %ld números desordenados é:\n\n", tamanhoArray);
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", arrayDesordenada[i]);
	}
	*/
	printf("\n");
	printf("Array desordenada:\n 1° número: %d\n Último número: %d\n", arrayDesordenada[0], arrayDesordenada[tamanhoArray-1]);
	
	/*QSort*/
	
	//Ordena array com qsort
	tempoInicial = getTime();
	int * arrayQSort = ordenaQSort(arrayDesordenada, tamanhoArray);
	tempoFinal = getTime();
	long tempoQSort = tempoFinal - tempoInicial;
	/*
	//Imprime array ordenada com qsort
	printf ("\nOrdenação por QSort:\n\n");
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", arrayQSort[i]);
	}
	*/
	printf("\n");
	printf("Ordenação QSort:\n 1° número: %d\n Último número: %d\n", arrayQSort[0], arrayQSort[tamanhoArray-1]);
	printf("Tempo de execução do Qsort (em nanosec): %ld\n\n", tempoQSort);
	
	
	/*Insertion Sort*/
	
	//Gera array de novo com mesma semente
	arrayDesordenada = geraArray(tamanhoArray, semente);
	
	//Ordena array com insertion sort
	tempoInicial = getTime();
	int * arrayISort = ordenaISort(arrayDesordenada, tamanhoArray);
	tempoFinal = getTime();
	long tempoISort = tempoFinal - tempoInicial;	
	/*
	//Imprime array ordenada com insertion sort
	printf ("\nOrdenação por Insertion Sort:\n\n");
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", arrayISort[i]);
	}
	*/
	printf("Ordenação ISort:\n 1° número: %d\n Último número: %d\n", arrayISort[0], arrayISort[tamanhoArray-1]);
	printf("Tempo de execução do Insertion sort (em nanosec): %ld\n\n", tempoISort);	
	
	//lerArquivo();
	//escreverArquivo();
	//Sleep(DELAY);
}

long getTime (){
	struct timespec t;
	long tempoNanosec=0;
	clock_gettime(CLOCK_MONOTONIC, &t);
	tempoNanosec = t.tv_sec*1000000000 + (t.tv_nsec);
	return tempoNanosec;
}


int *geraArray (int tamanho, long semente){
	array = malloc (tamanho * sizeof(int));
	srand (semente);
	for (int i=0; i<tamanho; i++){
		array[i] = rand();
	}
	return array;
}

int *ordenaQSort (int * minhaArray, long int tamanhoArray){
	qsort (minhaArray, tamanhoArray, sizeof(int), cmpfunc);
	return minhaArray;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int *ordenaISort (int * minhaArray, long int tamanhoArray){
	int i;
	for (int j=1; j<tamanhoArray; j++){
		int chave = minhaArray[j];
		i = j-1;
		while (i>=0 && minhaArray[i]>chave){
			minhaArray[i+1]=minhaArray[i];
			i=i-1;
		}
		minhaArray[i+1]=chave;
	}
	return minhaArray;
}

/*
void lerArquivo() {
	char textoArquivo[BUFLEN];
  	FILE *arquivo;
  	arquivo = fopen ("teste1.txt", "rt"); //rt ou rp
  	if (!arquivo) { // caso haja erro para abrir o arquivo, escreve na tela a mensagem de erro.
		perror("");
		return;
  	}
  	while (!feof(arquivo)) {
		if (fgets (textoArquivo, BUFLEN, arquivo)) {
      			printf ("%s", textoArquivo);
    		}
 	}
 	fclose(arquivo);
}
 
int escreverArquivo() {
	char buf[BUFLEN];
	FILE *fp;
	//fp = fputs ();
}
*/
 
