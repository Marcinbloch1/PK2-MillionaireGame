#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "statistics.h"

//function ends program
void end_program()
{
	printf("Data in statistic file isn't a number\n");
	system("PAUSE");
	exit(1);
}

//function checks if in statistics file data are numbers
//file-opened statistics file
void check_file(FILE *file)
{
	char line[128];
	char *data = "";


	while (fgets(line, sizeof(line), file))
	{
		data = _strdup(line);
		int d_size = ((sizeof(data)) - 1);
		for (int i = 0; i < d_size; i++)
		{
			if (data[i]<'0' || data[i]>'9')
			{
				if (data[i] != 13)	//checking if enter
				{
					if (data[i] != 32)	//checking if space
					{
						free(data);
						end_program();
					}
				}
			}
		}
		free(data);
	}
}

//function reads statistics from file to statistic structure
//file_name-name of the file
statistics_struct *read_statistics(const char* file_name)
{
	int num = 0;

	FILE* file = fopen(file_name, "r");

	check_file(file);

	rewind(file);

	statistics_struct *node2=malloc(sizeof(statistics_struct));
	int temp = 0;
	while (!feof(file))
	{
		fscanf(file, "%d", &num);
		switch (temp)
		{
			case 0: node2->game_played=num;
			case 1: node2->win_million=num;
			case 2: node2->win=num;
		}
		temp++;
	}
	return node2;


	fclose(file);
}

//function prints information about statistics
//first_stat-first element of statistic structure
void show_statistics(statistics_struct *first_stat)
{
	printf("\nGames played: %d\n", first_stat->game_played);
	printf("\nWon million:  %d\n", first_stat->win_million);
	printf("\nWins: %d\n\n", first_stat->win);
}

//function saves statistics to file
//first_stat-first element of statistic structure
//file_name-name of the file
void write_statistics(statistics_struct *first_stat, const char* file_name)
{
	FILE* file = fopen(file_name, "w");

	fprintf(file, "%d \n", first_stat->game_played);
	fprintf(file, "%d \n", first_stat->win_million);
	fprintf(file, "%d ", first_stat->win);

	fclose(file);

	show_statistics(first_stat);

	free(first_stat);
}