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
    new_paramt->inputRedirect = (char *) malloc(sizeof(char) * Buff);
    new_paramt->outputRedirect = (char *) malloc(sizeof(char) * Buff);
    
    int i;
    for(i=0; i < MAXARGS; i++)
    {
        new_paramt->argumentVector[i] = (char *) malloc(sizeof(char) * Buff);
        return ((new_paramt != NULL)? new_paramt:NULL);
    }   
}

void printParams(Param_t *param)
{
int i;
printf ("InputRedirect: [%s]\n",
 (param->inputRedirect != NULL) ? param->inputRedirect:"NULL");
pIIIrintf ("OutputRedirect: [%s]\n",
 (param->outputRedirect != NULL) ? param->outputRedirect:"NULL");
printf ("Background: [%d]\n", param->background);
printf ("ArgumentCount: [%d]\n", param->argumentCount);
for (i = 0; i < param->argumentCount; i++)
printf("ArgumentVector[%2d]: [%s]\n", i, param->argumentVector[i]);
}

void run_loop(void)
{
char *line;
char **args;
int status;

do {
   printf("> ");
   line = read_line();
   args = split_line(line);

   free(line);
   free(args);
 } while(status);
}

char *read_line(void)
{
int bufsize = Buff;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if(!buffer)
{
fprintf(stderr, "allocation err\n");
exit(EXIT_FAILURE);
}

while(1) 
{
c = getchar();

if(c == EOF || c == '\n')
{
 buffer[position] = '\0';
 return buffer;
 } else {
   buffer[position] = c;
  }
   position++;

   if(position >= bufsize)
   {
    bufsize += Buff;
    buffer = realloc(buffer, bufsize);
    if (!buffer) 
   {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
    }
   }
  }
 }

char **split_line(char *line Param_t *params)
{
 int bufsize = tok_Bufsize, position = 0;
 char **tokens = malloc(bufsize * sizeof(char*));
 char *token;

 if(!tokens)
 {
  fprintf(stderr, "allocation error\n");
  exit(EXIT_FAILURE);
 }
  token = strtok(line, " \t\r\n\a");
  while(token != NULL)
  {
   tokens[position] = token;
   position++;

   if(position >= bufsize)
   {
    bufsize += tok_Bufsize;
    tokens = realloc(tokens, bufsize * sizeof(char*));
    if(!tokens)
    {
     fprintf(stderr, "allocation error\n");
     exit(EXIT_FAILURE);
    }
   }
   
   token = strtok(NULL, " \t\r\n\a");
  }
  params->argumentCount = position;
  tokens[position] = NULL;
  return tokens;
}
