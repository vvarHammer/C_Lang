#include <stdlib.h>
#include <stdio.h>

int** stworzTablice(int wiersze, int kolumny);
void wypelnijTablice(int** tablica, int wiersze, int kolumny);
void pokazTablice(int** tablica, int wiersze, int kolumny);

int main()
{
	int wiersze, kolumny;
	printf("Podaj wymiary tablicy (wiersze i kolumny): ");
	scanf_s("%d %d", &wiersze, &kolumny);
	int** tab = stworzTablice(wiersze, kolumny);

	wypelnijTablice(tab, wiersze, kolumny);
	pokazTablice(tab, wiersze, kolumny);

	for (int i = 0; i < wiersze; i++)
	{
		free(tab[i]);
	}
	free(tab);
	return EXIT_SUCCESS;
}

int** stworzTablice(int wiersze, int kolumny)
{
	int** tablica = malloc(wiersze * sizeof(int*));
	if (tablica == NULL)
	{
		fprintf(stderr, "Błąd alokacji pamięci.\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < wiersze; i++)
	{
		tablica[i] = malloc(kolumny * sizeof(int));
		if (tablica[i] == NULL)
		{
			fprintf(stderr, "Blad alokacji pamieci w wierszu %d.\n", i);

			for (int j = 0; j < i; j++)
				free(tablica[j]);
			free(tablica);

			return NULL;
		}
	}
	return tablica;
}

void wypelnijTablice(int** tablica, int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
			tablica[i][j] = i + 3;
	}
}

void pokazTablice(int** tablica, int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
			printf("%d ", tablica[i][j]);
		printf("\n");
	}
}
