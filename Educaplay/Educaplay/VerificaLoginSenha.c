#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "VerificaLoginSenha.h"
#include "CadastroUsuario.h"
#include "Menu.h"
#include "conio2.h"
#include "funcoes_ascii.h"
#define background_color system("color 0f");



void VerificaLoginSenha() {
 	background_color;
	FILE* ArqUsuario;
	
	
	//se errar login ou senha ele retorna daqui	
Inicio:

	system("cls");
	
	
	//desenha logo "Educaplay"
	logo();
	//abre o "arq_binario.bin" e tem a permissao apenas de leitura
	ArqUsuario = fopen("arq_binario.bin", "rb");


	//chama struct do tipo Usuario
	Usuario u;

	char login_teste[50], senha_teste[50], armazena_login[50];

	//zera as variaveis
	memset(u.senha, 0x00, sizeof(u.senha));
	memset(u.login, 0x00, sizeof(u.login));
	memset(u.telefone, 0x00, sizeof(u.telefone));
	memset(login_teste, 0x00, sizeof(login_teste));
	memset(senha_teste, 0x00, sizeof(senha_teste));
	memset(u.mensagem, 0x00, sizeof(u.mensagem));



	//declaracao de variaveis
	int tamanho = 0, i = 0, login = 0, senha = 0, trocar_senha = 0, tamanho_login = 0;

	
	
	//imprime na tela "Login"
	//e posiciona
	gotoxy(18, 15);
	printf("Login: ");

	//imprime na tela "Senha"
	//e posiciona
	gotoxy(18, 20);
	printf("Senha: ");

	setbuf(stdin, NULL);
	//posiciona o campo de leitura de dados "fgets"
	gotoxy(26, 15);
	fgets(login_teste, 50, stdin);

	
	
	/*tamanho_login = strlen(login_teste);

	for (int n = 0; n <= tamanho_login - 1; n++) {
		armazena_login[n] = login_teste[n];
	}*/

	
	
	//posiciona a mascara de senha
	 gotoxy(26, 20);
	
	//aplica a mascara de senha
	do {


		senha_teste[tamanho] = getch();
		if (senha_teste[tamanho] == 8 && tamanho > 0) {
			printf("\b \b");
			senha_teste[tamanho] = '0';
			tamanho--;
		}
		else if (senha_teste[tamanho] == 13) {
			senha_teste[tamanho] = '\n';
			break;
		}
		else if (senha_teste[tamanho] != 8) {
			printf("%c", '*');
			tamanho++;

		}



	} while (tamanho < 150);


	
	//procura o login e senha dentro do arquivo ate que sejam iguais
	//quando achar, atribui 1 a variavel login e 1 a variavel senha
	//faz um for copiando para variavel armazena_login o nome do usuario
	while (fread(&u, sizeof(Usuario), 1, ArqUsuario) == 1) {


		if (strcmp(login_teste, u.login) == 0) {
			if (strcmp(senha_teste, u.senha) == 0) {
			 if(u.status==0){
				login = 1;
				senha = 1;
				tamanho_login = strlen(u.nome);
				for (int i = 0; i <= tamanho_login; i++) {
					armazena_login[i] = u.nome[i];
				}
				break;
			  }
			}
		}
		

		if (strcmp(login_teste, u.login) == 0) {
			if (strcmp(senha_teste, u.senha) == 0) {
				if (u.status <= 0) {
					login = 1;
					senha = 1;
					tamanho_login = strlen(u.nome);
					for (int i = 0; i <= tamanho_login; i++) {
						armazena_login[i] = u.nome[i];
					}
					break;
				}
			}
		}

		



	}


	


	

	//se login e senha estiverem corretos ele adiciona 1 a cada variavel
	//chama a variavel "Carregando" que desenha uma barra de "carregar" na tela
	//logo apos chama funcao "Menu"
	if (login == 1 && senha == 1) {
		system("cls");
		Carregando();
		Menu(armazena_login);
		


	}
	//apresenta mensagem "Login ou senha invalido, adiciona 1 a variavel trocar_senha
	//e volta para o inicio do programa para o usuario digitar login e senha
	//novamente
	else {

		
		printf("\n\t\t\t\t\t\tLogin ou senha invalido");
		trocar_senha += 1;
		Sleep(1000);
		fclose(ArqUsuario);
		goto Inicio;
	}
}
	
	
	
//SenhaIncorreta:
//	login = 0; senha = 0;
////	while (fread(&u, sizeof(Usuario), 1, ArqCadastro) == 1) {
//
//
//		


	
//}