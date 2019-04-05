#include<stdio.h>
#include<cstdlib>
#include <iostream>
#include <string>
#include<time.h>
#include<fstream>
using namespace std;
//<4
class Funkcje {
	public:
	virtual void wyswietlanie()=0;
	virtual void wpisz_dane_do()=0;								//klasa abstrakcyjna
};
class Sklep :public virtual Funkcje {
	string nazwa_sklepu;
	string pracownicy;
	string data;
public:
	virtual void wyswietlanie();
	virtual void wpisz_dane_do();
	Sklep();
	~Sklep();
};
class Laptop :public virtual Funkcje {
	friend class Serwis;											//more															//friend class Parametry;
	int cena;
	string marka;              //ASUS, MSI, LENOVO, APPLE, DELL, ACER, HP, DREAM_MACHINEE, HYPERBOOK, MICROSOFT, XIAOMI
	string procesor;       //intel,amd
	static int xtr;
	class Parametry {														//friend class Laptop;				//Dziêki temu mo¿na u¿yæ danych w private w funkcji wy¿ej parametry_laptopa
		string model;     //zennbooks ux303ub, ux410uq, ux430uq, y520, y700, ideapad 500, ideapad 700, aspire vx15, predator helios 300, predator x21, inspiron
		string rozdzielczosc;     //1366x768, 1920x1080, 2160x1440, 2560x1440, 3840x2160
		string wielkosc_matrycy;  // 11.6, 12.1, 12.5, 13.3, 14.1, 15.6, 17.3, 18.4, 21
		string rodzaj_matrycy;  //TN, IPS, MVA
		string rodzaj_dysku;   //ssd, hdd, sshd, ssd+hdd
		string pojemnosc_dysku; //128GB, 256GB, 512GB, 1TB, 1TB+128GB, 1TB+256GB
		string rodzaj_procesora;//Iintel i3,i5,i7 AMD A4, A6       I5 7200 I5 6200
		int ilosc_rdzeni;	 // 2,4
		string karta_graficzna; //nvidia gtx920m, gtx920mx, gtx930m, gtx930mx, gtx940m, gtx940mx, gtx945m, gtx950m, gtx960m, gtx965m, gtx970m, gtx980m, gtx150, gtx1050, gtx1050ti, gtx1060, gtx1070, gtx1080
		string ilosc_ramu;  // 2GB, 4GB, 6GB, 8GB, 12GB, 16GB
		string rodzaj_ramu; //DDR3, DDR4
		string waga;      // 1.2, 1.4, 2, 2.3 2.4, 2.5
		int gwarancja; //12, 24, 36
		string stan; //nowy u¿uwany, serwisowany
		string rodzaj_laptopa; // gameingowy, biznesowy, multimedialny	
	public:																									
		void dane(int &rozmiar);
		Parametry();
		~Parametry();
		Parametry(Parametry&tablica_para);																//1379 kopiuje parametry   
	};
public:
	Parametry *danee;
	void ile_bylo_konstruktorow();
	virtual void wpisz_dane_do();
	virtual void wyswietlanie();
	void wczytaj_plik(int elementy, int x, int y);													// wczytuje plik z podstawowymi danymi		
	Laptop();
	~Laptop();
};
class Serwis :public Laptop, public Sklep {																										//	friend class Laptop;																	//less
	int uszk_matryca;
	int nowa_cena;
	int uszk_procesor;
	int uszk_klawiatura;
	Laptop **obniz1;											//obnizka 1																									
	static const int promocja_l = 5;
	static const int okres = 10;
	static Sklep* info_prom;																		// Dopisanie osoby odpowiedzialnej za promocje czyli pracownika sklepu
	static int get_promocja();																		// Pobranie promocji
	static int get_okres();																			// Pobranie okresu
	static Sklep *get_info_prom(int elementy);														// Dopisanie osoby odpowiedzialnej za promocje czyli pracownika sklepu
	Laptop *a1;																						// Agregacja do obs³ugi laptopa
	int b2[10];
public:
	friend ostream& operator<<(ostream& out, Serwis& obiekt);
	friend istream& operator>>(istream& in, Serwis& obiekt);
	const Serwis& operator=(const Serwis& obiekt) {
		this->uszk_klawiatura = obiekt.uszk_klawiatura;
		this->uszk_matryca = obiekt.uszk_matryca;
		this->uszk_procesor = obiekt.uszk_procesor;
		this->nowa_cena = obiekt.nowa_cena;
		return *this;
	}
	int operator()(int x) {
		uszk_klawiatura += x;
	}
	int operator[](int index) {
		if (index < 0 || index>100) {
			cout << "Zly zakres " << endl;
			return -1;
		}
		else {
			return b2[index];
		}
	}
	void dodaj_laptopy_do_serwisu(void) {															//Dodanie laptopa do usterek
		a1->wpisz_dane_do();
		a1->wyswietlanie();
	}
	void pokaz_lap_w_serwisie(void) {
		a1->wyswietlanie();
	}
	Serwis(int roz) {
		for (int i = 0; i < roz; i++) {
			b2[i] = roz;
		}
	}																												//Serwis(Laptop**&aggr);
	virtual void wpisz_dane_do();
	virtual void wyswietlanie();
	void obnizka_jedna(Laptop**&tablica_laptopow, int &rozmiar, int elementy);								// Obni¿a 1 cene z laptopów z Laptopów
	void promocja(Laptop**&tablica_laptopow, int &rozmiar, int elementy, Sklep*&tab);						//Obni¿a wiele cen z laptopów z Laptopów + static wysietla ze promoocja i ile i okres
	friend void serwis_uszkodzenie(Serwis **&tab, int &rozmiar);													//Oniza cene jaka tzreba placic za uszkodzenie
	Serwis();
	~Serwis();																										//Konstruktor kopiujacy
	Serwis(Serwis*&naprawa, int ele){																																				
		cout << endl << "kopia" << endl;																						
		uszk_klawiatura = naprawa->uszk_klawiatura;
		uszk_matryca = naprawa->uszk_matryca;
		uszk_procesor = naprawa->uszk_procesor;
		a1 = new Laptop[ele];
		a1 = naprawa->a1;																							
		a1->cena = naprawa->a1->cena;    
		a1->marka = naprawa->a1->marka;
		a1->procesor = naprawa->a1->procesor;													
		cout << endl << "kopia" << endl;
	}
};
namespace Kontakty {
	class Kontakt {

		string numer_tele;
		string adres;
		int wielkosc;
		int *tab_p;
	public:
		
		int operator[](int index) {
			if (index < 0 || index>100) {
				cout << "Zly zakres " << endl;
				return -1;
			}
			else {
				return tab_p[index];
			}
		}

		friend ostream& operator<<(ostream& out, Kontakt& obiekt);
		friend istream& operator>>(istream& in, Kontakt& obiekt);

		void wyswietlanie();
		void wpisz_dane_do();
		Kontakt(Kontakt&tab);
		Kontakt();
		~Kontakt();
	};

	//Kontakt *tab;


	//----------------------- KONTAKT --------------------------------------------------------
	void tworzenie_alokacja(Kontakt*&tablica_telefonow, int rozmiar);
	void usuwanie(Kontakt*&tablica_kontaktow);

	void wpisz_dane_do(Kontakt*&tablica_kontaktow, int rozmiar);

	//-----------------------^^ MOD KONTAKT ^^------------------------------------------------------
	void dodaj_rekord(Kontakt*&tablica_kontaktow, int &rozmiar);
	void usun_ostatni_rekord(Kontakt*&tablica_kontaktow, int &rozmiar);
	void dodaj_do_tablicy(Kontakt*&tablica_kontaktow, int nowa_pozycja, int &rozmiar);
	void ususn_z_tablicy(Kontakt*&tablica_kontaktow, int pozycja_usuwana, int &rozmiar);
	void Kontakt::wyswietlanie() {
		cout << " Telefon: " << numer_tele << "  " << "Adres: " << adres << endl;
	}
	void wyswietlanie(Kontakt*&tablica_kontaktow, int rozmiar) {
		for (int i = 0; i < rozmiar; i++) {
			tablica_kontaktow[i].wyswietlanie();								 // " Cena: " << tablica_usterek[i]->usz_plyta_glowna << " Procesor " << tablica_usterek[i]->usz_plyta_glowna << endl;
		}
	}

	void ususn_z_tablicy(Kontakt*&tablica_kontaktow, int pozycja_usuwana, int &rozmiar) {
		Kontakt *nowa_tab_kon;
		rozmiar = rozmiar - 1;
		tworzenie_alokacja(nowa_tab_kon, rozmiar);
		pozycja_usuwana = pozycja_usuwana - 1;
		for (int i = 0; i < pozycja_usuwana; i++) {
			nowa_tab_kon[i] = tablica_kontaktow[i];

		}
		for (int i = pozycja_usuwana + 1; i < rozmiar + 1; i++) {
			nowa_tab_kon[i - 1] = tablica_kontaktow[i];
		}
		usuwanie(tablica_kontaktow);
		tablica_kontaktow = nowa_tab_kon;
	}

	void usun_ostatni_rekord(Kontakt*&tablica_kontaktow, int &rozmiar) {
		cout << "Usunieto ostatni kontakt " << endl;
		Kontakt *nowa_tab_kon;
		int s;
		s = rozmiar - 1;
		tworzenie_alokacja(nowa_tab_kon, s);
		for (int i = 0; i < s; i++) {
			nowa_tab_kon[i] = tablica_kontaktow[i];
		}
		usuwanie(tablica_kontaktow);
		rozmiar = rozmiar - 1;
		tablica_kontaktow = nowa_tab_kon;
	}


	void dodaj_do_tablicy(Kontakt*&tablica_kontaktow, int nowa_pozycja, int &rozmiar) {
		Kontakt *nowa_tab_kon;
		rozmiar = rozmiar + 1;
		tworzenie_alokacja(nowa_tab_kon, rozmiar);
		nowa_pozycja = nowa_pozycja - 1;

		for (int i = 0; i < nowa_pozycja; i++) {
			nowa_tab_kon[i] = tablica_kontaktow[i];

		}
		nowa_tab_kon[nowa_pozycja].wpisz_dane_do();

		for (int i = nowa_pozycja + 1; i < rozmiar; i++) {
			nowa_tab_kon[i] = tablica_kontaktow[i - 1];
		}
		tablica_kontaktow = nowa_tab_kon;
	}

	void usuwanie(Kontakt*&tablica_kontaktow) {
		delete[] tablica_kontaktow;
		tablica_kontaktow = nullptr;
	}


	void tworzenie_alokacja(Kontakt*&tablica_kontaktow, int rozmiar) {
		tablica_kontaktow = new Kontakt[rozmiar];
	}
	void Kontakt::wpisz_dane_do() {
		cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
		cout << "                                  " << endl;
		cout << "||                             || " << endl;
		cout << "||    Podaj numer telefonu     || " << endl;
		cout << "||                             || " << endl;
		cout << "             ";
		cin >> numer_tele;
		cout << "||                             || " << endl;
		cout << "||        Podaj adres          || " << endl;
		cout << "||                             || " << endl;
		cout << "             ";
		cin >> adres;
		cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
	}
	void wpisz_dane_do(Kontakt*&tablica_kontaktow, int rozmiar) {
		for (int i = 0; i < rozmiar; i++) {
			cout << " id: " << i + 1 << endl;
			tablica_kontaktow[i].wpisz_dane_do();
		}
	}

	void dodaj_rekord(Kontakt*&tablica_kontaktow, int &rozmiar) {
		Kontakt *nowa_tab_kon;
		int s;
		s = rozmiar + 1;
		tworzenie_alokacja(nowa_tab_kon, s);
		for (int i = 0; i < rozmiar; i++) {
			nowa_tab_kon[i] = tablica_kontaktow[i];
		}
		nowa_tab_kon[rozmiar].wpisz_dane_do();

		usuwanie(tablica_kontaktow);
		rozmiar = rozmiar + 1;
		tablica_kontaktow = nowa_tab_kon;
	}
	Kontakt::Kontakt(Kontakt&tab) {
		numer_tele = tab.numer_tele;
		adres = tab.adres;
		//cout << "Konstruktor kopiujacy " << endl;
	};
	Kontakt::Kontakt() {
		//cout << "Wartosci domyslne: " << endl;
		tab_p = new int[48];
		tab_p[2] = 3;
		numer_tele = "432-532-526";
		adres = "kwiatowa";
		//cout << "Numer telefonu: " << numer_tele << " adrs: " << adres << endl;
	}
	Kontakt::~Kontakt() {
		delete tab_p;
		numer_tele = "brak";
		adres = "brak";
		//cout << "Numer telefonu: " << numer_tele << " adrs: " << adres << endl;
	}
	ostream& operator<<(ostream& out, Kontakt& obiekt) {
		cout << " telefon:  " << obiekt.numer_tele << " Adres: " << obiekt.adres << endl;
		return out;
	}
	istream& operator>>(istream& in, Kontakt& obiekt) {
		cout << "Teelfon:  " << endl;
		in >> obiekt.numer_tele;
		cout << "Adres: " << endl;
		in >> obiekt.adres;
		return in;
	}
}

class Naprawa {																	//1041
public:
	virtual void pokazn() = 0;
	virtual void podajn() = 0;
};
class Oprogramowanie: public virtual Naprawa {
	int system;
	int sterowniki;
public:
	void virtual pokazn() {
		cout << "Koszt za naprawe systemu: " << system << endl;
		cout << "Koszt za naprawe sterownikow: " << sterowniki << endl;
	}
	void virtual podajn() {
		cout << "Podaj cene za naprawe systemu: " << endl;
		cin >> system;
		cout << "Podaj cene za naprawe sterownikow: " << endl;
		cin >> sterowniki;
	}
	Oprogramowanie() {
		system = 150;
		sterowniki = 250;
	}
};
class Akcesoria: public virtual Naprawa {
	int klawiatura;
	int touchpad;
	int matryca;
public:
	void virtual pokazn() {
		cout << "Koszt za naprawe klawiatury: " << klawiatura << endl;
		cout << "Koszt za naprawe touchpad: " << touchpad << endl;
		cout << "Koszt za naprawe matrycy: " << matryca << endl;
	}
	void virtual podajn() {
		cout << "Podaj cene za naprawe klawiatury: " << endl;
		cin >> klawiatura;
		cout << "Podaj cene za naprawe tuchpada: " << endl;
		cin >> touchpad;
		cout << "Podaj cene za naprawe matrycy: " << endl;
		cin >> matryca;
	}
	Akcesoria() {
		klawiatura = 100;
		touchpad = 200;
		matryca = 300;
	}
};
class Komponety :public Oprogramowanie, public Akcesoria{
	int karta_graficzna;
	int karta_dzwiekowa;
	int plyta_glowna;
public:
	void virtual pokazn() {
		cout << "Koszt za naprawe karty graficznej: " << karta_graficzna << endl;
		cout << "Koszt za naprawe karty dzwiekowej " << karta_dzwiekowa << endl;
		cout << "Koszt za naprawe plyty glownej: " << plyta_glowna << endl;
		cout << endl << "Odziedziczane dane z akcesoria: " << endl;
		Akcesoria::pokazn();
		cout << endl << "Odziedziczane dane z oprogramowania: " << endl;
		Oprogramowanie::pokazn();
	}
	void virtual podajn() {
		cout << "Podaj cene za naprawe karty graficznej: " << endl;
		cin >> karta_graficzna;
		cout << "Podaj cene za naprawe karty dzwiekowej: " << endl;
		cin >> karta_dzwiekowa;
		cout << "Podaj cene za naprawe plyty glownej: " << endl;
		cin >> plyta_glowna;
	}
	Komponety() {
		plyta_glowna = 450;
		karta_dzwiekowa = 550;
		karta_graficzna = 560;
	}
};
int Laptop::xtr = 0;
Sklep*Serwis::info_prom;
Sklep*Serwis::*get_info_prom;

//------------------------- LAPTOP --------------------------------------------------------
void tworzenie_alokacja(Laptop**&tablica_laptopow, int rozmiar);
void usuwanie(Laptop**&tablica_laptopow, int rozmiar);
void wpisz_dane_do(Laptop**&tablica_laptopow, int rozmiar);
void wyswietlanie(Laptop**&tablica_laptopow, int rozmiar);

void parametry_laptopa(Laptop**&tablica_laptopow, int &rozmiar);								//wyswietlanie konkretnego laptopa przy jego parametrach



//----------------------^^ MOD LAPTOP ^^------------------------------------------------------
void dodaj_rekord(Laptop**&tablica_laptopow, int &rozmiar);
void usun_ostatni_rekord(Laptop**&tablica_laptopow, int &rozmiar);
void dodaj_do_tablicy(Laptop**&tablica_laptopow, int nowa_pozycja, int &rozmiar);
void ususn_z_tablicy(Laptop**&tablica_laptopow, int pozycja_usuwana, int &rozmiar);
void dodaja_na_losowa_pozycje(Laptop**&tablica_laptopow, int &rozmiar);
void wczytaj_pliki(Laptop**&tabs, int &rozmiar);

//----------------------------- SKLEP -----------------------------------------------------
void tworzenie_alokacja(Sklep**&tablica_sklepu, int rozmiar);
void wyswietlanie(Sklep*&tablica_sklepu, int rozmiar);
void usuwanie(Sklep**&tablica_sklepu, int rozmiar);
void wpisz_dane_do(Sklep**&tablica_sklepu, int rozmiar);

//-------------------------^^ MOD SKLEP ^^--------------------------------------------------------
void dodaj_rekord(Sklep**&tablica_sklepu, int &rozmiar);
void usun_ostatni_rekord(Sklep**&tablica_sklepu, int &rozmiar);
void dodaj_do_tablicy(Sklep**&tablica_sklepu, int nowa_pozycja, int &rozmiar);
void ususn_z_tablicy(Sklep**&tablica_sklepu, int pozycja_usuwana, int &rozmiar);


//--------------------------- USTERKA -----------------------------------------------------
void tworzenie_alokacja(Serwis**&tablica_serwisu, int rozmiar);
void usuwanie(Serwis**&tablica_serwisu, int rozmiar);
void wyswietlanie(Serwis**&tablica_serwisu, int rozmiar);
void wpisz_dane_do(Serwis**&tablica_serwisu, int rozmiar);


//__________________________________________________________________________________________

int main()
{
	Laptop **lap_tab = nullptr, do_funkcji_lap;
	Sklep *skl_tab = nullptr, do_funkcji_skl;
	Serwis **ust_tab = nullptr, do_funkcji_ust;
	Kontakty::Kontakt *tablica_kon = nullptr, do_funkcji_kon;
	int ile_u, miejsce_w_tablicy, do_cena, miejsce_w_tablicy2, miejsce_w_tablicy3, miejsce_w_tablicy4, pole_z_menu1, pole_z_menu2, pole_z_menu3, pole_z_menu4, wielkosc_tab1, wielkosc_tab2 = 0, wielkosc_tab3, ile_zmian, wielkosc_tab4, kopia_kon, ile_zmian2, podany_rozmiar, roz=0,d2 = 2, nn=3;
	bool x = true;
	cout << "Ile laptopow" << endl;
	cin >> podany_rozmiar;
	tworzenie_alokacja(lap_tab, podany_rozmiar);
	wczytaj_pliki(lap_tab, podany_rozmiar);
	Laptop obb;																								
	Serwis**agr;
	tworzenie_alokacja(agr, roz);
	Serwis ob, ob1, ob2;																										
	Serwis **koppiowany;
	while (true) {
	skok:
		cout << "_________________________________" << endl;
		cout << "||  Sklep/serwis z laptopami.  ||" << endl;
		cout << "||    Wybierz opcje z Menu.    || " << endl;
		cout << "|| --------------------------- || " << endl;
		cout << "||                             || " << endl;
		cout << "||  1: Kontakt                 ||" << endl;
		cout << "|| --------------------------- || " << endl;
		cout << "||                             || " << endl;
		cout << "||  2: Zarzadzanie laptopami   ||" << endl;
		cout << "|| --------------------------- || " << endl;
		cout << "||                             || " << endl;
		cout << "||  3: Zarzadzanie serwisem    ||" << endl;
		cout << "|| --------------------------- || " << endl;
		cout << "||                             || " << endl;
		cout << "||  4: Koniec programu         ||" << endl;
		cout << "|| --------------------------- || " << endl;
		cout << "||                             || " << endl;
		cout << "||  5: Sklep  (zlicz kons)     ||" << endl;
		cout << "|| --------------------------- || " << endl;
		cout << "_________________________________" << endl;
		cin >> pole_z_menu1;
		switch (pole_z_menu1) {
		case 1:
			while (true) {
				cout << "__________________________________" << endl;
				cout << "||    Zarzadzanie Kontaktami.   ||" << endl;
				cout << "||    Wybierz opcje z Menu.     || " << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  1: Dodaj adresy i telefony  ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  2: Usuwanie                 ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  3: Koniec programu          ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  4: Powrot                   ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  5: Wyswietlanie             ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  6: Dodaj nowy rekord        ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  7: Ususn ostatni element    ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  8: Dodaj w konkretne miejsce||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  9: Usun wybrane miejsce     ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "||                              || " << endl;
				cout << "||  10: Kopiowanie              ||" << endl;
				cout << "|| ---------------------------- || " << endl;
				cout << "__________________________________" << endl;
				cin >> pole_z_menu4;
				switch (pole_z_menu4) {
				default: cout << "zly typ danych" << endl;
				case 1:
					cout << "Podaj ile kontaktow chcesz dodac" << endl;
					cin >> wielkosc_tab1;
					cout << "Podaj dane kontaktowe: " << endl << endl;
					Kontakty::tworzenie_alokacja(tablica_kon, wielkosc_tab1);
					Kontakty::wpisz_dane_do(tablica_kon, wielkosc_tab1);
					break;
				case 2:
					if (tablica_kon == nullptr) {
						cout << "Nie mozna usunac bo w pamieci nic nie ma. " << endl;
					}
					else {
						Kontakty::usuwanie(tablica_kon);
						cout << "Usunieto" << endl;	
					}
					break;
				case 3:
					exit(0);
					break;
				case 4:
					goto skok;
					break;
				case 5:
					cout << "||                             || " << endl;
					cout << "                                  " << endl;
					if (tablica_kon == nullptr) {
						cout << "Nie mozna nic wyswietlic bo pamiec jest pusta. " << endl;
					}
					else {
						Kontakty::wyswietlanie(tablica_kon, wielkosc_tab1);
					}
					cout << "                                  " << endl;
					cout << "||                             || " << endl;
					break;
				case 6:
					Kontakty::dodaj_rekord(tablica_kon, wielkosc_tab1);
					break;
				case 7:
					Kontakty::usun_ostatni_rekord(tablica_kon, wielkosc_tab1);
					break;
				case 8:
					cout << "Na ktora pozycje chcesz dodac nowy kontakt " << endl;
					cin >> miejsce_w_tablicy2;
					Kontakty::dodaj_do_tablicy(tablica_kon, miejsce_w_tablicy2, wielkosc_tab1);
					break;
				case 9:
					cout << "Ktory kontakt chcesz usunac z tablicy? " << endl;
					cin >> miejsce_w_tablicy4;
					Kontakty::ususn_z_tablicy(tablica_kon, miejsce_w_tablicy4, wielkosc_tab1);
					break;
				case 10:
					Kontakty::Kontakt *kopiuj(tablica_kon);
					cout << "Ktory element z kontaktow chcesz skopiowac? " << endl;
					cin >> kopia_kon;
					kopiuj[kopia_kon - 1].wyswietlanie();
					cin >> do_funkcji_kon;
					cout << do_funkcji_kon;
					break;
				}
			}
			break;
		case 2:
			while (true) {
				cout << "___________________________________" << endl;
				cout << "||    Zarzadzanie laptopami.     ||" << endl;
				cout << "||    Wybierz opcje z Menu.      || " << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  1: Aby wprowadzic dane       ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  2: Aby wyswietlic dane       ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  3: Aby usunac                ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  4: Powrot                    ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  5: Aby dodac nowy rekord     ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  6: Aby usunac ostatni rekord ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  7: Dodaj w konkretne miejsce ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  8: Usun wybranego laptopa    ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "||  9: Dodanie na losowa pozycje ||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "||                               || " << endl;
				cout << "|| 10: Pokaz dodatkowe informacje||" << endl;
				cout << "|| ----------------------------- || " << endl;
				cout << "___________________________________" << endl;
				cin >> pole_z_menu2;
				switch (pole_z_menu2) {
				case 1:
					cout << "Podaj ile wprowadzisz laptopow do bazy danych " << endl;
					cin >> wielkosc_tab2;
					tworzenie_alokacja(lap_tab, wielkosc_tab2);
					wpisz_dane_do(lap_tab, wielkosc_tab2);
					break;
				case 2:
					cout << "||                             || " << endl;
					cout << "                                  " << endl;
					if (lap_tab == nullptr) {
						cout << "Nie mozna nic wyswietlic bo pamiec jest pusta. " << endl;
					}
					else {
						if (wielkosc_tab2 == 0) {
							wyswietlanie(lap_tab, podany_rozmiar);
							wielkosc_tab2 = podany_rozmiar;
						}
						else {
							wyswietlanie(lap_tab, wielkosc_tab2);
						}
					}
					cout << "                                  " << endl;
					cout << "||                             || " << endl;
					break;
				case 3:
					cout << "||                             || " << endl;
					if (lap_tab == nullptr) {
						cout << "Nie mozna usunac bo w pamieci nic nie ma. " << endl;
					}
					else {
						usuwanie(lap_tab, wielkosc_tab2);
					}
					cout << "||          usunieto           || " << endl;
					break;
				case 4:
					goto skok;
					break;
				case 5:
					dodaj_rekord(lap_tab, wielkosc_tab2);
					break;
				case 6:
					usun_ostatni_rekord(lap_tab, wielkosc_tab2);
					break;
				case 7:
					cout << "Na ktore miejsce w tablicy chcesz dodac nowy element? " << endl;
					cin >> miejsce_w_tablicy;
					dodaj_do_tablicy(lap_tab, miejsce_w_tablicy, wielkosc_tab2);
					break;
				case 8:
					cout << "Jakie miejsce w tablicy chcesz usunac" << endl;
					cin >> miejsce_w_tablicy3;
					ususn_z_tablicy(lap_tab, miejsce_w_tablicy3, wielkosc_tab2);
					cout << "Usunieto" << endl;
					break;
				case 9:
					dodaja_na_losowa_pozycje(lap_tab, wielkosc_tab2);
					break;
				case 10:
					if (lap_tab == nullptr) {
						cout << "Nie ma laptopow w bazie." << endl;
					}
					else {
						cout << "Ile chcesz podac laptopow? " << endl;
						cin >> wielkosc_tab4;
						if (wielkosc_tab2 < wielkosc_tab4) {
							cout << "Nie ma tylu laptopow." << endl;
						}
						else
							parametry_laptopa(lap_tab, wielkosc_tab4);
					}
					break;
				default: cout << "poza zakresem" << endl;
				}
			}
			break;
		case 3:
			while (true) {
				cout << "_________________________________" << endl;
				cout << "||    Zarzadzanie serwisem .    ||" << endl;
				cout << "||    Wybierz opcje z Menu.     || " << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  1: Obnizka jednej ceny      ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  2: kop                      ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  3: Wpisywanie laptopow      ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  4: Powrot                   ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  5:Promocja:obnizka wielu cen||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  6: Informacje(promocja)     ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  7: Kopiowanie lap           ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  8: Obnizenie naprawy        ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  9: Wysietlenie calosci      ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  10: Opera                   ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "||                              || " << endl;
				cout << "||  11: Naprawa                 ||" << endl;
				cout << "|| ---------------------------  || " << endl;
				cout << "_________________________________" << endl;
				cin >> pole_z_menu3;
				switch (pole_z_menu3) {
				case 1:
					cout << "Ktory element w tablicy z cenami laptopow chcesz obnizyc" << endl;
					cin >> ile_zmian2;
					if (lap_tab == nullptr) {
						cout << "Brak danych. " << endl;
					}
					else
						do_funkcji_ust.obnizka_jedna(lap_tab, wielkosc_tab2, ile_zmian2);
					break;
				case 2:
					if (roz == 0) {
						cout << "Nie ma elementów" << endl;
					}															
					else {
						if (x == true) {
							Serwis **kopiuj_s(agr);
							for (int i = 0; i < roz; i++)
								kopiuj_s[i]->wyswietlanie();
						}	
					}
					break;
				case 3:
					usuwanie(agr, roz);															
					roz = 0;
					cout << "Podaj rozmiar " << endl;
					cin >> roz;
					tworzenie_alokacja(agr, roz);
					for (int i = 0; i < roz; i++) {
						agr[i]->dodaj_laptopy_do_serwisu();
						agr[i]->wpisz_dane_do();
					}
					break;
				case 4:
					goto skok;
					break;
				case 5:
					cout << "ile produktow chcesz zmienic?" << endl;
					cin >> ile_zmian;
					if (lap_tab == nullptr) {
						cout << "Brak danych. " << endl;
					}
					else
						do_funkcji_ust.promocja(lap_tab, wielkosc_tab2, ile_zmian, skl_tab);
					break;
				case 6:
					cout << "||                             || " << endl;
					if (skl_tab == nullptr || lap_tab == nullptr) {
						cout << "Brak danych. " << endl;
					}
					else {

						cout << "Za promocje odpowiedzialny jest: " << endl;
						wyswietlanie(skl_tab, ile_zmian);

						cout << endl;
						wyswietlanie(lap_tab, ile_zmian);
					}
					cout << "||                             || " << endl;
					break;
				case 7:																						
					for (int i = 0; i < roz; i++) {
						agr[i]->pokaz_lap_w_serwisie();						
					}																											
					if (true) {																										
						koppiowany = new Serwis*[roz];
						for (int i = 0; i < roz; i++) {
							koppiowany[i] = new Serwis(*agr,roz);
						}																											
						for (int i = 0; i < roz; i++) {
							koppiowany[i]->pokaz_lap_w_serwisie();
							koppiowany[i]->wyswietlanie();
						}
					}
					break;
				case 8:
					serwis_uszkodzenie(agr, roz);
					break;
				case 9:
					for (int i = 0; i < roz; i++) {
						agr[i]->pokaz_lap_w_serwisie();
						cout << endl;
						agr[i]->wyswietlanie();
						cout << endl;
					}
					break;
				case 10:
					cin >> ob;
					ob2 = ob1 = ob;
					cout << ob << endl;
					cout << ob1 << endl;
					cout << ob2 << endl;
					if (true) {
						Serwis obiekt(d2);
						cout <<"Opera []:"<< obiekt[1];
					}
					break;
				case 11:
					if (true) {
						Naprawa **tablica = new Naprawa*[nn];
						tablica[0] = new Oprogramowanie;
						tablica[1] = new Akcesoria;
						tablica[2] = new Komponety;
						for (int i = 0; i < nn; i++) {
							tablica[i]->podajn();
						}
						for (int i = 0; i < nn; i++) {
							tablica[i]->pokazn();
						}
						delete[] tablica;
					}
					break;
				default: cout << "poza zakresem" << endl;
				}
			}
			break;
		case 4:
			exit(0);
			break;
		case 5:
			do_funkcji_lap.ile_bylo_konstruktorow();
			for (int i = 0; i < wielkosc_tab2; i++) {
				lap_tab[i]->wyswietlanie();
			}
			if (true) {				
				Funkcje **kto = new Funkcje*[wielkosc_tab2];
				for (int i = 0; i < wielkosc_tab2; i++) {
					kto[i] = lap_tab[i];
				}
				for (int i = 0; i < wielkosc_tab2; i++) {
					kto[i]->wyswietlanie();
				}
				delete kto;	
			}
			break;
		default: cout << "poza zakresem" << endl;
		}
	}
	return 0;
}

//----------------------------- LAPTOP ------------------------------------------------------

void tworzenie_alokacja(Laptop**&tablica_laptopow, int rozmiar) {
	tablica_laptopow = new Laptop*[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		tablica_laptopow[i] = new Laptop;
	}
}
void Laptop::wpisz_dane_do() {
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
	cout << "                                  " << endl;
	cout << "||                             || " << endl;
	cout << "||         Podaj marke         || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> marka;
	cout << "||                             ||" << endl;
	cout << "||        Podaj cene           ||" << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> cena;
	cout << "||                             || " << endl;
	cout << "||        Podaj procesor       || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> procesor;
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
}
void wpisz_dane_do(Laptop**&tablica_laptopow, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		cout << "id " << i + 1 << endl;
		tablica_laptopow[i]->wpisz_dane_do();
	}
}
void Laptop::wyswietlanie() {
	cout << "Marka: " << marka << " Cena: " << cena << " Procesor " << procesor << endl;
}
void wyswietlanie(Laptop**&tablica_laptopow, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		tablica_laptopow[i]->wyswietlanie();
	}
}
void usuwanie(Laptop**&tablica_laptopow, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		delete tablica_laptopow[i];
	}
	delete tablica_laptopow;
	tablica_laptopow = nullptr;
}
void Laptop::ile_bylo_konstruktorow() {
	cout << "Uzyto konstruktora: " << xtr << " razy " << endl;
}
void Laptop::wczytaj_plik(int elementy, int x, int y) {
	fstream plikcena("cena.txt", ios::in);
	fstream plikmarka("marka.txt", ios::in);
	fstream plikprocesor("procesor.txt", ios::in);
	if (y == 1) {
		if (plikcena.good()) {
			for (int i = 0; i <= x; i++) {
				plikcena >> cena;
			}
			plikcena.close();
		}
	}
	if (y == 2) {
		if (plikmarka.good()) {
			for (int i = 0; i <= x; i++) {
				plikmarka >> marka;
			}
			plikmarka.close();
		}
	}
	if (y == 3) {
		if (plikprocesor.good()) {
			for (int i = 0; i <= x; i++) {
				plikprocesor >> procesor;
			}
			plikprocesor.close();
		}
	}
}
void wczytaj_pliki(Laptop**&tabs, int &rozmiar) {
	int plikii = 3;
	tworzenie_alokacja(tabs, rozmiar);
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 1; j <= plikii; j++) {
			tabs[i]->wczytaj_plik(rozmiar, i, j);
		}
	}
}

//----------------------------- SKLEP -------------------------------------------------------

void tworzenie_alokacja(Sklep**&tablica_sklepu, int rozmiar) {
	tablica_sklepu = new Sklep*[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		tablica_sklepu[i] = new Sklep;
	}
}
void Sklep::wyswietlanie() {
	cout << "| Nazwa sklepu: " << nazwa_sklepu << "| Pracownik: " << pracownicy << "| Data: " << data << " |" << endl;
}
void wyswietlanie(Sklep*&tablica_sklepu, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		tablica_sklepu[i].wyswietlanie();
	}
}
void Sklep::wpisz_dane_do() {
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
	cout << "                                  " << endl;
	cout << "||                             || " << endl;
	cout << "||        Podaj nazwe          || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> nazwa_sklepu;
	cout << "||                             || " << endl;
	cout << "||      Podaj pracownika       || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> pracownicy;
	cout << "||                             || " << endl;
	cout << "||        Podaj date           || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> data;
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
}
void wpisz_dane_do(Sklep**&tablica_sklepu, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		cout << " id: " << i + 1 << endl;
		tablica_sklepu[i]->wpisz_dane_do();
	}
}
void usuwanie(Sklep**&tablica_sklepu, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		delete[] tablica_sklepu[i];
	}
	delete[] tablica_sklepu;
}

//--------------------------- USTERKA --------------------------------------------------------

void tworzenie_alokacja(Serwis**&tablica_serwisu, int rozmiar) {
	tablica_serwisu = new Serwis*[rozmiar];
	for (int i = 0; i < rozmiar; i++)
		tablica_serwisu[i] = new Serwis;
}
void Serwis::wyswietlanie() {
	cout << "Koszt naprawy matrycy wyniosl: " << uszk_matryca << endl;
	cout << "Koszt naprawy klawiatury wyniosl: "  << uszk_klawiatura  << endl;
	cout << "Koszt naprawy procesora wyniosl: " << uszk_procesor << endl;
}
void wyswietlanie(Serwis**&tablica_serwisu, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		tablica_serwisu[i]->wyswietlanie();
	}
}
void usuwanie(Serwis**&tablica_serwisu, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		delete[] tablica_serwisu[i];
	}
	delete[] tablica_serwisu;
}
void Serwis::wpisz_dane_do() {
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
	cout << "                                  " << endl;
	cout << "||                             || " << endl;
	cout << "||    Uszkodzona klawiatura    || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> uszk_klawiatura;
	cout << "||                             || " << endl;
	cout << "||     Uszkodzona matryca      || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> uszk_matryca;
	cout << "||                             || " << endl;
	cout << "||    Uszkodzony procesor      || " << endl;
	cout << "||                             || " << endl;
	cout << "             ";
	cin >> uszk_procesor;
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
}
void wpisz_dane_do(Serwis**&tablica_serwisu, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		cout << " id: " << i + 1 << endl;
		tablica_serwisu[i]->wpisz_dane_do();
	}
}
void serwis_uszkodzenie(Serwis**&tab, int &rozmiar) {
	int k = 0, j = 10;
	Serwis **tabb;
	tworzenie_alokacja(tabb, rozmiar);
	for (int i = 0; i < rozmiar; i++) {
		tabb[i] = tab[i];
	}
	tabb[k]->uszk_matryca = tabb[k]->uszk_matryca-j;
	delete tab;
	tab = tabb;
	cout << "Cena naprawy laptopa " << k + 1 << " obnizona o " << j << ". W rezultacie nowa cena: " << tab[k]->uszk_matryca << endl;
	return;
}


//----------------------- POZOSTA£E FUNKCJE --------------------------------------------------

void Serwis::promocja(Laptop**&tablica_laptopow, int &rozmiar, int elementy, Sklep*&tab) {
	if (tablica_laptopow == nullptr || rozmiar<elementy)
		cout << "Nie ma tylu laptopow. " << endl;
	else {
		cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
		Serwis obiekt;
		Serwis**tablica_usterek;
		Laptop **nowa_tab_lap;
		Serwis **nowa_tab_ust;
		tworzenie_alokacja(tablica_usterek, elementy);
		tworzenie_alokacja(nowa_tab_lap, rozmiar);
		tworzenie_alokacja(nowa_tab_ust, elementy);
		for (int i = 0; i < elementy; i++) {
			cout << "O ile chcesz obnizyc cene w przypadku naprawy matrycy? Laptop: " << i + 1 << endl;
			cin >> tablica_usterek[i]->uszk_matryca;
			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
		}
		for (int i = 0; i < elementy; i++) {
			nowa_tab_ust[i]->nowa_cena = tablica_laptopow[i]->cena - tablica_usterek[i]->uszk_matryca - obiekt.get_promocja();
		}
		for (int i = 0; i < elementy; i++) {
			cout << "Stara cena " << i + 1 << " wynosi: " << tablica_laptopow[i]->cena << endl;
			cout << "Obnizka " << tablica_usterek[i]->uszk_matryca << endl;
			cout << "Nowa cena laptopa " << i + 1 << " wynosi: " << nowa_tab_ust[i]->nowa_cena << endl;
		}
		for (int i = 0; i < elementy; i++) {
			nowa_tab_lap[i]->cena = nowa_tab_ust[i]->nowa_cena;
			nowa_tab_lap[i]->marka = tablica_laptopow[i]->marka;
			nowa_tab_lap[i]->procesor = tablica_laptopow[i]->procesor;
		}
		for (int i = elementy; i < rozmiar; i++) {
			nowa_tab_lap[i]->cena = tablica_laptopow[i]->cena;
			nowa_tab_lap[i]->marka = tablica_laptopow[i]->marka;
			nowa_tab_lap[i]->procesor = tablica_laptopow[i]->procesor;
		}
		tab = obiekt.get_info_prom(elementy);
		delete[] nowa_tab_ust;
		delete[] tablica_usterek;
		delete[] tablica_laptopow;
		tablica_laptopow = nowa_tab_lap;	  
	}
}

//----------------------- MODYFIKOWANIE ----------------------------------------------------------
//----------------------- DODANIE DO TABLICY NA OSTATNIEJ POZYCJI --------------------------------
void dodaj_rekord(Laptop**&tablica_laptopow, int &rozmiar) {
	Laptop **nowa_tab_lap;
	int s = rozmiar + 1;
	tworzenie_alokacja(nowa_tab_lap, s);
	for (int i = 0; i < rozmiar; i++) {
		nowa_tab_lap[i] = tablica_laptopow[i];			//kopiowanie tablicy           
	}
	nowa_tab_lap[rozmiar]->wpisz_dane_do();

	delete[] tablica_laptopow; //
	rozmiar = rozmiar + 1;
	tablica_laptopow = nowa_tab_lap;//dopisanie referencji

}
void dodaj_rekord(Sklep**&tablica_sklepu, int &rozmiar) {
	Sklep **nowa_tab_skle;
	int s = rozmiar + 1;
	tworzenie_alokacja(nowa_tab_skle, s);
	for (int i = 0; i < rozmiar; i++) {
		nowa_tab_skle[i] = tablica_sklepu[i];
	}
	nowa_tab_skle[rozmiar]->wpisz_dane_do();
	delete[] tablica_sklepu;
	rozmiar = rozmiar + 1;
	tablica_sklepu = nowa_tab_skle;//dopisanie referencji
}

//----------------------- USUNIECIE Z OSTANIEJ POZYCJI W TABLICY ---------------------------------
void usun_ostatni_rekord(Laptop**&tablica_laptopow, int &rozmiar) {
	cout << "Usunieto ostatni rekord " << endl;
	Laptop **nowa_tab_lap;
	int s = rozmiar - 1;
	tworzenie_alokacja(nowa_tab_lap, s);
	for (int i = 0; i < s; i++) {
		nowa_tab_lap[i] = tablica_laptopow[i];
	}
	delete[] tablica_laptopow; //

	rozmiar = rozmiar - 1;
	tablica_laptopow = nowa_tab_lap;//dopisanie referencji
}
void usun_ostatni_rekord(Sklep**&tablica_sklepu, int &rozmiar) {
	Sklep **nowa_tab_skle;
	int s = rozmiar - 1;
	tworzenie_alokacja(nowa_tab_skle, s);
	for (int i = 0; i < rozmiar; i++) {
		nowa_tab_skle[i] = tablica_sklepu[i];
	}
	delete[] tablica_sklepu;
	rozmiar = rozmiar - 1;
	tablica_sklepu = nowa_tab_skle;//dopisanie referencji
}

//----------------------- DODANIE DO TABLICY NA WYBRANE MIEJSCE -----------------------------------
void dodaj_do_tablicy(Laptop**&tablica_laptopow, int nowa_pozycja, int &rozmiar) {
	Laptop **nowa_tab_lap;
	rozmiar = rozmiar + 1;
	tworzenie_alokacja(nowa_tab_lap, rozmiar);
	nowa_pozycja = nowa_pozycja - 1;
	for (int i = 0; i < nowa_pozycja; i++) {
		nowa_tab_lap[i] = tablica_laptopow[i];
	}
	nowa_tab_lap[nowa_pozycja]->wpisz_dane_do();
	for (int i = nowa_pozycja + 1; i < rozmiar; i++) {
		nowa_tab_lap[i] = tablica_laptopow[i - 1];
	}
	delete tablica_laptopow;
	tablica_laptopow = nowa_tab_lap;
}
void dodaj_do_tablicy(Sklep**&tablica_sklepu, int nowa_pozycja, int &rozmiar) {
	Sklep **nowa_tab_skle;
	rozmiar = rozmiar + 1;
	tworzenie_alokacja(nowa_tab_skle, rozmiar);
	nowa_pozycja = nowa_pozycja - 1;
	for (int i = 0; i < nowa_pozycja; i++) {
		nowa_tab_skle[i] = tablica_sklepu[i];
	}
	nowa_tab_skle[nowa_pozycja]->wpisz_dane_do();
	for (int i = nowa_pozycja + 1; i < rozmiar; i++) {
		nowa_tab_skle[i] = tablica_sklepu[i - 1];
	}
	tablica_sklepu = nowa_tab_skle;
	delete tablica_sklepu;
}

//----------------------- USUNIECIE Z TABLICY WYBRANEGO MIEJSCA -----------------------------------

void ususn_z_tablicy(Sklep**&tablica_sklepu, int pozycja_usuwana, int &rozmiar) {
	Sklep **nowa_tab_skle;
	rozmiar = rozmiar - 1;
	tworzenie_alokacja(nowa_tab_skle, rozmiar);
	pozycja_usuwana = pozycja_usuwana - 1;
	for (int i = 0; i < pozycja_usuwana; i++) {
		nowa_tab_skle[i] = tablica_sklepu[i];
	}
	for (int i = pozycja_usuwana + 1; i < rozmiar + 1; i++) {
		nowa_tab_skle[i - 1] = tablica_sklepu[i];
	}
	delete tablica_sklepu;
	tablica_sklepu = nowa_tab_skle;
}
void ususn_z_tablicy(Laptop**&tablica_laptopow, int pozycja_usuwana, int &rozmiar) {
	Laptop **nowa_tab_lap;
	rozmiar = rozmiar - 1;
	tworzenie_alokacja(nowa_tab_lap, rozmiar);
	pozycja_usuwana = pozycja_usuwana - 1;
	for (int i = 0; i < pozycja_usuwana; i++) {
		nowa_tab_lap[i] = tablica_laptopow[i];

	}
	for (int i = pozycja_usuwana + 1; i < rozmiar + 1; i++) {
		nowa_tab_lap[i - 1] = tablica_laptopow[i];
	}
	delete tablica_laptopow;
	tablica_laptopow = nowa_tab_lap;
}
//---------------------------------------------------------------------------------------------------
void dodaja_na_losowa_pozycje(Laptop**&tablica_laptopow, int &rozmiar) {
	srand(time(NULL));
	int losowa;
	Laptop **nowa_tab_lap;
	rozmiar = rozmiar + 1;
	tworzenie_alokacja(nowa_tab_lap, rozmiar);
	losowa = (rand() % rozmiar) + 1;
	cout << losowa << " " << rozmiar << endl;
	if ((losowa > 0) && (losowa < rozmiar + 1)) {
		losowa = losowa - 1;
		for (int i = 0; i < losowa; i++) {
			nowa_tab_lap[i] = tablica_laptopow[i];
		}
		nowa_tab_lap[losowa]->wpisz_dane_do();
		for (int i = losowa + 1; i < rozmiar; i++) {
			nowa_tab_lap[i] = tablica_laptopow[i - 1];
		}
		cout << losowa << " " << rozmiar << endl;
		delete tablica_laptopow;
		tablica_laptopow = nowa_tab_lap;
	}
	else {
		cout << losowa << " " << rozmiar << endl;
		cout << " Losowanie nie zadzialalo sproboj ponowanie " << endl;
		usun_ostatni_rekord(nowa_tab_lap, rozmiar);
	}
}

//-----------------------------------------------------------------------------------------------------

void Serwis::obnizka_jedna(Laptop**&tablica_laptopow, int &rozmiar, int elementy) {
	Serwis **nowa_tab_usterka;
	Serwis **tablica_usterek;
	tworzenie_alokacja(nowa_tab_usterka, elementy);
	tworzenie_alokacja(obniz1, rozmiar);
	tworzenie_alokacja(tablica_usterek, elementy);
	int do_elementu = elementy - 1;
	cout << "O ile chcesz obnizyc cene w przypadku naprawy matrycy? Laptop: " << elementy << endl;
	cin >> tablica_usterek[do_elementu]->uszk_matryca;
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ " << endl;
	nowa_tab_usterka[do_elementu]->nowa_cena = tablica_laptopow[do_elementu]->cena - tablica_usterek[do_elementu]->uszk_matryca;
	cout << "Stara cena " << elementy << " wynosi: " << tablica_laptopow[do_elementu]->cena << endl;
	cout << "Obnizka " << tablica_usterek[do_elementu]->uszk_matryca << endl;
	cout << "Nowa cena laptopa " << elementy << " wynosi: " << nowa_tab_usterka[do_elementu]->nowa_cena << endl;
	obniz1[do_elementu]->cena = nowa_tab_usterka[do_elementu]->nowa_cena;
	tablica_laptopow[do_elementu]->cena = obniz1[do_elementu]->cena;
}
int Serwis::get_okres() {
	return okres;
}
int Serwis::get_promocja() {
	return promocja_l;
}
void parametry_laptopa(Laptop**&tab_lap, int &rozmiar) {
	int k = 0;
	Laptop obiekt;
	cout << "||                             || " << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << "Laptop " << i + 1 << ". ";
		tab_lap[i]->wyswietlanie();	
	}
	obiekt.danee->dane(rozmiar);
}
Sklep*Serwis::get_info_prom(int elementy) {
	int k = 0;
	info_prom = new Sklep[elementy];
	info_prom[k].wpisz_dane_do();
	for (int i = 0; i < elementy; i++) {
		info_prom[i] = info_prom[k];
	}
	cout << "Cena obnizona dodatkowo o " << promocja_l << endl << " :Promocja jesienna. " << "Okres pozostaly do konca promocji: " << okres << " dni. " << endl;
	return info_prom;
}
void Laptop::Parametry::dane(int &rozmiar) {
	Parametry**tablica_plik;
	tablica_plik = new Laptop::Parametry*[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		tablica_plik[i] = new Laptop::Parametry;
	}
	fstream plik("model.txt", ios::in);
	fstream plik2("rozdzielczosc.txt", ios::in);
	fstream plik3("gwarancja.txt", ios::in);
	fstream plik4("ilosc_ramu.txt", ios::in);
	fstream plik5("ilosc_rdzeni.txt", ios::in);
	fstream plik6("karta_graficzna.txt", ios::in);
	fstream plik7("pojemnosc_dysku.txt", ios::in);
	fstream plik8("rodzaj_dysku.txt", ios::in);
	fstream plik9("rodzaj_laptopa.txt", ios::in);
	fstream plik10("rodzaj_matrycy.txt", ios::in);
	fstream plik11("rodzaj_procesora.txt", ios::in);
	fstream plik12("rodzaj_ramu.txt", ios::in);
	fstream plik13("stan.txt", ios::in);
	fstream plik14("waga.txt", ios::in);
	fstream plik15("wielkosc_matrycy.txt", ios::in);
	if (plik.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik >> tablica_plik[i]->model;
		}
		plik.close();
	}
	if (plik2.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik2 >> tablica_plik[i]->rozdzielczosc;
		}
		plik2.close();
	}
	if (plik3.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik3 >> tablica_plik[i]->gwarancja;
		}
		plik3.close();
	}
	if (plik4.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik4 >> tablica_plik[i]->ilosc_ramu;
		}
		plik4.close();
	}
	if (plik5.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik5 >> tablica_plik[i]->ilosc_rdzeni;
		}
		plik5.close();
	}
	if (plik6.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik6 >> tablica_plik[i]->karta_graficzna;
		}
		plik6.close();
	}
	if (plik7.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik7 >> tablica_plik[i]->pojemnosc_dysku;
		}
		plik7.close();
	}
	if (plik8.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik8 >> tablica_plik[i]->rodzaj_dysku;
		}
		plik8.close();
	}
	if (plik9.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik9 >> tablica_plik[i]->rodzaj_laptopa;
		}
		plik9.close();
	}
	if (plik10.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik10 >> tablica_plik[i]->rodzaj_matrycy;
		}
		plik10.close();
	}
	if (plik11.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik11 >> tablica_plik[i]->rodzaj_procesora;
		}
		plik11.close();
	}
	if (plik12.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik12 >> tablica_plik[i]->rodzaj_ramu;
		}
		plik12.close();
	}
	if (plik13.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik13 >> tablica_plik[i]->stan;
		}
		plik13.close();
	}
	if (plik14.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik14 >> tablica_plik[i]->waga;
		}
		plik14.close();
	}
	if (plik15.good()) {
		for (int i = 0; i < rozmiar; i++) {
			plik15 >> tablica_plik[i]->wielkosc_matrycy;
		}
		plik15.close();
	}
	Laptop::Parametry**kopia(tablica_plik);
	cout << "||                             || " << endl;
	for (int i = 0; i < rozmiar; i++) {
		cout << endl;
		cout << "Laptop " << i + 1 << ". ";
	cout << "Dodatkowe dane:" << endl;
	cout << "|| Model: " << kopia[i]->model << "|| Wielksoc matrycy: " << kopia[i]->wielkosc_matrycy << "|| Rodzaj matrycy: " << kopia[i]->rodzaj_matrycy << "|| Rodzaj dysku: " << kopia[i]->rodzaj_dysku << " ||" << endl;
	cout << "|| Pojemnosc dysku: " << kopia[i]->pojemnosc_dysku << "|| Karta graficzna: " << kopia[i]->karta_graficzna << "|| Ilosc ramu: " << kopia[i]->ilosc_ramu << "|| Rodzaj laptopa: " << kopia[i]->rodzaj_laptopa << " ||" << endl;
	cout << endl;
	}
	cout << "||                             || " << endl;
	delete[]tablica_plik;
}
ostream& operator<<(ostream& out, Serwis& obiekt) {
	cout << " Cena naprawy matrycy:  " << obiekt.uszk_matryca <<" Cena naprawy klawiatury: "<<obiekt.uszk_klawiatura<<" Cena naprawy procesora: "<<obiekt.uszk_procesor<< " Nowa cena: " << obiekt.nowa_cena << " Okres trwania promocji: " << obiekt.okres << endl;
	return out;
}
istream& operator>>(istream& in, Serwis& obiekt) {
	cout << "podaj Cena naprawy matrycy:  " << endl;
	in >> obiekt.uszk_matryca;
	cout << "podaj Cena naprawy klawiatury: " << endl;
	in >> obiekt.uszk_klawiatura;
	cout << "podaj Cena naprawy procesora: " << endl; 
	in >> obiekt.uszk_procesor;
	cout << "podaj Nowa cena: " << endl;
	in >> obiekt.nowa_cena;
	cout << "Okres trwania promocji: " << obiekt.okres<<endl;
	obiekt.get_okres;
	return in;
}

//--------------------- KONSTRUKTORY I DESTRUKTORY -----------------------------------------------------

Laptop::Laptop() {
	xtr++;
	marka = "ASUS";
	cena = 1000;
	procesor = "i7";
}														
Laptop::~Laptop() {
	marka = "brak";
	cena = 0;
	procesor = "brak";
	xtr--;
}
Serwis::Serwis() {
	a1 = new Laptop();
	uszk_matryca = 1000;
	nowa_cena = 2000;
}
Serwis::~Serwis() {
	uszk_matryca = 0;
	nowa_cena = 0;
	delete a1;
}
Laptop::Parametry::Parametry() {

	ilosc_ramu = "8gb";
	karta_graficzna = "gtx960";
	ilosc_rdzeni = 100;
}
Laptop::Parametry::~Parametry() {
	ilosc_ramu = "";
	karta_graficzna = "brak";
	ilosc_rdzeni = 0;
}
Sklep::Sklep() {
	nazwa_sklepu = "Dobry sklep";
	pracownicy = "Mariusz";
	data = "25.11.17r";
}
Sklep::~Sklep() {
	nazwa_sklepu = "";
	pracownicy = "";
	data = "";
	//cout << "Serwis ma powierzchnie " << serwis << " metrow kwadratowych, pracuje tu " << pracownicy << " pracownikow oraz mamy " << produkty << endl;
}
Laptop::Parametry::Parametry(Parametry&tablica_par) {
	model = tablica_par.model;
	wielkosc_matrycy = tablica_par.wielkosc_matrycy;
	rodzaj_matrycy = tablica_par.rodzaj_matrycy;
	rodzaj_dysku = tablica_par.rodzaj_dysku;
	ilosc_ramu = tablica_par.ilosc_ramu;
	karta_graficzna = tablica_par.karta_graficzna;
	pojemnosc_dysku = tablica_par.pojemnosc_dysku;
	rodzaj_laptopa = tablica_par.rodzaj_laptopa;
}


