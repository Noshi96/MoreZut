/*
Pawe³ Swora
22.05.17r.

Æwiczenie 10:
Celem æwiczenia jest sprawdzenie dzia³a³ania wskaŸników do funkcji.

Plik ogólny
*/

#include <iostream>
#include <stdio.h>
using namespace std;


//Funkcje


              int sortuj(int*tab, unsigned size, int kierunek(void*,void*)){       //funkcja sortowania b¹belkowego 
                    int i=0;
                     for(i;i<size;i++){
                      int j=0;                 
                       for(j;j<size-1;j++ ){
                        if(kierunek(&tab[j],&tab[j+1])==1)
                         swap(tab[j],tab[j+1]);
            
                                           }
                                       }
return (*tab);          
                                                                                  }
                                                                                  
                                                                                  
              int kierunek_r(void*a, void*b){                                      //funckja sortuj¹ca rosn¹co
                    if ((*(int*)a)>(*(int*)b)) return 1;                           //rzutowanie na inta
                     if ((*(int*)a)<(*(int*)b)) return -1;                         //rzutowanie na inta
return 0;
                                           }
                                           

              int kierunek_m(void*a, void*b){                                       //funkcja sortuj¹ca malej¹co
                    if ((*(int*)a)<(*(int*)b)) return 1;                            //rzutowanie na inta        
                     if ((*(int*)a)>(*(int*)b)) return -1;                          //rzutowanie na inta
return 0;
                                            }


              void pokaz(int*tab, unsigned size){                                   //funkcja wyœwietlaj¹ca tablice
                    int i=0;
                     for (i;i<size;i++)
                      printf("%d ",tab[i]);
                        printf("\n\n");
                                                }
             
                                                                                  
                                                                                  
              int wypelnij(int*tab, unsigned size, int liczby){                     //funkcja wype³niaj¹ca podan¹ tablice
                    int i=0;
                     for(i;i<size;i++){
                      printf("Podaj %d liczbe \n",i);
                       scanf("%d",&liczby);
                        tab[i]=liczby;                
                                      }
                                                              }
             
                                                          
int main()

{
    
             int *tab1;
              int rozmiartablicy1;
               int licz;
                
    
             printf("Podaj rozmiar tablicy do posortowania \n");
              scanf("%d",&rozmiartablicy1);
tab1=(int*) malloc(rozmiartablicy1* sizeof(*tab1));
                       
    
                wypelnij(tab1, rozmiartablicy1, licz);
                 printf("Tablica do posortowania ma postac: \n");
                  pokaz(tab1,rozmiartablicy1);
                
               printf("\n Wcisnij 1 jesli chcesz posortowac rosnaco, 2 jesli malejaco i 3 jesli oba \n");
                int kom; 
                 scanf("%d", &kom);
                 
                
                 switch (kom){
                  case 1:   
                   sortuj(tab1, rozmiartablicy1 , &kierunek_r);
                    printf("Posortowana rosnaco tablica ma postac: \n");
                     pokaz(tab1,rozmiartablicy1); 
                      break;
                             
                    
                   case 2:   
                    sortuj(tab1, rozmiartablicy1 , &kierunek_m);
                     printf("Posortowana malejaco tablica ma postac: \n");
                      pokaz(tab1,rozmiartablicy1);
                        break;
                               
                      
                   case 3:   
                    sortuj(tab1, rozmiartablicy1 , &kierunek_r);
                     printf("Posortowana rosnaco tablica ma postac: \n");
                      pokaz(tab1,rozmiartablicy1);
                       sortuj(tab1, rozmiartablicy1 , &kierunek_m);
                        printf("Posortowana malejaco tablica ma postac: \n");
                         pokaz(tab1,rozmiartablicy1);
                          break;
                                }

 printf("\n----------------------------------------------------------------------------------------- \n");                                
                                
                       printf("\nSortowanie malejace i rosnace wczesniej stworzonej tablicy \n");         
                        int tab[] = {4,31,2,14,24,9,4,2,30,56,99,23,46};
                         printf("Tablica ma postac: \n");
                          pokaz(tab, sizeof(tab)/sizeof(int));
                          
                           printf("Posortowana rosnaco \n");
                            sortuj(tab, sizeof(tab)/sizeof(int),&kierunek_r);
                             pokaz(tab, sizeof(tab)/sizeof(int));
                                        
                              printf("Posortowana malejaco \n");
                               sortuj(tab, sizeof(tab)/sizeof(int),&kierunek_m);
                                pokaz(tab, sizeof(tab)/sizeof(int));
                                
                 free(tab1);
    
system("pause");
}
