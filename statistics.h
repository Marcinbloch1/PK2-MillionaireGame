#ifndef STATISTICS_H
#define STATISTICS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure of statistics
typedef struct stat
{
	int game_played;
	int win_million;
	int win;
}statistics_struct;

//function reads statistics from file to statistic structure
//file_name-name of the file
statistics_struct *read_statistics(const char* file_name);

//function prints information about statistics
//first_stat-first element of statistic structure
void show_statistics(statistics_struct *first_stat);

//function saves statistics to file
//first_stat-first element of statistic structure
//file_name-name of the file
void write_statistics(statistics_struct *first_stat, const char* file_name);

#endif