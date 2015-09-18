#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parse.h"

void printParams(Param_t *param) {
    int i;
    printf ("InputRedirect: [%s]\n",
    (param->inputRedirect != NULL) ? param->inputRedirect:"NULL");
  
    printf ("OutputRedirect: [%s]\n",
    (param->outputRedirect != NULL) ? param->outputRedirect:"NULL");
  
    printf ("Background: [%d]\n", param->background);
  
    printf ("ArgumentCount: [%d]\n", param->argumentCount);
  
    for (i = 0; i < param->argumentCount; i++) {
      printf("ArgumentVector[%d]: [%s]\n", i, param->argumentVector[i] );
    }
}

char *readLine() {
   // const char t;
    
    FILE *in = stdin;

    char *str = malloc(sizeof(char) * 100);
    if(str == NULL)
		fprintf(stderr, "MEMORY ALLOCATION FAILED\n");
	fgets(str, 100, in);
	size_t length = strlen(str);
	if(length == 1)
		return str;
	if(str[length - 1] == '\n')
		str[length - 1] = '\0';
	
    return str;
}
void parseStr(char *str, Param_t *param) {
	char *token;
        const char delimiter[] = " ";

        token = strtok(str,delimiter);
        if (token[0] == '\n') {
        	printf("---> ");
        	str = readLine();
        	parseStr(str, param);
        	return;
        }

        while (token != NULL) {

        	if (token[0] == '>') {
            		param->outputRedirect = &token[1];
            		//printf("param->outputRedirect = %s\n",param->outputRedirect);
                }	
        	else if (token[0] == '<') {
                	param->inputRedirect = &token[1];
            		//printf("param->inputRedirect = %s\n",param->inputRedirect);
        		}
        	else if (token[0] == '&') { // MAKE SURE TO CHECK ABOUT BEING LAST CHARACTER
            		param->background = 1;
            		//printf("param->background = %d\n",param->background);
        	}
       		else 
        	{
			param->argumentVector[param->argumentCount] = token;
                	//printf("param->ArgumentVector[%d] = %s\n",param->argumentCount, param->argumentVector[param->argumentCount]);
                	param->argumentCount++;
		}
        	token = strtok(NULL, delimiter);
    }
}

int launch(Param_t *param)
{
	pid_t pid;
        int status;
 
       	pid = fork();	
        if(pid == 0){
		if(param->inputRedirect){
                        FILE *fin = freopen(param->inputRedirect, "r", stdin);
                                if(!(fin)){
                                        fprintf(stdout, "Error! Input redirection failed.");
                                }
                }

		if(param->outputRedirect){
			FILE *fout = freopen(param->outputRedirect, "w", stdout);
				if(!(fout)){
					fprintf(stdout, "Error! Output redirection failed.");
				}
		}
		execvp(param->argumentVector[0], param->argumentVector);
	}
	else if(pid < 0){
		fprintf(stdout, "Error! Process fork failed.");
	}
	else{

		if(param->background != 1){
			waitpid(pid, &status, 0);
			printf("DONE WITH BACKGROUND\n");
		}
		 else {
         	    waitpid(pid, &status, WNOHANG);
   	            printf("DONE WITH BACKGROUND\n");
		}
	}	
	return 0;
		
}

