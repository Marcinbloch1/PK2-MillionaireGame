#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"
#include "menu.h"
#include "game.h"


//function reads questions from file and add them to millionaire structure
//head-first element of millionaire structure, 
//current-current element of millionaire structure
//max_q-max number of questions
//file_name-name of the file
millionaire *read_file(millionaire *head, millionaire *current, int *max_q, const char* file_name)
{
	FILE *fp;
	char line[128];
	char *question = "";
	char *answer_a = "";
	char *answer_b = "";
	char *answer_c = "";
	char *answer_d = "";
	char *correct_answer = "";

	head = current = NULL;
	fp = fopen(file_name, "r");

	while (fgets(line, sizeof(line), fp))
	{
		if (line[0] >= 'A' && line[0] <= 'Z')
			question = _strdup(line);
		else if(line[0]=='a' && line[1]=='.')
			answer_a = _strdup(line);
		else if (line[0] == 'b' && line[1] == '.')
			answer_b = _strdup(line);
		else if (line[0] == 'c' && line[1] == '.')
			answer_c = _strdup(line);
		else if (line[0] == 'd' && line[1] == '.')
			answer_d = _strdup(line);
		else
		{
			correct_answer = _strdup(line);

			millionaire *node = malloc(sizeof(millionaire));

			node->id = (*max_q);
			node->question = question;
			node->answer_a = answer_a;
			node->answer_b = answer_b;
			node->answer_c = answer_c;
			node->answer_d = answer_d;
			node->correct_answer = correct_answer;

			node->next = NULL;

			if (head == NULL)
			{
				current = head = node;
			}
			else
			{
				current = current->next = node;
			}
			(*max_q)++;
		}
	}

	fclose(fp);
	return head;
}