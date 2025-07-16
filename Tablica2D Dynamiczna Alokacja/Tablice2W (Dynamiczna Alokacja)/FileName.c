#include <stdio.h>
#include <stdlib.h>

void wypelnijTab(int** tab, int wiersze, int kolumny);
void pokazTab(int** tab, int wiersze, int kolumny);

int main()
{
    int wiersze = 0, kolumny = 0;

    printf("Podaj wymiary Tab[X][Y]:");
    scanf_s("%d %d", &wiersze, &kolumny);

    int** Tablica = malloc(wiersze * sizeof(int*));
    for (int i = 0; i < wiersze; i++)
        Tablica[i] = malloc(kolumny * sizeof(int));

    wypelnijTab(Tablica, wiersze, kolumny);
    pokazTab(Tablica, wiersze, kolumny);

    for (int i = 0; i < wiersze; i++)
        free(Tablica[i]);
    free(Tablica);
    return 0;
}

void wypelnijTab(int** tab, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; i++)
        for (int j = 0; j < kolumny; j++)
            tab[i][j] = i + 2;
}

void pokazTab(int** tab, int wiersze, int kolumny)
{
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < kolumny; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}
