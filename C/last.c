/*  
    Nowy lab11
    
         Preprocesor - przygotowanie do kompilacji    If not define   an dev dyrektywa include za��czanie, dyrektywa timesw, else elif, warunkiem if mozna spr architekture(preprocesor to wysterowanie kompilatorem)
         preprocesors 4programesrs
         unDEF (odedefiniowanie wyrzucenie)
         jakie� makra
         sta�e modyfikator const 1 mozliwosc prepocesor 2 jakas....
         
         int*ptr                                         //moze to byc wska�nik na tablice// mo�emy przesuwa� adres//
         const int*zmienna        //wartosci na ktore wskazuje ska�nik nie mog� by� zmieniane//ale mozna przesuwa� wskaxnik adres
         int*const zmienn         //informacja ze wartosci mozna modyfikowac ale nie mozna przesuwa� wska�nika
         const int* const zmienn  // nie mozna modyfikowa� warto�ci i nie mo�na przesuwa� wska�nika
         
         
        ZAdanie
               odkopa� metody jak lab 8 
               pozabezpiecza� funkcje    //(sta�e zmienne w metodzie? n ma by� zabezpieczone 
               .
               .
               Pokza� preprocesor if not define // enumy tutaj zamkn�� and ifem 
               
               
               
               
               12 koniec
               19 last last 
               
    */
    /*

Pawe� Swora
29.05.17r.

�wiczenie 11:
PREPROCESOR

Plik og�lny
*/



#include <stdio.h>
#include "funkcje.h"
 

int main()
{ 
    
      printf("Nazwa pliku: %s\n",  __FILE__);
      pokaz0();                                                               //wy�wietla predefiniowane makra
        
 printf ("\n------------------------------------------------------\n");   
    
    printf ("Liczba %d\n", liczba);                                         ///preprocesor
    printf ("Liczba do kwadratu wynosi %d\n", pod(liczba));                 //preprocesor
    
             int *tab1;
              int rozmiartablicy1;
               int licz;
    
    
              printf("Podaj rozmiar tablicy \n");
               scanf("%d",&rozmiartablicy1);
tab1=(int*) malloc(rozmiartablicy1* sizeof(*tab1));                       //alokacja pamieci
                       
    
                wypelnij(tab1, rozmiartablicy1, licz);                     //wype�nienie tablicy
                 printf("Tablica ma postac: \n");
                  pokaz(tab1,rozmiartablicy1);                             //wy�wietlenie tablicy
    
    
    free(tab1);
    int zmienna;
    printf("\nWybierz zwierze:\n");
        printf("1. Pies\n2. Kot\n3. Mysz\n4. Ptak\n5. Lew\n6. Kuna\n7. Dzik\n");
scanf("%d",&zmienna);
switch(zmienna)
    {
    case pies:
         printf("Wybrales Psa\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;
    case kot:
         printf("Wybrales Kota\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;
    case mysz:
         printf("Wybrales Mysz\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;
    case ptak:
         printf("Wybrales Ptaka\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;
    case lew:
         printf("Wybrales Lwa\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;
    case kuna:
         printf("Wybrales Kune\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;
    case dzik:
         printf("Wybrales Dzika\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;
    default :
            printf("Wybrales wartosc ktorej nie ma w zakresie\n\n");
         printf("\n-------------------------------------------------------------------------\n\n"); 
         break;     
  };
  
    

   system("pause"); 
}
