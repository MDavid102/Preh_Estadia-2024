/*
 * exercise9.c
 *
 *  Created on: Jan 7, 2024
 *      Author: Mr.Robot
 */
//------------------------ Code to return the highest integer from an array -----------------------------------
#include <stdio.h>

#define MAX_SIZE 50 //define the maximum size of the array

int main(void) {
	// Declaration of variables
    int numCount, index;
    int numbers[MAX_SIZE];

    //asking the user for the size of the array and saving it in the variable
    printf("Enter the number of integers (up to %d): ", MAX_SIZE);
    scanf("%d", &numCount);

    //Condition to prevent wrong inputs
    if (numCount > MAX_SIZE || numCount <= 0) {
        printf("Invalid input or exceeded maximum size\n");
        return 1; //reporting the issue
    }

    //inputing the integers of the arrays and saving them
    for (index = 0; index < numCount; index++) {
        printf("Enter integer #%d: ", index + 1);
        scanf("%d", &numbers[index]);
    }

    //starting the reading from the first element to find the largest
    int max = numbers[0];
    for (index = 1; index < numCount; index++) {
        if (max < numbers[index]) {
            max = numbers[index];
        }
    }

    //print result
    printf("The largest number entered is: %d\n", max);

    getchar(); // To capture the newline after the last input
    getchar(); // To wait for user input before closing the console
    return 0;
}

