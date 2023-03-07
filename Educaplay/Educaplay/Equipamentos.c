#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include "CadastroEquipamento.h"
#include "ImprimirEquipamento.h"
#include "conio2.h"
#include "Data.h"
#define background_color system("color 0f");

void Equipamento() {
	background_color;
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	FILE* ArqEquipamento;
	char opcao[50];
	int tamanho = 0, int_opcao = 0;

	ArqEquipamento = fopen("arq_binario_equip.bin", "ab+");

	if (ArqEquipamento == NULL) {

		printf("Error ao abrir arquivo");

	}
	else {

		do {
			tamanho = 0;
			int_opcao = 0;
			opcao[tamanho] = '\0';
			system("cls");
			gotoxy(5, 8);
			printf("\t\t\t\t\t________________________________________\n");
			printf("\t\t\t\t\t| 1 - Cadastrar                        |\n");
			printf("\t\t\t\t\t| 2 - Imprimir relatório               |\n");
			printf("\t\t\t\t\t| 3 - Sair                             |\n");
			printf("\t\t\t\t\t----------------------------------------\n");
			printf("\t\t\t\t\t| Opção:                               |\n");
			gotoxy(1, 55);
			printf("\t\t\t\t\t----------------------------------------\n");

			//chama a funcao Data e escreve na tela
			Data();

			gotoxy(53, 13);
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
				CadastroEquipamento();
				break;

			case 2:
				ImprimirEquipamento();
				break;

			case 3:
				break;
			default:
				printf("Digite uma opção válida por favor! Pressione qualquer tecla para continuar...");
				getch();
				break;
			}






		} while (int_opcao != 3);




	}





	fclose(ArqEquipamento);
}