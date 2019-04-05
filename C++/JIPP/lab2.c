#include<stdio.h>
#include<math.h>


void wprowadz_dane(int *a, int *b, int *c, int *d) {
	printf("podaj a\n");
	scanf_s("%d", a);
	printf("podaj b\n");
	scanf_s("%d", b);
	printf("podaj c\n");
	scanf_s("%d", c);
	printf("podaj d\n");
	scanf_s("%d", d);
}

void formatuj_rownanie(int a, int b, int c, int d) {
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
float oblicz_d_r(int a, int b, int c) {
	float deltar = (b*b) - (4 * a*c);
	return deltar;
}

float oblicz_d_u(int a, int d) {
	float deltau = -(4 * a*d);
	return deltau;
}

float oblicz_p_d_r(float deltar, float deltau) {
	float pdeltar;
	pdeltar = sqrt((sqrt((deltar*deltar) + (deltau*deltau)) + deltar) / 2);
	return pdeltar;
}

float oblicz_p_d_u(float deltar, float deltau) {
	float pdeltau;
	pdeltau = sqrt((sqrt((deltar*deltar) + (deltau*deltau)) - deltar) / 2);
	return pdeltau;

}
void oblicz_rownanie(int a, int b, int c, int d, float *x1r, float *x1u, float *x2r, float *x2u, float *x3r, float *x3u, float *x4r, float *x4u) {

	float deltar, deltau, pdeltar, pdeltau, deltr;
	
	if (a != 0 && d == 0) {
		deltar = oblicz_d_r(a, b, c);
		deltau = oblicz_d_u(a, d);
		//1.1
		//deltar = 8.204060;
		if (deltar > 0) {
			pdeltar = oblicz_p_d_r(deltar, deltau);
			*x1r = (-(float)b - pdeltar) / (2 * a);
			*x2r = (-(float)b + pdeltar) / (2 * a);
		}
		//1.2
		if (deltar == 0) {
			*x1r = -(float)b / (2 * a);	
		}
		//1.3
		if (deltar < 0) {
			deltar = -deltar;
			pdeltar = oblicz_p_d_r(deltar, deltau);
			*x1r = (float)-b / (2 * a);
			*x1u = (float)-(pdeltar / (2 * a));
			*x2r = *x1r;
			*x2u = -*x1u;
		}
	}
	//2.
	if (a == 0 && b != 0 && d == 0) {
		*x1r = -((float)c / b);
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
		*x1r = -((float)c / b);	
		*x1u = -((float)d / b);	
	}
	//6.
	if (a != 0 && d != 0) {
		deltar = oblicz_d_r(a, b, c);
		deltau = oblicz_d_u(a, d);
		pdeltar = oblicz_p_d_r(deltar, deltau);
		pdeltau = oblicz_p_d_u(deltar, deltau);
		*x1r = (-b - pdeltar) / (2 * a);
		*x1u = (-b - pdeltau) / (2 * a);
		*x2r = (-b - pdeltar) / (2 * a);
		*x2u = (-b + pdeltau) / (2 * a);
		*x3r = (-b + pdeltar) / (2 * a);
		*x3u = (-b + pdeltau) / (2 * a);
		*x4r = (-b + pdeltar) / (2 * a);
		*x4u = (-b - pdeltau) / (2 * a);
	}
}
void dodaj(float deltar, float deltau, float *x1r, float *x1u, float *x2r, float *x2u, float *x3r, float *x3u, float *x4r, float *x4u, float*sr, float*su) {
	if (deltau != 0) {
		*sr = *x1r + *x2r + *x3r + *x4r;
		*su = *x1u + *x2u + *x3u + *x4u;
	}
	else if (deltar > 0) {
		*sr = *x1r + *x2r;
	}
	else if (deltar < 0) {
		*sr = *x1r + *x2r;
		*su = *x1u + *x2u;
	}
}
void odejmij(float deltar, float deltau, float *x1r, float *x1u, float *x2r, float *x2u, float *x3r, float *x3u, float *x4r, float *x4u, float*rr, float*ru) {
	if (deltau != 0) {
		*rr = *x1r - *x2r - *x3r - *x4r;
		*ru = *x1u - *x2u - *x3u - *x4u;
	}
	else if (deltar > 0) {
		*rr = *x1r - *x2r;
	}
	else if (deltar < 0) {
		*rr = *x1r - *x2r;
		*ru = *x1u - *x2u;
	}
}
void pomnoz(float deltar, float deltau, float *x1r, float *x1u, float *x2r, float *x2u, float *x3r, float *x3u, float *x4r, float *x4u, float*ir, float*iu) {
	if (deltau != 0) {
		*ir = ((*x1r * *x2r - *x1u * *x2u) * (*x3r * *x4r - *x3u * *x4u)) - ((*x1r * *x2u + *x2r * *x1u) * (*x3r * *x4u + *x4r * *x3u));
		*iu = ((*x1r * *x2r - *x1u * *x2u) * (*x3r * *x4u + *x4r * *x3u)) + ((*x1r * *x2u + *x2r * *x1u) * (*x3r * *x4r - *x3u * *x4u));
	}
	else if (deltar > 0) {
		*ir = *x1r * *x2r;
	}
	else if (deltar < 0) {
		*ir = (*x1r * *x2r - *x1u * *x2u);
		*iu = (*x1r * *x2u + *x2r * *x1u);
	}
}
void wyswietl_wynik(int a, int b, int c, int d, float x1r, float x1u, float x2r, float x2u, float x3r, float x3u, float x4r, float x4u, float sr, float su, float rr, float ru, float ir, float iu) {
	if (a != 0 && d == 0) {
		float deltar = oblicz_d_r(a, b, c);
		//printf("Delta= %f \n", deltar);

		//1.1
		//deltar = 8.204060;
		if (deltar > 0) {
			printf("x1r = %f \n", x1r);
			printf("x2r = %f \n", x2r);
			printf("\n");
			printf("sr = %f \n", sr);
			printf("rr = %f \n", rr);
			printf("ir = %f \n", ir);
		}

		//1.2
		if (deltar == 0) {
			printf("x1r = %f \n", x1r);
		}

		//1.3
		if (deltar < 0) {
		
			printf("x1r = %f \n", x1r);
			printf("x1u = %f \n", x1u);
			printf("x2r = %f \n", x2r);
			printf("x2u = %f \n", x2u);
			printf("\n");
			printf("sr = %f \n", sr);
			printf("su = %f \n", su);
			printf("rr = %f \n", rr);
			printf("ru = %f \n", ru);
			printf("ir = %f \n", ir);
			printf("iu = %f \n", iu);
		}

	}
	//2.
	if (a == 0 && b != 0 && d == 0) {
		printf("x1r = %f \n", x1r);

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
		printf("x1r = %f \n", x1r);
		printf("x1u = %f \n", x1u);
	}

	//6.
	if (a != 0 && d != 0) {
		float deltar = oblicz_d_r(a, b, c);
		float deltau = oblicz_d_u(a, d);
			printf("Delta = %f ", deltar);
			if (deltau > 0)
				printf("+ ");
			printf("%fi\n", deltau);
		printf("x1r = %f\n", x1r);
		printf("x1u = %f\n", x1u);
		printf("x2r = %f\n", x2r);
		printf("x2u = %f\n", x2u);
		printf("x3r = %f\n", x3r);
		printf("x3u = %f\n", x3u);
		printf("x4r = %f\n", x4r);
		printf("x4u = %f\n", x4u);
		printf("\n");
		printf("sr = %f \n", sr);
		printf("su = %f \n", su);
		printf("rr = %f \n", rr);
		printf("ru = %f \n", ru);
		printf("ir = %f \n", ir);
		printf("iu = %f \n", iu);
	}
}

int main() {

	int a=0, b=0, c=0, d=0;
	float deltar=0, deltau=0, pdeltar, pdeltau, x1r, x2r, x3r, x4r, x1u, x2u, x3u, x4u, sr=0, su=0, rr=0, ru=0, ir=0, iu=0;

	wprowadz_dane(&a,&b,&c,&d);
	formatuj_rownanie(a, b, c, d);
	deltar=oblicz_d_r(a,b,c);
	deltau=oblicz_d_u(a,d);
	oblicz_rownanie(a, b, c, d, &x1r, &x1u, &x2r, &x2u, &x3r, &x3u, &x4r, &x4u);
	printf("\n\n");
	dodaj(deltar, deltau, &x1r, &x1u, &x2r, &x2u, &x3r, &x3u, &x4r, &x4u, &sr, &su);
	odejmij(deltar, deltau, &x1r, &x1u, &x2r, &x2u, &x3r, &x3u, &x4r, &x4u, &rr, &ru);
	pomnoz(deltar, deltau, &x1r, &x1u, &x2r, &x2u, &x3r, &x3u, &x4r, &x4u, &ir, &iu);
	printf("\n\n");
	wyswietl_wynik(a, b, c, d, x1r, x1u, x2r, x2u, x3r, x3u, x4r, x4u, sr, su, rr, ru, ir, iu);

	printf("\n");

	system("pause");
}

//0 u 0 usuwamy zera przy wyswietlaniu
//x1 do x4 do skrot trzeba wszystkie
//oblicz rownanie wysietlamy torzsamosciowe
//biblio
//oblicz rownanie to poprzedni kod
