/*
5. Write a C program to check whether the Host machine is in Little Endian or

Big Endian. Enter a number, print the content of each byte location and
Convert the Endianness of the same i.e. Little to Big Endian and vice-versa.
*/

#include <stdio.h>

// Function to check endianness of the host machine
void check_endianness() {
    unsigned int x = 1;
    char *ptr = (char*)&x;

    // If lowest address contains 1, it's Little Endian
    if (*ptr == 1)
        printf("Host machine is Little Endian.\n");
    else
        printf("Host machine is Big Endian.\n");
}

// Function to print each byte of a number
void print_bytes(unsigned int num) {
    unsigned char *ptr = (unsigned char*)&num;
    printf("Bytes (from lowest address to highest):\n");
    for (int i = 0; i < 4; i++) {
        printf("Byte %d: %u (0x%02X)\n", i, ptr[i], ptr[i]);
    }
}

// Function to reverse the byte order (change endianness)
unsigned int reverse_endian(unsigned int num) {
    // Rearrange bytes to convert endianness
    return ((num >> 24) & 0xFF) |           // Move byte 3 to byte 0
           ((num >> 8)  & 0xFF00) |         // Move byte 2 to byte 1
           ((num << 8)  & 0xFF0000) |       // Move byte 1 to byte 2
           ((num << 24) & 0xFF000000);      // Move byte 0 to byte 3
}

int main() {
    unsigned int num, converted;

    // Step 1: Check host endianness
    check_endianness();

    // Step 2: Get input from user
    printf("\nEnter a 32-bit unsigned integer: ");
    scanf("%u", &num);

    // Step 3: Print original bytes
    printf("\nOriginal number: %u\n", num);
    print_bytes(num);

    // Step 4: Convert endianness
    converted = reverse_endian(num);

    // Step 5: Print converted result and its bytes
    printf("\nAfter Endianness Conversion:\n");
    printf("Converted number: %u\n", converted);
    print_bytes(converted);

    return 0;
}
