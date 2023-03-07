#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "UsuariosAtivosInativos.h"
#include "CadastroUsuario.h"
#include "ImprimirInativoeAtivo.h"
#include "BuscarInativoeAtivo.h"
#define background_color system("color 0f");

void UsuarioAtiveInativ() {
	background_color;
	Usuario u;
	char cpf[15], opcao[50];
	int contador = 0, tamanho = 0, int_opcao = 0;

	system("cls");

	do {
		system("cls");
		tamanho = 0;
		opcao[tamanho] = '\0';
		printf("\n---------------------------------------------------------------");
		printf("\n| 1 - Imprimir todos usuários | 2 - Buscar por nome | 3 - Sair |");
		printf("\n---------------------------------------------------------------\n");

		printf("C:\>");
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
			ImprimirAtiveInativ();

			break;


		case 2:
			BuscarAtiveInativ();
			break;
		case 3:
			printf("Sair");
			break;

		default:
			printf("\n\n\n\t\t\tDigite uma opção válida!! Aperte qualquer tecla para continuar...");
			getch();
			break;

		}
	} while (int_opcao != 3);

}