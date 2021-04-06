#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "millionaire_struct.h"

//function reads questions from file and add them to millionaire structure
//head-first element of millionaire structure, 
//current-current element of millionaire structure
//max_q-max number of questions
//file_name-name of the file
millionaire *read_file(millionaire *head, millionaire *current, int *max_q, const char* file_name);


#endif
