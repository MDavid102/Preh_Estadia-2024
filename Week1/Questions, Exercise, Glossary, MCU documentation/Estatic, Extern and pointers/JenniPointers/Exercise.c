/*
 * Exercise.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Mr.Robot
 */

#include <stdio.h>

int main(void){
	char myChar = 100, *pChar = &myChar;
	char readByte;

	printf("Address of myChar: %p\n", &myChar);

	readByte = *pChar;

	printf("Data obtain: %d\n", readByte);

	*pChar = 65;

	printf("Value of variable in step 1: %d\n", myChar);

	getchar();
	return 0;

}
