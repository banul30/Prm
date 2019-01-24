#include<stdio.h>
#include<stdlib.h>
#include "Pierwiastek.c"

int main(void)
{

    int i = 0, res = 0;
    struct pierwiastek *wsk = NULL;

    wydrukuj_liste();

    for(i = 100; i<105; i++)
        dodaj_do_listy(i, "gg");

    wydrukuj_liste();

    for(i = 40; i>35; i--)
        dodaj_do_listy(i, "yy");

    wydrukuj_liste();

    for(i = 100; i<105; i += 2)
    {
        wsk = przeszukaj_liste(i, NULL);
        if(NULL == wsk)
        {
            printf("Szukana wartosc: %d, nie zosta³a znaleziona na liscie pierwiastekow!\n",i);
        }
        else
        {
            printf("...Szukana wartosc: %d, zostala znaleziona!\n",wsk->elektronowWalencyjnych);
        }

        wydrukuj_liste();

		res = skasuj_wartosc_z_listy(i);
        if(res != 0)
        {
            printf("Wartosc: %d nie zostala skasowana z powodu braku jej na liscie!\n",i);
        }
        else
        {
            printf("...Wartosc: %d zostala skasowana z listy! \n",i);
        }

        wydrukuj_liste();
    }

    return 0;
}
