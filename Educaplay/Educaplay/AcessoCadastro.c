#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "CadastroUsuario.h"
#include "conio2.h"
#include "funcoes_ascii.h"
#include "AlterarDados.h"
#include "InativarUsuario.h"
#include "AtivarUsuario.h"
#include "Menu.h"
#include "UsuariosAtivosInativos.h"
#define background_color system("color 0f");
//#define config_tam_tela system("mode con:cols=65 lines=25");





void AcessoCadastro(char *a) {
	background_color;
	//dimensao da tela
	//config_tam_tela;

	//declara variaveis
	FILE* ArqUsuario;
	Usuario u;
	int voltarMenu = 0, j = 0, chancesErrar = 3;
	char pessoa_logada[50];

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));


	//realiza um loop enquanto o ponteiro de a for verdadeiro
	while (*a != '\0') {



		pessoa_logada[j] = *a;

		a++;
		j++;




		if (*a == '\0')break;





	}

	

	
	
Inicio:
	system("cls");

	
	asciiCadFechado();
	
	//abre o "arq_binario.bin" e tem a permissao apenas de leitura
	ArqUsuario = fopen("arq_binario.bin", "rb");

	//declara variaveis
	char login_dig[50], senha_dig[50];
	int tamanho = 0, login = 0, senha = 0;

	//zera variaveis
	memset(senha_dig, 0x00, sizeof(senha_dig));
	memset(login_dig, 0x00, sizeof(login_dig));

	//imprime na tela "Login" e arquiva o que for digitado
	//setbuf zera o buffer da variavel
	//gotoxy posiciona na tela
	setbuf(stdin, NULL); 
	gotoxy(10, 10);
	printf("Login: ");

	//imprime na tela "Senha"
	//gotoxy posiciona na tela
	gotoxy(10, 13);
	printf("Senha: ");

	//gotoxy posiciona na tela
	//fgets armazena o que foi digitado
	gotoxy(18, 10);
	fgets(login_dig, 50, stdin);

	
	//posiciona a mascara de senha na tela
	gotoxy(18, 13);

	//aplica a mascara de senha
	do {


		senha_dig[tamanho] = getch();
		if (senha_dig[tamanho] == 8 && tamanho > 0) {
			printf("\b \b");
			senha_dig[tamanho] = '0';
			tamanho--;
		}
		else if (senha_dig[tamanho] == 13) {
			senha_dig[tamanho] = '\n';
			break;
		}
		else if (senha_dig[tamanho] != 8) {
			printf("%c", '*');
			tamanho++;

		}



	} while (tamanho < 50);

	while (fread(&u, sizeof(Usuario), 1, ArqUsuario) == 1) {
		if (u.status < 0) {
			if (strcmp(login_dig, u.login) == 0) {
				if (strcmp(senha_dig, u.senha) == 0) {
					login = 1;
					senha = 1;
					break;
				}
			}
		}


	}

	

	

	//se login e senha estiverem corretos ele adiciona 1 a cada variavel
	//chama a funcao "asciiAberto" que desenha na tela e depois chama a funcao "CadastroUsuario"
	if (login == 1 && senha == 1) {
	
		asciiAberto();
		Sleep(300);
		CadastroUsuario();
		system("cls");


	}
	//apresenta mensagem "Login ou senha invalido, adiciona 1 a variavel trocar_senha
	//e volta para o inicio do programa para o usuario digitar login e senha
	//novamente
	else {

		voltarMenu += 1;
		chancesErrar -= voltarMenu;
		if (voltarMenu == 3) {
			Menu(pessoa_logada);
		}
		else {
			gotoxy(5, 15);
			printf("\n             Login ou senha invalido, se errar mais %d você será direcionado ao menu principal...",chancesErrar);
			chancesErrar = 3;
			getch();
			fclose(ArqUsuario);
			goto Inicio;
		}
		
	}
  }



void AcessoAlterarDados(char *a) {
	  
	  //define cor da tela e cor da fonte
		background_color;
	  //declara variaveis
	  FILE* ArqUsuario;
	  Usuario u;

	  int voltarMenu = 0, j = 0, chancesErrar = 3;
	  char pessoa_logada[50];

	  //zera o lixo de memoria da variavel str1
	  memset(pessoa_logada, 0x00, sizeof(pessoa_logada));


	  //realiza um loop enquanto o ponteiro de a for verdadeiro
	  while (*a != '\0') {



		  pessoa_logada[j] = *a;

		  a++;
		  j++;




		  if (*a == '\0')break;





	  }



  Inicio:
	  system("cls");


	  asciiCadFechado();

	  //abre o "arq_binario.bin" e tem a permissao apenas de leitura
	  ArqUsuario = fopen("arq_binario.bin", "rb");

	  //declara variaveis
	  char login_dig[50], senha_dig[50];
	  int tamanho = 0, login = 0, senha = 0;

	  //zera variaveis
	  memset(senha_dig, 0x00, sizeof(senha_dig));
	  memset(login_dig, 0x00, sizeof(login_dig));

	  //imprime na tela "Login" e arquiva o que for digitado
	  //setbuf zera o buffer da variavel
	  //gotoxy posiciona na tela
	  setbuf(stdin, NULL);
	  gotoxy(10, 10);
	  printf("Login: ");

	  //imprime na tela "Senha"
	  //gotoxy posiciona na tela
	  gotoxy(10, 13);
	  printf("Senha: ");

	  //gotoxy posiciona na tela
	  //fgets armazena o que foi digitado
	  gotoxy(18, 10);
	  fgets(login_dig, 50, stdin);


	  //posiciona a mascara de senha na tela
	  gotoxy(18, 13);

	  //aplica a mascara de senha
	  do {


		  senha_dig[tamanho] = getch();
		  if (senha_dig[tamanho] == 8 && tamanho > 0) {
			  printf("\b \b");
			  senha_dig[tamanho] = '0';
			  tamanho--;
		  }
		  else if (senha_dig[tamanho] == 13) {
			  senha_dig[tamanho] = '\n';
			  break;
		  }
		  else if (senha_dig[tamanho] != 8) {
			  printf("%c", '*');
			  tamanho++;

		  }



	  } while (tamanho < 50);

	  while (fread(&u, sizeof(Usuario), 1, ArqUsuario) == 1) {
		  if (u.status < 0) {
			  if (strcmp(login_dig, u.login) == 0) {
				  if (strcmp(senha_dig, u.senha) == 0) {
					  login = 1;
					  senha = 1;
					  break;
				  }
			  }
		  }


	  }





	  //se login e senha estiverem corretos ele adiciona 1 a cada variavel
	  //e abre menu
	  if (login == 1 && senha == 1) {
		  asciiAberto();
		  AlterarDados(pessoa_logada);
		  system("cls");


	  }
	  //apresenta mensagem "Login ou senha invalido, adiciona 1 a variavel trocar_senha
	  //e volta para o inicio do programa para o usuario digitar login e senha
	  //novamente
	  else {

		  voltarMenu += 1;
		  chancesErrar -= voltarMenu;
		  if (voltarMenu == 3) {
			  Menu(pessoa_logada);
		  }
		  else {
			  gotoxy(5, 15);
			  printf("\n             Login ou senha invalido, se errar mais %d você será direcionado ao menu principal...", chancesErrar);
			  chancesErrar = 3;
			  getch();
			  fclose(ArqUsuario);
			  goto Inicio;
		  }
		  
	  }
  }


void AcessoUsuarioAtivar(char *a) {
	//define cor da tela e cor da fonte
	background_color;
	//declara variaveis
	FILE* ArqUsuario;
	Usuario u;

	int voltarMenu = 0, j = 0, chancesErrar = 3;
	char pessoa_logada[50];

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));


	//realiza um loop enquanto o ponteiro de a for verdadeiro
	while (*a != '\0') {



		pessoa_logada[j] = *a;

		a++;
		j++;




		if (*a == '\0')break;





	}



Inicio:
	system("cls");


	asciiCadFechado();

	//abre o "arq_binario.bin" e tem a permissao apenas de leitura
	ArqUsuario = fopen("arq_binario.bin", "rb");

	//declara variaveis
	char login_dig[50], senha_dig[50];
	int tamanho = 0, login = 0, senha = 0;

	//zera variaveis
	memset(senha_dig, 0x00, sizeof(senha_dig));
	memset(login_dig, 0x00, sizeof(login_dig));

	//imprime na tela "Login" e arquiva o que for digitado
	//setbuf zera o buffer da variavel
	//gotoxy posiciona na tela
	setbuf(stdin, NULL);
	gotoxy(10, 10);
	printf("Login: ");

	//imprime na tela "Senha"
	//gotoxy posiciona na tela
	gotoxy(10, 13);
	printf("Senha: ");

	//gotoxy posiciona na tela
	//fgets armazena o que foi digitado
	gotoxy(18, 10);
	fgets(login_dig, 50, stdin);


	//posiciona a mascara de senha na tela
	gotoxy(18, 13);

	//aplica a mascara de senha
	do {


		senha_dig[tamanho] = getch();
		if (senha_dig[tamanho] == 8 && tamanho > 0) {
			printf("\b \b");
			senha_dig[tamanho] = '0';
			tamanho--;
		}
		else if (senha_dig[tamanho] == 13) {
			senha_dig[tamanho] = '\n';
			break;
		}
		else if (senha_dig[tamanho] != 8) {
			printf("%c", '*');
			tamanho++;

		}



	} while (tamanho < 50);

	while (fread(&u, sizeof(Usuario), 1, ArqUsuario) == 1) {
		if (u.status < 0) {
			if (strcmp(login_dig, u.login) == 0) {
				if (strcmp(senha_dig, u.senha) == 0) {
					login = 1;
					senha = 1;
					break;
				}
			}
		}


	}





	//se login e senha estiverem corretos ele adiciona 1 a cada variavel
	//e abre menu
	if (login == 1 && senha == 1) {
		asciiAberto();
		AtivarUsuario();
		system("cls");


	}
	//apresenta mensagem "Login ou senha invalido, adiciona 1 a variavel trocar_senha
	//e volta para o inicio do programa para o usuario digitar login e senha
	//novamente
	else {

		voltarMenu += 1;
		chancesErrar -= voltarMenu;
		if (voltarMenu == 3) {
			Menu(pessoa_logada);
		}
		else {
			gotoxy(5, 15);
			printf("\n             Login ou senha invalido, se errar mais %d você será direcionado ao menu principal...", chancesErrar);
			chancesErrar = 3;
			getch();
			fclose(ArqUsuario);
			goto Inicio;
		}

	}
}


void AcessoInativarUsuario(char *a) {
	//define cor da tela e cor da fonte
	background_color;
	//declara variaveis
	FILE* ArqUsuario;
	Usuario u;

	int voltarMenu = 0, j = 0, chancesErrar = 3;
	char pessoa_logada[50];

	//zera o lixo de memoria da variavel str1
	memset(pessoa_logada, 0x00, sizeof(pessoa_logada));


	//realiza um loop enquanto o ponteiro de a for verdadeiro
	while (*a != '\0') {



		pessoa_logada[j] = *a;

		a++;
		j++;




		if (*a == '\0')break;





	}



Inicio:
	system("cls");


	asciiCadFechado();

	//abre o "arq_binario.bin" e tem a permissao apenas de leitura
	ArqUsuario = fopen("arq_binario.bin", "rb");

	//declara variaveis
	char login_dig[50], senha_dig[50];
	int tamanho = 0, login = 0, senha = 0;

	//zera variaveis
	memset(senha_dig, 0x00, sizeof(senha_dig));
	memset(login_dig, 0x00, sizeof(login_dig));

	//imprime na tela "Login" e arquiva o que for digitado
	//setbuf zera o buffer da variavel
	//gotoxy posiciona na tela
	setbuf(stdin, NULL);
	gotoxy(10, 10);
	printf("Login: ");

	//imprime na tela "Senha"
	//gotoxy posiciona na tela
	gotoxy(10, 13);
	printf("Senha: ");

	//gotoxy posiciona na tela
	//fgets armazena o que foi digitado
	gotoxy(18, 10);
	fgets(login_dig, 50, stdin);


	//posiciona a mascara de senha na tela
	gotoxy(18, 13);

	//aplica a mascara de senha
	do {


		senha_dig[tamanho] = getch();
		if (senha_dig[tamanho] == 8 && tamanho > 0) {
			printf("\b \b");
			senha_dig[tamanho] = '0';
			tamanho--;
		}
		else if (senha_dig[tamanho] == 13) {
			senha_dig[tamanho] = '\n';
			break;
		}
		else if (senha_dig[tamanho] != 8) {
			printf("%c", '*');
			tamanho++;

		}



	} while (tamanho < 50);

	while (fread(&u, sizeof(Usuario), 1, ArqUsuario) == 1) {
		if (u.status < 0) {
			if (strcmp(login_dig, u.login) == 0) {
				if (strcmp(senha_dig, u.senha) == 0) {
					login = 1;
					senha = 1;
					break;
				}
			}
		}


	}





	//se login e senha estiverem corretos ele adiciona 1 a cada variavel
	//e abre menu
	if (login == 1 && senha == 1) {
		asciiAberto();
		InativarUsuario();
		system("cls");


	}
	//apresenta mensagem "Login ou senha invalido, adiciona 1 a variavel trocar_senha
	//e volta para o inicio do programa para o usuario digitar login e senha
	//novamente
	else {

		voltarMenu += 1;
		chancesErrar -= voltarMenu;
		if (voltarMenu == 3) {
			Menu(pessoa_logada);
		}
		else {
			gotoxy(5, 15);
			printf("\n             Login ou senha invalido, se errar mais %d você será direcionado ao menu principal...", chancesErrar);
			chancesErrar = 3;
			getch();
			fclose(ArqUsuario);
			goto Inicio;
		}

	}




}


