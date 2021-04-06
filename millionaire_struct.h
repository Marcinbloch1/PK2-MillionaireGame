#ifndef MILLIONAIRE_H
#define MILLIONAIRE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure of millionaire game
typedef struct list
{
	struct list *next;
	int id;
	char*question;
	char * answer_a;
	char * answer_b;
	char * answer_c;
	char * answer_d;
	char * correct_answer;
}millionaire;

#endif

