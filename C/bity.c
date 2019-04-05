/*

13.03.2017
Pawel Swora

Program wyœwietla zakresy minimalne i makksymalne zmiennych ca³kowitych 
ze znakiem i bez zbaku.
*/

#include <stdio.h>



int main()
{
    char zm_char=1;
     unsigned char zm_uchar=1;
     
      printf("Char ze znakiem \n\n");
       printf("Wielkosc char w bajtach: %d\n",sizeof(zm_char)); 
        
        zm_char=zm_char<<sizeof(zm_char)*8-1;
         zm_uchar=~zm_uchar+1;
                      
          printf("Zakres Min to: %d\n",zm_char);
           printf("Zakres Max to: %d\n\n",~zm_char);
           
            printf("Zakres Max bez znaku to: %u\n",zm_uchar);
             printf("Char bez znaku to 0\n\n\n");          
            
       
       
    int zm_int=1;
     unsigned int zm_uint=1;  
     
      printf("Int ze znakiem\n\n");
       printf("Wielkosc int w bajtach: %d\n",sizeof(zm_int));
                           
        zm_int=zm_int<<sizeof(zm_int)*8-1;
         zm_uint=~zm_uint+1;  
                         
          printf("Zakres Min to: %d\n",zm_int);
           printf("Zakres Max to: %d\n\n",~zm_int);
           
            printf("Zakres Max bez znaku to: %u\n",zm_uint);
             printf("Int bez znaku to 0\n\n\n");       
     
     
     
    short zm_short=1;
     unsigned short zm_ushort=1;
       
      printf("Short ze znakiem\n\n");
       printf("Wielkosc short w bajtach: %d\n",sizeof(zm_short));
        
        zm_short=zm_short<<sizeof(zm_short)*8-1;
         zm_ushort=~zm_ushort+1;
         
          printf("Zakres Min to: %d\n",zm_short);      
           printf("Zakres Max to: %d\n\n",~zm_short);
           
            printf("Zakres Max bez znaku to: %u\n",zm_ushort);
             printf("Short bez znaku to 0\n\n\n");  
           
           
                 
    long zm_long=1;
     unsigned zm_ulong=1;  
     
      printf("Long ze znakiem\n\n");
       printf("Wielkosc long w bajtach: %d\n",sizeof(zm_long));
         
        zm_long=zm_long<<sizeof(zm_long)*8-1;
         zm_ulong=~zm_ulong+1;
         
          printf("Zakres Min to: %d\n",zm_long);
           printf("Zakres Max to: %d\n\n",~zm_long);
           
            printf("Zakres Max bez znaku to: %u\n",zm_ulong);
             printf("Long bez znaku to 0\n\n\n"); 
              
                  
                           
    long long zm_longlong=1ll;
     unsigned long long zm_ulonglong=1ll;
       
      printf("Long long ze znakiem\n\n");
       printf("Wielkosc long long w bajtach: %d\n",sizeof(zm_longlong));
          
        zm_longlong=zm_longlong<<sizeof(zm_longlong)*8-1;
         zm_ulonglong=~zm_ulonglong+1;
          
          printf("Zakres Min to: %lld\n",zm_longlong);
           printf("Zakres Max to: %lld\n\n",~zm_longlong);
           
            printf("Zakres Max bez znaku to: %llu\n",zm_ulonglong);
             printf("Long long bez znaku to 0\n\n\n");
           
           
           
     system("pause");

}
