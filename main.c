#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
//#include <string.h>


#include <unistd.h>
#define Sleep(x) usleep((x)*1000000)
const float DELAY = 1;

#define BUFLEN 100

long getTime();
void lerArquivo();
int escreverArquivo();
int *geraArray (int);
int *ordenaArray (int *, int);
int cmpfunc (const void *, const void *);
int *array;

void main () {
	long tempoInicial = getTime();
	long tempoFinal = 0;
	long tempoDeExecucao = 0;
	
	//Gerar uma array de número aleatórios
	int tamanhoArray = 0;
	int * minhaArray;

	//Usuário especifica tamanho da array
	printf("Qual tamanho da sua array? ");
	scanf(" %d", &tamanhoArray);
	
	//Gera array
	minhaArray = geraArray(tamanhoArray);
	
	//Ordena array
	minhaArray = ordenaArray(minhaArray, tamanhoArray);
	
	//Imprime array ordenada
	printf ("\nSua array de %d elementos é:\n\n", tamanhoArray);
	for (int i=0; i < tamanhoArray; i++){
		printf("%d°: %d\n", (i+1), minhaArray[i]);
	}
	

	//lerArquivo();
	//escreverArquivo();
	//Sleep(DELAY);
  
	tempoFinal = getTime();
	tempoDeExecucao = tempoFinal - tempoInicial;
	printf ("Tempo de execução (em nanosegundos): %ld\n", tempoDeExecucao);
  
}

long getTime (){
	struct timespec t;
	long tempoNanosec=0;
	clock_gettime(CLOCK_MONOTONIC, &t);
	tempoNanosec = t.tv_sec*1000000000 + (t.tv_nsec);
	return tempoNanosec;
}


int *geraArray (int tamanho){
	array = malloc (tamanho * sizeof(int));
	srand (getTime());
	for (int i=0; i<tamanho; i++){
		array[i] = rand();
	}
	return array;
}

int *ordenaArray (int * minhaArray, int tamanhoArray){
	qsort (minhaArray, tamanhoArray, sizeof(int), cmpfunc);
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
 

 
 
 
