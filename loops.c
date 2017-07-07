//Caroline Desousa 
//October 9, 2015
//COP 2220 9:30am
//Lab 6: Loops

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	//variable declarations
	int num;
	
	//greet user & ask for a number from 1 to 10
	printf("Hello!\n\n");
	printf("Enter a number from 1 to 10: ");
	scanf("%d", &num);

	//process the for loop
	for (int a = 0; a < num; a++)
	{
		printf("FAU is awesome\n");
	}

	//process while loop
	int b = 0;
	while (b < num)
	{
		printf("Programming in C is fun\n");
		b++;
	}

	//process do/while loop
	int c = 0;
	do
	{
		printf("Florida beaches are beautiful\n");
		c++;

	} while (c < num);
	
	int sum = 0;
	//get new values from user
	printf("Enter a new value: ");
	scanf("%d", &num);

	while (num != -1)
	{
		if (num >= 0)
		{
			sum += num;
			printf("The sum total is: %d.\n", sum);
			printf("\nEnter a new value: ");
			scanf("%d", &num);
		}
		if (num == -1)
		{
			printf("See you later!\n\n");
		}
	}
	return 0;

}