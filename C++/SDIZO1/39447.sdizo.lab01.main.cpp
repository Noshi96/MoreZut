//SDIZO I1 210A LAB01
//Pawe� Swora
//sp39447@zut.edu.pl

#include <iostream>
#include<stdio.h>
#include <time.h>
#include<fstream>

using namespace std;

struct Struktura{//Deklaracja struktury
	int var_int;
	char var_char;
	float var_float;
};
//_____________________________________________________________________________________________________
Struktura losowanie(Struktura**&wskaznik, int rozmiar) {//Funkcja typu strukturalnego z parmetrami 1. Wskaka�nik(orgina�), 2.Rozmiar struktury.  Wska�nik wskazuje na wska�nik, talica ze wska�nikami 
	wskaznik = new Struktura*[rozmiar]; //dynamiczna alokacja pami�ci na tablic� N(rozmiar) wska�nik�w na struktury
	for (int i = 0; i < rozmiar; i++) {
		wskaznik[i] = new Struktura;// Ka�demu wska�nikowi przypisywana jest struktura. alokacja N struktur z przypisaniem uzyskanych adres�w do kolejnych kom�rek tablicy.
	}

	int stala_a=-1000;//Zakres minimalny w przedziale
	int stala_b=9000;//Zakres maksymalny w przedziale
	int wielkosc_przedzialu = stala_b - stala_a + 1;//Maksymalny przedzia�
		
		int wartosc_losowa_int;
		char wartosc_losowa_char;
		float wartosc_float;

		Struktura do_losowania;//Tworzenie obiektu
		Struktura do_floata;

		srand(time(NULL)); //Umo�liwia losowanie

		for (int i = 0; i < rozmiar; i++) {		
			wartosc_losowa_int = rand() % wielkosc_przedzialu - 1000;// DEFINE
			do_losowania.var_int = wartosc_losowa_int;//                           Losowanie i przypisanie wylosowanej warto�ci obiektowi w tablicy
			wskaznik[i] ->var_int = do_losowania.var_int;//

					for (int x = 0; x < i; x++) {								//Losowanie bez powtarzania
					while ((wskaznik[x]->var_int) == (wskaznik[i]->var_int)){
							wartosc_losowa_int = rand() % wielkosc_przedzialu - 1000;//
							do_losowania.var_int = wartosc_losowa_int;//           Losowanie i przypisanie wylosowanej warto�ci obiektowi w tablicy
							wskaznik[i]->var_int = do_losowania.var_int;//		Odwo�anie do miejsca w pami�ci i przypisanie warto�ci
							x = 0;
						}
					}
					int zakres_znakow = 23;
					int miejsce_B_w_ASCI = 66;

					wartosc_losowa_char = (rand() % zakres_znakow) + miejsce_B_w_ASCI;//
					do_losowania.var_char = wartosc_losowa_char;//                 Losowanie i przypisanie wylosowanej warto�ci obiektowi w tablicy
					wskaznik[i]->var_char = do_losowania.var_char;//

					wartosc_float = 1000 + i + 1;//
					do_floata.var_float = wartosc_float;//                          Przypisanie warto�ci obiektowi w tablicy
					wskaznik[i]->var_float = do_floata.var_float;//
		}
			return **wskaznik;
}
//___________________________________________________________________________________________
void kasowanie(Struktura**&wskaznik, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		delete[] wskaznik[i]; //Usuwa wska�niki w tablicy
	}
	delete[] wskaznik;//Usuwa tablice wska�nik�w
}
//___________________________________________________________________________________________
void sortowanie(Struktura**&wskaznik, int rozmiar) {
	for (int i=0; i < rozmiar; i++) {
		int zmiana = 0;								//flaga
		for (int j = 0; j < rozmiar-i-1; j++) {
			if ((wskaznik[j]->var_int) > (wskaznik[j + 1]->var_int)) {   //por�wnanie poprzedniego elementu z nast�pnym
				swap(wskaznik[j + 1], wskaznik[j]);
				zmiana = 1;
			}
		}
		if (zmiana == 0)
			break;
	}
}
//__________________________________________________________________________________________
int zliczanie_znakow(Struktura**&wskaznik, int rozmiar, char szukany_znak) {
	int licznik=0;
	for (int i = 0; i < rozmiar; i++) {
		if (wskaznik[i]->var_char==szukany_znak) {
			licznik++;
		}
	}
	return licznik;
}
//__________________________________________________________________________________________
void pokaz_all(Struktura **wskaznik, int ilosc_wyswietlen) {
	for (int i = 0; i < ilosc_wyswietlen; i++) {
		cout << "Numer struktury:"<< i + 1 << "   Wartosc losowa int:" << wskaznik[i]->var_int << "   Wartosc losowa char:" << wskaznik[i]->var_char << "   Wartosc float:" << wskaznik[i]->var_float << endl;
	//	cout  endl;
		//cout  endl;
		//cout endl<<endl;
	}
}
//__________________________________________________________________________________________
void main() {
	clock_t begin, end;
	double time_spent;
	begin = clock();
//------------------------------------------------------------------------------------------

	int N;
	char X;
	int ile_posortowanych=20;
	int ilosc_wystapien;

	fstream plik("inlab01.txt", ios::in);
	if (plik.good()) {
		plik >> N;
		plik >> X;
		plik.close();
	}
	Struktura **box;

	**box = losowanie(box, N);

	sortowanie(box, N);

	pokaz_all(box, ile_posortowanych);

	ilosc_wystapien = zliczanie_znakow(box, N, X);
	cout <<endl<< "Znak " << X << " wystapil " << ilosc_wystapien << " razy. " << endl<<endl;

	kasowanie(box, N);
//-----------------------------------------------------------------------------------------

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	cout << "Program wykonywal sie przez okres: " << time_spent << endl<<endl;
	system("pause");
}