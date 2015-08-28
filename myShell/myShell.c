/* 
 * File:   main.c
 * Author: Joshua
 *
 * Created on August 26, 2015, 9:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

/*
 * 
 */
int main() {
	int i;
	Param_t *paramsP;
	Param_t params = {NULL, NULL, 0, 0};

	for (i = 0 ; i < MAXARGS ; i++) {
		params.argumentVector[i] = NULL;
	}

  	paramsP = &params;

  	if(paramsP == NULL) {
  		fprintf(stdout, "Memory allocation failed\n");
  		exit(EXIT_FAILURE);
  	}

  	run_loop(paramsP);

	return (EXIT_SUCCESS);
}

