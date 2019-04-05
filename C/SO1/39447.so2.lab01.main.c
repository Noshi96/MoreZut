//SO2 IS1 210A LAB01
//Paweł Swora
//sp39447@zut.edu.pl

#include<stdio.h>
#include<utmp.h>
#include<unistd.h>
#include<stdlib.h>
#include<grp.h>
#include<pwd.h>

int main(int argc, char **argv){

printf("\n");

printf("-------------\n");

 struct utmp* user;										//w strukturze sa informacje o userzee

 setutent();
 
 while(user=getutent()){									// zwraca kolejna linie z pliku utmp zwraca NULL jak przejdzie cały
		if(user->ut_type==USER_PROCESS){						// zalogowani uzytkownicy
			printf(" %s ",user->ut_user);

 int wlacz;
 while( (wlacz = getopt(argc, argv, "ab") ) !=-1){						//kiedy skończą sie przelaczniki wypisuje -1
			int j;
			int ngroups=0;
			gid_t *groups;
			struct passwd *pw;
			struct group *gr;                      
	switch(wlacz){
		case 'a':
			printf(" (%s) ", user->ut_host);

	break;
		case 'b':printf("[");
			pw = getpwnam(user->ut_user);							//zawiera informacje o uzytkowniku
			if (getgrouplist(user->ut_user, pw->pw_gid, NULL, &ngroups)==-1){ // user, numer grupy(wybrany z passwd), wskaznik na grupe (gid_t), ilosc grup	(zwraca -1 gdy podana liczba grup jest mniejsza od podanje)	dla 0 sie nie wykona
				groups = malloc(ngroups * sizeof (gid_t));
				getgrouplist(user->ut_user, pw->pw_gid, groups, &ngroups);
					}
			for (j=0;j<ngroups;j++){
				printf ("(%s) ",getgrgid(groups[j])->gr_name);
					}
			printf("]");
				free(groups);
			
	break;

	default: abort();
				}
			}printf("\n");
		}
optind=0;										//reset getopt

	}

 endutent();
 printf("\n____________\n");
 printf("\n\n\n");

 return 0;
}