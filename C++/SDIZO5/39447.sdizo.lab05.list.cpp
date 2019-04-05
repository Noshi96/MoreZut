//SDIZO I1 210A LAB05
//Pawe³ Swora
//sp39447@zut.edu.pl

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<fstream>
#include<cstdlib>

using namespace std;


struct Lista {
public:
int klucz;
Lista *nastepny;
Lista *poprzedni;
}*head = NULL,
*koniec = NULL,
*wezel = NULL,
*obsluga_klucza = NULL;

 int licz_wstawiane_klucze = 0;
 int licz_szukane_klucze = 0;
 int licz_usuwane_klucze = 0;

void wstawianie(int N);
void dodaj_wezel(int klucz);
void wstawianie_naprzemienna(int N, int s);
void szukanie_klucza(int szukana);
int ile_znaleziono_kluczy(int N);
void usun_wezel(int nr_wezla);
int usun_wezly(int N);


void main() {

	int N = 10000;
	double time_spent;
	clock_t begin, end;
	srand(25);
	int przelacz=1;
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	
	time_spent;
	begin = clock();
	//------------------------------------------------------------------------------------------
	if (przelacz == 1) {
		wstawianie(N);
	}
	else {
		wstawianie_naprzemienna(N, przelacz);
	}																							//1								
																								//1

	//-----------------------------------------------------------------------------------------


	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Wstawianie przez okres: " << time_spent << endl << endl;

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	time_spent;
	begin = clock();
	//------------------------------------------------------------------------------------------
																									//2
																									//2

	ile_znaleziono_kluczy(N);


	//-----------------------------------------------------------------------------------------


	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Wyszukiwanie przez okres: " << time_spent << endl << endl;

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	time_spent;
	begin = clock();
	//------------------------------------------------------------------------------------------
																									//3
																									//3
	usun_wezly(N);



	//-----------------------------------------------------------------------------------------


	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Usuwanie przez okres: " << time_spent << endl << endl;


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	system("pause");
}


//------------------------------Funkcje-----------------------------------------------------------



void wstawianie(int N) {
	int los;
	for (int i = 0; i < N; i++) {
		
		los = ((rand()*rand()) % 100000);
		dodaj_wezel(los);
	}
	cout << "W liscie jest " << N-licz_wstawiane_klucze << " elementow" << endl;
	licz_wstawiane_klucze = 0;
}

void wstawianie_naprzemienna(int N, int s) {
	int nie_parzyste;
	int los;
	los = ((rand()*rand()) % 100000);
	dodaj_wezel(los);
	nie_parzyste = 1;
	int licz = 1;
	for (int i = 0; i < N-1; i++) {	
		if (i+1==nie_parzyste) {
			dodaj_wezel(licz);
			licz = licz + 1;
		}
		else {
			nie_parzyste = nie_parzyste + 2;
			los = ((rand()*rand()) % 100000);
			dodaj_wezel(los);
		}	
	}
	cout << "W liscie jest " << N-licz_wstawiane_klucze << " elementow" << endl;
	licz_wstawiane_klucze = 0;
}


void dodaj_wezel(int klucz) {

	wezel = new Lista();
	obsluga_klucza = new Lista();

	Lista *nastepnik_heada;
	nastepnik_heada = new Lista();

	Lista *nastepnik_konca;
	nastepnik_konca = new Lista();

	wezel->klucz = klucz;

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
				//	cout << "Blad! Klucz: " << klucz << " juz istnieje. " << endl;
					licz_wstawiane_klucze = licz_wstawiane_klucze + 1;
					return;
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
		}
		if (klucz>koniec->klucz) {
			nastepnik_konca = koniec;
			koniec = wezel;
			nastepnik_konca->nastepny = koniec;
			koniec->poprzedni = nastepnik_konca;
			koniec->nastepny = head;
			head->poprzedni = koniec;
			wezel->klucz = klucz;
		}	
		do {
			if (klucz>obsluga_klucza->klucz && klucz< obsluga_klucza->nastepny->klucz) {
				obsluga_klucza->nastepny->poprzedni = wezel;
				wezel->nastepny = obsluga_klucza->nastepny;
				obsluga_klucza->nastepny = wezel;
				wezel->poprzedni = obsluga_klucza;
				wezel->klucz = klucz;
			}
			obsluga_klucza = obsluga_klucza->nastepny;
		} while (obsluga_klucza != head);
	}
}

void szukanie_klucza(int szukana) {
	Lista *przechowaj;
	przechowaj = head;
	
	if (head != NULL) {
		bool spr = true;
		//head = head->nastepny;
		if (head == przechowaj && spr) {
			if (head->klucz == szukana) {
				//cout << "Klucz: " << head->klucz << " istnieje. " << endl;
				licz_szukane_klucze = licz_szukane_klucze + 1;
				spr = false;
			}
			head = head->nastepny;
		}
		while (head != przechowaj && spr) {
			if (head->klucz == szukana) {
				//cout << "Klucz: " << head->klucz << " istnieje. " << endl;
				licz_szukane_klucze = licz_szukane_klucze + 1;
				spr = false;	
			}
			head = head->nastepny;
		}
		if (spr == true) {
			//cout << "Podany klucz nie istnieje." << endl;
		}
	}
	else {
		//cout << "Podany klucz nie istnieje. Lista jest pusta. " << endl;
	}
	head = przechowaj;
}

int ile_znaleziono_kluczy(int N) {
	int los;
	for (int i = 0; i < N; i++) {	
		los = ((rand()*rand()) % 100000);
		szukanie_klucza(los);
	}
	cout << "Odszukano " << licz_szukane_klucze <<" kluczy."<< endl;
	return licz_szukane_klucze;
}

void usun_wezel(int nr_wezla) {
	Lista *przechowaj;
	przechowaj = head;
	if (head != NULL) {
		bool spr = true;
		do {
			if (head->klucz == nr_wezla) {
				licz_usuwane_klucze = licz_usuwane_klucze + 1;
				spr = false;
			}
			else {
				head = head->nastepny;
			}
		} while (head != przechowaj && spr);
		if (spr == true) {
			//cout << "Podany wezel nie istnieje. " << endl;
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
}

int usun_wezly(int N) {
	int los;
	for (int i = 0; i < N; i++) {
		los = ((rand()*rand()) % 100000);
		usun_wezel(los);
	}
	cout << "Usunieto " << licz_usuwane_klucze << " kluczy." << endl;
	return licz_usuwane_klucze;
}