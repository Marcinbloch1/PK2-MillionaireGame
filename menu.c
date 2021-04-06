#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

//function shows to user menu
int menu()
{
	printf("Welcome to the: Who wants to be a millionaire!\n");
	printf("Do you want to play?: (1-yes/2-no) ");
	int temp = 0;
	scanf_s("%d", &temp);
	return temp;
}

