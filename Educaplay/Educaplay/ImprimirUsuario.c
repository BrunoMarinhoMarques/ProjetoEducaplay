#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "CadastroUsuario.h"
#define background_color system("color 0f");

void ImprimirUsuario(){
	setlocale(LC_ALL, "Portuguese");
	background_color;
	Usuario u;
	FILE* ArqCadastro;
	int tamanho = 0, horas_trabalhadas_int = 0, valor_hora_int, salario_mensal = 0;
	system("cls");
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
			
			printf("Nome: %s\n", u.nome);
			printf("Data de nascimento: %s\n", u.data_nasc);
			printf("Endereco: %s\n", u.endereco);
			printf("Cpf: %s\n", u.cpf);
			printf("Email: %s\n", u.email);
			printf("Cargo: %s\n", u.cargo);
			printf("Valor Hora: %s\n", u.valor_hora);
			printf("Horas trabalhadas (semanalmente): %s\n", u.horas_trabalhadas);
			horas_trabalhadas_int = atoi(u.horas_trabalhadas);
			valor_hora_int = atoi(u.valor_hora);

			salario_mensal = (valor_hora_int * horas_trabalhadas_int) * 4;

			printf("Salario mensal: %d\n", salario_mensal);
			printf("\nTelefone: %s\n", u.telefone);
			printf("------------------------------------\n\n");
			}
		}

	}
	fclose(ArqCadastro);
	printf("Pressione qualquer tecla para continuar...");
	getch();




}


