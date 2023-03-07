#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MascaraSenha.h"
#include "VerificaLoginSenha.h"

//void MascaraSenha() {
//	int tamanho = 0;
//	char senha[50];
//	memset(senha, 0x00, sizeof(senha));
//	do {
//
//
//		senha[tamanho] = getch();
//		if (senha[tamanho] == 8 && tamanho > 0) {
//			printf("\b \b");
//			senha[tamanho] = '0';
//			tamanho--;
//		}
//		else if (senha[tamanho] == 13) {
//			senha[tamanho] = '\0';
//			break;
//		}
//		else if (senha[tamanho] != 8) {
//			printf("%c", '*');
//			tamanho++;
//
//		}
//
//
//
//	} while (tamanho < 50);
//
//}