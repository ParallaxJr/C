#include <stdio.h>
#include <stdlib.h>

void menu(void) {
	printf("Informe o seu voto\n");
	printf("------------------\n");
	printf("1 - Candidato 01\n");
	printf("2 - Candidato 02\n");
	printf("5 - Nulo\n");
	printf("6 - Branco\n");
	printf("0 - Encerrar\n");
	printf("------------------\n");
}

void criaArquivo(char nomeArquivo[100], int valor) {
	FILE *arquivo;
	arquivo=fopen(nomeArquivo,"w");
    fprintf(arquivo,"%d",valor);
	fclose(arquivo);
}

int leArquivoIncrementando(char nomeArquivo[100]) {
	FILE *arquivo;
	int valor;
	arquivo=fopen(nomeArquivo,"r");
    fscanf(arquivo,"%d",&valor);
	fclose(arquivo);
	return valor+1;
}

void geraTodosArquivos(void){
    int contador;
	criaArquivo("candidato1.txt",0);
	criaArquivo("candidato2.txt",0);
	criaArquivo("branco.txt",0);
	criaArquivo("nulo.txt",0);
	criaArquivo("total.txt",0);
}

void porcentagemVoto(void) {
	float total = leArquivoIncrementando("total.txt") - 1;
	float candidato1 = leArquivoIncrementando("candidato1.txt") - 1;
	float candidato2 = leArquivoIncrementando("candidato2.txt") - 1;
	float branco = leArquivoIncrementando("branco.txt") - 1;
	float nulo = leArquivoIncrementando("nulo.txt") - 1;

	printf("Candidato 1 ....... %.2f%% (%.0f)\n", candidato1/total*100, candidato1);
	printf("Candidato 2 ....... %.2f%% (%.0f)\n", candidato2/total*100, candidato2);
	printf("Nulo .............. %.2f%% (%.0f)\n", nulo/total*100, nulo);
	printf("Branco ............ %.2f%% (%.0f)\n", branco/total*100, branco);
	printf("---------------------------------\n");
	if (candidato1>candidato2) {
	    printf("O candidato 1 foi o vencedor!\n");
	}
	else {
        if (candidato1==candidato2) {
            printf("Empate!\n");
        }
        else {
            printf("O candidato 2 foi o vencedor!\n");
        }
	}
}

void incrementaVoto(int escolha) {
	if (escolha == 1) {
		criaArquivo("candidato1.txt",leArquivoIncrementando("candidato1.txt"));
	}
	if (escolha == 2) {
        criaArquivo("candidato2.txt",leArquivoIncrementando("candidato2.txt"));
	}
	if (escolha == 5) {
		criaArquivo("nulo.txt",leArquivoIncrementando("nulo.txt"));
	}
	if (escolha == 6) {
		criaArquivo("branco.txt",leArquivoIncrementando("branco.txt"));
	}
}

void validaMenu(int escolha) {
	if ((escolha > 0 && escolha < 7 ) && escolha != 3 && escolha != 4) {
	      criaArquivo("total.txt",leArquivoIncrementando("total.txt"));
	      incrementaVoto(escolha);
	  }
	  else {
	  	  if (escolha != 0) printf("Escolha invalida!");
	  	  getchar();
	  }
}

int main(void) {
	int escolha;
	geraTodosArquivos();
	do {
	  menu();
	  scanf("%d",&escolha);
	  validaMenu(escolha);
	  system("cls");
	} while (escolha !=0);
	porcentagemVoto();
}
