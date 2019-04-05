/*
Pawe³ Swora
03.04.17r.

Æwiczenie 5:
Celem æwiczenia jest sprawdzenie dzia³a³ania tablic.
*/


#include <stdio.h>



int main()
{
    
    char napis[]={'W','i','t','a','j',' ','w',' ','d','o','m'};
    printf("Napis %s\n",napis);
    int d;
    d=sizeof(napis);
    printf("napis ma %d znakow \n",d);
    
    printf("pierwszy znak to %c \n",napis[0]);
    
    int tabel[10];
    int a;
    a=sizeof(tabel)/sizeof(int);
    printf("Tablica ma %d znakow\n",a);
    
   printf("\n\n Tablica o wielkosci 10 ma w sobie 10 znakow \n ");
    int tabint[10]={1,2,3,4,5,6,7,8,9,10};
    int i;
    for(i=0; i<sizeof(tabint)/sizeof(int); i++)
{
   printf("%d\n",tabint[i]);   
}
   
   printf("\n\n Tablica o wielkosci 10 ma w sobie 4 znaki \n ");
    int tabint2[10]={1,2,3,4};
    int j;
    for(j=0; j<sizeof(tabint2)/sizeof(int); j++)
{
   printf("%d\n",tabint2[j]);   
}
   printf("\n\n Tablica o nieokreslonej wielkosci ma w sobie 4 znaki \n"); 
    int tabint3[]={1,2,3,4};
   int k;
    for(k=0; k<sizeof(tabint3)/sizeof(int); k++)
{
   printf("%d\n",tabint3[k]);   
}
 
 
 printf("\n\n Tablica dwuwymiarowa o wielkosci 3 na 3 ma w sobie 9 znakow \n");
 int matrix[3][3]={1,2,3,4,5,6,7,8,9};
 int x;
 int y;
 int z;
 x=sizeof(matrix)/sizeof(int);
 //y=sizeof(matrix[][3]);   //Wyrzuca b³¹d
 //z=sizeof(matrix[]);     //Wyrzuca b³¹d
 
printf("Wymiar matrix %d \n",x);
//printf("Wymiar matrix2 %d \n",y);
//printf("Wymiar matrix3 %d \n",z);
 
 
int matrix4[3][3]={11,12,13,14,15,16,17,18,19};
 int ma4;
 ma4=sizeof(matrix4)/sizeof(int);
 printf("\n Tablica matrix4 ma %d znakow\n",ma4);
     for(k=0; k<sizeof(matrix4)/sizeof(int)/3; k++)
{
     for(i=0; i<sizeof(matrix4)/sizeof(int)/3; i++){
   printf("%d\n",matrix4[k][i]);   
}}
 
int matrix5[3][3]={{21,22,23},{24,25,26},{27,28,29}};
 int ma5;
 ma5=sizeof(matrix5)/sizeof(int);
 printf("\n Tablica matrix5 ma %d znakow\n",ma5);
      for(k=0; k<sizeof(matrix5)/sizeof(int)/3; k++)
{
     for(i=0; i<sizeof(matrix5)/sizeof(int)/3; i++){
   printf("%d\n",matrix5[k][i]);   
}}
 
int matrix6[][3]={{31,32,33},{34,35,36},{37,38,39}};
 int ma6;
 ma6=sizeof(matrix6)/sizeof(int);
 printf("\n Tablica matrix6 ma %d znakow\n\n",ma6);
      for(k=0; k<sizeof(matrix6)/sizeof(int)/3; k++)
{
     for(i=0; i<sizeof(matrix6)/sizeof(int)/3; i++){
   printf("%d\n",matrix6[k][i]);   
}} 
//int matrix7[][]={{1,2,3},{4,5,6}};  //Wyrzuca b³¹d
//int matrix8[][]={1,2,3,4};         //Wyrzuca b³¹d  
 
system("pause");    
    
}


