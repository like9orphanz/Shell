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
#define CMD_LEN 2048
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

char **format_args(char command[CMD_LEN], Param_t *params);

Param_t *new_paramt(void);

void printParams(Param_t *param);

#endif	/* PARSE_H */

