#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "PesquisaUsuario.h"
#include "CadastroUsuario.h"
#define background_color system("color 0f");

void PesquisaUsuario() {
	background_color;
	FILE* ArqUsuario;
	Usuario u;
	int contador=0;
	char cpf[50], a;


	system("cls");

	//abre o arquivo "arq_binario.bin"
	ArqUsuario = fopen("arq_binario.bin", "rb");

	//se for nulo ele escreve a mensagem "Problemas na abertura do arquivo
	if (ArqUsuario == NULL) {

		printf("Problemas na abertura do arquivo!!");

	}
	else {

		do {

			//abre novamente o arquivo "arq_binario.bin"
			ArqUsuario = fopen("arq_binario.bin", "rb");

			//limpa informacoes da tela
			system("cls");


			//limpa buffer teclado
			setbuf(stdin, NULL);
			printf("Digite cpf sem espaco ou ponto (EX:123456789): ");
			fgets(cpf, 50, stdin);

			//roda dentro do arquivo de texto linha por linha enquanto for
			//verdadeiro
			while (fread(&u, sizeof(Usuario), 1, ArqUsuario) == 1) {

				//compara o que foi digitado com o que esta dentro
				//do arquivo de texto, se for igual retorna verdadeiro(0)
				//e imprimi

			//se status de usuario for ativo(0) ele faz a busca
				if (u.status == 0) {
					//se o cpf digitado foi igual ao cpf que esta em arquivo de texto
					if (strcmp(cpf, u.cpf) == 0) {

						printf("Nome: %s\n", u.nome);
						printf("Endereco: %s\n", u.endereco);
						printf("Cpf: %s\n", u.cpf);
						printf("Telefone: %s\n", u.telefone);
						printf("Cargo: %s\n", u.cargo);
						printf("------------------------------------\n\n");
						contador = 0;
						break;
						
					
					}
					//se ele nao encontrar variavel "contador" recebe o valor 1
					
				}
				else {
					contador = 1;
				}
				
				
				
				
			
			}
			//se contador for igual a 1 
			//retorna mensagem "Usuario Inexistente" e depois zera variavel
			if (contador == 1) {
				printf("Usuário não existe!\n");
				printf("------------------------------------\n\n");
				contador = 0;
			}
			
			
			
			fclose(ArqUsuario);

			printf("Gostaria de continuar? (s/n)");
			a = getchar();

		} while (a == 's' || a == 'S');



	}

}