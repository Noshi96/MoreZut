/*
tklimek@wi.zut.edu.pl
Pawe� Swora
29.05.17r.

�wiczenie 11:
PREPROCESOR

Plik nag��wkowy
*/
#warning dziala

#define liczba 3
#define pod(x) ((x)*(x))
//#define funkcje_h                               //spowoduje, �e kompilator skompiluje poni�szy kod tylko gdy zosta�a zdefiniowana odpowiednia sta�a 
#ifndef funkcje_h                                     //ifndef zadzia�e jesli nie bedzie definicji funkcjih                                            
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

