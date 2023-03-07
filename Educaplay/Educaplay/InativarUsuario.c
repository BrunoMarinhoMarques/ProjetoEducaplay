#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InativarUsuario.h"
#include "CadastroUsuario.h"
#include "funcoes_ascii.h"
#include <Windows.h>
#include <locale.h>
#define background_color system("color 0f");

void InativarUsuario() {
	setlocale(LC_ALL, "Portuguese");
	background_color;
	system("cls");
	FILE* ArqCadastro;
	Usuario u;
	char retorno, salvar;
	int tam = 0, i = 0, a = 0, cpf_int[11], id = 0, cont = 0;
	char cpf[15];

	//variavel recebe fopen, caso nao exista o arquivo ele cria um com nome de "arq_binario"
	//se ja houver ele adiciona todos os registros no fim do arquivo
	ArqCadastro = fopen("arq_binario.bin", "r+b");

	//Caso nao conseguir abrir o arquivo ele vira com o valor nulo entao ele retorna mensagem
	//Problemas na abertura de arquivo
	if (ArqCadastro == NULL) {

		printf("Problemas na abertura de arquivo!\n");
	}
	else {

		do{

		system("cls");
		setbuf(stdin, NULL);
		printf("Digite o CPF do usuário que gostaria de inativar: ");
		fgets(cpf, 15, stdin);

		//roda dentro do arquivo de texto linha por linha enquanto for
			//verdadeiro
		ArqCadastro = fopen("arq_binario.bin", "r+b");
		while (fread(&u, sizeof(Usuario), 1, ArqCadastro) == 1) {
			if (u.status <= 0) {
				if (u.status == 0) {

					//compara o que foi digitado com o que esta dentro
					//do arquivo de texto, se for igual retorna verdadeiro(0)
					//e imprimi
					if (strcmp(cpf, u.cpf) == 0) {

						printf("Nome: %s\n", u.nome);
						printf("Data de nascimento: %s\n", u.data_nasc);
						printf("Endereço: %s\n", u.endereco);
						printf("Cpf: %s\n", u.cpf);
						printf("Cargo: %s\n", u.cargo);
						printf("Telefone: %s\n", u.telefone);
						printf("------------------------------------\n\n");

						id = u.id;
						id += 1;
						 
						printf("Tem certeza que gostaria de inativar este usuário? (s/n): ");
						salvar = getchar();

						if (salvar == 's' || salvar == 'S') {

							if (strcmp(cpf, u.cpf) == 0) {
								cont = 0;
								u.status = 1;
								memset(u.mensagem, 0x00, sizeof(u.mensagem));
								fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
								fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
								printf("Esta pessoa está inativa!\n\n");
								break;
								Sleep(750);
								fclose(ArqCadastro);

							}
							
						}

					}
				}
				else {

					cont = 1;
				}
			}
			
		}
			

			if (cont == 1) {
				printf("Usuário não existe!\n");
				printf("------------------------------------\n\n");
				cont = 0;
			}

			fclose(ArqCadastro);

			
			printf("Gostaria de continuar? (s/n)");
			a = getchar();
			limpaBuffer();
			//enquanto for digitado 's' ou 'S' ele continua o loop
		}while (a == 's' || a == 'S');


		}
	}


			



		