#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

Param_t *new_paramt(void)
{
    Param_t *new_paramt = (Param_t *) malloc(sizeof(Param_t));
    new_paramt->inputRedirect = NULL;
    new_paramt->outputRedirect = NULL;
    new_paramt->argumentCount = 0;
    new_paramt->background = 0;
    new_paramt->inputRedirect = (char *) malloc(sizeof(char) * CMD_LEN);
    new_paramt->outputRedirect = (char *) malloc(sizeof(char) * CMD_LEN);
    
    int i;
    for(i=0; i < MAXARGS; i++)
    {
        new_paramt->argumentVector[i] = (char *) malloc(sizeof(char) * CMD_LEN);
        return ((new_paramt != NULL)? new_paramt:NULL);
    }   
}

void printParams(Param_t * param)
{
int i;
printf ("InputRedirect: [%s]\n",
 (param->inputRedirect != NULL) ? param->inputRedirect:"NULL");
printf ("OutputRedirect: [%s]\n",
 (param->outputRedirect != NULL) ? param->outputRedirect:"NULL");
printf ("Background: [%d]\n", param->background);
printf ("ArgumentCount: [%d]\n", param->argumentCount);
for (i = 0; i < param->argumentCount; i++)
printf("ArgumentVector[%2d]: [%s]\n", i, param->argumentVector[i]);
}

