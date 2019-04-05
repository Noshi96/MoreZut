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
	
char* (*grupy)(char*);

int main(int argc, char **argv){
	void *handle = dlopen("./39447.so2.lab02.lib.so", RTLD_LAZY);							// dopiero gdy wczytuje wywoluje//nie jest konieczne natychmiastowe przydzielenie zasobów// dostep do zasobow
		if(!handle){
			printf("\n %s \n",dlerror());
			printf("biblioteka");
			}
		else{
			grupy = dlsym(handle, "grupy");
			if(grupy==NULL){
				printf("funkcja");			
				}
			}
printf("\n");
printf("-------------\n");
 struct utmp* user;										//w strukturze sa informacje o userzee
 setutent();
 while(user=getutent()){									// zwraca kolejna linie z pliku utmp zwraca NULL jak przejdzie cały
		if(user->ut_type==USER_PROCESS){						// zalogowani uzytkownicy
			printf(" %s ",user->ut_user);

		if ((handle)&&(dlerror()==NULL)&&(grupy!=NULL)){

 int wlacz;	
 while( (wlacz = getopt(argc, argv, "ab") ) !=-1){						//kiedy skończą sie przelaczniki wypisuje -1
			char *dd;
			int j;
			int ngroups=0;
			gid_t *groups;
			struct passwd *pw;
			struct group *gr;                      
	switch(wlacz){
		case 'a':
			printf(" (%s) ", user->ut_host);
			printf("\n\n");
	break;
		case 'b':
				printf(" %s", grupy(user->ut_user));
			printf("]");			
	break;
	default: abort();
				}
			}printf("\n");		
}
	else {
		printf("\n");
		if((user=getutent())==NULL){
			printf("\nBrak biblioteki lub brak funkcji w bibliotece");
				}
			}
		}
optind=0;										//reset getopt
	}

 endutent();
 printf("\n____________\n");
 printf("\n\n\n");
	
if(handle){									//0 powodzenie handle licznik liczy do zera 
 dlclose(handle);							//jesli zamkne a nie otworzylem to sie wywali
}

 return 0;
}