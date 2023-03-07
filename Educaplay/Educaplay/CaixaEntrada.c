#define _CRT_SECURE_NO_WARNINGS
#include "CaixaEntrada.h"
#include "CadastroUsuario.h"
#include "Menu.h"
#include "conio2.h"
#include "ExcluirCaixaEntrada.h"
#include "MostraMensagemCaixaEntrada.h"
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#define background_color system("color 0f");

void EnviarMensagem(char *a) {
	setlocale(LC_ALL, "Portuguese");
	char pessoa_logada[50];
	int i = 0;
	background_color;
	system("cls");

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));

	while (*a != '\0') {

		pessoa_logada[i] = *a;

		a++;
		i++;



	}

	

	char dest[100], armazenar_nome[50];
	char mensagem[500], ler_umensagem[500], continuar;
	int id = 0, tamanho_mesagem, mensagem_escrita = 0, contador = 0, tam_pessoa_logada = 0, tam_mensagem_que_sera_armazenada = 0;
	FILE* ArqCadastro;
	FILE* ArqCadastro2;

	Usuario u;

Volta:
	system("cls");
	memset(dest, 0x00, sizeof(dest));
	memset(mensagem, 0x00, sizeof(mensagem));
	tam_pessoa_logada = strlen(pessoa_logada);

	setbuf(stdin, NULL);
	printf("Qual o destinatario: ");
	fgets(dest, 100, stdin);
	
	

	if (strcmp(dest,pessoa_logada) == 0) {

		printf("Você não pode enviar mensagem para si mesmo! digite outro usuário...");
		Sleep(250);
		goto Volta;

		
	}

	ArqCadastro = fopen("arq_binario.bin", "rb");
	while (fread(&u, sizeof(Usuario), 1, ArqCadastro)) {
		if (strcmp(dest, u.nome) == 0) {
			if (u.status == 1) {
				printf("Usuário não existe!\n");
				printf("------------------------------------\n\n");
				Sleep(300);

				printf("Gostaria de continuar? (s/n)");
				continuar = getchar();
				if (continuar == 's' || continuar == 'S') {

					goto Volta;

				}
				else {
					Menu(pessoa_logada);
				}
				
			}

		}


	}
	fclose(ArqCadastro);

	


	
		pessoa_logada[tam_pessoa_logada - 1] = '\0:';

	
	
	

	ArqCadastro2 = fopen("arq_binario.bin", "rb");
	while (fread(&u, sizeof(Usuario), 1, ArqCadastro2)) {
		if (strcmp(dest, u.nome) == 0) {
			if (u.status <= 1) {

				mensagem_escrita = strlen(u.mensagem) - 1;
				contador = 0;
				if (mensagem_escrita < 0) {
					mensagem_escrita = 0;
				}
				
				break;
			}
		}
		else {
			contador = 1;
		}


	}

	if (contador == 1) {
		printf("Usuário não existe!\n");
		printf("------------------------------------\n\n");

		printf("\nGostaria de continuar? (s/n)\n");
		continuar = getchar();

		if (continuar == 's' || continuar == 'S') {
			goto Volta;
		}
		else {
			Menu(pessoa_logada);
		}
		
	}
	
	fclose(ArqCadastro2);


	if (mensagem_escrita < 500) {

		printf("\nMensagem que gostaria de enviar: ");
		fgets(mensagem, 500, stdin);

		tamanho_mesagem = strlen(mensagem) - 1;




		ArqCadastro = fopen("arq_binario.bin", "rb+");

		while (fread(&u, sizeof(Usuario), 1, ArqCadastro)) {
			if (u.status != 1) {
				if (strcmp(dest, u.nome) == 0) {
					id = u.id;
					id += 1;




					for (int i = 0; i <= tam_pessoa_logada; i++) {
						if (mensagem_escrita == 0) {

							u.mensagem[i] = pessoa_logada[i];
						}
						else if (mensagem_escrita > 1) {
							u.mensagem[(mensagem_escrita + 1) + i] = pessoa_logada[i];

						}

					}


					strcat(u.mensagem, " -\n");



					for (int i = 0; i <= tamanho_mesagem; i++) {

						if (mensagem_escrita == 0) {

							u.mensagem[mensagem_escrita + (tam_pessoa_logada + 1) + i] = mensagem[i];
						}

						else if (mensagem_escrita > 1) {

							u.mensagem[mensagem_escrita + (tam_pessoa_logada + 2) + i] = mensagem[i];
						}


					}




					tam_mensagem_que_sera_armazenada = strlen(u.mensagem);




					//u.mensagem[(tam_pessoa_logada + 1) + tamanho_mesagem + mensagem_escrita] = '\n';


					if (tam_mensagem_que_sera_armazenada < 500) {
						fseek(ArqCadastro, id * sizeof(Usuario), SEEK_SET);
						fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
						printf("mensagem enviada com sucesso!");
						Sleep(350);
						fclose(ArqCadastro);

					}
					else {
						printf("Caixa de mensagem cheia, limpe a caixa de mensagem");
						getch();
						break;
					}



				}



			}

		}


	}
}




//funcao caixa de entrada
void CaixaEntrada(char *a) {

	//declara as variaveis
	char pessoa_logada[100], ler_umensagem[500];
	char opcao[50];
	int tamanho = 0, int_opcao = 0;
	FILE* ArqCadastro;
	Usuario u;
	int i = 0, tam_umesagem = 0, contar = 0;
	background_color;
	system("cls");

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));
	
	while (*a != '\0') {

		pessoa_logada[i] = *a;

		a++;
		i++;
		

		if (*a == '\0')break;


	}

	
	do {
		//zera variaveis e limpa tela
		system("cls");
		memset(opcao, 0x00, sizeof(opcao));
		tamanho = 0;
		contar = 0;

		//abre o arquivo de texto
		ArqCadastro = fopen("arq_binario.bin", "rb");

		//conta quantos mensagens estao escritas na caixa de entrada
		while (fread(&u, sizeof(Usuario), 1, ArqCadastro)) {
			if (strcmp(pessoa_logada, u.nome) == 0) {
				tam_umesagem = strlen(u.mensagem);

				for (int i = 0; i <= tam_umesagem; i++) {
					ler_umensagem[i] = u.mensagem[i];

					if (ler_umensagem[i] == '\n')contar += 1;
				}

			}


		}
		//contar = (contar / 2);
		//fecha arquivo de texto
		fclose(ArqCadastro);

		

		gotoxy(8, 10);
		printf("\t\t\t\t\t-----------------------------------------------\n");
		printf("\t\t\t\t\t| 1 - Caixa de Entrada  (%d)                   |\n", contar);
		printf("\t\t\t\t\t| 2 - Enviar mensagem                         |\n");
		printf("\t\t\t\t\t| 3 - Excluir mensagem                        |\n");
		printf("\t\t\t\t\t| 4 - Sair                                    |\n");
		printf("\t\t\t\t\t-----------------------------------------------\n");
		printf("\t\t\t\t\t| Opcao:                                      |\n");
		printf("\t\t\t\t\t-----------------------------------------------\n");

		gotoxy(51, 16);

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
			MostraMensagemCaixaEntrada(pessoa_logada);
			break;

		case 2:
			EnviarMensagem(pessoa_logada);
			break;

		case 3:
			ExcluirCaixaEntrada(pessoa_logada);
			break;

		case 4:
			Menu(pessoa_logada);
			break;
		default:
			printf("\n\n\n\t\t\tDigite uma opção válida!! Aperte qualquer tecla para continuar...");
			getch();
			break;
		}

	} while(int_opcao != 4);
	




	
	

}
