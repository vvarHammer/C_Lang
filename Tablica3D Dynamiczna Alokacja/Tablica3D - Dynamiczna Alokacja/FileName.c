#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 3

int*** stworzTab3D(int rozmiar);
void freeTab3D(int*** tab, int rozmiar);          // do zwolnienia pamieci po zakonczeniu pracy na tablicy 3D, albo to
void freeTab3D_Pointer(int**** tab, int rozmiar); // albo to (&tablica) w main - to ustawia wskaznik tablicy na NULL po zwolnieniu pamieci
void wypelnijTab3D(int*** tab, int rozmiar);
void wypiszTab3D(int*** tab, int rozmiar);

int main()
{
    int*** tab = stworzTab3D(ROZMIAR);

    wypelnijTab3D(tab, ROZMIAR);
    wypiszTab3D(tab, ROZMIAR);

    //freeTab3D(tab, ROZMIAR); // zwalnianie pamieci bez ustawienia wskaznika tablicy na NULL (dziala, ale lepiej go ustawic na NULL)
	freeTab3D_Pointer(&tab, ROZMIAR); // zwalnianie pamieci i ustawianie wskaznika tablicy na NULL (dobra praktyka, zeby uniknac bledow)
    printf("Wskaznik tab po zwolnieniu = %p", tab); // czy wskaznik na tablice na pewno == NULL; jesli ostrzezenie kompilatora: rzutowanie (void*)tab

    //getch();
    return EXIT_SUCCESS;
}

int*** stworzTab3D(int rozmiar)
{
    int*** Tablica = malloc(rozmiar * sizeof(int**)); // alokacja 1-szego wymiaru
    if (!Tablica)
    {
        printf("Nie udalo sie zaalokac pamieci w etapie 1.");
        free(Tablica); // w razie bledu: zwolnij pamiec 1-szego wymiaru
        return NULL;
    }
    for (int i = 0; i < rozmiar; i++)
    {
        Tablica[i] = malloc(rozmiar * sizeof(int*)); // alokacja 2-ego wymiaru
        if (!Tablica[i])
        {
            printf("Nie udalo sie zaalokac pamieci w etapie 2.");
            for (int i = 0; i < rozmiar; i++)
                free(Tablica[i]); // w razie bledu: zwolnij pamiec 1 + 2-ego wymiaru \/
            free(Tablica);
            return NULL;
        }

        for (int j = 0; j < rozmiar; j++)
        {
            Tablica[i][j] = malloc(rozmiar * sizeof(int));
            if (!Tablica[i][j])
            {
                printf("Nie udalo sie zaalokac pamieci w etapie 3.");
                for (int k = 0; k < rozmiar; k++)
                {
                    for (int l = 0; l < rozmiar; l++)
                    {
                        free(Tablica[k][l]); // w razie bledu, zwolnij pamiec wszystkich wymiarow \/
                    }
                    free(Tablica[i]);
                }
                free(Tablica);
                return NULL;
            }
        }
    }
    return Tablica; // jezeli bez bledow: zwroc tablice 3D
}

void freeTab3D(int*** tab, int rozmiar) // zwalnianie wszystkich wymiarow tablicy, bez ustawiania jej wskaznika = NULL (dobra praktyka)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
            free(tab[i][j]);
        free(tab[i]);
    }
    free(tab);
}

void wypelnijTab3D(int*** tab, int rozmiar) // klasyczne wypelnianie tablicy 3D (przypisanie wartosci po 3 wymiarach)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            for (int k = 0; k < rozmiar; k++)
                tab[i][j][k] = 20 * k + j; // przykladowe wypelnienie
        }
    }
}

void wypiszTab3D(int*** tab, int rozmiar) // klasyczne wypisywanie tablicy 3D (printf po 3 wymiarach)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            for (int k = 0; k < rozmiar; k++)
                printf("TAB[%d][%d][%d] = %d\n", i, j, k, tab[i][j][k]);
        }
    }
}

void freeTab3D_Pointer(int**** tab, int rozmiar) // poczworny wskaznik, zeby wyzerowac wskaznik na oryginalna tablice
{
    if (tab == NULL || *tab == NULL) // jezeli wskaznik juz == NULL, albo wskaznik na ten wskaznik == NULL, to dobrze - nic nie rob
        return;

    for (int i = 0; i < rozmiar; i++) // jesli trzeba zwolnic wskaznik, iterujemy z dodatkowym wskaznikiem na tablice, po kazdym wymiarze
    {
        for (int j = 0; j < rozmiar; j++)
            free((*tab)[i][j]);
        free((*tab)[i]);
    }
    free(*tab);
    *tab = NULL; // na koniec ustaw wskaznik tablicy na NULL; sprawdz to w mainie
}