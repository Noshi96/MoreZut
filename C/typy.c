/*
Pawe� Swora
27.03.17r.

�wiczenie 4:
Typy danych, bloki w programie warunki i petle (while, do while, for)
*/


#include <stdio.h>
#include <setjmp.h>


int main()
{l1:{
          //Wy�wietlenie zmiennej w bloku oraz poza nim
 
         unsigned  wynik;
          wynik=5;
           
          {
           unsigned  wynik=4;
            printf("Wynik w bloku tej samej zmiennej %u\n",wynik);          
          }

          printf("Wynik poza blokiem tej samej zmiennej %u\n\n",wynik);
           

            //Zwyk�y warunek
            
             if(wynik==5){printf("Jesli wynik wynosi 5 wypisz  %u\n\n\n\n",wynik);}
             printf("\n----------------------------------------------------------------------------\n");
             //Warunek po kt�rym wykonuje si� suma
             
             int a=3;
             int b=4; 
             int c=5;
             int suma;
             
             if(a<b)
                   {                 
                    suma=a+c;
                     printf("Wynik sumy jesli a jest mniejsze od b wynosi %d\n\n\n",suma);
                    }
                     else {
                         suma=a+b;
                          printf("Wynik sumy jesli a jest wieksze  od b wynosi %d\n\n\n",suma);
                          }
               printf("\n--------------------------------------------------------------------------\n");
               //Ile razy wykona�a si� p�tla while 
                     
             int x=1;
             int z=5;      
             while(x<z)
             {
              printf("Petla nr %d \n",x);  
              x+=1;
                    
             }                             
                printf("Petla wykonala sie %u  razy (petla while) \n\n\n",x-1);   
            printf("\n-----------------------------------------------------------------------------\n");        
           //Suma liczb p�tl� while
           { 
            int y=5;
            int i;
            suma=0;
             
             while(i<=y){
                         suma+=i;
                         i++;
                         }
             printf("Suma liczb od 1 do %d wynosi %d (petla while)\n\n",y,suma);
             }
             printf("\n----------------------------------------------------------------------------\n");
             //Suma liczb petl� do while
                  {                 
                 int y=6;
                 int i=0;
                 int suma=0;           
                          
                      do{
                          suma+=i;
                          i++;
                          }
                               
                       while(i<=y);   
                       printf("Suma liczb od 1 do %d wynosi %d (petla do while)\n\n\n\n",y,suma);
                  }  
              printf("\n--------------------------------------------------------------------------\n");
             //Wy�wietlanie znak�w p�tl� for
               {
                int i;
                int y=125;       
                 for(i=0; i<=y; i++){
                       printf("***");  
                                    }
                                     printf("\n Znaki * wyswietlane petla for \n\n\n\n");           
               }
               printf("\n-----------------------------------------------------------------------\n");
               //P�tla for wykorzystuj�ca continue �eby wy�wietli� liczby parzyste
               {
               int i;
               int y=30;
                printf("Liczby w zakresie od 1 do %d parzyste to (petla for)\n ",y);
                  for (i=1 ;i<=y;i++) {
                  if (i%2==1) continue ;
                   printf ("%d ", i);
                                       }  
               }
                printf("\n---------------------------------------------------------------------\n"); 
               //P�tla for wykorzystuj�ca break
               {
                  int i;
                  int y=25;
                  int x=21;
                      for(i=1; i<=y; i++){
                         if (i>=x) break;      
                                        } 
                     printf("\n\n\n\n Petla dla %d powtorzen zostala przerwana i wykonala sie %d razy (petla for)\n\n",y ,i);
               }
               printf("\n----------------------------------------------------------------------\n");
               // Silnia p�tl� for
              l2: {
                int i;
                int sil=1;
                int y=7;
                 for (i=2; i<=y; i++){
                     sil=sil*i;
                                      }
                  printf("\n\n\n Silnia z %d wynosi %d  (petla for) \n\n\n\n",y,sil);
                                                         
               }
               printf("\n----------------------------------------------------------------------\n");
               // Funkcja goto ktora skacze do wyznaczonych miejsc w programie (tylko w petli)
               int g;
               
                   printf("Jesli chcesz wykonac caly program jeszcze raz nacisnij 1. Jesli chcesz zobaczyc jeszcze raz silnie nacisnij 2 lub zakoncz naciskajac 3\n ") ;       
                   scanf("%d",&g);
                   if (g==1){goto l1;}        
                   if (g==2){goto l2;}     
                   if (g==3){goto l3;}      
                              
                            
       
 l3: system("pause");  
    
}
}
