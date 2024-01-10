/*
 * exercise3.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

int main(void){
	int m = 300;
	float fx = 300.600006;
	char cht = 'z';

	int *p1 = &m;
	float *p2 = &fx;
	char *p3 = &cht;

	//p1 = &m;
	//p2 = &fx;
	//p3 = &cht;

	printf("using &\n");
	printf("Address of m = %p\n", &m);
	printf("Address of fx = %p\n", &fx);
	printf("Address of xht = %p\n", &cht);

	printf("using & and *\n");
	printf("Value at address of m = %d\n", *(&m));
	printf("Value at address of fx = %f\n", *(&fx));
	printf("Value at address of cht = %c\n", *(&cht));

	printf("using pointer variable\n");
	printf("Address of m = %p\n", p1);
	printf("Address of fx = %p\n", p2);
	printf("Address of cht = %p\n", p3);

	printf("using pointer operation\n");
	printf("Value at address of m = %d\n", *p1);
	printf("Value at address of fx = %f\n", *p2);
	printf("Value at address of cht = %c\n", *p3);

	getchar();

	return 0;
}
