#define _CRT_SECURE_NO_WARNINGS
#include "ImprimirInativoeAtivo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CadastroUsuario.h"
#define background_color system("color 0f");

void ImprimirAtiveInativ() {
	background_color;
	FILE* ArqCadastro;
	Usuario u;

	system("cls");
	ArqCadastro = fopen("arq_binario.bin", "rb");
	//enquanto retornar 1 nao chegou no fim do arquivo e ele continuara imprimindo
	while (fread(&u, sizeof(Usuario), 1, ArqCadastro) == 1) {
		if (u.status >= 0) {


			printf("Status %d\n", u.status);
			printf("Nome: %s\n", u.nome);
			printf("Data de nascimento: %s\n", u.data_nasc);
			printf("Endereco: %s\n", u.endereco);
			printf("Cpf: %s\n", u.cpf);
			printf("Telefone: %s\n", u.telefone);
			printf("Cargo: %s\n", u.cargo);
			printf("------------------------------------\n\n");
			
		}
	}


	fclose(ArqCadastro);

	printf("Pressione qualquer tecla para continuar...");
	getch();
}