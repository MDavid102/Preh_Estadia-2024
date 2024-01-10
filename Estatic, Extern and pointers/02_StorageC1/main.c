/*
 * main.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Mr.Robot
 */

#include <stdio.h>


int counterextern;

void incrementCounter(){

	static int v = 0; //local static variable
	v++;
	printf("Value: %d\n", v);
}

int main(void){

	printf("counter extern = %d\n", counterextern);

	incrementCounter();
	incrementCounter();

	getchar();

	return 0;
}
