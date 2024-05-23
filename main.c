#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
//#include <string.h>


#include <unistd.h>
#define Sleep(x) usleep((x)*1000000)
const float DELAY = 1;

#define BUFLEN 100

//Declaração de funções
long getTime();
int *geraArray (int, long);
int *ordenaQSort (int *, int);
int *ordenaISort (int *, int);
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
	int tamanhoArray = 0;
	int * arrayDesordenada;
	printf("Qual tamanho da sua array? ");
	scanf(" %d", &tamanhoArray);
	arrayDesordenada = geraArray(tamanhoArray, semente);
	printf("\nSua array de %d números desordenados é:\n\n", tamanhoArray);
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", arrayDesordenada[i]);
	}
	
	/*QSort*/
	
	//Ordena array com qsort
	tempoInicial = getTime();
	int * arrayQSort = ordenaQSort(arrayDesordenada, tamanhoArray);
	tempoFinal = getTime();
	long tempoQSort = tempoFinal - tempoInicial;
	
	//Imprime array ordenada com qsort
	printf ("\nOrdenação por QSort:\n\n");
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", arrayQSort[i]);
	}
	
	
	/*Insertion Sort*/
	
	//Gera array de novo com mesma semente
	arrayDesordenada = geraArray(tamanhoArray, semente);
	
	//Ordena array com insertion sort
	tempoInicial = getTime();
	int * arrayISort = ordenaISort(arrayDesordenada, tamanhoArray);
	tempoFinal = getTime();
	long tempoISort = tempoFinal - tempoInicial;
	
	//Imprime array ordenada com insertion sort
	printf ("\nOrdenação por Insertion Sort:\n\n");
	for (int i=0; i < tamanhoArray; i++){
		printf("%d\n", arrayISort[i]);
	}
	
	//Imprime tempos de execução
	printf("\nTempo de execução do Qsort (em nanosec): %ld\n", tempoQSort);
	printf("\nTempo de execução do Insertion sort (em nanosec): %ld\n", tempoISort);
	
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

int *ordenaQSort (int * minhaArray, int tamanhoArray){
	qsort (minhaArray, tamanhoArray, sizeof(int), cmpfunc);
	return minhaArray;
}

int *ordenaISort (int * minhaArray, int tamanhoArray){
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

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

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
 

	/* No main
	//Escolher operação, ler o gerar arquivo (ainda não implementado)
	char operacao;
	printf("- Para ler e ordenar array de um arquivo, digite 1. \n- Para gerar, ordenar e escrever um array aleatório em um arquivo, digite 2.\n");
	scanf(" %c", &operacao);
	
	if (operacao == "1") {
		printf("Operacao 1");
	}
	else if (operacao == "2"){
		printf("Operacao 2");
	}
	else {
		printf("Operacao invalida.");
	}
	*/
 
 
