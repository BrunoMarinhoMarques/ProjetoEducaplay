#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "AtivarUsuario.h"
#include "CadastroUsuario.h"
#include "ImprimirUsuario.h"
#include "InativarUsuario.h"
#include "AcessoCadastro.h"
#include "AlterarDados.h"
#include "VerificaLoginSenha.h"
#include "PesquisaUsuario.h"
#include "UsuariosAtivosInativos.h"
#include "Equipamentos.h"
#include "TelaLogin.h"
#include "CaixaEntrada.h"
#include "conio2.h"
#include "funcoes_ascii.h"
#include "Equipamentos.h"
#include "backup.h"
#include "Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
void Menu(char *a) {
	setlocale(LC_ALL, "Portuguese");
	//declara varivel
	char pessoa_logada[50], ler_umensagem[500], opcao[50];
	int j = 0, tam_umensagem = 0, contar = 0, tamanho = 0, tam_opcao = 0, int_opcao = 0;
	//declarando variavel 
	int i = 0;
	FILE* ArqCadastro;
	Usuario u;


	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));
	
	//pega o parametro digitado na funcao "VerificaTela" e armazena na variavel str1
	while (*a != '\0') {
		
		

		pessoa_logada[j] = *a;

		a++;
		j++;
		


		
		if (*a == '\0')break;
		
		
	
		
		
	}

	


	
	
	
		

		_setcursortype(2);
		


		//cria o menu e pega o que foi digitado pelo usuario
		do {

			//zera valor das variaveis
			tamanho = 0;
			contar = 0;
			opcao[i] = '\0';
			//abre o arquivo
			ArqCadastro = fopen("arq_binario.bin", "rb");

			//conta quantas mensagens estao escritos na caixa de entrada
			while (fread(&u, sizeof(Usuario), 1, ArqCadastro)) {
				if (strcmp(pessoa_logada, u.nome) == 0) {
					tam_umensagem = strlen(u.mensagem);

					//conta quantas vezes acha um '\n' e adiciona  1 a variavel contar
					for (int i = 0; i <= tam_umensagem; i++) {
						ler_umensagem[i] = u.mensagem[i];

						if (ler_umensagem[i] == '\n')contar += 1;
					}

				}


			}

			
			//fecha arquivo
			fclose(ArqCadastro);
			

			
			//apaga o que estiver escrito na tela
			system("cls");
			
			//imprimi o usuario na tela
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
			printf("\n   Usuário: %s\n", pessoa_logada);
			printf("-----------------------------------------------------------------------------------------------------------------------\n");

			//imprimi menu na tela
			gotoxy(5, 6);
			printf("\t\t\t\t\t________________________________________\n");
			printf("\t\t\t\t\t| 1 - Cadastrar                        |\n");
			printf("\t\t\t\t\t| 2 - Buscar                           |\n");
			printf("\t\t\t\t\t| 3 - Imprimir relatório               |\n");

			printf("\t\t\t\t\t| 4 - Inativar                         |\n");

			printf("\t\t\t\t\t| 5 - Ativar                           |\n");

			printf("\t\t\t\t\t| 6 - Alterar dados                    |\n");

			printf("\t\t\t\t\t| 7 - Ativos | Inativos                |\n");

			printf("\t\t\t\t\t| 8 - Caixa de mensagem (%d)            |\n", contar);
			printf("\t\t\t\t\t| 9 - Backup                           |\n");
			printf("\t\t\t\t\t| 10 - Equipamentos                    |\n");
			printf("\t\t\t\t\t| 11 - Deslogar                        |\n");
			printf("\t\t\t\t\t| 12 - Sair                            |\n");
			printf("\t\t\t\t\t----------------------------------------\n");
			printf("\t\t\t\t\t| Opcao:                               |\n");

			
			printf("\t\t\t\t\t----------------------------------------\n");

			
			//chama a funcao Data e escreve na tela
			Data();

			//digitar a opcao escolhida
			gotoxy(52, 20);
			//scanf_s("%d", &opcao);

			
			

			
			
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
				//se digitado 1 chama a funcao cadastro
			case 1:
				gotoxy(5, 7);
				textbackground(1);
				printf("\t\t\t\t\t| 1 - Cadastrar                        |\n");
				Sleep(250);
				AcessoCadastro(pessoa_logada);
				break;
				//se digitado 2 chama a funcao busca
			case 2:
				gotoxy(5, 8);
				textbackground(1);
				printf("\t\t\t\t\t| 2 - Buscar                          |\n");
				Sleep(250);
				PesquisaUsuario();
				break;
				//se digitado 3 chama a funcao sair
			case 3:
				gotoxy(5, 9);
				textbackground(1);
				printf("\t\t\t\t\t| 3 - Imprimir relatório               |\n");
				Sleep(250);
				ImprimirUsuario();
				break;
			case 4:
				gotoxy(5, 10);
				textbackground(1);
				printf("\t\t\t\t\t| 4 - Inativar                         |\n");
				Sleep(250);
				AcessoInativarUsuario(pessoa_logada);
				break;
			case 5:
				gotoxy(5, 11);
				textbackground(1);
				printf("\t\t\t\t\t| 5 - Ativar                           |\n");
				Sleep(250);
				AcessoUsuarioAtivar(pessoa_logada);
				break;

			case 6:
				gotoxy(5, 12);
				textbackground(1);
				printf("\t\t\t\t\t| 6 - Alterar dados                    |\n");
				Sleep(250);
				AcessoAlterarDados(pessoa_logada);
				break;

			case 7:
				gotoxy(5, 13);
				textbackground(1);
				printf("\t\t\t\t\t| 7 - Ativos | Inativos                  |\n");
				Sleep(250);
				UsuarioAtiveInativ();
				break;

			case 8:
				gotoxy(5, 14);
				textbackground(1);
				printf("\t\t\t\t\t| 8 - Caixa de mensagem                          |\n");
				Sleep(250);
				CaixaEntrada(pessoa_logada);
				break;

			case 9:
				gotoxy(5, 15);
				textbackground(1);
				printf("\t\t\t\t\t| 9 - Backup                           |\n");
				Sleep(250);
				Backup();
				break;



			case 10:
				gotoxy(5, 16);
				textbackground(1);
				printf("\t\t\t\t\t| 10 - Equipamentos                             |\n");
				Sleep(250);
				Equipamento();
				system("cls");
				break;

			case 11:
				gotoxy(5, 17);
				textbackground(1);
				printf("\t\t\t\t\t| 11 - Deslogar                        |\n");
				Sleep(250);
				TelaLogin();
				system("cls");
				break;

			case 12:
				gotoxy(5, 18);
				textbackground(1);
				printf("\t\t\t\t\t| 12 - Sair                             |\n");
				Sleep(250);
				system("cls");
				exit(1);
				break;

			default:
				printf("\n\n\n\t\t\tDigite uma opção válida!! Aperte qualquer tecla para continuar...\n");
				
				getch();
				break;
			}
			//enquanto o que for digitado for diferente de 6 continua executando
		} while (opcao != 12);

		
		

	}
