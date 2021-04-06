#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lifelines.h"
#include "operations.h"


//function of fifty-fifty lifeline
//list-firt element of millionaire structure
//first_op-first element of operations structure
void half(millionaire *list, operations_struct *first_op)
{
	if (list == NULL) printf("List is empty");
	else
	{
		millionaire *current = list;
		int current_num = 0;
		while (current_num != first_op->random_number)
		{
			current = current->next;
			current_num++;
		}

		printf("%s", current->question);

		int number_correct = 0;
		switch (current->correct_answer[0])
		{
			case 'a': number_correct = 0; break;
			case 'b': number_correct = 1; break;
			case 'c': number_correct = 2; break;
			case 'd': number_correct = 3; break;
		}
		int random_num = 4;
		int random_num2 = 4;

		do 
		{
			random_num = randomize_num(4);
		} while (random_num == number_correct);

		do
		{
			random_num2 = randomize_num(4);
		} while (random_num2 == number_correct || random_num2==random_num);

		char *table_of_answers[4];

		table_of_answers[0] = current->answer_a;
		table_of_answers[1] = current->answer_b;
		table_of_answers[2] = current->answer_c;
		table_of_answers[3] = current->answer_d;

		switch (random_num)
		{
			case 0: table_of_answers[0] = "a.\n"; break;
			case 1: table_of_answers[1] = "b.\n"; break;
			case 2: table_of_answers[2] = "c.\n"; break;
			case 3: table_of_answers[3] = "d.\n"; break;
		}
		switch (random_num2)
		{
			case 0: table_of_answers[0] = "a.\n"; break;
			case 1: table_of_answers[1] = "b.\n"; break;
			case 2: table_of_answers[2] = "c.\n"; break;
			case 3: table_of_answers[3] = "d.\n"; break;
		}
		
		printf("%s%s%s%s", table_of_answers[0], table_of_answers[1], table_of_answers[2], table_of_answers[3]);

		return;

	}
}

//function of phone a friend lifeline
//first_op-first element of operations structure
void phone(operations_struct *first_op)
{
	char probability_tab[20];
	probability(&probability_tab, first_op);
	int r = randomize_num(sizeof(probability_tab));
	printf("In that case i would answer: %c\n", probability_tab[r]);
}

//function of ask the audience lifeline
//first_op-first element of operations structure
void audience(operations_struct *first_op)
{
	char probability_tab[20];
	probability(&probability_tab, first_op);

	int l = 0, an_a = 0, an_b = 0, an_c = 0, an_d = 0;
	while (l < 10)
	{
		int r = randomize_num(sizeof(probability_tab));
		if (probability_tab[r] == 'a')
		{
			an_a = an_a + 10;
		}
		else if (probability_tab[r] == 'b')
		{
			an_b = an_b + 10;
		}
		else if (probability_tab[r] == 'c')
		{
			an_c = an_c + 10;
		}
		else if (probability_tab[r] == 'd')
		{
			an_d = an_d + 10;
		}

		l++;
	}
	char per = '%';
	printf("Audience results: \na.%d%c\nb.%d%c\nc.%d%c\nd.%d%c\n", an_a, per, an_b, per, an_c, per, an_d, per);
}

//function checks if user has used lifeline
//first_life-first element of lifelines structure
//first_op-first element of operations structure
//head-first element of millionaire structure, 
void check_half(lifelines_struct *first_life, operations_struct *first_op, millionaire *head)
{
	if ((first_life->half_h) == 0)
	{
		half(head, first_op);
		(first_life->half_h) = 1;
	}
	else
		used_lifeline();
}

//function checks if user has used lifeline
//first_life-first element of lifelines structure
//first_op-first element of operations structure
void check_phone(lifelines_struct *first_life, operations_struct *first_op)
{
	if ((first_life->phone_h) == 0)
	{
		phone(first_op);
		(first_life->phone_h) = 1;
	}
	else
		used_lifeline();
}

//function checks if user has used lifeline
//first_life-first element of lifelines structure
//first_op-first element of operations structure
void check_audience(lifelines_struct *first_life, operations_struct *first_op)
{
	if ((first_life->audience_h) == 0)
	{
		audience(first_op);
		(first_life->audience_h) = 1;
	}
	else
		used_lifeline();
}

//function prints an information about used lifeline
void used_lifeline()
{
	printf("\nYou have already used that lifeline!\n");
}