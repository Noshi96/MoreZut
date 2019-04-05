#include<vector>
#include<complex>
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

void formatuj_liczbe_zesp(complex<float> l_zespolona) {
	if (l_zespolona.imag() == 0) {
		printf("%.3f   \n", l_zespolona.real());
	}
	else if (l_zespolona.imag() > 0) {
		printf("%.3f + %.3fi   \n", l_zespolona.real(), l_zespolona.imag());
	}
	else {
		printf("%.3f %.3fi  \n", l_zespolona.real(), l_zespolona.imag());
	}
}

class Dane {
protected:
		   vector <int> zmienna;
		   vector <complex<float>> wyniki;
public:
	int element = 0;
	void wprowadz_dane() {
		int size = 4;
		for (int i = 0; i < size; i++) {
			printf("podaj zmienna: %d \n",i);
			scanf_s("%d", &element);
										//cin >> element;
			zmienna.push_back(element);
		}
		//delta 0 pdelta 1
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));

		wyniki.at(0).real(0);
		wyniki.at(0).imag(0);

		wyniki.at(1).real(0);
		wyniki.at(1).imag(0);
	}
	
	complex<float> obl_delta() {
		wyniki.at(0).real((zmienna.at(1)*zmienna.at(1)) - (4 * zmienna.at(0)*zmienna.at(2)));
		wyniki.at(0).imag(-(4 * zmienna.at(0)*zmienna.at(3)));
		return wyniki.at(0);
	}

	complex<float> oblicz_p_d_r() {
		wyniki.at(1).real(sqrt((sqrt((wyniki.at(0).real()*wyniki.at(0).real()) + (wyniki.at(0).imag()*wyniki.at(0).imag())) + wyniki.at(0).real()) / 2));
		return wyniki.at(1);
	}

	complex<float> oblicz_p_d_u() {
		wyniki.at(1).imag(sqrt((sqrt((wyniki.at(0).real()*wyniki.at(0).real()) + (wyniki.at(0).imag()*wyniki.at(0).imag())) - wyniki.at(0).real()) / 2));
		return wyniki.at(1);
	}
};

class Pierwiastki {
protected:
	complex <float> pierwiastek[4];
	int przekaz[4];
};

class Bazowa : public Dane, public Pierwiastki {
public:
	Bazowa() {
		wprowadz_dane();
		//x1 x2 x3 x4   2,3,4,5
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
			
		wyniki.at(2).real();
		wyniki.at(2).imag();
		wyniki.at(3).real();
		wyniki.at(3).imag();
		wyniki.at(4).real();
		wyniki.at(4).imag();
		wyniki.at(5).real();
		wyniki.at(5).imag();

		obl_delta();
		oblicz_p_d_r();
		oblicz_p_d_u();
	}

	void formatuj_rownanie() {
		if (zmienna.at(0) == 0 && zmienna.at(1) == 0 && zmienna.at(2) == 0 && zmienna.at(3) == 0  ) {
			printf("0");
		}
		if (zmienna.at(0) > 0) {
			printf("%dxx", zmienna.at(0));
		}
		else if (zmienna.at(0)<0) {
			printf("%dxx", zmienna.at(0));
		}
		else {
			printf("");
		}
		if (zmienna.at(1) > 0 && zmienna.at(0) != 0) {
			printf("+%dx", zmienna.at(1));
		}
		else if (zmienna.at(1) > 0 && zmienna.at(0) == 0) {
			printf("%dx", zmienna.at(1));
		}
		else if (zmienna.at(1)<0) {
			printf("%dx", zmienna.at(1));
		}
		else if (zmienna.at(1) == 0 && zmienna.at(0) != 0) {
			printf("");
		}
		else {
			printf("");
		}
		if (zmienna.at(2) > 0) {
			printf("+%d", zmienna.at(2));
		}
		else if (zmienna.at(2)<0) {
			printf("%d", zmienna.at(2));
		}
		else {
			printf("");
		}
		if (zmienna.at(3) > 0 && zmienna.at(2) == 0 && zmienna.at(1) == 0 && zmienna.at(0) == 0) {
			printf("%di=0", zmienna.at(3));
		}
		else if (zmienna.at(3) > 0) {
			printf("+%di=0", zmienna.at(3));
		}
		else if (zmienna.at(3)<0) {
			printf("%di=0", zmienna.at(3));
		}
		else {
			printf("=0");
		}
		printf("\n");
	}

	void oblicz_rownanie() {
		if (zmienna.at(0) != 0 && zmienna.at(3) == 0) {
			if (wyniki.at(0).real() > 0) {
				wyniki.at(2).real((-(float)zmienna.at(1) - wyniki.at(1).real()) / (2 * zmienna.at(0)));
				wyniki.at(3).real((-(float)zmienna.at(1) + wyniki.at(1).real()) / (2 * zmienna.at(0)));
			}
			//1.2
			if (wyniki.at(0).real() == 0) {
				wyniki.at(2).real(-(float)zmienna.at(1) / (2 * zmienna.at(0)));
			}
			//1.3
			if (wyniki.at(0).real() < 0) {
				obl_delta();
				wyniki.at(0).real(-wyniki.at(0).real());
				oblicz_p_d_r();
				wyniki.at(2).real((float)-zmienna.at(1) / (2 * zmienna.at(0)));
				wyniki.at(2).imag((float)-(wyniki.at(1).real() / (2 * zmienna.at(0))));
				wyniki.at(3).real(wyniki.at(2).real());
				wyniki.at(3) = (conj(wyniki.at(2)));
				obl_delta();
			}
		}
		//2.
		if (zmienna.at(0) == 0 && zmienna.at(1) != 0 && zmienna.at(3) == 0) {
			wyniki.at(2).real(-((float)zmienna.at(2) / zmienna.at(1)));
		}
		//3.
		if (zmienna.at(0) == 0 && zmienna.at(1) == 0 && (zmienna.at(2) != 0 || zmienna.at(3) != 0)) {
			//printf("Rownanie sprzeczne \n");
		}

		//4.
		if (zmienna.at(0) == 0 && zmienna.at(1) == 0 && zmienna.at(2) == 0 && zmienna.at(3) == 0) {
			//printf("Rownanie tozsamosciowe \n");
		}
		//5.
		if (zmienna.at(0) == 0 && zmienna.at(1) != 0 && zmienna.at(3) != 0) {
			wyniki.at(2).real(-((float)zmienna.at(2) / zmienna.at(1)));
			wyniki.at(2).imag(-((float)zmienna.at(3) / zmienna.at(1)));
		}
		//6.
		if (zmienna.at(0) != 0 && zmienna.at(3) != 0) {
			wyniki.at(2).real((-zmienna.at(1) - wyniki.at(1).real()) / (2 * zmienna.at(0)));
			wyniki.at(2).imag((-zmienna.at(1) - wyniki.at(1).imag()) / (2 * zmienna.at(0)));
			wyniki.at(3).real((-zmienna.at(1) - wyniki.at(1).real()) / (2 * zmienna.at(0)));
			wyniki.at(3).imag((-zmienna.at(1) + wyniki.at(1).imag()) / (2 * zmienna.at(0)));
			wyniki.at(4).real((-zmienna.at(1) + wyniki.at(1).real()) / (2 * zmienna.at(0)));
			wyniki.at(4).imag((-zmienna.at(1) + wyniki.at(1).imag()) / (2 * zmienna.at(0)));
			wyniki.at(5).real((-zmienna.at(1) + wyniki.at(1).real()) / (2 * zmienna.at(0)));
			wyniki.at(5).imag((-zmienna.at(1) - wyniki.at(1).imag()) / (2 * zmienna.at(0)));
		}
	}

	void wyswietl_wynik() {
		if (zmienna.at(0) != 0 && zmienna.at(3) == 0) {

			//printf("Delta= %f \n", wyniki.at(0).real());
			printf("Delta = ");
			formatuj_liczbe_zesp(wyniki.at(0));

			//1.1
			//deltar = 8.204060;
			if (wyniki.at(0).real() > 0) {
				printf("x1r = %.3f \n", wyniki.at(2).real());
				printf("x2r = %.3f \n", wyniki.at(3).real());
				printf("\n");
			}

			//1.2
			if (wyniki.at(0).real() == 0) {
				printf("x1r = %.3f \n", wyniki.at(2).real());
			}

			//1.3
			if (wyniki.at(0).real() < 0) {	
				printf("x1 ");
				formatuj_liczbe_zesp(wyniki.at(2));
				printf(" x2 ");																				///////////////////////////////////
				formatuj_liczbe_zesp(wyniki.at(3));
				printf("\n");
			}
		}
		//2.
		if (zmienna.at(0) == 0 && zmienna.at(1) != 0 && zmienna.at(3) == 0) {
			printf("x1r = %.3f \n", wyniki.at(2).real());
		}

		//3.
		if (zmienna.at(0) == 0 && zmienna.at(1) == 0 && (zmienna.at(2) != 0 || zmienna.at(3) != 0)) {
			printf("Rownanie sprzeczne \n");
		}

		//4.
		if (zmienna.at(0) == 0 && zmienna.at(1) == 0 && zmienna.at(2) == 0 && zmienna.at(3) == 0) {
			printf("Rownanie tozsamosciowe \n");
		}

		//5.
		if (zmienna.at(0) == 0 && zmienna.at(1) != 0 && zmienna.at(3) != 0) {
			printf("x1 = ");
			formatuj_liczbe_zesp(wyniki.at(2));
		}

		//6.
		if (zmienna.at(0) != 0 && zmienna.at(3) != 0) {
			printf("Delta = ");
			formatuj_liczbe_zesp(wyniki.at(0));

			printf("x1 ");
			formatuj_liczbe_zesp(wyniki.at(2));
			printf("\n");
			printf("x2 ");
			formatuj_liczbe_zesp(wyniki.at(3));
			printf("\n");
			printf("x3 ");
			formatuj_liczbe_zesp(wyniki.at(4));
			printf("\n");
			printf("x4 ");
			formatuj_liczbe_zesp(wyniki.at(5));
			printf("\n");
		}
	}

	complex <float> *getPierwiastki() {
		pierwiastek[0].real(wyniki.at(2).real());
		pierwiastek[0].imag(wyniki.at(2).imag());	
		pierwiastek[1].real(wyniki.at(3).real());
		pierwiastek[1].imag(wyniki.at(3).imag());
		pierwiastek[2].real(wyniki.at(4).real());
		pierwiastek[2].imag(wyniki.at(4).imag());
		pierwiastek[3].real(wyniki.at(5).real());
		pierwiastek[3].imag(wyniki.at(5).imag());
		return pierwiastek;
	}

	 int *getdane() {
		przekaz[0] = zmienna.at(0);
		przekaz[1] = zmienna.at(1);
		przekaz[2] = zmienna.at(2);
		przekaz[3] = zmienna.at(3);
		return przekaz;
	}

	 void czysc() {
		 wyniki.erase(wyniki.begin(), wyniki.end());
		 zmienna.erase(zmienna.begin(), zmienna.end());
	 }
};

class Operacje :public Dane {
public:
	virtual void wykonaj_operacje(complex <float> delta) = 0;
	virtual void wyswietl_wynik(complex <float> delt) = 0;
	virtual void czysc() = 0;
};

class Dodawanie : public Operacje {
public:
	Dodawanie(complex <float> *tab, int *tab2) {
		//suma
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		
		wyniki.at(0) = tab[0];
		wyniki.at(1) = tab[1];
		wyniki.at(2) = tab[2];
		wyniki.at(3) = tab[3];
		wyniki.at(4) = tab[4];
		
		zmienna.push_back(tab2[0]);
		zmienna.push_back(tab2[1]);
		zmienna.push_back(tab2[2]);
		zmienna.push_back(tab2[3]);
	}

	void wykonaj_operacje(complex <float> delta) {
		if (delta.imag() != 0) {
			wyniki.at(4) = (wyniki.at(0) + wyniki.at(1) + wyniki.at(2) + wyniki.at(3));
		}
		else if (delta.real() > 0) {
			wyniki.at(4) = (wyniki.at(0) + wyniki.at(1));
		}
		else if (delta.real() < 0) {
			wyniki.at(4) = (wyniki.at(0) + wyniki.at(1));
		}
	}

	void wyswietl_wynik(complex <float> delta) {
		if (zmienna.at(0) != 0 && zmienna.at(3) == 0) {
			//1.1
			if (delta.real() > 0) {
				printf("Suma: %.3f \n", wyniki.at(4).real());
				printf("\n");
			}
			//1.3
			if (delta.real() < 0) {
				printf("Suma: ");
				formatuj_liczbe_zesp(wyniki.at(4));
			}
		}
		//6.
		if (zmienna.at(0) != 0 && zmienna.at(3) != 0) {
			printf("Suma: ");
			formatuj_liczbe_zesp(wyniki.at(4));
		}
	}
	void czysc() {
		while (!wyniki.empty()) {																						//wykonuj sie gdy jest rózny od pustego 
			wyniki.pop_back();
		}
		for (int i = zmienna.size(); i>0; i--) {
			zmienna.pop_back();
		}
	}
};

class Odejmowanie : public  Operacje {
public:
	Odejmowanie(complex <float> *tab, int *tab2) {
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		
		wyniki.at(0) = tab[0];
		wyniki.at(1) = tab[1];
		wyniki.at(2) = tab[2];
		wyniki.at(3) = tab[3];
		wyniki.at(4) = tab[4];

		zmienna.push_back(tab2[0]);
		zmienna.push_back(tab2[1]);
		zmienna.push_back(tab2[2]);
		zmienna.push_back(tab2[3]);
	}

	void wykonaj_operacje(complex <float> delta) {
		if (delta.imag() != 0) {
			wyniki.at(4) = (wyniki.at(0) - wyniki.at(1) - wyniki.at(2) - wyniki.at(3));
		}
		else if (delta.real() > 0) {
			wyniki.at(4) = (wyniki.at(0) - wyniki.at(1));
		}
		else if (delta.real() < 0) {
			wyniki.at(4)=(wyniki.at(0) - wyniki.at(1));
		}
	}

	void wyswietl_wynik(complex <float> delta) {	
		if (zmienna.at(0) != 0 && zmienna.at(3) == 0) {
			//1.1
			if (delta.real() > 0) {
				printf("Roznica: %.3f \n", wyniki.at(4).real());
				printf("\n");
			}
			//1.3
			if (delta.real() < 0) {
				printf("Roznica: ");
				formatuj_liczbe_zesp(wyniki.at(4));
			}
		}
		//6.
		if (zmienna.at(0) != 0 && zmienna.at(3) != 0) {
			printf("Roznica: ");
			formatuj_liczbe_zesp(wyniki.at(4));
		}
	}

	void czysc() {
		while (!wyniki.empty()) {																				//wykonuj sie gdy jest rózny od pustego 
			wyniki.pop_back();
		}
		for (int i = zmienna.size(); i>0; i--) {
			zmienna.pop_back();
		}
	}
};

class Mnozenie : public Operacje {
public:
	Mnozenie(complex <float> *tab, int *tab2) {
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		wyniki.push_back(complex<float>(0, 0));
		
		wyniki.at(0) = tab[0];
		wyniki.at(1) = tab[1];
		wyniki.at(2) = tab[2];
		wyniki.at(3) = tab[3];
		wyniki.at(4) = tab[4];

		zmienna.push_back(tab2[0]);
		zmienna.push_back(tab2[1]);
		zmienna.push_back(tab2[2]);
		zmienna.push_back(tab2[3]);
	}

	void wykonaj_operacje(complex <float> delta) {
		if (delta.imag() != 0) {
			wyniki.at(4) = (wyniki.at(0) * wyniki.at(1) * wyniki.at(2) * wyniki.at(3));
		}
		else if (delta.real() > 0) {
			wyniki.at(4) = (wyniki.at(0) * wyniki.at(1));
		}
		else if (delta.real() < 0) {
			wyniki.at(4) = (wyniki.at(0) * wyniki.at(1));
		}
	}

	void wyswietl_wynik(complex <float> delta) {
		if (zmienna.at(0) != 0 && zmienna.at(3) == 0) {
			//1.1
			if (delta.real() > 0) {
				printf("Iloczyn: %.3f \n", wyniki.at(4).real());
				printf("\n");
			}
			//1.3
			if (delta.real() < 0) {
				printf("Iloczyn: ");
				formatuj_liczbe_zesp(wyniki.at(4));
			}
		}
		//6.
		if (zmienna.at(0) != 0 && zmienna.at(3) != 0) {
			printf("Iloczyn: ");
			formatuj_liczbe_zesp(wyniki.at(4));
		}
	}
	void czysc() {
		while (!wyniki.empty()) {														//wykonuj sie gdy jest rózny od pustego 
			wyniki.pop_back();
		}
		zmienna.erase(zmienna.begin(), zmienna.end());
	}
};


int main() {

	Bazowa *obiekt=new Bazowa();
	Operacje *operacje[3];

	obiekt->oblicz_rownanie();
	obiekt->formatuj_rownanie();
	obiekt->wyswietl_wynik();

	operacje[0] = new Dodawanie(obiekt->getPierwiastki(), obiekt->getdane());
	operacje[1] = new Odejmowanie(obiekt->getPierwiastki(), obiekt->getdane());
	operacje[2] = new Mnozenie(obiekt->getPierwiastki(), obiekt->getdane());

	operacje[0]->wykonaj_operacje(obiekt->obl_delta());
	operacje[0]->wyswietl_wynik(obiekt->obl_delta());
	operacje[0]->czysc();
	operacje[1]->wykonaj_operacje(obiekt->obl_delta());
	operacje[1]->wyswietl_wynik(obiekt->obl_delta());
	operacje[1]->czysc();
	operacje[2]->wykonaj_operacje(obiekt->obl_delta());
	operacje[2]->wyswietl_wynik(obiekt->obl_delta());
	operacje[2]->czysc();

	

	delete operacje[2];
	delete operacje[1];
	delete operacje[0];
	obiekt->czysc();
	delete obiekt;

	system("pause");
	getchar();
}