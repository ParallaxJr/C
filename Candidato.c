#include <stdio.h>
#include <locale.h>

void menu(){
	printf("___________ELEIÇÃO DEV__________\n");
	printf("Digite 1 - Candidato A\n");
	printf("Digite 2 - Candidato B\n");
	printf("Digite 3 - Candidato C\n");
	printf("Digite 4 para Analisar os votos já computados\n");
	printf("Anular Voto - Digite 0\n");
}

main(){
	setlocale(LC_ALL,"");
	int voto = 0, escolha;
	FILE *candA, *candB, *candC,*nulo;
	menu();
	printf("\nFaça a sua escolha: ");
	scanf("%d",&escolha);
	do{
		if(escolha == 1){
			candA=fopen("CandidatoA.txt","w");
			fprintf(candA,"%d",voto);
			fclose(candA);
		}
		if(escolha == 2){
			candB=fopen("CandidatoB.txt","w");
			fprintf(candB,"%d",voto);
			fclose(candB);
		}
		if(escolha == 3){
			candC=fopen("CandidatoC.txt","w");
			fprintf(candC,"%d",voto);
			fclose(candC);
		}
	}while(escolha!=0);
		printf("Voto Anulado!!");
		nulo=fopen("VotosNulos.txt","w");
		fprintf(nulo,"%d",voto);
		fclose(nulo);
}
