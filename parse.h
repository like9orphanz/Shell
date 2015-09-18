/* 
 * File:   parse.h
 * Author: Joshua
 *
 * Created on August 26, 2015, 9:26 PM
 */

#ifndef PARSE_H
#define	PARSE_H


/* don’t test program with more than this many tokens for input */
#define MAXARGS 32
#define Buff 1024
#define tok_Bufsize 64

/* structure to hold input data */
struct PARAM
{
 char *inputRedirect; /* file name or NULL */
 char *outputRedirect; /* file name or NULL */
 int background; /* either 0 (false) or 1 (true) */
 int argumentCount; /* number of tokens in argument vector */
 char *argumentVector[MAXARGS]; /* array of strings */
};
/* a typedef so we don’t need to use "struct PARAM" all the time */
typedef struct PARAM Param_t;

void printParams(Param_t *);

char * readLine();

void parseStr(char *, Param_t *);

int launch(Param_t *);
#endif	/* PARSE_H */
