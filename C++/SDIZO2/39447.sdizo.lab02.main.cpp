//SDIZO I1 210A LAB02
//Pawe³ Swora
//sp39447@zut.edu.pl

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<fstream>

using namespace std;

struct Lista {
public:
	int klucz;
	double zmienna_double;
	char zmienna_char;
	Lista *nastepny;
	Lista *poprzedni;
}*head = NULL,
*koniec = NULL,
*wezel = NULL,
*obsluga_klucza=NULL;

void dodaj_wezel(int klucz, int &i);
void wstawianie(int X);
void szukanie_klucza(int szukana);
void usun_wezel(int nr_wezla);
void prezentacja_pierwsza(int wartosc);
void prezentacja_ostatnia(int wartosc);
int wypisz_ile_wezlow(Lista *&head);
void usun_wszystko(Lista*&head);


void main() {
	int X, k1, k2, k3, k4, k5,i=0,pierwszy=20,ostatni=11;
	head = NULL;
	fstream plik("inlab02.txt", ios::in);
	if (plik.good()) {
		plik >> X;
		plik >> k1;
		plik >> k2;
		plik >> k3;
		plik >> k4;
		plik >> k5;
		plik.close();
	}
	
	clock_t begin, end;
	double time_spent;
	begin = clock();
	//------------------------------------------------------------------------------------------

	cout << "_________________Inicjalizacja_______________________________________" << endl;
	cout << endl;
	cout << "_________________Wyszukanie klucza k1________________________________" << endl;
	szukanie_klucza(k1);
	cout << endl;
	cout << "_________________Wstawienie X elementow______________________________" << endl;
	wstawianie(X);
	cout << endl;
	cout << "_________________Wypisanie liczby wezlow_____________________________" << endl;
	wypisz_ile_wezlow(head);
	cout << endl;
	cout << "_________________Prezentacja pierwszych 20 wezlow____________________" << endl;
	prezentacja_pierwsza(pierwszy);
	cout << endl;
	cout << "_________________Wstawienie klucza k2____________________" << endl;
	dodaj_wezel(k2, i);
	cout << endl;
	cout << "_________________Prezentacja pierwszych 20 wezlow____________________" << endl;
	prezentacja_pierwsza(pierwszy);
	cout << endl;
	cout << "_________________Wstawienie klucza k3____________________" << endl;
	dodaj_wezel(k3, i);
	cout << endl;
	cout << "_________________Prezentacja pierwszych 20 wezlow____________________" << endl;
	prezentacja_pierwsza(pierwszy);
	cout << endl;
	cout << "_________________Wstawienie klucza k4____________________" << endl;
	dodaj_wezel(k4, i);
	cout << endl;
	cout << "_________________Prezentacja pierwszych 20 wezlow____________________" << endl;
	prezentacja_pierwsza(pierwszy);
	cout << endl;
	cout << "_________________Wstawienie klucza k5____________________" << endl;
	dodaj_wezel(k5, i);
	cout << endl;
	cout << "_________________Usuwanie klucza k3____________________" << endl;
	usun_wezel(k3);
	cout << endl;
	cout << "_________________Prezentacja pierwszych 20 wezlow____________________" << endl;
	prezentacja_pierwsza(pierwszy);
	cout << endl;
	cout << "_________________Usuwanie klucza k2____________________" << endl;
	usun_wezel(k2);
	cout << endl;
	cout << "_________________Prezentacja pierwszych 20 wezlow____________________" << endl;
	prezentacja_pierwsza(pierwszy);
	cout << endl;
	cout << "_________________Usuwanie klucza k5____________________" << endl;
	usun_wezel(k5);
	cout << endl;
	cout << "_________________Wypisanie liczby wezlow_____________________________" << endl;
	wypisz_ile_wezlow(head);
	cout << endl;
	cout << "_________________Wyszukanie klucza k5________________________________" << endl;
	szukanie_klucza(k5);
	cout << endl;
	cout << "_________________Prezentacja ostatnich 11 wezlow_____________________" << endl;
	prezentacja_ostatnia(ostatni);
	cout << endl;
	cout << "_________________Usuniecie wszystkich elementow______________________" << endl;
	usun_wszystko(head);
	cout << endl;
	cout << "_________________Prezentacja ostatnich 11 wezlow_____________________" << endl;
	prezentacja_ostatnia(ostatni);
	cout << endl;
	cout << "_________________Wypisanie liczby wezlow_____________________________" << endl;
	wypisz_ile_wezlow(head);
	cout << endl;
	//-----------------------------------------------------------------------------------------

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Program wykonywal sie przez okres: " << time_spent << endl << endl;
	system("pause");
}
//------------------------------Funkcje-----------------------------------------------------------

void dodaj_wezel(int klucz, int &i) {
	
	wezel = new Lista();
	obsluga_klucza = new Lista();

	Lista *nastepnik_heada;
	nastepnik_heada = new Lista();

	Lista *nastepnik_konca;
	nastepnik_konca = new Lista();



	wezel->klucz = klucz;
	wezel->zmienna_double = rand();
	wezel->zmienna_char = 'T';

	if (head == NULL && koniec == NULL) {
		head = wezel;
		koniec = wezel;
		head->poprzedni = koniec;
		koniec->nastepny = head;
	}
	else {
		obsluga_klucza = head;

		do {
			if (klucz == obsluga_klucza->klucz) {
				cout << "Blad! Klucz: " << klucz << " juz istnieje. " << endl;
				i = i - 1;
			}
			obsluga_klucza = obsluga_klucza->nastepny;
		} while (obsluga_klucza != head);

		if (klucz<head->klucz) {

			nastepnik_heada = head;
			head = wezel;

			nastepnik_heada->poprzedni = head;
			head->nastepny = nastepnik_heada;
			head->poprzedni = koniec;
			koniec->nastepny = head;
			wezel->klucz = klucz;
			wezel->zmienna_double = rand();
			wezel->zmienna_char = 'T';
		}
		if (klucz>koniec->klucz) {

			nastepnik_konca = koniec;
			koniec = wezel;

			nastepnik_konca->nastepny = koniec;
			koniec->poprzedni = nastepnik_konca;
			koniec->nastepny = head;
			head->poprzedni = koniec;
			wezel->klucz = klucz;
			wezel->zmienna_double = rand();
			wezel->zmienna_char = 'T';
		}

		do {
			if (klucz>obsluga_klucza->klucz && klucz< obsluga_klucza->nastepny->klucz) {

				obsluga_klucza->nastepny->poprzedni = wezel;
				wezel->nastepny = obsluga_klucza->nastepny;
				obsluga_klucza->nastepny = wezel;
				wezel->poprzedni = obsluga_klucza;
				wezel->klucz = klucz;
				wezel->zmienna_double = rand();
				wezel->zmienna_char = 'T';
			}
			obsluga_klucza = obsluga_klucza->nastepny;
		} while (obsluga_klucza != head);
	}
}

void wstawianie(int X) {
	srand(time(NULL));
	for (int i = 0; i < X; i++) {
		int los;
		los = (rand() % 99901) + 99;
		dodaj_wezel(los, i);
	}
}

void szukanie_klucza(int szukana) {
	Lista *przechowaj;
	przechowaj = head;
	if (head != NULL) {
		bool spr = true;
		head = head->nastepny;
		while (head != przechowaj && spr) {
			if (head->klucz == szukana) {
				cout << "Klucz: " << head->klucz << " istnieje. " << endl;
				spr = false;
			}
			head = head->nastepny;
		}
		if (spr == true) {
			cout << "Podany klucz nie istnieje." << endl;
		}
	}
	else{
		cout << "Podany klucz nie istnieje. Lista jest pusta. " << endl;
	}
	head = przechowaj;
}

void usun_wezel(int nr_wezla) {
	Lista *przechowaj;
	przechowaj = head;
	if (head != NULL) {
		bool spr = true;
		head = head->nastepny;
		while (head != przechowaj && spr) {
			if (head->klucz == nr_wezla) {
				spr = false;
			}
			else {
				head = head->nastepny;
			}
		}
		if (spr == true) {
			cout << "Podany wezel nie istnieje. " << endl;
		}
		else {
			wezel = head->poprzedni;
			obsluga_klucza = head->nastepny;
			wezel->nastepny = obsluga_klucza;
			obsluga_klucza->poprzedni = wezel;
			delete head;
			head = wezel;
		}
	}
	head = przechowaj;
}

void prezentacja_pierwsza(int wartosc) {
	Lista *przechowaj;
	przechowaj = head;
	int i = 0;
	if (head != NULL) {
		while (i != wartosc) {
			cout << "| Klucz: " << head->klucz << endl;// "| Pole double: " << head->zmienna_double << "| Pole char: " << head->zmienna_char << "|" << endl;
			head = head->nastepny;
			i++;
		}
	}
	else {
		cout << "Lista jest pusta. " << endl;
	}
	head = przechowaj;
}

void prezentacja_ostatnia(int wartosc) {
	Lista *przechowaj;
	przechowaj = head;
	if (head != NULL) {
		head = head->poprzedni;
		for (int i = wartosc; i > 0; i--) {
			cout << "| Klucz: " << head->klucz << endl;// "| Pole double: " << head->zmienna_double << "| Pole char: " << head->zmienna_char << "|" << endl;
			head = head->poprzedni;
		}
	}
	else {
		cout << "Lista jest pusta. " << endl;
	}
	head = przechowaj;
}

int wypisz_ile_wezlow(Lista *&head) {
	int licznik = 0;
	if (head != NULL) {
		Lista *przechowaj;
		przechowaj = head;
		head = head->nastepny;
		while (head != przechowaj) {
			head = head->nastepny;
			licznik++;
		}
	}
	else {
		cout << "Brak danych. " << endl;
		licznik = -1;
	}
	cout << "W liscie znajduja sie " << licznik+1 << " wezly. " << endl;
	return licznik;
}

void usun_wszystko(Lista*&head) {
	Lista *przechowaj;
	przechowaj = head;
	head = head->nastepny;
	while (head != przechowaj) {
		head = head->nastepny;
		wezel = head->poprzedni;
		delete wezel;
	}
	cout << "Usunieto wszsytkie elementy. " << endl;
	delete head;
	head = NULL;
}