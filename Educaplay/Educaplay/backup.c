#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "conio2.h"
#include "CadastroUsuario.h"
#include <Windows.h>
#include "funcoes_ascii.h"
#include <time.h>
#define background_color system("color 0f");




void CopiarConteudo(FILE* FILE1, FILE* FILE2) {

	char leitor[4];

	FILE* arq;

	arq = fopen("arq_binario.bin", "rb");

	memset(leitor, 0x00, sizeof(leitor));

	while (fgets(leitor, sizeof(leitor), FILE1) != NULL) {
			fputs(leitor, FILE2);
		
			
	}

		
		




}




void Backup() {
	background_color;
	system("cls");
	int num = 0, num_randomico, i = 0, tam_backup;
	char backup[5], copia_backup[6], armazena_bin[] = ".bin", op;
	memset(copia_backup, 0x00, sizeof(copia_backup));

	
	gotoxy(32, 12);
	printf("Gostaria de realizar o backup? (s/n)");
	op = getchar();
	limpaBuffer();

	if (op == 's' || op == 'S') {

		srand(time(NULL));

		void CopiarConteudo(FILE * FILE1, FILE * FILE2);

		FILE* FILE1 = fopen("arq_binario.bin", "rb");

		if (FILE1 == NULL) {

			printf("Nao foi possivel abrir arquivo");
		}


		srand(time(NULL));


		num_randomico = rand() % 100;


		backup[i] = 97 + (char)(rand() % 26);




		for (int i = 0; i <= 4; i++) {
			if (backup[i] == 'Ì')break;
			copia_backup[i] = backup[i];

		}

		strcat(copia_backup, armazena_bin);


		FILE* FILE2 = fopen(copia_backup, "wb+");

		CopiarConteudo(FILE1, FILE2);

		fclose(FILE1);
		fclose(FILE2);


		system("cls");

		for (int i = 0; i <= 20; i++) {
			
			gotoxy(45 + i, 13);
			textbackground(15);
			printf("%c", 219);
			Sleep(150);


			gotoxy(53, 11);
			textcolor(15);
			textbackground(0);
			printf("%d%%", num);
			num += 5;



		}

		gotoxy(40, 16);
		printf("Backup realizado com sucesso!");
		Sleep(450);

	}

}