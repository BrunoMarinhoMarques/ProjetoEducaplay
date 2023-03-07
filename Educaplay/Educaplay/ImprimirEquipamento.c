#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "CadastroEquipamento.h"

void ImprimirEquipamento() {
	system("cls");
	FILE *ArqEquipamento;
	Equip equip;
	int armazena_valores = 0, soma_valores = 0;

	ArqEquipamento = fopen("arq_binario_equip.bin", "rb");

	while (fread(&equip, sizeof(Equip), 1, ArqEquipamento) == 1) {



		printf("Nome : %s\n", equip.nome);
		printf("Especificacoes: %s\n", equip.especificacoes);
		printf("Valor: %s\n", equip.valor);
		printf("--------------------------------------------\n\n");

		armazena_valores = atoi(equip.valor);
		soma_valores += armazena_valores;
		
	}

	printf("Valor total dos equipamentos: %d\n\n", soma_valores);
	printf("-----------------------------------------------\n\n");
	printf("Pressione qualquer tecla para continuar...\n");
	getch();
	
	

	fclose(ArqEquipamento);





}

