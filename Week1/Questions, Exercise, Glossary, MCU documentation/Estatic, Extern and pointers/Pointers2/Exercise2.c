/*
 * Exercise2.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Mr.Robot
 */

#include <stdio.h>

int main(void){
	int* ab; // Declare a pointer variable ab
	int m = 29;   // Declare an integer variable m

	printf(" Address of m : %p\n", &m);
	printf(" Value of m : %d\n\n", m);

	ab = &m; // Assign the address of m to the pointer variable ab

	printf(" Now ab is assigned with the address of m.\n");
	printf(" Address of pointer ab : %p\n", ab);
	printf(" Content of pointer ab : %d\n\n", *ab);

	 m = 34; // Assign the value 34 to the variable m

	 printf(" The value of m assigned to 34 now.\n");
	 printf(" Address of pointer ab : %p\n", ab);
	 printf(" Content of pointer ab : %d\n\n", *ab);

	 *ab = 7; // Assign the value 7 to the variable pointed by ab

	 printf(" The pointer variable ab is assigned the value 7 now.\n");
	 printf(" Address of m : %p\n", &m);


	 printf(" Value of m : %d\n\n", m);

	 getchar();
	 return 0;
}
