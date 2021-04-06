#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "millionaire_struct.h"
#include "statistics.h"
#include "operations.h"
#include "lifelines.h"

//functions prints questions and answers on the screen		
//list-first element of millionaire structure,
//first_op-first element of operations structure
millionaire *showquestion(millionaire *list, operations_struct *first_op);

//function prints information about how much money user won		
//first_op-first element of operations structure
void win_million(operations_struct *first_op);

//function prints information about wrong answer and shows how much money user won		
//first_op-first element of operations structure
void wrong_answer(operations_struct *first_op);

//function change the amount of money		
//first_op-first element of operations structure
void how_much_money(operations_struct *first_op);

//function shows how much money user has		
//first_op-first element of operations structure
void show_money(operations_struct *first_op);

//function ptints information about good answer and check if user has answered to 12 question
//first_op-first element of operations structure
//head_stat-first element of statistic structure
void good_answer(operations_struct *first_op, statistics_struct *head_stat);

//function checks which option user has chosen		
//first_op-first element of operations structure
//first_life-first element of lifelines structure
//head-first element of millionaire structure, 
//head_stat-first element of statistic structure
void check_answer(operations_struct *first_op, 
	lifelines_struct *first_life, millionaire *head, statistics_struct *head_stat);

//function starts game and choose randomly questions from structure
//head-first element of millionaire structure, 
//max_q-max number of questions
//head_stat-first element of statistic structure
void random_question(millionaire *head, int *max_q, statistics_struct *head_stat);		

#endif
