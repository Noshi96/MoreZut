/*
Pawe³ Swora
10.04.17r.

Æwiczenie 6:
Celem æwiczenia jest sprawdzenie dzia³a³ania wskaŸników.
*/


#include <stdio.h>



int main()
{
  

                 int liczbb=35;
         int *wsk1=&liczbb;
                      printf("Adres wskaznika %d \n",wsk1);
                 printf("Adres liczby %d \n",&wsk1);
                 printf("Liczba %d \n",*wsk1);
      
                 *wsk1=27;
    
               printf("Adres wskaznika %d \n",wsk1);
                 printf("Adres liczby %d \n",&wsk1);
                printf("Liczba %d \n\n",*wsk1);
    
    
                          int liczba=12;
                          
                   int *wsk2=&liczba;
                       
                  printf("Liczba i wskaznik na liczbe %d %d \n",liczba,*wsk2);
                 printf("Wskaznik na liczbe %d \n\n",*wsk2);
                
                 
    
    
    int *wsk=(int*)calloc(1,sizeof(int));
     if(!wsk) {
    free(wsk);
    return-1;
                }
                else{   
                     *wsk=55;
                     printf("Wskaznik : %d\n\n", *wsk);  
                     }
    
    
    
       int tab[10]={1,2,3,4,5,6,7,8,9,0};
       
       int *wsktab=tab;
       
        int *adres=&tab[0];
           int x;
           int y;
           y=sizeof(tab)/sizeof(int);
           x=sizeof(wsktab);
           printf("Adres pierwszego elementu w tablicy %d \n",adres);
           printf("Rozmiar tablicy %d \n",y);
           printf("Rozmiar adresu wskaznika  %d \n",x);
           
           
    int i;
    for(i=0; i<sizeof(tab)/sizeof(int); i++){
             
             printf("%d\n",tab[i]);
             }
    for(i=0; i<10; i++)
    {
    printf("%d\n",*(wsktab+i));
}


printf("\nRozmiar wskaznika int %d\n",sizeof(int*));
printf("Rozmiar wskaznika double %d\n",sizeof(double*));
printf("Rozmiar wskaznika float %d\n\n",sizeof(float*));



int (*wsktab1)[10];
         
    wsktab1=(int(*)[10])tab;//dp wsktab=tab
    
    for(i=0; i<sizeof(*wsktab1)/sizeof(int);i++){
    printf("Wartosc komorki \n %d to %d \n",i,(*wsktab1[i]));//wsktab[i]
}
    for(i=0; i<sizeof(*wsktab1)/sizeof(int);i++){
    printf("Adres komorki\n %d to %d \n",i,wsktab1[i]); }
    
    system("pause"); 
}
