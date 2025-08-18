/*
1. Write a C program to swap the content of 2 variables entered through the
command line using function and pointer.
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	*a+=*b;
	*b=*a-*b;
	*a=*a-*b;
}
int main(int argc, char *args[]){
	if(argc!=3){
		printf("Usage: %s <num1> <num2>\n",args[0]);
		return 1;
	}
	int a, b;
	a=atoi(args[1]);
	b=atoi(args[2]);
	printf("Original Values: a=%d, b=%d\n",a,b);
	swap(&a,&b);
	printf("Swapped Values: a=%d, b=%d\n",a,b);
}
