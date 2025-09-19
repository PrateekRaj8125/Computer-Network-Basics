/*
2. Write a C program to assign values to each member of the following structure.
Pass the populated structure to a function Using call-by-value and another
function using call-by-address and print the value of each member of the
structure.
struct student_info{
int roll_no;
char name [50];
float CGPA;
struct dob age;
};
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store date of birth
struct dob{
    int dd,mm,yyyy;
};

// Structure to store student information
struct student_info{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

// Function to display student info using call-by-value
void display_by_value(struct student_info s){
    printf("\n[Display by Value]\n");
    printf("Roll No: %d\n", s.roll_no);
    printf("Name   : %s\n", s.name);
    printf("CGPA   : %.2f\n", s.CGPA);
    printf("DOB    : %02d-%02d-%04d\n", s.age.dd, s.age.mm, s.age.yyyy);
}

// Function to display student info using call-by-address
void display_by_address(struct student_info *s) {
    printf("\n[Display by Address]\n");
    printf("Roll No: %d\n", s->roll_no);
    printf("Name   : %s\n", s->name);
    printf("CGPA   : %.2f\n", s->CGPA);
    printf("DOB    : %02d-%02d-%04d\n", s->age.dd, s->age.mm, s->age.yyyy);
}

void main(){
    struct student_info std; // Declare structure variable

    // Input values for each member of the structure
    printf("Enter Roll No.:");
    scanf("%d",&std.roll_no);

    printf("Enter Name:");
    getchar(); // Consume newline left by previous scanf
    scanf("%[^\n]s",std.name);

    printf("Enter CGPA:");
    scanf("%f",&std.CGPA);

    printf("Enter Date of Birth [In Format(dd mm yyyy)]:");
    scanf("%d %d %d",&std.age.dd, &std.age.mm, &std.age.yyyy);

    // Pass structure by value
    display_by_value(std);

    // Pass structure by address
    display_by_address(&std);
}