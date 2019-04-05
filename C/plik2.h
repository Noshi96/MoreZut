/*
Pawe³ Swora
15.05.17r.

Æwiczenie 9:
Celem æwiczenia jest sprawdzenie dzia³a³ania plików .

Plik nag³ówkowy
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
//zmienne te powinny byæ w obu plikach c a nie w .h wiec deklarujemy obie zmienne w obu plikach przy czym w jednej ma byæ extern z pliku
//wychodz¹cego a potem delarakcja w pliku wynikowym i wartoœæ w tym 1 przypisujemy, przez co bedzie juz w tym drugim
