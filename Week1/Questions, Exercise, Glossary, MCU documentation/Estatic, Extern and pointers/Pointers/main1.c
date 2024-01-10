/*
 * main1.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

int main(void){
	//Dlecaring variables m = 10
	int m = 10, n, o;
	int *z = &m; //pointer Z to direction of variable m

	printf("Z stores the address of m = %p\n", z);
	printf("*Z stores the value of m = %i\n", *z);
	printf("&m  is the address of m = %p\n", &m);
	printf("&n stores the address of m = %p\n", &n);
	printf("&o stores the address of m = %p\n", &o);
	printf("&z stores the address of m = %p\n", &z);

	getchar();

	return 0;
}
