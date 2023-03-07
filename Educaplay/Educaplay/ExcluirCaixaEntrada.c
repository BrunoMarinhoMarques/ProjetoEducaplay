#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "VerificaLoginSenha.h"
#include "CadastroUsuario.h"
#include "CaixaEntrada.h"
#include "Menu.h"
#include "conio2.h"
#include "funcoes_ascii.h"
#define background_color system("color 0f");

void ExcluirCaixaEntrada(char* a) {
	FILE* ArqCadastro;
	Usuario u;
	char pessoa_logada[50], opcao[50];
	int i = 0, id = 0, tamanho = 0, int_opcao = 0;
	background_color;
	system("cls");

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));

	while (*a != '\0') {

		pessoa_logada[i] = *a;

		a++;
		i++;





	}






	gotoxy(8, 5);
	printf("\t\t\t\t\tGostaria de excluir a caixa de entrada?");

	gotoxy(8, 10);
	printf("\t\t\t\t\t-----------------------------------\n");
	printf("\t\t\t\t\t| 1 - Sim                         |\n");
	printf("\t\t\t\t\t| 2 - Nao                         |\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	printf("\t\t\t\t\t| Opcao:                          |\n");
	printf("\t\t\t\t\t-----------------------------------\n");

	do{
		int_opcao = 0;
		tamanho = 0;
		opcao[tamanho] = '\0';
	
    //digitar a opcao escolhida
	gotoxy(52, 14);

	while ((opcao[tamanho] = getch()) != '\r') {
		if (opcao[tamanho] >= '0' && opcao[tamanho] <= '9') {
			printf("%c", opcao[tamanho]);
			tamanho++;

		}
		else if (opcao[tamanho] == 8 && tamanho > 0) {
			printf("\b \b");
			opcao[tamanho] = '0';
			tamanho--;
		}

	}





	int_opcao = atoi(opcao);

	switch (int_opcao)
	{
			case 1:
				ArqCadastro = fopen("arq_binario.bin", "rb+");

				while (fread(&u, sizeof(Usuario), 1, ArqCadastro)) {
					if (strcmp(pessoa_logada, u.nome) == 0) {
						id = u.id;
						id += 1;

						memset(u.mensagem, 0x00, sizeof(u.mensagem));
						fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
						fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
						fclose(ArqCadastro);
						printf("\n\n\t\t\t\t\tMensagem excluida com sucesso!\n\n");
						Sleep(550);
						CaixaEntrada(pessoa_logada);
						break;


					}



				}
				break;

			case 2:
				CaixaEntrada(pessoa_logada);
			default:
				printf("Escolha uma opção válida!!");
				break;

			}

	}while(int_opcao != 2);
	
}