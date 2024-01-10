/*
 * exercise7.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Mr.Robot
 */


#include <stdio.h>

int main(void){

    int arr1[100], x, z;

    printf(" Input the number of elements to store in the array :");
    scanf("%d", &x); // Read the number of elements to be stored in the array

    printf(" Input %d number of elements in the array :\n", x);
    for (z = 0; z < x; z++) {
        printf(" element - %d : ", z);
        scanf("%d", arr1 + z); // Read and store 'n' elements in the array arr1 using pointer arithmetic
    }

    printf(" The elements you entered are : \n");
    for (z = 0; z < x; z++) {
        printf(" element - %d : %d \n", z, *(arr1 + z)); // Display the elements stored in the array using pointers
    }
    getchar();
    getchar();
    return 0;
}
