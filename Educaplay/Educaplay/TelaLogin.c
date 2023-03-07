#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CadastroUsuario.h"
#include "MascaraSenha.h"
#include "VerificaLoginSenha.h"
#define background_color system("color 0f");


void TelaLogin() {

	//coloca cor da tela
	background_color;

	//limpa a tela
	system("cls");

	//chama a funcao "VerificaLoginSenha"
	VerificaLoginSenha();
	
	
	

}