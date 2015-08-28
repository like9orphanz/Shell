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
int main(void)
{
  Param_t *params = new_paramt();
  if(params == NULL)
  {
   fprintf(stdout, "Memory allocation failed\n");
   exit(EXIT_FAILURE);

    return (EXIT_SUCCESS);
}

