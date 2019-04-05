#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/*
   22.05.2017 Lab 10
   Jêdrzej B³aszczak
*/ 

int direction_inc_int (const void *a, const void *b)
{
    if ((*(int*)a)>(*(int*)b)) return 1;
    if ((*(int*)a)<(*(int*)b)) return -1;
    return 0;
}

int direction_dec_int(const void *a, const void *b)
{
    if ((*(int*)a)>(*(int*)b)) return -1;
    if ((*(int*)a)<(*(int*)b)) return 1;
    return 0;
}

void print(int* tab, unsigned size)
{
          for (int i = 0; i < size; i++)
          printf("%d ", tab[i]);
          printf("\n\n");
}

int bubblesort (int* tab, unsigned size, int direction(const void* , const void*))
{
    
       for( int i = 0; i < size; i++ )
              {
                    for( int j = 0; j < size - 1; j++ )
                    {
                         if( direction(&tab[j], &tab[j+1])==1 )
                         std::swap( tab[ j ], tab[ j + 1 ] );
            
                    }
              }return (*tab);
}


int main()
{
    int tab[] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 0};
    print(tab, sizeof(tab)/sizeof(int));
    bubblesort(tab, sizeof(tab)/sizeof(int), &direction_inc_int);
    print(tab, sizeof(tab)/sizeof(int));
    
    system("pause");
}


 
  //x = 2, y = 1
}




/*
   22.05.2017 Lab 10
   Jêdrzej B³aszczak
*/ 
 
/*
int direction_inc_int (const void *a, const void *b)
{
    if ((*(int*)a)>(*(int*)b)) return 1;
    if ((*(int*)a)<(*(int*)b)) return -1;
    return 0;
}

int direction_dec_int(const void *a, const void *b)
{
    if ((*(int*)a)>(*(int*)b)) return -1;
    if ((*(int*)a)<(*(int*)b)) return 1;
    return 0;
}

void print(int* tab, unsigned size)
{
     int i=0;
          for (i;i<size;i++)
          printf("%d ", tab[i]);
          printf("\n\n");
}

int bubblesort (int* tab, unsigned size, int direction(const void* , const void*))
{
    void swap(void *x,void *y);
      int i=0;         
       for(i; i < size; i++ )
              {    int j=0;
                    for(j;j<size-1;j++)
                    {
                         if( direction(&tab[j], &tab[j+1])==1 )
                         swap( tab[ j ], tab[ j + 1 ] );
            
                    }
              }return (*tab);
}


int main()

{
    int tab[] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 0};
    print(tab, sizeof(tab)/sizeof(int));
    bubblesort(tab, sizeof(tab)/sizeof(int), &direction_inc_int);
    print(tab, sizeof(tab)/sizeof(int));
    
    system("pause");
}
*/
