/*
Pawe³ Swora
15.05.17r.

Æwiczenie 9:
Celem æwiczenia jest sprawdzenie dzia³a³ania plików.

Plik z funkcjami
*/
#include <stdio.h>

 int zmiennaglob=2;
 int para2=4; 
  
 int funkcja2(int zmiennaglob,int para2){
     printf("Zmienne globalne wynosza %d %d\n\n",zmiennaglob,para2);
     
printf("\n-------------------------------------------------------------------------\n");     
//----------------------------------------------------------------------------------     
     printf("Podaj liczbe a zostana do niej dodane obie zmienne globalne \ni policzy sie z niej kwadrat \n");
      
     }
     
  
//------------------------------------------------------------------------------ 
 
  int funkcja1(int parametr1){
    
    int kwadrat;
      kwadrat=parametr1*parametr1;
      int podana;
       printf("Kwadrat podanej liczby %d (%d+%d+%d) wynosi %d \n",parametr1,podana=parametr1-zmiennaglob-para2,zmiennaglob,para2,kwadrat);
 printf("\n-------------------------------------------------------------------------\n"); 
//----------------------------------------------------------------------------------  
 
       
        printf("\nWybierz zwierze:\n");
        printf("1. Pies\n2. Kot\n3. Mysz\n4. Ptak\n5. Lew\n6. Kuna\n7. Dzik\n");   
 return 0;   
}

//-------------------------------------------------------------------

void funkcja3(int zmienna){
  enum zwierze{
       pies=1,
       kot,
       mysz,
       ptak,
       lew,
       kuna,
       dzik
       };   
         

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
  }
//--------------------------------------------------------------------------------------------
   extern int glob=199;
 static int pakiet=200;
 
  void funkcja4(glob,pakiet){
             
  printf("To jest zmienna o zakresie globalnym %d\n",glob); 
             printf("To jest zmienna o zakresie pakietowym %d\n",pakiet);
printf("\n-------------------------------------------------------------------------\n"); 
}
  
  
  
  
  
  
  
  
  
     
