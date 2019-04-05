//SDIZO I1 210A LAB03
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
	char tablica_znakow[10];
};

void inicjacja(Drzewo*&root);
void dodaj_wezel(Drzewo*&root, int klucz, int &i);
void wstawianie(Drzewo*&root, int X);
void szukanie(Drzewo*&root, int klucz);
void usuwanie(Drzewo*&root, int x);
void tryb_preorder(Drzewo*&root);
void tryb_inorder(Drzewo*&root);
void tryb_postorder(Drzewo*&root);

int licz_preorder = 0;
int licz_inorder = 0;
int licz_postorder = 0;

void main() {
	Drzewo *root;
	
	int X, k1, k2, k3, k4, i = 0;
	fstream plik("inlab03.txt", ios::in);
	if (plik.good()) {
		plik >> X;
		plik >> k1;
		plik >> k2;
		plik >> k3;
		plik >> k4;
		plik.close();
	}

	clock_t begin, end;
	double time_spent;
	begin = clock();
	//------------------------------------------------------------------------------------------

	inicjacja(root);
	
	usuwanie(root, k1);
	dodaj_wezel(root, k1, i);
	wstawianie(root, X);
	tryb_inorder(root);
	cout << "Liczba odwiedzonych wezlow: Inorder: " << licz_inorder << endl;
	licz_inorder = 0;
	tryb_preorder(root);
	cout << "Liczba odwiedzonych wezlow: Preorder: " << licz_preorder << endl;
	licz_preorder = 0;
	dodaj_wezel(root, k2, i);
	tryb_inorder(root);
	cout << "Liczba odwiedzonych wezlow: Inorder: " << licz_inorder << endl;
	licz_inorder = 0;
	dodaj_wezel(root, k3, i);
	dodaj_wezel(root, k4, i);
	usuwanie(root, k1);
	tryb_preorder(root);
	cout << "Liczba odwiedzonych wezlow: Preorder: " << licz_preorder << endl;
	licz_preorder = 0;
	szukanie(root, k1);
	usuwanie(root, k2);
	tryb_inorder(root);
	cout << "Liczba odwiedzonych wezlow: Inorder: " << licz_inorder << endl;
	licz_inorder = 0;
	usuwanie(root, k3);
	usuwanie(root, k4);
	
	
	//-----------------------------------------------------------------------------------------


	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Program wykonywal sie przez okres: " << time_spent << endl << endl;


	system("pause");
}


//------------------------------Funkcje-----------------------------------------------------------


void inicjacja(Drzewo*&root) {
	root = NULL;
}

void dodaj_wezel(Drzewo*&root, int klucz, int &i) {


	if (root == NULL) {
		root = new Drzewo();
		root->klucz = klucz;
		_itoa_s(klucz, root->tablica_znakow, 10);
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
		_itoa_s(klucz, nowy_wezel->tablica_znakow, 10);
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
				cout << "Klucz juz istnieje: " << klucz << endl;
				i--;
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
void wstawianie(Drzewo*&root, int X) {
	srand(time(NULL));
	for (int i = 0; i < X; i++) {
		int los;
		los = (rand() % 20001) - 10000;
		dodaj_wezel(root, los, i);
	}
}

void szukanie(Drzewo*&root, int klucz) {
	Drzewo *obsluga_klucza;
	obsluga_klucza = root;
	bool x = true;
	while (x) {

		if (obsluga_klucza == NULL) {
			x = false;
			cout << "Nie istnieje wyszukiwany klucz: " << klucz << endl;
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
			cout << "Wyszukiwany klucz: " << klucz << " istnieje." << endl;
			x = false;
		}
	}
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
		else if(wezel_biezacy->klucz > x) {
			wezel_biezacy = wezel_biezacy->lewy_potomek;
		}
	}

	if (wezel_biezacy == NULL) {
		cout << "Nie ma takiego klucza: " << x << endl;
		return;
	}
	
	if (wezel_biezacy->prawy_potomek == NULL && wezel_biezacy->lewy_potomek == NULL) { //zerowany wezel jest lisciem, nie ma podrzew
		if (wezel_biezacy == root) {									// jezeli jest rootem wyzeruj
			delete root;
			root = NULL;											 //zerowany liœæ jest korzeniem
			return;
		}
		if (rodzic->prawy_potomek == wezel_biezacy) {	// jezeli wezel jest prawym potomkiem i nie ma zadnych potomkow wyzeruj (lisc)
			rodzic->prawy_potomek = NULL;
			return;
		}
		else if(rodzic->lewy_potomek==wezel_biezacy) {
			rodzic->lewy_potomek = NULL;				//// jezeli wezel jest lewym potomkiem i nie ma zadnych potomkow to wyzeruj
			return;
		}
	}

	if (wezel_biezacy->prawy_potomek == NULL) {		//usuwany wezel ma tylko lewe poddrzewo
		if (wezel_biezacy == root) {					//usuwany korzen
			delete root;
			root = wezel_biezacy->lewy_potomek;

		}
		else if (rodzic->prawy_potomek == wezel_biezacy) { //jezeli prawy potomek rodzica jest taki sam jak element do usuniecia przypisz rodzicowi lewego potomka wezla
			rodzic->prawy_potomek = wezel_biezacy->lewy_potomek;
		}
		else if (rodzic->lewy_potomek == wezel_biezacy) {
			rodzic->lewy_potomek = wezel_biezacy->lewy_potomek;
		}
		return;
	}
	
		
	if (wezel_biezacy->lewy_potomek == NULL) {		//usuwany jezeli wezel ma tylko prawe podrzewo
			if (wezel_biezacy == root) {			//jezeli usuwamy roota, przypisujemy rootowi prawego potomka usuwanego wezla
				delete root;
				root = wezel_biezacy->prawy_potomek; //usuwany korzen
			}
			else if (rodzic->prawy_potomek == wezel_biezacy) {	//jezeli prawy potomek rodzica jest taki sam jak wezel do usuniecia przypisz rodzicowi lewego/prawego przodka wezla
				rodzic->prawy_potomek = wezel_biezacy->prawy_potomek;
			}
			else if(rodzic->lewy_potomek == wezel_biezacy) {
				rodzic->lewy_potomek = wezel_biezacy->prawy_potomek;
			}
			return;
		}
		
	if (x==root->klucz) {

		Drzewo *prawaG;
		prawaG = root->prawy_potomek;
		Drzewo *lewe = root->lewy_potomek;
		Drzewo *nowy_korzen = lewe;
		while (lewe->prawy_potomek != NULL) {								//szukanie najwiekszego elementu
			lewe = lewe->prawy_potomek;										//prawa galaz jest prawym potomkiem
		}																	//lewy potomek staje sie rootem

		lewe->prawy_potomek = prawaG;										//najwiekszy element ktory byl po prawej
		
		delete root;
		root = nowy_korzen;
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
		}
		else if (rodzic->lewy_potomek == wezel_biezacy) {
			rodzic->lewy_potomek = dziecko;
		}
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
	return;
}


void tryb_preorder(Drzewo*&root) {
	if (root != NULL) {
		cout << root->klucz << endl;
		licz_preorder = licz_preorder + 1;
		tryb_preorder(root->lewy_potomek);
		tryb_preorder(root->prawy_potomek);
	}
}

void tryb_inorder(Drzewo*&root) {
	if (root != NULL) {
		tryb_inorder(root->lewy_potomek);
		cout << root->klucz << endl;
		licz_inorder = licz_inorder + 1;
		tryb_inorder(root->prawy_potomek);
	}
}

void tryb_postorder(Drzewo*&root) {
	if (root != NULL) {
		tryb_postorder(root->lewy_potomek);
		tryb_postorder(root->prawy_potomek);
		cout << root->klucz << endl;
		licz_postorder = licz_postorder + 1;
	}
}
