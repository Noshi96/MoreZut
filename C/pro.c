/*
Pawe³ Swora
20.03.17r.

Program pokazuje zastosowanie parametrów.
Zawiera przyk³ady preinkrementacji oraz postinkrementacji i konwersji.
*/


#include <stdio.h>



int main()
{
    
  int a=5;
   int b=5; 
    int z;
    int x =5;
     float c;
     printf("a wynosi %d\n",a);
     printf("b wynosi %d\n",b);
     printf("x wynosi %d\n",x);
      printf("z to int \n");
      printf("c to float \n\n");
      
  z=a==b; //operacja przypisania z do a, a nastêpnie porównanie z b
   
    printf("Wynik z=a==b to %d\n",z);
     printf("Wynik z=a==b dla floata to %f\n",z);
      
    
  z=!b; // zanegowanie b przez operator not i przypisanie do z
   printf("Wynik z=!b to %d\n",z);
  z=a++; // zwiêksza zmienn¹ o jeden ale zrobi to dopiero przy nastepnej operacji(postinkrementacja)(pêtla for)
   printf("Wynik z=a++ to %d\n",z);
   z=++a; // zwiêksza zmienn¹ o jeden od razu (preinkrementacja)    
    printf("Wynik z=++a to %d\n",z);   
    
  z=a++ +b; // zwiêksza zmienn¹ a o jeden ale dopiero w nastêpnej operacji wiêc wyœwietli siê suma a i b nie zwiêkszona o jeden
   printf("Wynik z=a++ +b to %d\n",z);
   z=++a + !b ; // wczeœniej podeniesiona zmienna a o 1 teraz zostaje od razu podniesiony o kolejne 1 i dodana zostanie zanegowana zmienna b
    printf("Wynik z=++a + !b to %d\n\n",z);
    

  z=z+1; // oznacza tyle co ++z 
  printf("Wynik z=z+1 to %d\n",z);  
   z=z+z; 
    printf("Wynik z=z+z to %d\n",z);
    z+=2; // oznacza to samo co z=z+2
     printf("Wynik dla z+=2 to %d\n",z);
     z-=2; // oznacza to samo co z=z-2
      printf("Wynik dla z-=2 to %d\n\n\n",z);
     
   c=x/3.0; // 3.0 oznacza ¿e jest liczb¹ zmiennoprzecinkow¹
    printf("Wynik c=x/3.0 to %f\n",c);
   c=(float)x/3.0; // konwersja x na floata
    printf("Wynik c=(float)x/3.0 to %f\n",c);
   c=(float)x/3; // konwersja x na floata
    printf("Wynik c=(float)x/3 to %f\n",c);
   c=(int)x/3.0; // konwersja x na inta i liczba zmiennoprzecinkowa
    printf("Wynik c=(int)x/3.0 to %f\n",c);
   c=(int)x/3; // konwersja x na inta
     printf("Wynik c=(int)x/3 to %f\n\n",c);
     
    int d=4;
     int e=0;
      float f;
      f=d/3.0; // dzielenie przez liczbê zmiennoprzecinkow¹
      
      printf("d wynosi %d\n",d);
      printf("e wynosi %d\n",e);
      printf("f to float \n\n",e);
     
     
     
      printf("Wynik f=d/3.0 dla floata to %f\n\n",f);
       
    
    
    
    
  system("pause");  
    
}
