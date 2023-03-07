#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <stdio.h>
#include "conio2.h"
#include "funcoes_ascii.h"
#include "CadastroEquipamento.h"
#include "Data.h"
#define background_color system("color 0f");


void CadastroEquipamento() {
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	background_color;
	FILE* ArqEquipamento;
	FILE* VerUltimoID;
	Equip equip;
	int contagem = 0, tamanho = 0, j = 0, armazena_valor[50], tamanho_valor = 0;
	char c, continuar, valor[50];
	memset(valor, 0x00, sizeof(valor));
	memset(armazena_valor, 0x00, sizeof(armazena_valor));
	setlocale(LC_ALL, "Portuguese");

	ArqEquipamento = fopen("arq_binario_equip.bin", "ab+");

	if (ArqEquipamento == NULL) {

		printf("ERROR AO ABRIR O ARQUIVO");
	}

	else {
	
		do {
			ArqEquipamento = fopen("arq_binario_equip.bin", "ab+");
			voltainicio:
			system("cls");
			///*VerUltimoID = fopen("arq_binario.bin", "rb");
			//contagem = 0;
			//while (fread(&equip, sizeof(Equip), 1, VerUltimoID) == 1) {


			//	contagem++;


			//}
			//fclose(VerUltimoID);*/

			setbuf(stdin, NULL);
			printf("Nome do Equipamento: ");
			fgets(equip.nome, 50, stdin);

			setbuf(stdin, NULL);
			printf("Especificaçoes (caso houver): ");
			fgets(equip.especificacoes, 200, stdin);

			setbuf(stdin, NULL);
			printf("Valor: ");
			fgets(equip.valor, 50, stdin);
			
		
			

			
			printf("\nCadastrar ?(s/n)");
			c = getchar();

			if (c == 's' || c == 'S') {

				limpaBuffer();
				fwrite(&equip, sizeof(Equip), 1, ArqEquipamento);
				printf("\ncadastrado com sucesso!\n");
				fclose(ArqEquipamento);
				

			}

		
			
			


			system("cls");
			
			printf("Gostaria de continuar? (s/n)");
			continuar = getchar();

			

		} while (continuar == 's' || continuar == 'S');
		


	}


	fclose(ArqEquipamento);

	

}