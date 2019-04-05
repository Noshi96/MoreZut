//SO2 IS1 210A LAB03
//Paweł Swora
//sp39447@zut.edu.pl

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<time.h>
#include<sys/wait.h>

extern char **environ;

void start(char **argv, int argc){
	if(argc==1||strlen(argv[1])==0){
		exit(0);
		}
	else{
		//printf("\nok\n");
		}
	}

int down_x(int x){
	int v=x;
	while(x&=x-1)
		v=x;
	return v;
	}

char *maintext(int argc, char **argv){ 
	char *text;
	int ln_text;
	int tmp;
	
	ln_text=strlen(argv[1]);
	tmp=down_x(ln_text);

	text=malloc((down_x(ln_text))*sizeof(char));
	strncpy(text, argv[1], tmp);						//jesli jest potega 2
	if(ln_text&(ln_text-1)){				//sprawdza czy liczba jest potega 2
		
		strncpy(text, argv[1], tmp);			//przypisuje jesli nie jest potega 2
		return text;
			}
		return text;	
		}

char *divileft(char *newText, char *text, int size){
	newText=malloc(size*sizeof(char));
	if(size!=0){
		strncpy(newText, text, size/2);
		
		}
	else{exit(0);}
	return newText;
	}

char *diviright(char *newText, char *text, int size){
	newText=malloc(size*sizeof(char));
	if(size!=0){
		strncpy(newText, text+size/2, size/2);
		
		}
	else{exit(0);}
	return newText;
	}

int main(int argc, char **argv){
    start(argv, argc);
	char *text;
	char *newtextLefttmp, *sklej, *newtextRighttmp, *newr, *newl;
	int *status, size, ln_text;

		ln_text=strlen(argv[1]);
		size=(down_x(ln_text));
		text=maintext(argc, argv);
		newr=diviright(newtextRighttmp, text, size);
		newl=diviright(newtextRighttmp, text, size);
	
	
	if(argc==2){
		sklej=malloc(strlen(text)*sizeof(char));
		strcat(sklej,text);
		}
	else if(argc==3){
		sklej=malloc(strlen(text)*sizeof(char));
		strcat(sklej,argv[2]);
		strcat(sklej," ");
		strcat(sklej,text);
		}
			
			pid_t c_pid =fork();
	if(c_pid<0){
			perror("Fork failed \n");
			}

	if(c_pid>0){
		c_pid=fork();

		if(c_pid<0){
			perror("Fork failed \n");
			}	
		
		if(c_pid==0){
			execl("a.out","a.out",divileft(newtextLefttmp, text, size),sklej,NULL);
			}	
		else{
			
			if(wait(status)==-1)
				
				if(WIFEXITED(status)==0){
			
						printf("blad waita  \n");
					}
			
			if(wait(status)==-1)
				if(WIFEXITED(status)==0){
					
						printf("blad waita  \n");
					}	
			}
		}
	else if(c_pid==0){
		execl("a.out","a.out",diviright(newtextRighttmp, text, size),sklej,NULL);
		}
	
	printf("%d %s \n",(int)getpid(),sklej);

	free(sklej);
	free(text);
	free(newr);
	free(newl);

 return 0;
}