#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CadastroUsuario.h"
#include "funcoes_ascii.h"
#include <locale.h>
#include <windows.h>
#include "conio2.h"
#define background_color system("color 0f");
//#define config_tam_tela system("MODE con cols=140 lines=35");


void CadastroUsuario() {
	background_color;
	setlocale(LC_ALL, "Portuguese");
	//config_tam_tela;
	FILE* ArqCadastro;
	FILE* VerUlitimoID;
	FILE* CPFCadastrados;
	FILE* VerificCpf;
	Usuario u, teste;
	char c, cpf[15], salvar;
	int status = 0, id = 0, tam_cpf, contagem = 0, i = 0, tam_nome = 0, tam_end = 0, cpf_existe = 0;
	int  a = 0, b = 0, soma_digito_1 = 0, soma_digito_2 = 0, num_verificador_1 = 10, num_verificador_2 = 11, res_1, res_2, tamanho_data_nasc;
	int tamanho_usuario = sizeof(u) / sizeof(Usuario);
	
	

	//variavel recebe fopen, caso nao exista o arquivo ele cria um com nome de "arq_binario"
	//se ja houver ele adiciona todos os registros no fim do arquivo
	ArqCadastro = fopen("arq_binario.bin", "ab");

	//se o arquivo nao existir ou tiver problemas para abrir retorna mensagem "Problemas ao abrir arquivo"
	if (ArqCadastro == NULL) printf("Problemas ao abrir arquivo");


	//senao ele continua
	else {
		do {
			

			

				VerUlitimoID = fopen("arq_binario.bin", "rb");
				contagem = 0;
				while (fread(&u, sizeof(Usuario), 1, VerUlitimoID) == 1) {


					contagem++;


				}

				

				fclose(VerUlitimoID);

				ArqCadastro = fopen("arq_binario.bin", "ab+");

				Nome:
				memset(u.nome, 0x00, sizeof(u.nome));
				memset(u.endereco, 0x00, sizeof(u.endereco));
				memset(u.cpf, 0x00, sizeof(u.cpf));
				memset(u.cpf_int, 0x00, sizeof(u.cpf_int));
				memset(u.login, 0x00, sizeof(u.login));
				memset(u.senha, 0x00, sizeof(u.senha));
				memset(u.telefone, 0x00, sizeof(u.telefone));
				memset(cpf, 0x00, sizeof(cpf));
				memset(u.mensagem, 0x00, sizeof(u.mensagem));
			
				system("cls");
				//zera buffer da variavel
				setbuf(stdin, NULL);
				//imprime mensagem "Digite seu nome" e armazena

				
				
				printf("Digite o nome: ");
				fgets(u.nome, 99, stdin);

				tam_nome = strlen(u.nome) - 1;

				if (tam_nome <= 0) {
					printf("Por favor digite algo");
					Sleep(250);
					goto Nome;
				}

			
				data_nasc:
				setbuf(stdin, NULL);
				printf("Digite a data de nascimento (Ex: 1/2/1234) : ");
				fgets(u.data_nasc, 9, stdin);
				


				u.id = (contagem + 1) - 2;
				u.status = status;

				
				End:
				//zera buffer da variavel
				setbuf(stdin, NULL);
				//imprime mensagem "Digite seu endereco" e armazena
				limpaBuffer();
				printf("Digite o endereco: ");
				fgets(u.endereco, 99, stdin);

				tam_end = strlen(u.endereco) - 1;

			    if (tam_end <= 0) {

					printf("Por favor digite algo");
					Sleep(250);
					goto End;

				}
			VoltarCpfCadastrado:
				//zera variaveis
				i = 0, a = 0, b = 0, soma_digito_1 = 0, soma_digito_2 = 0, num_verificador_1 = 10, num_verificador_2 = 11, res_1 = 0, res_2 = 0;
				memset(u.cpf, 0x00, sizeof(u.cpf));

				//zera buffer da variavel
				setbuf(stdin, NULL);

				//imprime mensagem "Digite seu cpf" e armazena
				printf("Digite o cpf sem ponto ou espaço (Ex:123456789): ");
				fgets(u.cpf, 15, stdin);

				//variavel "tam_cpf" armazena o valor da string de "u.cpf"
				tam_cpf = strlen(u.cpf);


				//realiza for que armazena u.cpf na variavel cpf
				for (int r = 0; r <= tam_cpf - 1; r++) {
					cpf[r] = u.cpf[r];
				}

				VerificCpf = fopen("arq_binario.bin", "rb");

				//enquanto houver registros ele continua fazendo a leitura
				while (fread(&teste, sizeof(Usuario), 1, VerificCpf) == 1) {

					//e se o cpf armazenado for igual ao cpf armazenado no arquivo "arq_binario.bin"
					if (strcmp(cpf, teste.cpf) == 0) {

						cpf_existe = 1;
						break;
						
						
					}
				}

				fclose(VerificCpf);

				if (cpf_existe == 1) {
					cpf_existe = 0;
					//entao ele imprime mensagem "Este CPF ja possui cadastro
					printf("\nEste CPF já possui cadastrado!\n\n");
					//e retorna para digitar o cpf novamente
					goto VoltarCpfCadastrado;
					
				}




				///VERIFICAÇAO DE CPF
				//enquanto i for menor que o tamanho de cpf ele continua executando
				while (i < tam_cpf) {
					if (cpf[i] != '.' && cpf[i] != '-') {

						u.cpf_int[a] = cpf[i];
						a++;
					}
					i++;
				}

				a = 0;

				//primeiro digito verificador
				while (a <= 8) {
					soma_digito_1 += (u.cpf_int[a] - 48) * (num_verificador_1 - a);
					a++;
				}
				res_1 = soma_digito_1 % 11;
				res_1 = 11 - res_1;
				if (res_1 == 10) {
					res_1 = 0;
				}

				a = 0;

				//segundo digito verificador
				while (a < 10)
				{
					soma_digito_2 += (u.cpf_int[a] - 48) * (num_verificador_2 - a);
					a++;
				}
				res_2 = soma_digito_2 % 11;
				res_2 = 11 - res_2;
				if (res_2 == 10) {
					res_2 = 0;
				}
				//ele pega o valor de res_1 e soma + 48 para estar com a mesma numeracao da tabela ASCIIe compara com o valor de u.cpf_int[9] (posicao do primeiro numero verificador) que esta armazenado com o valor da tabela ASCII
				//ele pega o valor de res_2 e soma + 48 para estar com a mesma numeracao da tabela ASCIIe compara com o valor de u.cpf_int[11](posicao do segundo numero verificador)que esta armazenado com o valor da tabela ASCII
				//caso seja igual ele retorna mensagem "CPF VALIDO"
				if ((res_1 + 48) == u.cpf_int[9] && (res_2 + 48) == u.cpf_int[10]) {

					printf("cpf válido!!\n");
				}

				//senao retorna "CPF INVALIDO"
				else {
					printf("cpf inválido!!\n");


				}


				//zera buffer da variavel
				setbuf(stdin, NULL);
				//imprime mensagem "Digite seu telefone" e armazena
				
				printf("Digite o telefone: ");
				fgets(u.telefone, 14, stdin);


				//zera buffer da variavel
				setbuf(stdin, NULL);
				//imprime mensagem "Digite seu login" e armazena
				
				printf("Digite o login: ");
				fgets(u.login, 50, stdin);

				//zera buffer da variavel
				setbuf(stdin, NULL);
				//imprime mensagem "Digite sua senha" e armazena
				
				printf("Digite a senha: ");
				fgets(u.senha, 50, stdin);

				//zera buffer da variavel
				setbuf(stdin, NULL);
				//imprime mensagem "Digite sua senha" e armazena
				printf("Digite o cargo: ");
				fgets(u.cargo, 30, stdin);


				setbuf(stdin, NULL);
				printf("Digite o valor/hora: ");
				fgets(u.valor_hora, 10, stdin);

				setbuf(stdin, NULL);
				printf("Digite a quantidade de horas trabalhadas por semana: ");
				fgets(u.horas_trabalhadas, 6, stdin);


				//zera buffer da variavel
				setbuf(stdin, NULL);
				//imprime mensagem "Digite sua senha" e armazena
				
				printf("Digite o email: ");
				fgets(u.email, 30, stdin);

			
				printf("Gostaria de salvar? (s/n)");
				salvar = getchar();

				//se digitar 's' ou 'S'
 				if (salvar == 's' || salvar == 'S') {

					Beep(780, 350);
					fwrite(&u, sizeof(Usuario), 1, ArqCadastro);
					system("cls");
					printf("\n\nCadastrado com sucesso!\n\n");
					
				}
				
				printf("Deseja continuar (s/n)?");
				limpaBuffer();
				c = getchar();

				
				fclose(ArqCadastro);
			
		}while (c == 's' || c=='S');
		
	}

	

	
	
	
}