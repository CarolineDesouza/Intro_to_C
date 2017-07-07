//Caroline Desousa 
//September 10, 2015
//COP 2220 9:30am Class
//Lab 3 - Calculate area of circle & rectangle

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	//declare variables for radius, length & width
	int radius;
	int sideLength;
	int sideWidth;
	int areaRect;
	double areaCir;

	//Greet user and ask for radius
	printf("Hello! \n\nWe're going to calculate the area of a circle & a rectangle.");
	printf("\n\nPlease enter a number for the radius: ");
	
	//receive user radius input
	scanf("%d", &radius);

	//calculate area of the circle
	areaCir = radius*radius*3.14;

	//print area of circle & radius onto screen
	printf("\nThe area of a circle with radius %d is %.2f\n\n", radius, areaCir);

	//ask & receive length of rectangle side
	printf("\nNow let's calculate the area of a rectangle.\n\n");
	printf("Enter the length of a side: ");
	scanf("%d", &sideLength);

	//ask & receive width of rectangle side
	printf("\nNow enter the width: ");
	scanf("%d", &sideWidth);

	//calculate the area of a triangle
	areaRect = sideWidth*sideLength;

	//print area of rectangle onto screen
	printf("\nA rectangle with width %d and length %d has an area of %d.\n\n", sideWidth, sideLength, areaRect);
	printf("Thanks for your input!\n\n");
		return 0;
}