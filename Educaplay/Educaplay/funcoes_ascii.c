#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>
#include "conio2.h"

void asciiCadFechado() {
	FILE* arq;
	char txt[128];
	int contador = 0, true = 0;


	//se nao tiver nada no arquivo de texto ele retorna erro
	if ((arq = fopen("cadeado.txt", "r")) == 0) {
		puts("Erro");
	}

	//senao ele desenha na tela o que tem dentro do arquivo e posiciona com gotoxy
	else {
		while (fgets(txt, sizeof(txt), arq) != NULL) {
			contador++;
			gotoxy(18, contador); printf("%s", txt);
			true = 1;
		}
	}
}


void asciiAberto() {
	FILE* arq;
	char txt[128];
	int contador = 0;

	//se nao tiver nada no arquivo de texto ele retorna erro
	if ((arq = fopen("cadeado_aberto.txt", "r")) == 0) {
		puts("Erro");
	}

	//senao ele desenha na tela o que tem dentro do arquivo e posiciona com gotoxy
	else {
		while (fgets(txt, sizeof(txt), arq) != NULL) {
			contador++;
			gotoxy(18, contador); printf("%s", txt);
		}
	}
}

void logo() {
	FILE* arq;
	char txt[128];
	int contador = 0;

	//se nao tiver nada no arquivo de texto ele retorna erro
	if ((arq = fopen("logo.txt", "r")) == 0) {
		puts("Erro");
	}

	//senao ele desenha na tela o que tem dentro do arquivo e posiciona com gotoxy
	else {
		while (fgets(txt, sizeof(txt), arq) != NULL) {
			contador++;
			gotoxy(35, contador); printf("%s", txt);
			
		}
	}
}

//desenha o "carregando" na tela
void Carregando() {

	for (int i = 0; i < 2; i++) {
		
		_setcursortype(0);
		gotoxy(50, 15);
		printf("O---------");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("-O--------");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("--O-------");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("---O------");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("----O-----");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("-----O----");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("------O---");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("-------O--");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("--------O-");
		Sleep(30);
		system("cls");
		gotoxy(50, 15);
		printf("---------O");
		Sleep(30);
		system("cls");


	}
}

void limpaBuffer(void) {
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}
