#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void main(void){
	setlocale(LC_ALL, "Portuguese");
	char **filme;
	int i = 3, n, lim, res, resp, quant_f = 2;
	int total, resp1, c = 0, v = 0, inserir_f;
	char filme_escolhido[20];
	int result;
	
	filme = malloc(40*sizeof(char*));
	
	filme[0] = "Toy Story";
	filme[1] = "Colombiana";
	filme[2] = "Wall-E";
	printf("Filmes Dísponíveis:\n\n");
	for(i = 0; i < 3; i++){
		printf("%d. %s\n", i+1, filme[i]);
	}
	
	printf("\n");
	system("pause");
	system("cls");
menu:
	printf("Chegamos na parte final!\n\n");
	printf("1 - Buscar Filmes\n");
	printf("2 - Identificar a quantidade de Filmes na Lista\n");
	printf("3 - Remover Filmes da Lista\n");
	printf("4 - Adicionar Filmes na Lista\n");
	printf("5 - Finalizar o programa\n");

	printf("\nDigite o número de acordo com o que deseja fazer: ");
	scanf("%d", &res);
	
	switch(res){
		case 1:
			system("cls");
			fflush(stdin);
			printf("Digite o nome do filme que deseja verificar: ");
			gets(filme_escolhido);
			for(i = 0; i <= quant_f; i++){	
				result = strcmp(filme_escolhido, filme[i]);
					if( result == 0 ){
						printf("\nO filme está na lista!!\n");
						printf("Encontra-se na posição %d.\n", i+1);
					}
			}
			printf("\n");
			for(i = 0; i <= (quant_f); i++){
				printf("%d. %s\n", i+1, filme[i]);
			}
			printf("\nRetornar ao menu anterior ?\n");
			printf("\n1 - Sim\n2 - Não\n");
			scanf("%d", &resp);
			if( resp == 1 ){
				system("cls");
				goto menu;
			}else{
				exit(1);
			}
			break;
		case 2:
			system("cls");
			total = (quant_f-c);
			printf("A quantidade de filmes na lista é %d.\n", (total+v+1));
			printf("\n");
			for(i = 0; i <= (quant_f); i++){
				printf("%d. %s\n", i+1, filme[i]);
			}
			printf("\nRetornar ao menu anterior ?\n");
			printf("\n1 - Sim\n2 - Não\n");
			scanf("%d", &resp);
			if( resp == 1 ){
				system("cls");
				goto menu;
			}else{
				exit(1);
			}
			break;
		case 3:
			system("cls");
			printf("Digite o valor equivalente ao filme que deseja remover:\n");
			for(i = 0; i <= (quant_f); i++){
				printf("%d. %s\n", i+1, filme[i]);
			}
			scanf("%d", &resp1);
			for(i = 0; i <= (quant_f); i++){
				if( (resp1-1) == i ){
					filme[i] = "";
					c++;
				}
			}
			printf("\n");
			for(i = 0; i <= (quant_f); i++){
				printf("%d. %s\n", i+1, filme[i]);
			}
			printf("\nRetornar ao menu anterior ?\n");
			printf("\n1 - Sim\n2 - Não\n");
			scanf("%d", &resp);
			if( resp == 1 ){
				system("cls");
				goto menu;
			}else{
				exit(1);
			}
			break;
		case 4:
			system("cls");
			for(i = 0; i < quant_f; i++){
				if( strlen(filme[i]) == 0 ){
					printf("Digite o nome do filme que deseja inserir na lista: ");
					fflush(stdin);
					v++;
					filme[i] = malloc(40*sizeof(char));
					gets(filme[i]);	
					printf("O filme foi inserido na posição %d.\n", i+1);
					goto final;				
				}
			}
			do{
				printf("Digite o nome do filme que deseja inserir na lista: ");
				fflush(stdin);
				quant_f++;
				filme[quant_f] = malloc(40*sizeof(char));
				gets(filme[quant_f]);
				printf("Deseja parar de inserir?\n");
				printf("1 - Sim\n2 - Não\n");
				scanf("%d", &resp);
			}while(resp != 1);
			final:
			printf("\nRetornar ao menu anterior ?\n");
			printf("\n1 - Sim\n2 - Não\n");
			scanf("%d", &resp);
			if( resp == 1 ){
				system("cls");
				goto menu;
			}else{
				exit(1);
			}
			break;
		case 5:
			exit(1);
			break;
		default:
			exit(1);
			
	}
}



