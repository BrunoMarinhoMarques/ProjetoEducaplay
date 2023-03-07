#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AlterarDados.h"
#include "CadastroUsuario.h"
#include "Menu.h"
#include <Windows.h>
#include <locale.h>
#define background_color system("color 0f");
//#define config_tam_tela system("MODE con cols=140 lines=35");
void AbrirArquivo(ArqCadastro) {
	ArqCadastro = fopen("arq_binario.bin", "rb+");
}

void AlterarDados(char *a) {
	setlocale(LC_ALL, "Portuguese");
	background_color;
	//limpa a tela
	system("cls");
	
	//define tamanho da tela
	//config_tam_tela;

	//declara variaveis
	FILE* ArqCadastro;
	Usuario u;
	int id = 0, contador = 0, tamanho, int_opcao, i = 0, j = 0;
	char cpf[15], continuar;
	char opcao[50], pessoa_logada[50];

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));

	//pega o parametro digitado na funcao "VerificaTela" e armazena na variavel str1
	while (*a != '\0') {



		pessoa_logada[j] = *a;

		a++;
		j++;




		if (*a == '\0')break;





	}

	ArqCadastro = fopen("arq_binario.bin", "rb+");

	if (ArqCadastro == NULL) {

		printf("Problemas na abertura de arquivo!\n");

	}

	else {
	Voltar:
		tamanho = 0;
		opcao[i] = '\0';
		//limpa a tela e abre arquivo de texto novamente
		system("cls");
		ArqCadastro = fopen("arq_binario.bin", "rb+");

		//pega o que foi digitado pelo usuario
		setbuf(stdin, NULL);
		printf("Digite o CPF do usuário que gostaria de alterar: ");
		fgets(cpf, 15, stdin);


		while (fread(&u, sizeof(Usuario), 1, ArqCadastro) == 1) {
			if (strcmp(cpf, u.cpf) == 0) {
				contador = 0;
				printf("Nome: %s\n", u.nome);
				printf("Endereco: %s\n", u.endereco);
				printf("Cpf: %s\n", u.cpf);
				printf("Telefone: %s\n", u.telefone);
				printf("------------------------------------\n\n");
				id = u.id;
				id += 1;
			
			do{
				int_opcao = 0;
				tamanho = 0;
				opcao[i] = '\0';
				printf("\nDigite o dado que deseja atualizar: \n");
				printf("\n---------------------------------------------------------------------------------------");
				printf("\n1 - Nome | 2 - Endereco | 3 - CPF | 4 - Telefone | 5 - Login | 6 - Senha | 7 - Sair ");
				printf("\n---------------------------------------------------------------------------------------\n");


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
					//se digitado 1 ira imprimir "Nome" na tela e ler o que foi digitado pelo usuario
					//pegara a posicao a partir do ID digitado e atualizara a linha nome no arquivo binario
				case 1:
					AbrirArquivo();
					setbuf(stdin, NULL);
					printf("\nNome: ");
					fgets(u.nome, 100, stdin);
					fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
					fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
					Beep(780, 350);
					printf("Os dados foram alterados!");
					fclose(ArqCadastro);
					break;

					//se digitado 2 ira imprimir "Endereco" na tela e ler o que foi digitado pelo usuario
					//pegara a posicao a partir do ID digitado e atualizara a linha endereco no arquivo binario
				case 2:
					AbrirArquivo();
					setbuf(stdin, NULL);
					printf("\nEndereco: ");
					fgets(u.endereco, 100, stdin);
					fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
					fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
					Beep(780, 350);
					printf("Os dados foram alterados!");
					fclose(ArqCadastro);
					break;

					//se digitado 3 ira imprimir "CPF" na tela e ler o que foi digitado pelo usuario
					//pegara a posicao a partir do ID digitado e atualizara a linha CPF no arquivo binario
				case 3:
					AbrirArquivo();
					setbuf(stdin, NULL);
					printf("\nCPF: ");
					fgets(u.cpf, 15, stdin);
					fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
					fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
					Beep(780, 350);
					printf("Os dados foram alterados!");
					fclose(ArqCadastro);
					break;

					//se digitado 1 ira imprimir "Nome" na tela e ler o que foi digitado pelo usuario
					//pegara a posicao a partir do ID digitado e atualizara a linha nome no arquivo binario
				case 4:
					AbrirArquivo();
					setbuf(stdin, NULL);
					printf("\nTelefone: ");
					fgets(u.telefone, 14, stdin);
					fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
					fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
					Beep(780, 350);
					printf("\nOs dados foram alterados!\n");
					fclose(ArqCadastro);
					break;
				case 5:
					AbrirArquivo();
					setbuf(stdin, NULL);
					printf("\nLogin: ");
					fgets(u.login, 14, stdin);
					fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
					fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
					Beep(780, 350);
					printf("\nOs dados foram alterados!\n");
					fclose(ArqCadastro);
					break;

				case 6:
					AbrirArquivo();
					setbuf(stdin, NULL);
					printf("\nSenha: ");
					fgets(u.senha, 14, stdin);
					fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
					fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
					Beep(780, 350);
					printf("\nOs dados foram alterados!\n");
					fclose(ArqCadastro);
					break;

				case 7:
					
					Menu(pessoa_logada);
					break;



				default:
					printf("\nDigite uma opção válida!!\n");
					break;
				}

			} while (int_opcao != 7);
				

				

				

				

			/*	fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
				fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
				printf("Os dados foram alterados!");
				fclose(ArqCadastro);*/



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

		printf("Gostaria de continuar? (s/n)");
		continuar = getchar();

		if (continuar == 's' || continuar == 'S') {

			goto Voltar;
			fclose(ArqCadastro);
		}
		


	}

}