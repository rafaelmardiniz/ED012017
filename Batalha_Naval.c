/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados– 1/2017
Aluno: Rafael Martins Diniz
Matricula: 160060346
Turma: B
Jogo de Batalha Naval entre dois players. */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

	char g_sea[15][15][2];
	char g_aux[15][15][2];

//system("clear");


void insert_ships() {

	int i, j, l, lin, colun ;

	for(l = 0; l <= 1; l++) {
		for(i = 0; i <= 6; i++) {
			lin = rand() % 14;
			colun = rand() % 13;
			g_sea[lin][colun][l] = 'S';
		}
	}
}

void insert_water() {

	int i, j, k;

	for(k = 0; k <= 1; k++) {
		for(i = 0; i <= 14; i++) {
			for(j = 0; j <= 13; j++) {
				g_sea[i][j][k] = '.';
				g_aux[i][j][k] = '.';
			}
		}
	}
}

void init_sea() {

	int i, j;

	insert_water();
	insert_ships();

	for(i = 0; i <= 1; i++) {
		for(j = 0; j <= 14; j++) {
			g_sea[j][14][i] = '\0';
			g_aux[j][14][i] = '\0';
		}
	}
}

void start() {
	init_sea();
	system("clear");
	printf("                           \n");
	printf("                           \n");
	printf("        Bem vindo ao       \n");
	printf("          Batalha          \n");
	printf("           Naval           \n");
	printf("                           \n");
	printf("      Pressione enter      \n");
	printf("            ...            \n");
	getchar();
}

void result(int winner) {

	system("clear");
	printf("\n");
	printf("\n");
	printf("Player %d ganhou a batalha", winner);
	printf("\n");
	printf("Obrigado por jogar");
	printf("\n");
	printf("Pressione enter...");
	getchar();
}

void print_sea(int p) {

	int player,i,j;

	if(p == 0) player = 1;
	else player = 0;

	system("clear");
	for(i = 0; i <= 14; i++) {
		for(j = 0; j <= 14; j++) {
			if(g_aux[i][j][player] == '\0') printf("\n");
			else printf("%c\t", g_aux[i][j][player]);
		}
	}
}

int torpedo(lin,colun,p) {

	int player;

	if(p == 0) player = 1;
	else player = 0;

	if((g_sea[lin][colun][player] == '.')) {
		g_aux[lin][colun][player] = 'W';
		return 0;
	}
	else {
		g_aux[lin][colun][player] == 'S';
		return 1;
	}
}

void play() {

	int lin, colun, player = 0, dest_ships1 = 0, dest_ships2 = 0;

	do {
		system("clear");
		print_sea(player);
		printf("\n");
		printf(" Player %d Escolha uma coordenada para lançar um torpedo: ", player + 1);
		scanf("%d %d", &lin, &colun);
		torpedo(lin, colun);
		printf("%d", player);
		if(player == 0) {
			printf("teste");
			dest_ships2 += torpedo(lin, colun, player);
			player = 1;
			printf("%d", dest_ships2);
		}
		else {
			dest_ships1 += torpedo(lin, colun, player);
			player = 0;
		}

	} while(dest_ships1 < 7 || dest_ships2 < 7);

	if(dest_ships1 == 7) result(2);
	else result(1);
}

int main() {

	start();
	play();
	system("clear");
	printf("\n");
	printf("\n");
	printf("Fim de jogo");
	printf("\n");
	return 0;
}
