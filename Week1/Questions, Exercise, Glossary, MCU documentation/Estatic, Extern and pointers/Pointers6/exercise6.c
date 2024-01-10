/*
 * exercise6.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

int main(void){
	int x, z;
	int *p1 = &x, *p2 = &z;

	printf("Enter first number: \n");
	scanf("%d", &x);

	printf("Enter second number: \n");
	scanf("%d", &z);

	if(*p1 > *p2){
		printf("%d is greater than %d\n", *p1, *p2);
	}
	else{
		printf("%d is greater than %d\n",*p2, *p1);
	}

	getchar();
	getchar();
	return 0;
}
