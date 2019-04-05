//SDIZO IS1 210A LAB06
//Pawe³ Swora
//sp39447@zut.edu.pl

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<fstream>
#include<cstdlib>

using namespace std;

void inicjacja(int *&tablica,int rozmiar);
int funkcja_mieszajaca(int klucz,int rozmiar);
int kolizja(int klucz);
void usuwanie(int *&tablica, int rozmiar, int klucz);

void usuwanie_dwa(int *&tablica, int rozmiar, int klucz);

void wstawienie_nowego_elementu(int *&tablica, int rozmiar, int klucz, int &I);
void wstawienie_nowego_elementu_dwa(int *&tablica, int rozmiar, int klucz, int &I);
void wstawienie(int *&tablica, int ilosc_elementow, int rozmiar);
void wstawienie_dwa(int *&tablica, int ilosc_elementow, int rozmiar);
void szukaj(int *&tablica, int rozmiar, int klucz, int i);
void szukaj_dwa(int *&tablica, int rozmiar, int klucz, int i);
void wyswietlanie(int *&tablica, int min, int max);



void main() {
	
	int mieszanie;
	int X, k1, k2, k3, k4, o = 0;
	fstream plik("inlab06.txt", ios::in);
	if (plik.good()) {
		plik >> X;
		plik >> k1;
		plik >> k2;
		plik >> k3;
		plik >> k4;
		plik.close();
	}

	mieszanie =1;

	if (mieszanie == 1) {

		clock_t begin, end;
		double time_spent;
		begin = clock();
		//------------------------------------------------------------------------------------------
		int *Tab;
		int rozmiar = 1000;

		inicjacja(Tab, rozmiar);
		usuwanie(Tab, rozmiar, k1);
		wstawienie_nowego_elementu(Tab, rozmiar, k1, o);
		wyswietlanie(Tab, 0, 100);
		wstawienie(Tab, X, rozmiar);
		wstawienie_nowego_elementu(Tab, rozmiar, k2, o);
		wstawienie_nowego_elementu(Tab, rozmiar, k3, o);
		wstawienie_nowego_elementu(Tab, rozmiar, k4, o);
		wyswietlanie(Tab, 0, 100);
		wyswietlanie(Tab, 500, 600);
		usuwanie(Tab, rozmiar, k3);
		usuwanie(Tab, rozmiar, k4);
		wyswietlanie(Tab, 0, 100);
		wyswietlanie(Tab, 500, 600);

		

		delete Tab;
		//-----------------------------------------------------------------------------------------


		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "Program wykonywal sie przez okres: " << time_spent << endl << endl;

	}


	if (mieszanie == 2) {

		clock_t begin, end;
		double time_spent;
		begin = clock();
		//------------------------------------------------------------------------------------------
		int *Tab;
		int rozmiar = 1000;

		inicjacja(Tab, rozmiar);
		usuwanie_dwa(Tab, rozmiar, k1);
		wstawienie_nowego_elementu_dwa(Tab, rozmiar, k1, o);
		wyswietlanie(Tab, 0, 100);
		wstawienie_dwa(Tab, X, rozmiar);
		wstawienie_nowego_elementu_dwa(Tab, rozmiar, k2, o);
		wstawienie_nowego_elementu_dwa(Tab, rozmiar, k3, o);
		wstawienie_nowego_elementu_dwa(Tab, rozmiar, k4, o);
		wyswietlanie(Tab, 0, 100);
		wyswietlanie(Tab, 500, 600);
		usuwanie_dwa(Tab, rozmiar, k3);
		usuwanie_dwa(Tab, rozmiar, k4);
		wyswietlanie(Tab, 0, 100);
		wyswietlanie(Tab, 500, 600);

		

		delete Tab;
		//-----------------------------------------------------------------------------------------


		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "Program wykonywal sie przez okres: " << time_spent << endl << endl;

	}
	

	system("pause");
}


//------------------------------Funkcje-----------------------------------------------------------



void inicjacja(int *&tablica, int rozmiar) {
	tablica = NULL;
	if (tablica == NULL) {
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		tablica[i] = 0;
	}
}
}

int funkcja_mieszajaca(int klucz,int rozmiar) {
	int wynik;
	wynik = ((klucz % 1000) + (2^(klucz%10)+1))%997;
	//cout << "Klucz: " << klucz << endl;
	//cout << "Wynik mieszania " << wynik << endl;
	return wynik;	
}

int kolizja(int klucz) {
	int wynik;
	wynik = (3 * klucz) % 19 + 1;
	//cout << "Wynik kolizji " << wynik << endl;
	return wynik;
}

void usuwanie(int *&tablica, int rozmiar, int klucz) {

	int pozycja = funkcja_mieszajaca(klucz, rozmiar);
	int pozycja_kolizja = kolizja(klucz);

	if (tablica[pozycja] != 0 && tablica[pozycja] != -1) {
		for (int i = 0; i < rozmiar; i++) {
			if (tablica[pozycja + i] == klucz) {
				if (pozycja + i > rozmiar) {
					for (int j = 0; j < rozmiar; j++) {
						if (tablica[j] == 0 || tablica[j] == -1) {
							tablica[j] = -1;
							cout <<"Usunieto klucz na pozycji "<< pozycja + i << " Klucz: " << tablica[pozycja + i] <<" Pierwotna pozycja byla wieksza od rozmiaru tablicy. "<< endl;
							return;
						}
					}
				}
				else {
					tablica[pozycja + i] = -1;
					cout <<"Usunieto klucz na pozycji "<< pozycja + i << " Klucz:  " << tablica[pozycja + i] << " Byla  kolizja|||" << endl;
					return;
				}
			}
		}
	}
	if (tablica[pozycja] == 0 || tablica[pozycja] == -1) {
		//tablica[pozycja] = klucz;
		cout << "Klucza nie ma w tablicy: " << klucz << endl << endl;
		return;
	}
}



void usuwanie_dwa(int *&tablica, int rozmiar, int klucz) {

	int pozycja = funkcja_mieszajaca(klucz, rozmiar);
	int pozycja_kolizja = kolizja(klucz);

	if (tablica[pozycja] != 0 && tablica[pozycja] != -1) {
		for (int i = 0; i < rozmiar; i++) {

			if (tablica[pozycja + (i * pozycja_kolizja)] == klucz) {
				if (pozycja + (i*pozycja_kolizja) > rozmiar) {
					if (tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] == 0 || tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] == -1) {
						tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] = -1;
						cout << "Usunieto klucz na pozycji " << (pozycja + (i * pozycja_kolizja)) - rozmiar << " Klucz: " << tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] << " Pierwotna pozycja byla wieksza od rozmiaru tablicy. " << endl;
						return;
					}
					else {
						for (int j = 0; j < rozmiar; j++) {
							if (tablica[j] != 0 || tablica[j] != -1) {
								tablica[j] = -1;
									cout << "Usunieto klucz na pozycji " << j << " Klucz: " << tablica[j] << " Pierwotna pozycja byla wieksza od rozmiaru tablicy 2. " << endl;
								return;
							}
						}
					}
				}
				else {
					tablica[pozycja + (i * pozycja_kolizja)] = -1;
					cout << "Usunieto klucz na pozycji " << pozycja + (i * pozycja_kolizja) << " Klucz:  " << tablica[pozycja + (i * pozycja_kolizja)] << " Byla  kolizja|||" << endl;
					return;
				}
			}
		}
	}
	if (tablica[pozycja] == 0 || tablica[pozycja] == -1) {
		//tablica[pozycja] = klucz;
		cout << "Klucza  nie ma w tablicy: " << klucz <<" Na pozycji: "<<pozycja<< endl << endl;
		return;
	}
}




void szukaj_dwa(int *&tablica, int rozmiar, int klucz, int I) {
	
	if (tablica == NULL) {
		tablica = new int(rozmiar);
		cout << "byl null " << endl;
	}
	int pozycja = funkcja_mieszajaca(klucz, rozmiar);
	int pozycja_kolizja = kolizja(klucz);
	for (int i = 0; i < rozmiar; i++) {
		if (tablica[i] == klucz) {
			cout << "Ten klucz: " << klucz << " juz istnieje |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			I = I - 1;
			return;
		}
	}
	if (tablica[pozycja] != 0 && tablica[pozycja] != -1) {
		for (int i = 0; i < rozmiar; i++) {

			if (tablica[pozycja + (i * pozycja_kolizja)] == 0 || tablica[pozycja + (i * pozycja_kolizja)] == -1) {
				if (pozycja + (i*pozycja_kolizja) > rozmiar) {
					if (tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] == 0 || tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] == -1) {
						cout << "znaleziono klucz na pozycji " << (pozycja + (i * pozycja_kolizja)) - rozmiar << " Klucz: " << tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] << " Pierwotna pozycja byla wieksza od rozmiaru tablicy. " << endl;
						return;
					}
					else {
						for (int j = 0; j < rozmiar; j++) {
							if (tablica[j] == 0 || tablica[j] == -1) {
								
									cout << "znaleziono klucz na pozycji " << j << " Klucz: " << tablica[j] << " Pierwotna pozycja byla wieksza od rozmiaru tablicy 2. " << endl;
								return;
							}
						}
					}
				}
				else {
					
					cout << "znaleziono klucz na pozycji " << pozycja + (i * pozycja_kolizja) << " Klucz:  " << tablica[pozycja + (i * pozycja_kolizja)] << " Byla  kolizja|||" << endl;
					return;
				}
			}
		}
	}
	if (tablica[pozycja] == 0 || tablica[pozycja] == -1) {
		
		cout << "znaleziono klucz: " << klucz <<" Na pozycji: "<<pozycja<< endl << endl;
		return;
	}
}


void szukaj(int *&tablica, int rozmiar, int klucz, int I) {
	int szukajj;

	int pozycja = funkcja_mieszajaca(klucz, rozmiar);
	int pozycja_kolizja = kolizja(klucz);

	for (int i = 0; i < rozmiar; i++) {
		if (tablica[i] == klucz) {
			cout << "Ten klucz: " << klucz << " juz istnieje |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			I = I - 1;
			return;
		}
	}


	if (tablica[pozycja] != 0 && tablica[pozycja] != -1) {
		for (int i = 0; i < rozmiar; i++) {
			if (tablica[pozycja + i] == 0 || tablica[pozycja + i] == -1) {
				if (pozycja + i > rozmiar) {
					for (int j = 0; j < rozmiar; j++) {
						if (tablica[j] == 0 || tablica[j] == -1) {
							
							cout <<"znaleziono klucz na pozycji "<< pozycja + i << " Klucz: " << tablica[pozycja + i] <<" Pierwotna pozycja byla wieksza od rozmiaru tablicy. "<< endl;
							return;
						}
					}
				}
				else {
					
					cout <<"znaleziono klucz na pozycji "<< pozycja + i << " Klucz:  " << tablica[pozycja + i] << " Byla  kolizja|||" << endl;
					return;
				}
			}
		}
	}
	if (tablica[pozycja] == 0 || tablica[pozycja] == -1) {
		cout << "znaleziono klucz: " << klucz << endl << endl;
		return;
	}


}


void wstawienie_nowego_elementu(int *&tablica, int rozmiar, int klucz,int &I) {
	if (tablica == NULL) {
		tablica = new int(rozmiar);
		cout << "byl null " << endl;
	}
	int pozycja = funkcja_mieszajaca(klucz, rozmiar);
	for (int i = 0; i < rozmiar; i++) {
		if (tablica[i] == klucz ) {
			cout << "Ten klucz: " << klucz << " juz istnieje |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			I = I - 1;
			return;
		}
	}
		if (tablica[pozycja] != 0 && tablica[pozycja] != -1) {
			for (int i = 0; i < rozmiar; i++) {
				if (tablica[pozycja + i] == 0 || tablica[pozycja + i] == -1) {
					if (pozycja + i > rozmiar) {
						for (int j = 0; j < rozmiar; j++) {
							if (tablica[j] == 0 || tablica[j] == -1) {
								tablica[j] = klucz;
								//cout <<"Dodano klucz na pozycji "<< pozycja + i << " Klucz: " << tablica[pozycja + i] <<" Pierwotna pozycja byla wieksza od rozmiaru tablicy. "<< endl;
								return;
							}
						}
					}
					else {
						tablica[pozycja + i] = klucz;
						//cout <<"Dodano klucz na pozycji "<< pozycja + i << " Klucz:  " << tablica[pozycja + i] << " Byla  kolizja|||" << endl;
						return;
					}
				}
			}
		}
		if (tablica[pozycja] == 0 || tablica[pozycja] == -1) {
			tablica[pozycja] = klucz;
			//cout << "Dodano klucz: " << klucz << endl << endl;
			return;
		}
}

void wstawienie(int *&tablica,int ilosc_elementow, int rozmiar) {
	srand(time(NULL));
	int losowa;
	for (int i = 0; i < ilosc_elementow; i++) {
		losowa = (rand() % 20001) + 20000;
		wstawienie_nowego_elementu(tablica, rozmiar, losowa, i);
	}
}

void wyswietlanie(int *&tablica, int min, int max) {
	for (int i = min; i <= max; i++) {
		cout << "Pozycja w tablicy: " << i << " Wartosc klucza " << tablica[i] << endl;
	}
}


void wstawienie_nowego_elementu_dwa(int *&tablica, int rozmiar, int klucz, int &I) {
	if (tablica == NULL) {
		tablica = new int(rozmiar);
		cout << "byl null " << endl;
	}
	int pozycja = funkcja_mieszajaca(klucz, rozmiar);
	int pozycja_kolizja = kolizja(klucz);
	for (int i = 0; i < rozmiar; i++) {
		if (tablica[i] == klucz) {
			cout << "Ten klucz: " << klucz << " juz istnieje |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			I = I - 1;
			return;
		}
	}
	if (tablica[pozycja] != 0 && tablica[pozycja] != -1) {
		for (int i = 0; i < rozmiar; i++) {
		
			if (tablica[pozycja + (i * pozycja_kolizja)] == 0 || tablica[pozycja + (i * pozycja_kolizja)] == -1) {
				if (pozycja + (i*pozycja_kolizja) > rozmiar) {
						if (tablica[(pozycja + (i * pozycja_kolizja))-rozmiar] == 0 || tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] == -1){
							tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] = klucz;
							//cout << "Dodano klucz na pozycji " << (pozycja + (i * pozycja_kolizja)) - rozmiar << " Klucz: " << tablica[(pozycja + (i * pozycja_kolizja)) - rozmiar] << " Pierwotna pozycja byla wieksza od rozmiaru tablicy. " << endl;
							return;
						}
						else {
							for (int j = 0; j < rozmiar; j++) {
								if (tablica[j] == 0 || tablica[j] == -1) {
									tablica[j] = klucz;
								//	cout << "Dodano klucz na pozycji " << j << " Klucz: " << tablica[j] << " Pierwotna pozycja byla wieksza od rozmiaru tablicy 2. " << endl;
									return;
								}
							}
						}
				}
				else {
					tablica[pozycja + (i * pozycja_kolizja)] = klucz;
					//cout << "Dodano klucz na pozycji " << pozycja + (i * pozycja_kolizja) << " Klucz:  " << tablica[pozycja + (i * pozycja_kolizja)] << " Byla  kolizja|||" << endl;
					return;
				}
			}
		}
	}
	if (tablica[pozycja] == 0 || tablica[pozycja] == -1) {
		tablica[pozycja] = klucz;
		//cout << "Dodano klucz: " << klucz <<" Na pozycji: "<<pozycja<< endl << endl;
		return;
	}
}

void wstawienie_dwa(int *&tablica, int ilosc_elementow, int rozmiar) {
	srand(time(NULL));
	int losowa;
	for (int i = 0; i < ilosc_elementow; i++) {
		losowa = (rand() % 20001) + 20000;
		wstawienie_nowego_elementu_dwa(tablica, rozmiar, losowa, i);
	}
}