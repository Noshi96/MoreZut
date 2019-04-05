/*
Pawe³ Swora
29.05.17r.

Æwiczenie 11:
PREPROCESOR

Plik z funkcjami
*/
#include <stdio.h>

int wypelnij(/*const*/ int* const tab, const unsigned size, int liczby){//informacja ze wartosci mozna modyfikowac ale nie mozna przesuwaæ wskaŸnika //wartosci na ktore wskazuje wskaŸnik nie mog¹ byæ zmieniane                    //funkcja wype³niaj¹ca podan¹ tablice
                    int i=0;                              //jeœli const przed int nie dzia³a bo chce modyfikowaæ wartoœci
                     for(i;i<size;i++){
                      printf("Podaj %d liczbe \n",i);
                       scanf("%d",&liczby);
                        tab[i]=liczby;                
                                      }
                                                             }

  void pokaz(const int* const tab, const unsigned size){          // nie mozna modyfikowaæ wartoœci i nie mo¿na przesuwaæ wskaŸnika       //wartosci na ktore wskazuje wskaŸnik nie mog¹ byæ zmieniane                       //funkcja wyœwietlaj¹ca tablice
                    int i=0;
                     for (i;i<size;i++){                       //zamiast i size nie bedzie dzia³ac bo zmiania siê jego wartosc
                      printf("%d ",tab[i]);}
                        printf("\n\n");
                                                }
                                                
   void pokaz0(){
        
         printf("Nazwa pliku: %s\n",  __FILE__);           //Predefiniowane makra
      printf("Data: %s\n",  __DATE__);
      printf("Czas: %s\n",  __TIME__);
        
        }
