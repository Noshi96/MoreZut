/*

06.03.2017
Pawel Swora


Program wyœwietla iloœæ bajtów na jakich operuj¹ podane zmienne w bajtach.
*/

#include <stdio.h>



int main()
{
          char znak;
          int liczba;
          
          
        printf("sizeof char: %u\n", sizeof(char));
         printf("sizeof int: %u\n", sizeof(int));
          printf("sizeof float: %u\n", sizeof(float));
           printf("sizeof double: %u\n", sizeof(double));
            printf("sizeof long double: %u\n", sizeof(long double));
             printf("sizeof short: %u\n", sizeof(short));
              printf("sizeof long: %u\n", sizeof(long));
               printf("sizeof long long: %u\n", sizeof(long long));
                printf("sizeof unsigned: %u\n", sizeof(unsigned));
         
         system("pause");
}
