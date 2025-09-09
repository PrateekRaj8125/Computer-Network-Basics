/*
3. Write a C program to extract each byte from a given number and store them in
separate character variables and print the content of those variables.
*/
#include <stdio.h>

void main() {
    unsigned int num;           // Variable to store the input number
    char byte1, byte2, byte3, byte4; // Variables to store each byte

    // Prompt user to enter a 32-bit unsigned integer
    printf("Enter a 32-bit unsigned integer: ");
    scanf("%u", &num);

    // Extract each byte using bitwise operations
    byte1 = (num & 0xFF);           // Extract least significant byte
    byte2 = (num >> 8) & 0xFF;      // Extract second byte
    byte3 = (num >> 16) & 0xFF;     // Extract third byte
    byte4 = (num >> 24) & 0xFF;     // Extract most significant byte

    // Print the content of each byte variable
    printf("Byte 1 (LSB): %u\n", (unsigned char)byte1);
    printf("Byte 2      : %u\n", (unsigned char)byte2);
    printf("Byte 3      : %u\n", (unsigned char)byte3);
    printf("Byte 4 (MSB): %u\n", (unsigned char)byte4);
}
