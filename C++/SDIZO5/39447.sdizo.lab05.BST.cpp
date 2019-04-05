//SDIZO I1 210A LAB05
//Pawe³ Swora
//sp39447@zut.edu.pl

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<fstream>
#include<cstdlib>

using namespace std;


struct Drzewo {
	int klucz;
	Drzewo *lewy_potomek;
	Drzewo *prawy_potomek;
};

void dodaj_wezel(Drzewo*&root, int klucz);
void wstawianie(Drzewo*&root, int X);
void wstawianie_naprzemienna(Drzewo*&root, int N, int s);
void szukanie(Drzewo*&root, int klucz);
int ile_znaleziono_kluczy(Drzewo*&root, int N);
void usuwanie(Drzewo*&root, int x);
int usun_wezly(Drzewo*&root, int N);

int licz_wstawiane_klucze = 0;
int licz_szukane_klucze = 0;
int licz_usuwane_klucze = 0;




void main() {

	int N = 30000;
	double time_spent;
	clock_t begin, end;
	srand(25);
	int przelacz = 1;

	Drzewo *root;
	root = NULL;

	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	time_spent;
	begin = clock();
	//------------------------------------------------------------------------------------------
	if (przelacz == 1) {
		wstawianie(root, N);
	}
	else {
		wstawianie_naprzemienna(root, N, przelacz);
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
	


	ile_znaleziono_kluczy(root, N);

	//-----------------------------------------------------------------------------------------


	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Wyszukiwanie przez okres: " << time_spent << endl << endl;

	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	time_spent;
	begin = clock();
	//------------------------------------------------------------------------------------------
	

	usun_wezly(root,N);



	//-----------------------------------------------------------------------------------------


	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Usuwanie przez okres: " << time_spent << endl << endl;


	//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	system("pause");
}


//------------------------------Funkcje-----------------------------------------------------------


void wstawianie(Drzewo*&root, int N) {
	//srand(time(NULL));
	int los;
	for (int i = 0; i < N; i++) {
		
		los = ((rand()*rand()) % 100000);
		dodaj_wezel(root, los);
	}
	cout << "W liscie jest " << N - licz_wstawiane_klucze << " elementow" << endl;
	licz_wstawiane_klucze = 0;
}

void wstawianie_naprzemienna(Drzewo*&root, int N, int s) {
	
	int nie_parzyste;
	int los;

	los = ((rand()*rand()) % 100000);
	dodaj_wezel(root,los);

	nie_parzyste = 1;
	int licz = 1;
	for (int i = 0; i < N - 1; i++) {

		if (i + 1 == nie_parzyste) {
			dodaj_wezel(root,licz);
			licz = licz + 1;
		}
		else {
			nie_parzyste = nie_parzyste + 2;
			los = ((rand()*rand()) % 100000);
			dodaj_wezel(root,los);
		}
	}
	cout << "W liscie jest " << N - licz_wstawiane_klucze << " elementow" << endl;
	licz_wstawiane_klucze = 0;
}

void dodaj_wezel(Drzewo*&root, int klucz) {


	if (root == NULL) {
		root = new Drzewo();
		root->klucz = klucz;
		root->lewy_potomek = NULL;
		root->prawy_potomek = NULL;
	}
	else
	{
		Drzewo *obsluga_klucza;
		obsluga_klucza = root;

		Drzewo *wezel_biezacy;
		wezel_biezacy = root;

		Drzewo *nowy_wezel;
		nowy_wezel = new Drzewo();

		nowy_wezel->klucz = klucz;
		nowy_wezel->lewy_potomek = NULL;
		nowy_wezel->prawy_potomek = NULL;


		bool x = true;
		while (x) {

			if (obsluga_klucza == NULL) {
				x = false;
			}
			else if (obsluga_klucza->klucz < klucz)
			{
				obsluga_klucza = obsluga_klucza->prawy_potomek;
				
			}
			else if (obsluga_klucza->klucz > klucz)						//sprawdza czy klucz juz istnieje
			{
				obsluga_klucza = obsluga_klucza->lewy_potomek;
				
			}
			else if (obsluga_klucza->klucz == klucz) {
				//cout << "Klucz juz istnieje: " << klucz << endl;
				licz_wstawiane_klucze = licz_wstawiane_klucze + 1;
				return;
			}
		}


		bool obs_petla = true;

		while (obs_petla) {
			if (wezel_biezacy->klucz > klucz) {
				if (wezel_biezacy->lewy_potomek == NULL) {
					wezel_biezacy->lewy_potomek = nowy_wezel;
					obs_petla = false;
				}
				else {
					wezel_biezacy = wezel_biezacy->lewy_potomek;
				}
			}
			else if (wezel_biezacy->klucz < klucz) {
				if (wezel_biezacy->prawy_potomek == NULL) {
					wezel_biezacy->prawy_potomek = nowy_wezel;
					obs_petla = false;
				}
				else {
					wezel_biezacy = wezel_biezacy->prawy_potomek;
				}
			}

		}
	}

}

void szukanie(Drzewo*&root, int klucz) {
	Drzewo *obsluga_klucza;
	obsluga_klucza = root;
	bool x = true;
	while (x) {

		if (obsluga_klucza == NULL) {
			x = false;
			//cout << "Nie istnieje wyszukiwany klucz: " << klucz << endl;
		}
		else if (obsluga_klucza->klucz < klucz)
		{
			obsluga_klucza = obsluga_klucza->prawy_potomek;
		}
		else if (obsluga_klucza->klucz > klucz)
		{
			obsluga_klucza = obsluga_klucza->lewy_potomek;
		}
		else if (obsluga_klucza->klucz == klucz) {
			//cout << "Wyszukiwany klucz: " << klucz << " istnieje." << endl;
			licz_szukane_klucze = licz_szukane_klucze + 1;
			x = false;
		}
	}
}

int ile_znaleziono_kluczy(Drzewo*&root,int N) {
	int los;
	for (int i = 0; i < N; i++) {
		los = ((rand()*rand()) % 100000);
		szukanie(root,los);
	}
	cout << "Odszukano " << licz_szukane_klucze << " kluczy." << endl;
	return licz_szukane_klucze;
}

void usuwanie(Drzewo*&root, int x) {
	Drzewo *wezel_biezacy;
	Drzewo *rodzic;
	rodzic = NULL;
	wezel_biezacy = root;

	while (wezel_biezacy != NULL && x != wezel_biezacy->klucz) {
		rodzic = wezel_biezacy;
		if (wezel_biezacy->klucz < x) {
			wezel_biezacy = wezel_biezacy->prawy_potomek;
		}
		else if (wezel_biezacy->klucz > x) {
			wezel_biezacy = wezel_biezacy->lewy_potomek;
		}
	}

	if (wezel_biezacy == NULL) {
		//cout << "Nie ma takiego klucza: " << x << endl;
		return;
	}

	if (wezel_biezacy->prawy_potomek == NULL && wezel_biezacy->lewy_potomek == NULL) { //zerowany wezel jest lisciem, nie ma podrzew
		if (wezel_biezacy == root) {									// jezeli jest rootem wyzeruj
			delete root;
			root = NULL;											 //zerowany liœæ jest korzeniem
			licz_usuwane_klucze = licz_usuwane_klucze + 1;
			return;
		}
		if (rodzic->prawy_potomek == wezel_biezacy) {	// jezeli wezel jest prawym potomkiem i nie ma zadnych potomkow wyzeruj (lisc)
			rodzic->prawy_potomek = NULL;
			licz_usuwane_klucze = licz_usuwane_klucze + 1;
			return;
		}
		else if (rodzic->lewy_potomek == wezel_biezacy) {
			rodzic->lewy_potomek = NULL;				//// jezeli wezel jest lewym potomkiem i nie ma zadnych potomkow to wyzeruj
			licz_usuwane_klucze = licz_usuwane_klucze + 1;
			return;
		}
	}

	if (wezel_biezacy->prawy_potomek == NULL) {		//usuwany wezel ma tylko lewe poddrzewo
		if (wezel_biezacy == root) {					//usuwany korzen
			delete root;
			//licz_usuwane_klucze = licz_usuwane_klucze + 1;
			root = wezel_biezacy->lewy_potomek;

		}
		else if (rodzic->prawy_potomek == wezel_biezacy) { //jezeli prawy potomek rodzica jest taki sam jak element do usuniecia przypisz rodzicowi lewego potomka wezla
			rodzic->prawy_potomek = wezel_biezacy->lewy_potomek;
		}
		else if (rodzic->lewy_potomek == wezel_biezacy) {
			rodzic->lewy_potomek = wezel_biezacy->lewy_potomek;
		}
		licz_usuwane_klucze = licz_usuwane_klucze + 1;
		return;
	}


	if (wezel_biezacy->lewy_potomek == NULL) {		//usuwany jezeli wezel ma tylko prawe podrzewo
		if (wezel_biezacy == root) {			//jezeli usuwamy roota, przypisujemy rootowi prawego potomka usuwanego wezla
			delete root;
			licz_usuwane_klucze = licz_usuwane_klucze + 1;
			root = wezel_biezacy->prawy_potomek; //usuwany korzen
		}
		else if (rodzic->prawy_potomek == wezel_biezacy) {	//jezeli prawy potomek rodzica jest taki sam jak wezel do usuniecia przypisz rodzicowi lewego/prawego przodka wezla
			rodzic->prawy_potomek = wezel_biezacy->prawy_potomek;
		}
		else if (rodzic->lewy_potomek == wezel_biezacy) {
			rodzic->lewy_potomek = wezel_biezacy->prawy_potomek;
		}
		licz_usuwane_klucze = licz_usuwane_klucze + 1;
		return;
		
	}

	


	Drzewo *dziadek;
	dziadek = wezel_biezacy;
	Drzewo *dziecko;
	dziecko = wezel_biezacy->lewy_potomek;

	while (dziecko->prawy_potomek != NULL) { // usuwany wezel ma oba poddrzewa
		dziadek = dziecko; //szukanie ostatniego najwiekszego prawego potomka usuwanego wezlu
		dziecko = dziecko->prawy_potomek;
	}
	if (dziecko == wezel_biezacy->lewy_potomek) {	//poprzednik jest lewym potomkiem usuwanego wezla
		if (wezel_biezacy == root) {  // jezeli usuwane wezel jest rootem przypisz rootowi lewego potomka
			delete root;
			root = wezel_biezacy->lewy_potomek;//usuwany korzen
		}
		else if (rodzic->prawy_potomek == wezel_biezacy) { //jezeli prawy potomek rodzica jest taki sam jak wezel usuwany  przypisz lewego potomka wezla usuwanego
			rodzic->prawy_potomek = dziecko;
			dziecko->prawy_potomek = wezel_biezacy->prawy_potomek;
		}
		else if (rodzic->lewy_potomek == wezel_biezacy) {
			rodzic->lewy_potomek = dziecko;
			dziecko->prawy_potomek = wezel_biezacy->prawy_potomek;
		}
		licz_usuwane_klucze = licz_usuwane_klucze + 1;
		return;
	}
	Drzewo *wnuk;

	wnuk = dziecko->lewy_potomek;		//ewentualny potomek poprzednika   adopcja potomstwa poprzednika przez jego rodzica
	if (dziadek->prawy_potomek == dziecko) {	//poprzednik nie jest lewym potomiekm wezla tylko wnukiem lub pra wnukiem
		dziadek->prawy_potomek = wnuk;
	}
	else if (dziadek->lewy_potomek == dziecko) {
		dziadek->lewy_potomek = wnuk;
	}
	dziecko->lewy_potomek = wezel_biezacy->lewy_potomek;	//adopcja potomstwa usuwanego wezla przez jego poprzednika
	dziecko->prawy_potomek = wezel_biezacy->prawy_potomek;
	if (wezel_biezacy == root) {						// adopcja poprzednika przez rodzica usuwanego wezla
		delete root;
		root = dziecko;
	}
	else if (rodzic->prawy_potomek == wezel_biezacy) {
		rodzic->prawy_potomek = dziecko;
	}
	else if (rodzic->lewy_potomek == wezel_biezacy) {
		rodzic->lewy_potomek = dziecko;
	}
	licz_usuwane_klucze = licz_usuwane_klucze + 1;
	return;
}

int usun_wezly(Drzewo*&root,int N) {
	int los;
	for (int i = 0; i < N; i++) {
		los = ((rand()*rand()) % 100000);
		usuwanie(root,los);
	}
	cout << "Usunieto " << licz_usuwane_klucze << " kluczy." << endl;
	return licz_usuwane_klucze;
}
