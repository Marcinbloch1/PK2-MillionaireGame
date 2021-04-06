#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include "operations.h"
#include "lifelines.h"

//function shows correct answers on the screen
//if you don't want to see correct answers you should comment 
//this function in showquestion function
void show_correct_answer(millionaire *current)
{
	printf("%s", current->correct_answer);
}

//functions prints questions and answers on the screen		
//list-first element of millionaire structure,
//first_op-first element of operations structure
millionaire *showquestion(millionaire *list, operations_struct *first_op)		
{
	if (list == NULL) printf("List is empty");
	else
	{
		millionaire *current = list;
		int a = 0;
		while (a != first_op->random_number)
		{
			current = current->next;
			a++;
		}

		printf("%s", current->question);
		printf("%s", current->answer_a);
		printf("%s", current->answer_b);
		printf("%s", current->answer_c);
		printf("%s", current->answer_d);
		show_correct_answer(current);	//shows correct answer, comment if you don't want to see correct answers
		printf("\n");
		char *correct_an = current->correct_answer;
		return correct_an[0];

	}
}

//function prints information about how much money user won		
//first_op-first element of operations structure
void win_million(operations_struct *first_op)		
{
	printf("\n\nCongratulations! You have won %d dollars!\n\n", first_op->money);
}

//function prints information about wrong answer and shows how much money user won		
//first_op-first element of operations structure
void wrong_answer(operations_struct *first_op)		
{
	printf("\nYour answer is wrong!\n\n");
	printf("\n\nCongratulations! You have won %d dollars!\n\n", (first_op->money_guarantee));
}

//function change the amount of money		
//first_op-first element of operations structure
void how_much_money(operations_struct *first_op)		
{
	switch (first_op->num_q)
	{
	case 0:	(first_op->money) = 0; (first_op->money_guarantee) = 0; break;
	case 1:	(first_op->money) = 500; break;
	case 2: (first_op->money) = 1000; (first_op->money_guarantee) = 1000; break;
	case 3: (first_op->money) = 2000; break;
	case 4: (first_op->money) = 5000; break;
	case 5: (first_op->money) = 10000; break;
	case 6: (first_op->money) = 20000; break;
	case 7: (first_op->money) = 40000; (first_op->money_guarantee) = 40000; break;
	case 8: (first_op->money) = 75000; break;
	case 9: (first_op->money) = 125000; break;
	case 10: (first_op->money) = 250000; break;
	case 11: (first_op->money) = 500000; break;
	}
}

//function shows how much money user has		
//first_op-first element of operations structure
void show_money(operations_struct *first_op)		
{
	printf("\nYou have: %d dollars", first_op->money);
	printf("\nYou have: %d dollars guarantee\n\n", first_op->money_guarantee);
}

//function ptints information about good answer and check if user has answered to 12 question
//first_op-first element of operations structure
//head_stat-first element of statistic structure
void good_answer(operations_struct *first_op, statistics_struct *head_stat)		 
{
	printf("\nGood answer!\n");
	(first_op->num_q)++;
	if ((first_op->num_q) == 12)
	{
		(first_op->money) = 1000000;
		(head_stat->game_played)++;
		(head_stat->win_million)++;
		(head_stat->win)++;
		win_million(first_op);
		(first_op->check_return) = 1;
	}
	(first_op->if_end) = 1;
}

//function checks which option user has chosen		
//first_op-first element of operations structure
//first_life-first element of lifelines structure
//head-first element of millionaire structure, 
//head_stat-first element of statistic structure
void check_answer(operations_struct *first_op, lifelines_struct *first_life, 
	millionaire *head, statistics_struct *head_stat)		
{
	if (first_op->user_answer == 'a' || first_op->user_answer == 'b' || 
		first_op->user_answer == 'c' || first_op->user_answer == 'd')
	{
		if (first_op->user_answer == first_op->correct_answer)
		{
			good_answer(first_op, head_stat);
		}
		else
		{
			wrong_answer(first_op);
			(head_stat->game_played)++;
			(first_op->check_return) = 1;
		}
	}
	else if (first_op->user_answer == 'q')
	{
		win_million(first_op);
		(head_stat->game_played)++;
		(head_stat->win)++;
		(first_op->check_return) = 1;
	}
	else if (first_op->user_answer == 'r')
	{
		check_half(first_life, first_op, head);
	}
	else if (first_op->user_answer == 't')
	{
		check_phone(first_life, first_op);
	}
	else if (first_op->user_answer == 'y')
	{
		check_audience(first_life, first_op);
	}
	else
	{
		printf("\nType again\n");
	}
}

//function starts game and choose randomly questions from structure
//head-first element of millionaire structure, 
//max_q-max number of questions
//head_stat-first element of statistic structure
void random_question(millionaire *head, int *max_q, statistics_struct *head_stat)		
{
	int n_of_random[12];

	operations_struct *node_operations = malloc(sizeof(operations_struct));
	lifelines_struct *node_lifelines = malloc(sizeof(lifelines_struct));
	node_lifelines->half_h = 0;
	node_lifelines->phone_h = 0;
	node_lifelines->audience_h = 0;
	(node_operations->num_q) = 0;

	while ((node_operations->num_q) < 12)
	{
		how_much_money(node_operations);

		node_operations->random_number = randomize_num(*max_q);

		int check_ran = if_random(n_of_random, node_operations);

		if (check_ran != 1)
		{
			show_money(node_operations);

			node_operations->correct_answer = showquestion(head, node_operations);
			node_operations->if_end = 0;

			while (node_operations->if_end == 0)
			{
				printf("Enter your answer(a, b, c, d), fifty-fifty(r), phone-a-friend(t), ask-the-audience(y), end game(q): \n");
				scanf_s(" %c", &(node_operations->user_answer));

				check_answer(node_operations, node_lifelines, head, head_stat);

				if (node_operations->check_return == 1)
				{
					free(node_operations);
					free(node_lifelines);
					return;
					
				}
			}
		}
	}

	
}