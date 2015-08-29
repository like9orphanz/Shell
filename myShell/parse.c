#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
      printf("ArgumentVector[%2d]: [%s]\n", i, param->argumentVector[i]);
    }
}

char *readLine() {
    const char t;
    FILE *in = stdin;

    char *str = malloc(sizeof(char) * 32);
    if (str == NULL) fprintf(stderr, "MEMORY ALLOCATION FAILED\n");

    fgets(str,32,in);

    /*if (fgets(str, 32, in) != NULL) {
        puts(str);
    }
    */

    return str;
}

void parseStr(char *str, Param_t *param) {
    char *token;
    const char delimiter[] = " ";

    token = strtok(str,delimiter);
    if (token[0] == '\n') {
        printf("Re enter string\n");
        str = readLine();
        parseStr(str, param);
        return;
    }

    while (token != NULL) {
        if (token[0] == '>') {
            param->outputRedirect = token;
            //printf("param->outputRedirect = %s\n",param->outputRedirect);
        }
        else if (token[0] == '<') {
            param->inputRedirect = token;
            //printf("param->inputRedirect = %s\n",param->inputRedirect);
        }
        else if (token[0] == '&') { // MAKE SURE TO CHECK ABOUT BEING LAST CHARACTER
            param->background = 1;
            //printf("param->background = %d\n",param->background);
        }
        else {
            param->argumentVector[param->argumentCount] = token;
            //printf("param->ArgumentVector[%d] = %s\n",param->argumentCount, param->argumentVector[param->argumentCount]);
            param->argumentCount++;
        }

        token = strtok(NULL, delimiter);
    }
}

