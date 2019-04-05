/*
tklimek@wi.zut.edu.pl
Pawe³ Swora
29.05.17r.

Æwiczenie 11:
PREPROCESOR

Plik nag³ówkowy
*/
#warning dziala

#define liczba 3
#define pod(x) ((x)*(x))
//#define funkcje_h                               //spowoduje, ¿e kompilator skompiluje poni¿szy kod tylko gdy zosta³a zdefiniowana odpowiednia sta³a 
#ifndef funkcje_h                                     //ifndef zadzia³e jesli nie bedzie definicji funkcjih                                            
int wypelnij(int* const tab, const unsigned size, int liczby);   
 void pokaz(const int* const tab,const unsigned size);
  void pokaz0();
  
  enum zwierze{
       pies=1,
       kot,
       mysz,
       ptak,
       lew,
       kuna,
       dzik
       };
#endif   

