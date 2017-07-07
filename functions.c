//Caroline Desousa 
//September 17, 2015
//COP 2220 9:30am Class
//Lab 4 - Functions for calculating area of circle & rectangle

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//FUNCTION PROTOTYPES

//greets the user
void Greeting();

//gets an integer from the user
int GetInt();

//calculates area of a circle
double CalculateAreaCir(int);

//calculates area of a rectangle
int CalculateAreaRect(int, int);

int main()
{
	int radius, sideLength, sideWidth;
	int areaRect;
	double areaCir;

	//function call to greeting
	Greeting();

	//ask user for a radius
	printf("\n\nPlease enter a number for the radius: ");
	radius = GetInt(); //function call to get integer
	areaCir = CalculateAreaCir(radius);

	//print results onto the screen
	printf("\nThe area of a circle with radius %d is %.2f\n\n", radius, areaCir);
	
	//ask user for length
	printf("\nNow let's calculate the area of a rectangle.\n\n");
	printf("Enter the length of a side: ");

	sideLength = GetInt(); //function call to get integer

	//ask user for width
	printf("\nNow enter the width: ");

	sideWidth = GetInt(); //function call to get last intger

	areaRect = CalculateAreaRect(sideLength, sideWidth);
	
	//print area of rectangle onto screen
	printf("\nA rectangle with width %d and length %d has an area of %d.\n\n", sideWidth, sideLength, areaRect);
	printf("Thanks for your input!\n\n");

	return 0;
}

//function definition to greet the user
void Greeting()
{
	printf("Hello! \n\nWe're going to calculate the area of a circle & a rectangle.");

}

//function definition to get integer from user and return to main
int GetInt(void)
{
	int num; 
	printf("");
	scanf("%d", &num);
	return num;
}

//function definition to calculate area of a circle
double CalculateAreaCir(int radius)
{
	double areaCir;
	areaCir = (double)(radius*radius*3.14);

	return areaCir;
}

//function definition to calculate area of a rectangle
int CalculateAreaRect(int sideLength, int sideWidth)
{
	int areaRect;

	areaRect = sideLength*sideWidth;

	return areaRect;
}
