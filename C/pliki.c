/*
Pawe� Swora
15.05.17r.

�wiczenie 9:
Celem �wiczenia jest sprawdzenie dzia�a�ania plik�w i ich zakres�w.
*/

#include <stdio.h>

int funkcja1(int parametr1){
    
int kwadrat;
 kwadrat=parametr1*parametr1;
 
 printf("Kwadrat podanej liczby wynosi %kwadrat ",parametr1);   
 return 0;   
}
int main()
{
    funkcja1(6);
    
    
                                                 
    system("pause"); 
}
