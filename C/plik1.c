/*
Pawe³ Swora
15.05.17r.

Æwiczenie 9:
Celem æwiczenia jest sprawdzenie dzia³a³ania plików.

Plik ogólny
*/


#include <stdio.h>
#include "plik2.h"

int main()
{
    
    funkcja2(zmiennaglob,para2);                                  //wyœwietla zmienne globalne
//-------------------------------------------------------------------------------------------------------
 
      scanf("%d",&para1);                                         // wykonuje podniesienie do 2 potegi
        funkcja1(para1+zmiennaglob+para2);    
                                            
  
//--------------------------------------------------------------------------------------------------------------
         
          scanf("%d",&zmienna);                                   //enum zwierzat
            funkcja3(zmienna);  
               
               
//-------------------------------------------------------------------------------------------------------------- 

             funkcja4(glob,pakiet);                                          // zakresy zmiennych globalnych i pakietowych                                                                    
            //printf("\nTo jest zmienna o zakresie globalnym %d\n",glob); 
            // printf("To jest zmienna o zakresie pakietowym %d\n\n",pakiet);
     
   system("pause"); 
}
