#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "millionaire_struct.h"

//structure of operations
//num_q-number of question, 
//user_answer-contains option which user has chosen, 
//correct_answer-correct answer, 
//if_end-shows if the game is ended, 
//money-amount of money, 
//money_guarantee-amount of guarantee money, 
//random_number-random number from 1-12, 
//check_return-shows if the game is ended, 
//max_q - max number of questions
typedef struct oper
{
	int num_q;
	char user_answer;
	char correct_answer;
	int if_end;
	int random_number;
	int check_return;
	int money;
	int money_guarantee;
}operations_struct;

//function checks if question has been shown before
//n_of_random-table of numbers which was drawn before
//first_op-first element of operations structure
int if_random(int n_of_random[], operations_struct *first_op);

//function set the probability of phone lifeline and audience lifeline
//probability_tab-table helps with setting probability
//first_op-first element of operations structure
void probability(char *probability_tab, operations_struct *first_op);

//function which choose a random number
//ran-random number from 1-12, 
int randomize_num(int ran);

//funcion free allocated memory
//head-first element of millionaire structure, 
void free_list(millionaire *head);

#endif