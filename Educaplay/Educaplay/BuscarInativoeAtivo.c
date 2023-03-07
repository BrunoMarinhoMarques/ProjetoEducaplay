#define _CRT_SECURE_NO_WARNINGS
#include "BuscarInativoeAtivo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CadastroUsuario.h"
#define background_color system("color 0f");

void BuscarAtiveInativ() {
	background_color;

	//declara variaveis
	FILE* ArqCadastro;
	Usuario u;
	char nome[50], continuar;
	int contador = 0;

	Voltar:
	//abre novamente o arquivo "arq_binario.bin"
	ArqCadastro = fopen("arq_binario.bin", "rb");

	//limpa informacoes da tela
	system("cls");


			//limpa buffer teclado
			setbuf(stdin, NULL);
			printf("Digite nome: ");
			fgets(nome, 50, stdin);

			//roda dentro do arquivo de texto linha por linha enquanto for
			//verdadeiro
			while (fread(&u, sizeof(Usuario), 1, ArqCadastro) == 1) {

				//compara o que foi digitado com o que esta dentro
				//do arquivo de texto, se for igual retorna verdadeiro(0)
				//e imprimi

			//se status de usuario for ativo e inativo ele faz a busca
				if (u.status >= 0) {
					//se o cpf digitado foi igual ao cpf que esta em arquivo de texto
					if (strcmp(nome, u.nome) == 0) {

						printf("Status: %d\n", u.status);
						printf("Nome: %s\n", u.nome);
						printf("Endereco: %s\n", u.endereco);
						printf("Cpf: %s\n", u.cpf);
						printf("Telefone: %s\n", u.telefone);
						printf("------------------------------------\n\n");
						contador = 0;

					}
					//se ele nao encontrar variavel "contador" recebe o valor 1

				}
				else {
					contador = 1;
				}
			}

			if (contador == 1) {
				printf("Usuário não existe!\n");
				printf("------------------------------------\n\n");
				contador = 0;
			}
			fclose(ArqCadastro);
			printf("Gostaria de continuar? (s/n)");
			continuar = getchar();

			if (continuar == 's' || continuar == 'S') {
				goto Voltar;
			}
}