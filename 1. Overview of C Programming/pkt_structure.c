/*
4. Write a C Program to enter a number and store the number across the
following structure and print the content of each member of the structure.
Then aggregate each member of the structure to form the original number and
print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};
*/

#include <stdio.h>

// Structure to hold bytes of the number
struct pkt {
    char ch1;      // First byte (LSB)
    char ch2[2];   // Second and third bytes
    char ch3;      // Fourth byte (MSB)
};

int main() {
    unsigned int num;
    struct pkt p;

    // Step 1: Input a 32-bit unsigned integer from user
    printf("Enter a 32-bit unsigned integer: ");
    scanf("%u", &num);

    // Step 2: Break the number into bytes and assign to structure members
    p.ch1     = (num & 0xFF);             // Assign least significant byte to ch1
    p.ch2[0]  = (num >> 8) & 0xFF;        // Assign second byte to ch2[0]
    p.ch2[1]  = (num >> 16) & 0xFF;       // Assign third byte to ch2[1]
    p.ch3     = (num >> 24) & 0xFF;       // Assign most significant byte to ch3

    // Step 3: Print structure contents as unsigned integers
    printf("\n--- Structure Members (Bytes) ---\n");
    printf("ch1     = %u\n", (unsigned char)p.ch1);
    printf("ch2[0]  = %u\n", (unsigned char)p.ch2[0]);
    printf("ch2[1]  = %u\n", (unsigned char)p.ch2[1]);
    printf("ch3     = %u\n", (unsigned char)p.ch3);

    // Step 4: Reconstruct original number from structure members
    unsigned int reconstructed = ((unsigned char)p.ch3 << 24) |
                                 ((unsigned char)p.ch2[1] << 16) |
                                 ((unsigned char)p.ch2[0] << 8) |
                                 (unsigned char)p.ch1;

    // Step 5: Print reconstructed number
    printf("\nReconstructed number: %u\n", reconstructed);

    return 0;
}