/*
#define BUFLEN 100

void lerArquivo();
int escreverArquivo();

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
