#ifndef LIFELINES_H
#define LIFELINES_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "millionaire_struct.h"
#include "operations.h"

//structure of lifelines
//half_h-help variable which check if lifeline has been used before
//phone_h-help variable which check if lifeline has been used before
//audience_h-help variable which check if lifeline has been used before
typedef struct life
{
	int half_h;
	int phone_h;
	int audience_h;
}lifelines_struct;

//function of fifty-fifty lifeline
//list-firt element of millionaire structure
//first_op-first element of operations structure
void half(millionaire *list, operations_struct *first_op);

//function of phone a friend lifeline
//first_op-first element of operations structure
void phone(operations_struct *first_op);

//function of ask the audience lifeline
//first_op-first element of operations structure
void audience(operations_struct *first_op);

//function checks if user has used lifeline
//first_life-first element of lifelines structure
//first_op-first element of operations structure
//head-first element of millionaire structure, 
void check_half(lifelines_struct *first_life, operations_struct *first_op, millionaire *head);

//function checks if user has used lifeline
//first_life-first element of lifelines structure
//first_op-first element of operations structure
void check_phone(lifelines_struct *first_life, operations_struct *first_op);

//function checks if user has used lifeline
//first_life-first element of lifelines structure
//first_op-first element of operations structure
void check_audience(lifelines_struct *first_life, operations_struct *first_op);

//function prints an information about used lifeline
void used_lifeline();


#endif
