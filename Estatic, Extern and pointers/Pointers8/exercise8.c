/*
 * exercise8.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

// Function to swap characters
void changePosition(char *str1, char *str2)
{
    char swap;
    swap = *str1;
    *str1 = *str2;
    *str2 = swap;
}

// Function to generate permutations of a string
void FunctionPermuChar(char *cht, int stno, int endno)
{
    int i;
    if (stno == endno)
        printf("%s  ", cht); // Print the generated permutation when stno equals endno
    else
    {
        for (i = stno; i <= endno; i++)
        {
            changePosition((cht + stno), (cht + i)); // Swap characters at positions stno and i
            FunctionPermuChar(cht, stno + 1, endno); // Recursively generate permutations for the rest of the string
            changePosition((cht + stno), (cht + i)); // Restore the original string by swapping back
        }
    }
}

// Main function
int main()
{
    char str[] = "Angel"; // The input string

    int n = strlen(str); // Get the length of the string
    printf(" The permutations of the string are : \n");
    FunctionPermuChar(str, 0, n - 1); // Call function to generate permutations
    printf("\n\n");

    getchar();
    return 0;
}
