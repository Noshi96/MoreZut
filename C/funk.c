/*
Pawe³ Swora
08.05.17r.

Æwiczenie 8:
Celem æwiczenia jest sprawdzenie dzia³a³ania funkcji i zmiennych statycznych.
*/


#include <stdio.h>


int myFunction(int para1, double para2){
           int wynik=para1+para2;
           printf("Wynik to %d\n\n",wynik);
return 0;    
      
      }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------       
// -----2 czesc---------           
int myFunction2(int tab[], double para2){
    int x;
    x=sizeof(tab);                                                  // na stosie przechowywana jest kopia i pracujemy na kopi w pêtli
                         int i; 
                   for(i=0;i<para2;i++){
                     tab[i];
                      printf("%d miejsce w tablicy ma wartosc %d  %d\n\n",i,tab[i],x);}                    
return 0;    
      }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------       
      
int myFunctio3(int *tab1, int n){
      int i=1;
           for(i; i<n; i++){
              tab1[i]=tab1[i-1]+tab1[i];                                                   //przekazanie tablicy przez wskaŸnik
                  }
return 0;    
      }
      
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------      

int FunSta(int licz){
    
               static int zmien = 0;                                                            //bez static wartoœæ zmiennej w funkcji wraca do stanu z przed wykonania funkcji  
                zmien=zmien+licz;                                                               // z staticiem zmienna jest sta³a w funkcji i przy kolejnych wykonaniach jest zapisany poprzedni stan
                  printf("Funkcja dodawania ze zmienna statyczna wykonuje sie %d razy a wynik jej to %d \n\n" ,licz,zmien);
return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
int FunSta2(int licz2){
    
               int zmien2 = 0;                                                            //bez static wartoœæ zmiennej w funkcji wraca do stanu z przed wykonania funkcji  
                zmien2=zmien2+licz2;                                                               // z staticiem zmienna jest sta³a w funkcji i przy kolejnych wykonaniach jest zapisany poprzedni stan
                  printf("Funkcja dodawania bez zmiennej statycznej wykonuje sie %d razy a wynik jej to %d \n\n" ,licz2,zmien2);
return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------- 

int main()
{
    int p1=5;
    int p2=4;
    
    
    myFunction(p1,p2);
    
printf("\n---------------------------------------------------------------------------- \n");

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------    
    
int tab[]={1,2,3,4,5,6,7,8,9,0};
myFunction2(tab,5);

printf("\n----------------------------------------------------------------------------\n");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
 
  int t2=7;                                                                                                                                          // scanf("%d",t2);                 
  int tab2[]={1,2,3,4,5,6,7,8,9,0};    
   int k=0;
    for(k;k<sizeof(tab2)/sizeof(int); k++){
            printf("%d  miejsce tablicy to %d\n",k,tab2[k]);
            }
            printf("\n Po dodaniu %d elementow\n",t2);
    myFunctio3(tab2,t2);  
     for(k=0;k<t2; k++){
            printf("%d  miejsce tablicy to %d\n",k,tab2[k]);
            }
      
printf("\n-----------------------------------------------------------------------------\n");

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------      
            
            int i=0;
            int stat=5;
             for(i; i<stat; i++){       
                      FunSta(stat);
                    }
                    
printf("\n----------------------------------------------------------------------------\n");
                    
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------                  
                    
                    int stat2=5;
                    int j=0;
                       for(j; j<stat2; j++){       
                        FunSta2(stat);
                    }
                    
printf("\n-----------------------------------------------------------------------------\n");
           
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------                    
     //static int      
     
     
     
     
     
     
     
     
     
                                                     
    system("pause"); 
}
