#include <stdio.h>
#include <stdlib.h>

void wypiszTablice(int tablica[3][4], int wiersze, int kolumny);
void zmienWartosci(int tablica[3][4], int wiersze, int kolumny);
double sredniaWiersza(int tablica[3][4], int wiersz, int kolumny);
int sumaWiersza(int tablica[3][4], int wiersz, int kolumny);


int main()
{
	int tablica[3][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	wypiszTablice(tablica, 3, 4);
	zmienWartosci(tablica, 3, 4);
	wypiszTablice(tablica, 3, 4);

	for (int i = 0; i < 3; i++)
	{
		printf("Suma wiersza %d: %d\n", i, sumaWiersza(tablica, i, 4));
		printf("Srednia wiersza %d: %.2f\n", i, sredniaWiersza(tablica, i, 4));
	}

	return EXIT_SUCCESS;
}

void wypiszTablice(int tablica[3][4], int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			printf("%d ", tablica[i][j]);
		}
		printf("\n");
	}
}

void zmienWartosci(int tablica[3][4], int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			printf_s("Podaj wartosc dla tablicy[%d][%d]:\n ", i, j);
			scanf_s("%d", &tablica[i][j]);
		}
	}
}

double sredniaWiersza(int tablica[3][4], int wiersz, int kolumny)
{
	double suma = 0.0;
	for (int j = 0; j < kolumny; j++)
	{
		suma += tablica[wiersz][j];
	}
	return suma / kolumny;
}

int sumaWiersza(int tablica[3][4], int wiersz, int kolumny)
{
	int suma = 0;
	for (int j = 0; j < kolumny; j++)
	{
		suma += tablica[wiersz][j];
	}
	return suma;
}