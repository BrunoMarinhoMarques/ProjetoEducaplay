#define _CRT_SECURE_NO_WARNINGS
#include "CaixaEntrada.h"
#include "CadastroUsuario.h"
#include "Menu.h"
#include "conio2.h"
#include "ExcluirCaixaEntrada.h"
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#define background_color system("color 0f");

void MostraMensagemCaixaEntrada(char *a) {
	setlocale(LC_ALL, "Portuguese");
	FILE *ArqCadastro;
	Usuario u;
	char pessoa_logada[50], ler_umensagem[500];
	int i = 0, tam_umensagem = 0, contar = 0;
	background_color;
	system("cls");

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));

	while (*a != '\0') {

		pessoa_logada[i] = *a;

		a++;
		i++;


		if (*a == '\0')break;


	}

	

	ArqCadastro = fopen("arq_binario.bin", "rb");

	//Caso nao conseguir abrir o arquivo ele vira com o valor nulo entao ele retorna mensagem
	//Problemas na abertura de arquivo
	//system("cls");
	if (ArqCadastro == NULL) {

		printf("Problemas na abertura de arquivo! \n");
	}
	else {
		//enquanto retornar 1 nao chegou no fim do arquivo e ele continuara imprimindo
		while (fread(&u, sizeof(Usuario), 1, ArqCadastro) == 1) {
			if (u.status == 0) {
				if (strcmp(pessoa_logada, u.nome) == 0) {
					
				
					gotoxy(35, 3);
					printf("Caixa de Entrada\n\n");

					
					printf("\n\n%s\n\n", u.mensagem);
					printf("----------------------------------------------------------------------\n\n");
					break;

				}
			
			}
		}

	}
	fclose(ArqCadastro);
	getch();
	
}