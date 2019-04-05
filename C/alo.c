/*
Pawe³ Swora
24.04.17r.

Æwiczenie 7:
Celem æwiczenia jest sprawdzenie dzia³a³ania alokacji
malloc, calloc.
*/


#include <stdio.h>
#include <stdlib.h>


int main()
{
    //------------wektory-------------------------------------
    int *intPtr;                                                            
    long *longPtr;
          longPtr=malloc(sizeof(long));
    
    
       intPtr=(int*)malloc(10*sizeof(int));                                 //przydziela pamiec i zwraca ^wskaŸnik do przydzielonej pamiêci^
       intPtr=(int*)calloc(10,sizeof(int));                              //przydzeila pamiêæ dla tablicy zawierajacej x elementów  ^^ 0 pamiec
    
         if(!intPtr)
           return-1;
    
    *intPtr=12;
    *(intPtr+2)=2;
    intPtr[2]=12;
    
 //--------------------alokacja dla tablicy dwu wymiarowej----------------------------------------   
    
    
   long **ptr; 
   long *tab[4]; 
    
    ptr=(long**)calloc(4,sizeof(long*));                       //tablica która przechowuje adresy (long** to rzutowanie)      zwraca void wiec sie typy nie zgadzaja wiec rzutujemy
  
          if(!ptr)
           return -1;
  
    int i=0;
          for(i;i<4;i++){                             //wype³nienie tablicy wektorami
                   
                 ptr[i]=(long*)calloc(5,sizeof(long));       //long bo w tablicy mamy juz longi
                   if(!ptr) return -1;
                                  }
  
  //-----------------alokacja dla  tablicy 3 wymiarowej        -------------------------------------------------------
  
  //long *tab2[4];          //to zastepuje calloca tego wyzej bo znamy iloœæ wierszy(tablica 4 wskaŸników)
  
  
  
                                                      
       int j,k;
                 int ***ptr2;
                       ptr2=(int***)calloc(3,sizeof(int**));
                        if(!ptr2) return -1;
                                              
                               for(i=0;i<3;i++){  
                                for(j=0;j<3;j++){
                                                 
                                 ptr2[j]=(long**)calloc(3,sizeof(long*));
                                  if(!ptr2[j]) return -1; 
                                                
                                    for(k=0;k<3;k++){
                                       ptr2[j][k]=(long*)calloc(3,sizeof(long));
                                        if(!ptr2[j][k]) return -1;
                                                     } 
                                                  }   
                                                 }                                                               
    system("pause"); 
}
