/*
 * exercise10.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

int getLength(const char*);  //Function declaration

int main() {
	//Declaring variables
    char inputString[50];
    int length;

    //Asking string from the user
    printf("Enter a string: ");

    //functions to read the string for the user and stores it in variable
    fgets(inputString, sizeof(inputString), stdin);

    //calling the function to find the length
    length = getLength(inputString);
    printf("Length of the string '%s' is: %d\n", inputString, length - 1); //print result

    getchar(); //get the print
    return 0;
}

int getLength(const char* str) { //function initialization
    int count = 0;  //Local variable

    while (*str) {
        count++; //counting the string and adding 1 each time
        str++;
    }

    return count; //return the integer number of the elements of the string
}

