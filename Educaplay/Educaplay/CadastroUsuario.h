#pragma once

typedef struct 
{
	//int idUltimoUsu;
	
	char nome[100];
	int id;
	char endereco[100];
	char cpf[15];
	int cpf_int[11];
	char login[50];
	char senha[50];
	char cargo[30];
	char email[30];
	char data_nasc[10];
	char valor_hora[10];
	char horas_trabalhadas[6];
	char telefone[14];
	char mensagem[500];
	int status;
	//int trocar_senha_usuario = 0;
}Usuario;