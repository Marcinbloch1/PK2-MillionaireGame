#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "millionaire_struct.h"
#include "statistics.h"
#include "operations.h"
//#include "vld.h"



int main()
{
	srand(time(NULL));
	millionaire *current, *head;	//declare a structure
	int max_q = 0;
	char *questions_file="questions.txt";
	char *statistics_file = "statistics.txt";

	statistics_struct *first_stat = read_statistics(statistics_file);	

	millionaire *first_millionaire = read_file(&head, &current, &max_q, questions_file);

	show_statistics(first_stat);

	while (menu() == 1)
	{
		random_question(first_millionaire, &max_q, first_stat);
		system("PAUSE");
		system("cls");
	}
	free_list(first_millionaire);

	write_statistics(first_stat, statistics_file);

	system("PAUSE");
	return 0;

}