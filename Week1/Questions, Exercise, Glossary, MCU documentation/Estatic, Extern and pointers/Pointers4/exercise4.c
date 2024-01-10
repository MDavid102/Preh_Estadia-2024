/*
 * exercise4.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Mr.Robot
 */
//----------- Write a program to add 2 numbers using pointers------------------//
#include <stdio.h>

int main(void){
	int x, b, sum;
	int *p1 = &x;
	int *p2 = &b;

	printf("Insert the first integer: \n");
	scanf("%d", &x);

	printf("Insert the second integer: \n");
	scanf("%d", &b);

	sum = *p1 + *p2;
	printf("the sum of the number is: %d\n", sum);

	getchar();
	getchar();

	return 0;
}
