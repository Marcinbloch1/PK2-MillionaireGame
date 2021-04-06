#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "operations.h"


//function checks if question has been shown before
//n_of_random-table of numbers which was drawn before
//first_op-first element of operations structure
int if_random(int n_of_random[], operations_struct *first_op)
{
	for (int i = 0; i < 12; i++)
	{
		if (n_of_random[i] == first_op->random_number)
			return 1;
	}
	n_of_random[first_op->num_q] = first_op->random_number;
	return 2;
}

//function set the probability of phone lifeline and audience lifeline
//probability_tab-table helps with setting probability
//first_op-first element of operations structure
void probability(char *probability_tab, operations_struct *first_op)
{
	for (int i = 0; i < 16; i++)
	{
		probability_tab[i] = first_op->correct_answer;
	}
	probability_tab[16] = 'a';
	probability_tab[17] = 'b';
	probability_tab[18] = 'c';
	probability_tab[19] = 'd';
}

//function which choose a random number
//ran-random number from 1-12, 
int randomize_num(int ran)
{
	return rand() % ran;
}

//funcion free allocated memory
//head-first element of millionaire structure, 
void free_list(millionaire *head)
{
	while (head)
	{
		
		millionaire *next_node = head;
		next_node = next_node->next;

		free(head->question);
		free(head->answer_a);
		free(head->answer_b);
		free(head->answer_c);
		free(head->answer_d);
		free(head->correct_answer);
		free(head);
		
		head = next_node;
	}
}