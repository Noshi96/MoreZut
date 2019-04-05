#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

struct Liczba_zespolona {
	float cz_rz;
	float cz_ur;
};

void formatuj_liczbe_zesp(Liczba_zespolona l_zespolona) {

	if (l_zespolona.cz_ur == 0) {
		printf("%.3f   \n", l_zespolona.cz_rz);
	}
	else if (l_zespolona.cz_ur > 0) {
		printf("%.3f + %.3fi   \n", l_zespolona.cz_rz, l_zespolona.cz_ur);
	}
	else {
		printf("%.3f %.3fi  \n", l_zespolona.cz_rz, l_zespolona.cz_ur);
	}
}



class Dane {

protected:
	int a, b, c, d;
	Liczba_zespolona delta, pdelta;
public:
	void wprowadz_dane() {
		printf("podaj a\n");
		scanf_s("%d", &a);
		printf("podaj b\n");
		scanf_s("%d", &b);
		printf("podaj c\n");
		scanf_s("%d", &c);
		printf("podaj d\n");
		scanf_s("%d", &d);
	}

	 Liczba_zespolona obl_delta() {
		delta.cz_rz = (b*b) - (4 * a*c);
		delta.cz_ur = -(4 * a*d);
		return delta;
	}

	 Liczba_zespolona oblicz_p_d_r() {
		 pdelta.cz_rz = sqrt((sqrt((delta.cz_rz*delta.cz_rz) + (delta.cz_ur*delta.cz_ur)) + delta.cz_rz) / 2);
		 return pdelta;
	}

	 Liczba_zespolona oblicz_p_d_u() {
		 pdelta.cz_ur = sqrt((sqrt((delta.cz_rz*delta.cz_rz) + (delta.cz_ur*delta.cz_ur)) - delta.cz_rz) / 2);
		 return pdelta;
	}
};


class Pierwiastki {
protected:
	Liczba_zespolona pierwiastek[4];
	Liczba_zespolona x1, x2, x3, x4;
	int dane[4];
public:
	Pierwiastki() {
		x1.cz_rz=0;
		x1.cz_ur=0;
		x2.cz_rz=0;
		x2.cz_ur=0;
		x3.cz_rz=0;
		x3.cz_ur=0;
		x4.cz_rz=0;
		x4.cz_ur=0;
	}
};

class Bazowa : public Dane, public Pierwiastki {

public:

	Bazowa() {
			wprowadz_dane();
			obl_delta();
			oblicz_p_d_r();
			oblicz_p_d_u();
	}

	void formatuj_rownanie() {
		if (a > 0) {
			printf("%dxx", a);
		}
		else if (a<0) {
			printf("%dxx", a);
		}
		else {
			printf("");
		}
		if (b > 0 && a != 0) {
			printf("+%dx", b);
		}
		else if (b > 0 && a == 0) {
			printf("%dx", b);
		}
		else if (b<0) {
			printf("%dx", b);
		}
		else if (b == 0 && a != 0) {
			printf("");
		}
		else {
			printf("");
		}
		if (c > 0) {
			printf("+%d", c);
		}
		else if (c<0) {
			printf("%d", c);
		}
		else {
			printf("");
		}
		if (d > 0 && c == 0 && b == 0 && a == 0) {
			printf("%di=0", d);
		}
		else if (d > 0) {
			printf("+%di=0", d);
		}
		else if (d<0) {
			printf("%di=0", d);
		}
		else {
			printf("=0");
		}
		printf("\n");
	}

	void oblicz_rownanie() {
		if (a != 0 && d == 0) {
			if (delta.cz_rz > 0) {
				x1.cz_rz = (-(float)b - pdelta.cz_rz) / (2 * a);
				x2.cz_rz = (-(float)b + pdelta.cz_rz) / (2 * a);
			}
			//1.2
			if (delta.cz_rz == 0) {
				x1.cz_rz = -(float)b / (2 * a);
			}
			//1.3
			if (delta.cz_rz < 0) {
				obl_delta();
				delta.cz_rz = -delta.cz_rz;
				oblicz_p_d_r();
				x1.cz_rz = (float)-b / (2 * a);
				x1.cz_ur = (float)-(pdelta.cz_rz / (2 * a));
				x2.cz_rz = x1.cz_rz;
				x2.cz_ur = -x1.cz_ur;
				obl_delta();
			}
		}
		//2.
		if (a == 0 && b != 0 && d == 0) {
			x1.cz_rz = -((float)c / b);
		}
		//3.
		if (a == 0 && b == 0 && (c != 0 || d != 0)) {
			printf("Rownanie sprzeczne \n");
		}

		//4.
		if (a == 0 && b == 0 && c == 0 && d == 0) {
			printf("Rownanie tozsamosciowe \n");
		}
		//5.
		if (a == 0 && b != 0 && d != 0) {
			x1.cz_rz = -((float)c / b);
			x1.cz_ur = -((float)d / b);
		}
		//6.
		if (a != 0 && d != 0) {
			x1.cz_rz = (-b - pdelta.cz_rz) / (2 * a);
			x1.cz_ur = (-b - pdelta.cz_ur) / (2 * a);
			x2.cz_rz = (-b - pdelta.cz_rz) / (2 * a);
			x2.cz_ur = (-b + pdelta.cz_ur) / (2 * a);
			x3.cz_rz = (-b + pdelta.cz_rz) / (2 * a);
			x3.cz_ur = (-b + pdelta.cz_ur) / (2 * a);
			x4.cz_rz = (-b + pdelta.cz_rz) / (2 * a);
			x4.cz_ur = (-b - pdelta.cz_ur) / (2 * a);
		}
	}

	void wyswietl_wynik() {
		if (a != 0 && d == 0) {

			printf("Delta= %f \n", delta.cz_rz);

			//1.1
			//deltar = 8.204060;
			if (delta.cz_rz > 0) {
				printf("x1dr = %f \n", x1.cz_rz);
				printf("x2r = %f \n", x2.cz_rz);
				printf("\n");
				
			}

			//1.2
			if (delta.cz_rz == 0) {
				printf("x1r = %f \n", x1.cz_rz);
			}

			//1.3
			if (delta.cz_rz < 0) {

				printf("x1 %f");
				formatuj_liczbe_zesp(x1);
				printf(" x2 ");
				formatuj_liczbe_zesp(x2);
				printf("\n");
			}

		}
		//2.
		if (a == 0 && b != 0 && d == 0) {
			printf("x1r = %f \n", x1.cz_rz);
		}

		//3.
		if (a == 0 && b == 0 && (c != 0 || d != 0)) {
			printf("Rownanie sprzeczne \n");
		}

		//4.
		if (a == 0 && b == 0 && c == 0 && d == 0) {
			printf("Rownanie tozsamosciowe \n");
		}

		//5.
		if (a == 0 && b != 0 && d != 0) {
			printf("x1");
			formatuj_liczbe_zesp(x1);
		}

		//6.
		if (a != 0 && d != 0) {
			printf("Delta = %f ", delta.cz_rz);
			if (delta.cz_ur > 0)
				printf("+ ");
			printf("%fi\n", delta.cz_ur);

			printf("x1 ");
			formatuj_liczbe_zesp(x1);
			printf("\n");
			printf("x2 ");
			formatuj_liczbe_zesp(x2);
			printf("\n");
			printf("x3 ");
			formatuj_liczbe_zesp(x3);
			printf("\n");
			printf("x4 ");
			formatuj_liczbe_zesp(x4);
			printf("\n");
		}
	}

	int *getDane() {
		dane[0] = a;
		dane[1] = b;
		dane[2] = c;
		dane[3] = d;
		return dane;
	}

	Liczba_zespolona* getPierwiastki() {
		pierwiastek[0].cz_rz = x1.cz_rz;
		pierwiastek[0].cz_ur = x1.cz_ur;
		pierwiastek[1].cz_rz = x2.cz_rz;
		pierwiastek[1].cz_ur = x2.cz_ur;
		pierwiastek[2].cz_rz = x3.cz_rz;
		pierwiastek[2].cz_ur = x3.cz_ur;
		pierwiastek[3].cz_rz = x4.cz_rz;
		pierwiastek[3].cz_ur = x4.cz_ur;
		return pierwiastek;
	}
};

class Operacje:public Dane {
protected:
	Liczba_zespolona suma, roznica, iloczyn;

public:
	virtual void wykonaj_operacje(Liczba_zespolona delta) = 0;
	virtual void wyswietl_wynik() = 0;
};

class Dodawanie : public Pierwiastki, public Operacje {
public:
	Dodawanie(Liczba_zespolona *tab, int *dane) {
		a = dane[0];
		b = dane[1];
		c = dane[2];
		d = dane[3];

		x1 = tab[0];
		x2 = tab[1];
		x3 = tab[2];
		x4 = tab[3];
		suma.cz_rz = 0.0;
		suma.cz_ur = 0.0;
	}

	void wykonaj_operacje(Liczba_zespolona delta) {
		if (delta.cz_ur != 0) {
			suma.cz_rz = x1.cz_rz + x2.cz_rz + x3.cz_rz + x4.cz_rz;
			suma.cz_ur = x1.cz_ur + x2.cz_ur + x3.cz_ur + x4.cz_ur;
		}
		else if (delta.cz_rz > 0) {
			suma.cz_rz = x1.cz_rz + x2.cz_rz;
		}
		else if (delta.cz_rz < 0) {
			suma.cz_rz = x1.cz_rz + x2.cz_rz;
			suma.cz_ur = x1.cz_ur + x2.cz_ur;
		}
	}

	void wyswietl_wynik() {
		if (a != 0 && d == 0) {
			//1.1
			if (delta.cz_rz > 0) {
				printf("sr = %f \n", suma.cz_rz);
			}
			//1.3
			if (delta.cz_rz < 0) {
				printf("suma ");
				formatuj_liczbe_zesp(suma);
				printf("\n");
			}
		}
		//6.
		if (a != 0 && d != 0) {
			printf("suma ");
			formatuj_liczbe_zesp(suma);
			printf("\n");
		}
	}
};

class Odejmowanie :public Pierwiastki, public  Operacje {
public:
	Odejmowanie(Liczba_zespolona *tab, int *dane) {
		a = dane[0];
		b = dane[1];
		c = dane[2];
		d = dane[3];

		x1 = tab[0];
		x2 = tab[1];
		x3 = tab[2];
		x4 = tab[3];
		roznica.cz_rz = 0.0;
		roznica.cz_ur = 0.0;
	}

	void wykonaj_operacje(Liczba_zespolona delta) {
		if (delta.cz_ur != 0) {
			roznica.cz_rz = x1.cz_rz - x2.cz_rz - x3.cz_rz - x4.cz_rz;
			roznica.cz_ur = x1.cz_ur - x2.cz_ur - x3.cz_ur - x4.cz_ur;
		}
		else if (delta.cz_rz > 0) {
			roznica.cz_rz = x1.cz_rz - x2.cz_rz;
		}
		else if (delta.cz_rz < 0) {
			roznica.cz_rz = x1.cz_rz - x2.cz_rz;
			roznica.cz_ur = x1.cz_ur - x2.cz_ur;
		}
	}
	void wyswietl_wynik() {
		if (a != 0 && d == 0) {
			//1.1
			if (delta.cz_rz > 0) {
				printf("rr = %f \n", roznica.cz_rz);
			}
			//1.3
			if (delta.cz_rz < 0) {
				printf("roznica ");
				formatuj_liczbe_zesp(roznica);
				printf("\n");
			}
		}
		//6.
		if (a != 0 && d != 0) {
			printf("roznica ");
			formatuj_liczbe_zesp(roznica);
			printf("\n");
		}
	}
};

class Mnozenie : public Pierwiastki, public Operacje {
public:
	Mnozenie(Liczba_zespolona *tab, int *dane) {

		a = dane[0];
		b = dane[1];
		c = dane[2];
		d = dane[3];

		x1 = tab[0];
		x2 = tab[1];
		x3 = tab[2];
		x4 = tab[3];
		iloczyn.cz_rz = 0.0;
		iloczyn.cz_ur = 0.0;
	}

	void wykonaj_operacje(Liczba_zespolona delta) {
		if (delta.cz_ur != 0) {
			iloczyn.cz_rz = ((x1.cz_rz * x2.cz_rz - x1.cz_ur * x2.cz_ur) * (x3.cz_rz * x4.cz_rz - x3.cz_ur * x4.cz_ur)) - ((x1.cz_rz * x2.cz_ur + x2.cz_rz * x1.cz_ur) * (x3.cz_rz * x4.cz_ur + x4.cz_rz * x3.cz_ur));
			iloczyn.cz_ur = ((x1.cz_rz * x2.cz_rz - x1.cz_ur * x2.cz_ur) * (x3.cz_rz * x4.cz_ur + x4.cz_rz * x3.cz_ur)) + ((x1.cz_rz * x2.cz_ur + x2.cz_rz * x1.cz_ur) * (x3.cz_rz * x4.cz_rz - x3.cz_ur * x4.cz_ur));
		}
		else if (delta.cz_rz > 0) {
			iloczyn.cz_rz = x1.cz_rz * x2.cz_rz;
		}
		else if (delta.cz_rz < 0) {
			iloczyn.cz_rz = (x1.cz_rz * x2.cz_rz - x1.cz_ur * x2.cz_ur);
			iloczyn.cz_ur = (x1.cz_rz * x2.cz_ur + x2.cz_rz * x1.cz_ur);
		}
	}

	void wyswietl_wynik() {
		if (a != 0 && d == 0) {
			//1.1
			if (delta.cz_rz > 0) {
				printf("ir = %f \n", iloczyn.cz_rz);
			}
			//1.3
			if (delta.cz_rz < 0) {
				printf("iloczyn ");
				formatuj_liczbe_zesp(iloczyn);
				printf("\n");
			}
		}
		//6.
		if (a != 0 && d != 0) {
			printf("iloczyn ");
			formatuj_liczbe_zesp(iloczyn);
			printf("\n");
		}
	}

};

int main() {
	
	Bazowa *obiekt= new Bazowa();
	Operacje *operacje[3];

	obiekt->oblicz_rownanie();
	obiekt->formatuj_rownanie();
	obiekt->wyswietl_wynik();
	
	operacje[0] = new Dodawanie(obiekt->getPierwiastki(),obiekt->getDane());
	operacje[1] = new Odejmowanie(obiekt->getPierwiastki(), obiekt->getDane());
	operacje[2] = new Mnozenie(obiekt->getPierwiastki(), obiekt->getDane());

	operacje[0]->wykonaj_operacje(obiekt->obl_delta());
	operacje[0]->wyswietl_wynik();
	operacje[1]->wykonaj_operacje(obiekt->obl_delta());
	operacje[1]->wyswietl_wynik();
	operacje[2]->wykonaj_operacje(obiekt->obl_delta());
	operacje[2]->wyswietl_wynik();




	delete operacje[2];
	delete operacje[1];
	delete operacje[0];
	delete obiekt;



	system("pause");
	getchar();
}

//jest klasa jest obiekt
//na 4 dziedziczenie i polimorfizm
// na 5 typy generyczne
