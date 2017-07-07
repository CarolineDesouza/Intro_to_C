//Caroline Navega Desouza
//COP 2220
//October 16, 2015
//Lab 7 Pointers

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//FUNCTION PROTOTYPES
void Greeting(void);
int CalcSum(int, int);
int CalcDiff(int, int);
void CalcBoth(int, int, int*, int*);


int main()
{
	int Sum, Diff;
	int num1 = 0, num2 = 0;

	//Greet user
	Greeting();

	//Get 2 numbers from user
	printf("Enter a number: ");
	scanf("%d", &num1);

	printf("\nAnd another number: ");
	scanf("%d", &num2);

	//Function call to calculate sum of 2 nums
	Sum = CalcSum(num1, num2);
	printf("\n\nThe sum inside the Main function is: %d \n\n", Sum);

	//Function call to subtract 2 nums
	Diff = CalcDiff(num1, num2);
	printf("\n\nThe difference inside the Main function is: %d \n\n", Diff);
	
	//Function call to calculate both
	CalcBoth(num1, num2, &Sum, &Diff);
	printf("Back in the Main function, the sum is %d and the difference is %d \n\n", Sum, Diff);
	return 0;
}

//FUNCTION DEFINITIONS
void Greeting()
{
	printf("Hey! So, this program calculates the sum and difference of 2 integers.\n\n");
	printf("Let's begin...\n\n");
}

//Gets nums from user & adds them
int CalcSum(int num1, int num2)
{
	int total;

	total = num1+num2;
	
	printf("\n\nThe sum inside CalculateSum function is: %d", total);

	return total;
}

//Subtracts user nums 
int CalcDiff(int num1, int num2)
{
	int total;

	total = num1-num2;

	printf("\nThe difference inside CalculateSum function is: %d", total);

	return total;
}

//Calculates nums & stores results in pointers
void CalcBoth(int num1, int num2, int*sumPtr, int*diffPtr)
{
	*sumPtr = num1 + num2;
	*diffPtr = num1 - num2;
	printf("Inside CalcBoth, the sum is %d, the difference is %d \n\n", *sumPtr, *diffPtr);
}