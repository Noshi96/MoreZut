/*
Pawe� Swora
15.05.17r.

�wiczenie 9:
Celem �wiczenia jest sprawdzenie dzia�a�ania plik�w .

Plik nag��wkowy
*/

  int funkcja1(int parametr1); 
  int funkcja2(int zmiennaglob,int para2);
  void funkcja3(int zmienna);                        
  void funkcja4(int glob,int pakiet);
  
  int zmiennaglob;
  int para1;                                   //do kwadratu
  int para2;                                  //do kwadratu
  int zmienna;                                //do enuma
  int glob;                           //do zakresu globalnego
  int pakiet;                           //do zakresu pakietowego
//zmienne te powinny by� w obu plikach c a nie w .h wiec deklarujemy obie zmienne w obu plikach przy czym w jednej ma by� extern z pliku
//wychodz�cego a potem delarakcja w pliku wynikowym i warto�� w tym 1 przypisujemy, przez co bedzie juz w tym drugim
