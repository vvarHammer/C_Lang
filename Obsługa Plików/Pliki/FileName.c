#include <stdio.h>
#include <stdlib.h>

void zapisTabDoPliku(const char* nazwaPliku, int tablica[][4], int wiersze, int kolumny);
void odczytTabZPliku(const char* nazwaPliku, int tablica[][4], int wiersze, int kolumny);
void wypiszTablice(int tablica[][4], int wiersze, int kolumny);
void zerujTablice(int tablica[][4], int wiersze, int kolumny);

int main()
{
	int tablica[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	printf("Tablica przed zapisem do pliku:\n");
	wypiszTablice(tablica, 4, 4);

	zapisTabDoPliku("tablica.txt", tablica, 4, 4);

	zerujTablice(tablica, 4, 4);
	printf("Tablica po zerowaniu:\n");
	wypiszTablice(tablica, 4, 4);

	odczytTabZPliku("tablica.txt", tablica, 4, 4);

	printf("Tablica po odczycie z pliku:\n");
	wypiszTablice(tablica, 4, 4);

	return EXIT_SUCCESS;
}

void zapisTabDoPliku(const char* nazwaPliku, int tablica[][4], int wiersze, int kolumny)
{
	FILE* plik = fopen(nazwaPliku, "w");
	if (plik == NULL) {
		perror("Nie mozna otworzyc pliku do zapisu");
		return;
	}
	fprintf(plik, "%d %d\n", wiersze, kolumny);
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			fprintf(plik, "%d ", tablica[i][j]);
		}
		fprintf(plik, "\n");
	}
	fclose(plik);
}

void odczytTabZPliku(const char* nazwaPliku, int tablica[][4], int wiersze, int kolumny)
{
	FILE* plik = fopen(nazwaPliku, "r");
	if (plik == NULL) {
		perror("Nie mozna otworzyc pliku do odczytu");
		return;
	}
	fscanf_s(plik, "%d %d", &wiersze, &kolumny);
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			fscanf_s(plik, "%d", &tablica[i][j]);
		}
	}
	fclose(plik);
}

void wypiszTablice(int tablica[][4], int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			printf("%d ", tablica[i][j]);
		}
		printf("\n");
	}
}

void zerujTablice(int tablica[][4], int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			tablica[i][j] = 0;
		}
	}
}