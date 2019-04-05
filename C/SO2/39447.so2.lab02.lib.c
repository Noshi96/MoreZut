//SO2 IS1 210A LAB02
//Paweł Swora
//sp39447@zut.edu.pl

#include<stdio.h>
#include<utmp.h>
#include<unistd.h>
#include<stdlib.h>
#include<grp.h>
#include<pwd.h>
#include<dlfcn.h>
#include<string.h>

char *grupy(char *gru){
			int size_str;										
	
			char *zwraca;

			int i,j,kop;
			int ngroups=0;
			gid_t *groups;
			struct passwd *pw;
			struct group *gr;
 
			printf("[");
			pw = getpwnam(gru);							//zawiera informacje o uzytkowniku
			if (getgrouplist(gru, pw->pw_gid, NULL, &ngroups)==-1){ // user, numer grupy(wybrany z passwd), wskaznik na grupe (gid_t), ilosc grup	(zwraca -1 gdy podana liczba grup jest mniejsza od podanje)	dla 0 sie nie wykona
				groups = malloc(ngroups * sizeof (gid_t));
				getgrouplist(gru, pw->pw_gid, groups, &ngroups);
					}
			
			for (j=0;j<ngroups;j++){
				size_str+=strlen(getgrgid(groups[j])->gr_name)+5;			//+znak na koncu stringa
					}

			zwraca=malloc(size_str*sizeof(char));
			strcpy(zwraca,"");

			for (j=0;j<ngroups;j++){
				strcat(zwraca," (");
				strcat(zwraca,getgrgid(groups[j])->gr_name);
				strcat(zwraca,") ");
					}
		
				free(groups);
			return zwraca;
		}		
















