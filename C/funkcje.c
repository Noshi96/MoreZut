/*
Pawe� Swora
29.05.17r.

�wiczenie 11:
PREPROCESOR

Plik z funkcjami
*/
#include <stdio.h>

int wypelnij(/*const*/ int* const tab, const unsigned size, int liczby){//informacja ze wartosci mozna modyfikowac ale nie mozna przesuwa� wska�nika //wartosci na ktore wskazuje wska�nik nie mog� by� zmieniane                    //funkcja wype�niaj�ca podan� tablice
                    int i=0;                              //je�li const przed int nie dzia�a bo chce modyfikowa� warto�ci
                     for(i;i<size;i++){
                      printf("Podaj %d liczbe \n",i);
                       scanf("%d",&liczby);
                        tab[i]=liczby;                
                                      }
                                                             }

  void pokaz(const int* const tab, const unsigned size){          // nie mozna modyfikowa� warto�ci i nie mo�na przesuwa� wska�nika       //wartosci na ktore wskazuje wska�nik nie mog� by� zmieniane                       //funkcja wy�wietlaj�ca tablice
                    int i=0;
                     for (i;i<size;i++){                       //zamiast i size nie bedzie dzia�ac bo zmiania si� jego wartosc
                      printf("%d ",tab[i]);}
                        printf("\n\n");
                                                }
                                                
   void pokaz0(){
        
         printf("Nazwa pliku: %s\n",  __FILE__);           //Predefiniowane makra
      printf("Data: %s\n",  __DATE__);
      printf("Czas: %s\n",  __TIME__);
        
        }
