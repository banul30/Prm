
struct pierwiastek
{
    char nazwa[30];
    char symbol[5];
    double masaAtomowa;
    int elektronowWalencyjnych;
    struct pierwiastek *nastepny;
};

struct pierwiastek *pierwszy = NULL;
struct pierwiastek *ostatni = NULL;


struct pierwiastek* utworz_liste(int elektronowWalencyjnych, char nazwa[])
{
    printf("Utworzenie listy z pierwiastek poczatkowym o wartosci: %d\n",elektronowWalencyjnych);
    struct pierwiastek *wsk = (struct pierwiastek*)malloc(sizeof(struct pierwiastek));
    if(NULL == wsk)																	//w przypadku nieprzydzielenia pamiêci na pierwiastek listy
    {																				//funkcja zwraca NULL, co swiadczy o niepowodzeniu
        printf("Nieudana proba utworzenia pierwszego pierwiasteku listy!\n");			//tworzenia listy
        return NULL;
    }
    wsk->elektronowWalencyjnych = elektronowWalencyjnych;																	//przypisanie wartosci typu int do utworzonego pierwiasteku
    wsk->nastepny = NULL;															//aktualnie nie ma kolejnego pierwiasteku na liscie

    pierwszy = ostatni = wsk;														//utworzony pierwiastek jest pierwszym pierwiastekem na liscie
    return wsk;																		//i jednoczesnie pierwiastekem bie¿¹cym
}


struct pierwiastek* dodaj_do_listy(int elektronowWalencyjnych, char nazwa[])
{
    if(NULL == pierwszy)
    {
        return (utworz_liste(elektronowWalencyjnych, nazwa));													//jesli lista jest pusta to dodaj utworz pierwszy pierwiastek
    }

    printf("Dodanie pierwiasteku listy na jej koncu o wartosci: %d\n",elektronowWalencyjnych);			//zgodnie z wartoscia przekazanego argumentu dodaj_na_koncu

    struct pierwiastek *wsk = (struct pierwiastek*)malloc(sizeof(struct pierwiastek));			//alokacja pamiêci na kolejny pierwiastek listy
    if(NULL == wsk)																	//w przypadku nieprzydzielenia pamiêci na pierwiastek listy
    {																				//funkcja zwraca NULL, co swiadczy o niepowodzeniu
        printf("Nieudana proba utworzenia nowego pierwiasteku listy!\n");				//utworzenia nowego pierwiasteku listy
        return NULL;
    }
    wsk->elektronowWalencyjnych = elektronowWalencyjnych;																//przypisanie wartosci typu int do utworzonego pierwiasteku
    wsk->nastepny = NULL;															//aktualnie nie ma kolejnego pierwiasteku na liscie

        ostatni->nastepny = wsk;													//pomiedzy pierwiastekami w kazdym przypadku
        ostatni = wsk;

    return wsk;																		//funkcja zwraca wskaznik do nowoutworzonego pierwiasteku
}


struct pierwiastek* przeszukaj_liste(int elektronowWalencyjnych, struct pierwiastek **poprzedni)
{
    struct pierwiastek *wsk = pierwszy;													//zmienne pomocnicze w funkcji
    struct pierwiastek *tmp = NULL;														//poszukiwanie zaczyna siê od pierwszego pierwiasteku na liscie
    int znaleziony = 0;

    printf("...Przeszukiwanie listy. Szukana wartosc: %d \n",elektronowWalencyjnych);

    while(wsk != NULL)
    {
        if(wsk->elektronowWalencyjnych == elektronowWalencyjnych)															//jesli szukana wartosc zostala znaleziona na liscie
        {																			//to dzialanie petli zostaje przerwane
            znaleziony = 1;
            break;
        }
        else
        {
            tmp = wsk;
            wsk = wsk->nastepny;
        }
    }

    if(1 == znaleziony)
    {
        if(poprzedni)																//jesli do funkcji przekazany jest adres wskaznika
            *poprzedni = tmp;														//do poprzedniego pierwiasteku wzgledem wyszukanego
        return wsk;																	//to jego wartosc jest ustawiana - wykorzystane w funkcji
    }																				//skasuj_wartosc_z_listy(...)
    else																			//funkcja zwraca wskaznik do struktury, ktora zwiera poszukiwana wartosc
    {
        return NULL;
    }
}


int skasuj_wartosc_z_listy(int elektronowWalencyjnych)
{
    struct pierwiastek *poprzedni = NULL;												//zmienne pomocnicze w funkcji
    struct pierwiastek *do_skasowania = NULL;

    printf("...Kasowanie wartosci: %d z listy pierwiastekow\n",elektronowWalencyjnych);

    do_skasowania = przeszukaj_liste(elektronowWalencyjnych,&poprzedni);								//znajdz pierwsza strukture zgodna ze wzorcem elektronowWalencyjnych,
    																				//która zostanie skasowana
	if(NULL == do_skasowania)
    {
        return -1;																	//jesli nie znaleziono poszukiwanej wartosci to funkcja zwraca -1
    }
    else
    {
        if(NULL != poprzedni)														//wylaczenie kasowanego pierwiasteku z listy
            poprzedni->nastepny = do_skasowania->nastepny;							//czyli poprzestawianie wskaznikow w pierwiastekach
																					//omijajac pierwiastek kasowany
        if(do_skasowania == ostatni)												//w zlaeznosci czy kasowany elemen znajduje sie:
        {																			//wewnatrz listy, na koncu listy lub na poczatku listy
            ostatni = poprzedni;
        }
        else if(do_skasowania == pierwszy)
        {
            pierwszy = do_skasowania->nastepny;
        }
    }

    free(do_skasowania);															//zwolnienie pamieci skasowanego pierwiasteku
    do_skasowania = NULL;															//"wyzerowanie" wskaznika

    return 0;
}


void wydrukuj_liste(void)
{
    struct pierwiastek *wsk = pierwszy;
    int i=0;
    if(NULL == wsk)
    {
    	printf("Lista jest pusta!\n");
    }
	else
    {
	    printf("\n ------- Wydruk listy / Poczatek ------- \n");
	    while(wsk != NULL)
	    {
	        printf("%3d. %5d %s \n",i,wsk->elektronowWalencyjnych);
	        wsk = wsk->nastepny;
	        i++;
	    }
	    printf("------- Wydruk listy / Koniec --------- \n");
	}
    return;
}
