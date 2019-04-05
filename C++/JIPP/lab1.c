#include<stdio.h>

int a, b, c, d;
float deltar, deltau ,deltr, pdeltar, pdeltau, x1r, x2r, x3r, x4r, x1u, x2u, x3u, x4u;
int main() {
	a = 1; 
	b = 1; 
	c = 1; 
	d = 0; 

	if (a > 0) {
		printf("%dxx", a);
	}
	else if(a<0){
		printf("%dxx", a);
	}
	else {
		printf("");
	}
	if (b > 0 && a!=0) {
		printf("+%dx", b);
	}
	else if (b > 0 && a == 0) {
		printf("%dx", b);
	}
	else if(b<0) {
		printf("%dx", b);
	}
	else if(b==0 && a!=0){
		printf("");
	}
	else {
		printf("");
	}
	if (c > 0) {
		printf("+%d", c);
	}
	else if(c<0){
		printf("%d", c);
	}
	else {
		printf("");
	}
	if (d > 0 && c == 0 && b==0 && a==0) {
		printf("%di=0", d);
	}
	else if (d > 0) {
		printf("+%di=0", d);
	}
	else if(d<0) {
		printf("%di=0", d);
	}
	else {
		printf("=0");
	}
	printf("\n");
	//printf("%dxx %dx %d %d = 0 \n",a,b,c,d);

	//1.
	if (a != 0 && d == 0) {
		deltar = b * b - 4 * a*c;
		printf("Delta= %f \n", deltar);


		//1.1
		//deltar = 8.204060;
		if (deltar > 0) {

			pdeltar = deltar;
		etykieta:
			pdeltar = 0.5*(pdeltar + (deltar / pdeltar));
			if (pdeltar != 0.5*(pdeltar + (deltar / pdeltar))) {
				goto etykieta;
			}
			else {
				//printf("obliczony pierwiastek z delty (1.12) %f \n", pdeltar);
			}

			//printf("obliczony pierwiastek z delty (1.13) %f  \n", pdeltar);

			x1r = (-b - pdeltar) / (2 * a);
			printf("x1r= %f \n", x1r);

			x2r = (-b + pdeltar) / (2 * a);
			printf("x2r= %f \n", x2r);
		}

		//1.2
		if (deltar == 0) {
			x1r = -(float)b / (2 * a);
			printf("x1r= %f \n", x1r);
		}

		//1.3
		if (deltar < 0) {
			x1r = -(float)b / (2 * a);
			printf("x1r= %f \n", x1r);

			if (deltar < 0) {
				deltar = -deltar;
			}

			pdeltar = deltar;
		etykieta2:
			pdeltar = 0.5*(pdeltar + (deltar / pdeltar));
			if (pdeltar != 0.5*(pdeltar + (deltar / pdeltar))) {
				goto etykieta2;
			}
			else {
				//printf("obliczony pierwiastek z delty %f \n", pdeltar);
			}


			x1u = (-pdeltar) / (2 * a);
			printf("x1u %f \n", x1u);

			x2r = x1r;
			printf("x2r= %f \n", x2r);

			x2u = -x1u;
			printf("x2u= %f \n", x2u);
		}

	}
	//2.
	if (a == 0 && b != 0 && d == 0) {
		x1r = -(float)c / b;
		printf("x1r= %f \n", x1r);
		/*float axx = 1;
		int bxx = 2;
		float wynik;
		wynik= axx / bxx;
		printf("%f\n", wynik);*/
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
		x1r = -(float)c / b;
		printf("x1r= %f \n", x1r);
		x1u = -(float)d / b;
		printf("x1u= %f \n", x1u);
		/*
		int axx = 10;
		int bxx = 3;
		int wynik = axx / bxx;
		printf("%d\n", wynik);
		*/
	}

	//6.
	if (a != 0 && d != 0) {
		
		//delta = deltar + deltau*i; //przyklad

		deltar = (b * b) - (4 * a*c);
		printf("deltar= %f \n", deltar);
		deltau = -(4 * a*d);
		printf("deltau= %f \n", deltau);
		
		pdeltar = ((deltar*deltar) + (deltau*deltau));
		//printf("Z tego liczony pierwiastek %f\n", pdeltar);

	etykieta3:
		pdeltar = 0.5*(pdeltar + (((deltar*deltar) + (deltau*deltau)) / pdeltar));
		if (pdeltar != 0.5*(pdeltar + (((deltar*deltar) + (deltau*deltau)) / pdeltar))) {
			goto etykieta3;
		}
		else {
			//printf("obliczony pierwiastek zagzniezdzonyR  %f \n", pdeltar);
		}

		deltr = ((pdeltar + deltar) / 2);
		pdeltar = deltr;
		//printf("Z tego liczony pierwiastek %f \n", pdeltar);

	etykieta4:

		pdeltar = 0.5*(pdeltar + (deltr / pdeltar));
		if (pdeltar != 0.5*(pdeltar + (deltr / pdeltar))) {
			goto etykieta4;
		}
		else {
			//printf("obliczony pierwiastek duzyR %f \n", pdeltar);
		}


		pdeltau = ((deltar*deltar) + (deltau*deltau));
		//printf("Z tego liczony pierwiastek %f \n", pdeltau);

	etykieta5:
		pdeltau = 0.5*(pdeltau + (((deltar*deltar) + (deltau*deltau)) / pdeltau));
		if (pdeltau != 0.5*(pdeltau + (((deltar*deltar) + (deltau*deltau)) / pdeltau))) {
			goto etykieta5;
		}
		else {
			//printf("obliczony pierwiastek zagzniezdzonyU  %f \n", pdeltau);
		}

		
		deltr = (pdeltau - deltar) / 2;
		pdeltau = deltr;
		//printf("Z tego liczony pierwiastek %f\n", pdeltau);
	etykieta6:
		pdeltau = 0.5*(pdeltau + ((deltr) / pdeltau));
		if (pdeltau != 0.5*(pdeltau + ((deltr) / pdeltau))) {
			goto etykieta6;
		}
		else {
			//printf("obliczony pierwiastek duzyU %f \n", pdeltau);
		}

		//printf("%f, %f\n",pdeltar,pdeltau);

		x1r = (-b - pdeltar) / (2 * a);
		x1u = (-b - pdeltau) / (2 * a);
		x2r = (-b - pdeltar) / (2 * a);
		x2u = (-b + pdeltau) / (2 * a);
		x3r = (-b + pdeltar) / (2 * a);
		x3u = (-b + pdeltau) / (2 * a);
		x4r = (-b + pdeltar) / (2 * a);
		x4u = (-b - pdeltau) / (2 * a);


		printf("x1r = %f\n", x1r);
		printf("x1u = %f\n", x1u);
		printf("x2r = %f\n", x2r);
		printf("x2u = %f\n", x2u);
		printf("x3r = %f\n", x3r);
		printf("x3u = %f\n", x3u);
		printf("x4r = %f\n", x4r);
		printf("x4u = %f\n", x4u);


	}
	system("pause");

	return 0;
}

