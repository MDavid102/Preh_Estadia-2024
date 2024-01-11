/*
 * union.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

union Example{
	int var;
	int var1;
};

int main(void){
	union Example ex1;
	ex1.var = 12;

	printf("value of var: %d and value of var1: %d\n", ex1.var, ex1.var1);

	ex1.var1 = 25;

	printf("Value of var1: %d\n", ex1.var1);
	printf("Value of var when one of the members change: %d\n", ex1.var);

	getchar();
	return 0;
}
