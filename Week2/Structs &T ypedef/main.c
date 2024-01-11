/*
 * main.c
 *
 *  Created on: Jan 9, 2024
 *      Author: Mr.Robot
 */

// ----------------- Exercise using struct and typedef -----------------------

#include <stdio.h>
//#include <string.h>

//To define a struct we must first declare it
// we use typedef to give it an alias and to create a variable of type (in this case Movie)
typedef struct {
	//members of the struc
	char *name;
	int year;
	char *actor;
} Movie;

int main(void){
	//First method
	 Movie movie1; // variable to access the struct
	 //assigning values to the members of the struct
	movie1.year = 2002;
	movie1.name = "Harry Potter";
	movie1.actor = "Daniel Radcliffe";

	//Second method
	// this one has a disadvantage, we need to input the info in the right place
	//struct Movie movie1 = {"Harry Potter", 2002, "Daniel Radcliffe"};

	//third method
	//struct Movie movie1 = {.actor = "Daniel Radcliffe", .name = "Harry Potter", .year = 2002};

	//printing members
	printf("The movie is %s.\n Its main actor is %s.\n And its release year was %d.\n", movie1.name, movie1.actor, movie1.year);

	//getting the printf
	getchar();
	return 0;
}
