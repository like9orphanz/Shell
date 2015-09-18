/* 
 * File:   myShell.c
 * Created on August 26, 2015, 9:26 PM
 * Authors: Joshua			
 *		    Sam
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unistd.h"
#include <sys/wait.h>
#include "parse.h"

/*
 * 
 */
int main(int argc, char *argv[])
{
       //*************************************************when not in back ground mode do not let commands be saved into the argv********NO USER INPUT********** 

	// Variables
	int i;
	char *inStr;
	
	do
	{
	// Structs
	Param_t *paramsP;
	
	// Initialize struct
	Param_t params = {NULL, NULL, 0, 0};
	for (i = 0 ; i < MAXARGS ; i++) params.argumentVector[i] = NULL;
  	paramsP = &params;
        
	
 	// Read parse and assign user input to struct

	
	
        printf("---> ");
	
  	inStr = readLine();
 	parseStr(inStr, paramsP);   
	launch(paramsP);
        if(argc == 2 && strcasecmp(inStr, "-Debug"))
		printParams(paramsP);      	
        }while(strcasecmp(inStr, "exit"));
	
 	


return (0); 
}
