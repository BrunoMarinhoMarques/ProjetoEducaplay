#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void Data() {

	////ponteiro para struct que armazena data e hora  
	struct tm* data_hora_atual;

	////variável do tipo time_t para armazenar o tempo em segundos  
	time_t segundos;

	////obtendo o tempo em segundos  
	time(&segundos);

	////para converter de segundos para o tempo local  
	////utilizamos a função localtime  
	data_hora_atual = localtime(&segundos);

	//escreve a data na tela
	printf("\n\n\n\n\n\n\n\n   Dia:%d/%d/%d\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900);



}