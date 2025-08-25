/*
1. Write a C program to swap the content of 2 variables entered through the
command line using function and pointer.
*/

#include<stdio.h>
#include<stdlib.h>

// Function to swap two integers using pointers
void swap(int *a, int *b){
    // Swapping without using a temporary variable
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main(int argc, char *args[]){
    // Check if exactly two arguments are provided
    if(argc != 3){
        printf("Usage: %s <num1> <num2>\n", args[0]);
        return 1;
    }

    int a, b;
    // Convert command line arguments to integers
    a = atoi(args[1]);
    b = atoi(args[2]);

    // Print original values
    printf("Original Values: a=%d, b=%d\n", a, b);

    // Call swap function to swap values of a and b
    swap(&a, &b);

    // Print swapped values
    printf("Swapped Values: a=%d, b=%d\n", a, b);
}
