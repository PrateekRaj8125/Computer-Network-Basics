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

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    unsigned int num;
    struct pkt p;

    // Step 1: Input
    printf("Enter a 32-bit unsigned integer: ");
    scanf("%u", &num);

    // Step 2: Break the number into bytes and assign to structure members
    p.ch1     = (num & 0xFF);             // Byte 0 (LSB)
    p.ch2[0]  = (num >> 8) & 0xFF;        // Byte 1
    p.ch2[1]  = (num >> 16) & 0xFF;       // Byte 2
    p.ch3     = (num >> 24) & 0xFF;       // Byte 3 (MSB)

    // Step 3: Print structure contents as unsigned integers
    printf("\n--- Structure Members (Bytes) ---\n");
    printf("ch1     = %u\n", (unsigned char)p.ch1);
    printf("ch2[0]  = %u\n", (unsigned char)p.ch2[0]);
    printf("ch2[1]  = %u\n", (unsigned char)p.ch2[1]);
    printf("ch3     = %u\n", (unsigned char)p.ch3);

    // Step 4: Reconstruct original number
    unsigned int reconstructed = ((unsigned char)p.ch3 << 24) |
                                 ((unsigned char)p.ch2[1] << 16) |
                                 ((unsigned char)p.ch2[0] << 8) |
                                 (unsigned char)p.ch1;

    // Step 5: Print reconstructed number
    printf("\nReconstructed number: %u\n", reconstructed);

    return 0;
}