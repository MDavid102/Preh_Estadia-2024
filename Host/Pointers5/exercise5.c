/*
 * exercise5.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

int SumTwoNumbers(int *, int *); //declare function

int main(void){
	int a, b,sumMain; //declare variables

	printf("Enter first number: \n"); //Ask fr first number
	scanf("%d", &a);

	printf("Enter second number: \n"); //ask for second number
	scanf("%d", &b);

	sumMain = SumTwoNumbers(&a, &b); //calling the function and adding the
	printf("The sum of %d + %d = %d\n", a, b, sumMain); //print result

	getchar();
	getchar();
	return 0;

}

int SumTwoNumbers(int *x, int *z){  //Initialize function and declaring variables
	int sumlocal;

	sumlocal = *x + *z;  //operation of adding the 2 numbers

	return sumlocal;  // the function will return the sum of the 2 numbers
}
