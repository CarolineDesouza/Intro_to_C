//Caroline Desousa 
//September 25, 2015
//COP 2220 9:30am
//Lab 5: Calculate sales tax for an item

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()

{
	//declare variable
	double originalprice;
	double totalprice;
	double sevenPer;
	double sixPer;

	//greet user
	printf("Hello!\n\n");
	
	//ask & get item price from user
	printf("Please enter the price of your item: \n\n");
	scanf("%lf", &originalprice);

	//calculations
	if (originalprice < 250)
	{
		//if price is less than $250, taxes are 7%
		sevenPer = originalprice*.07;

		//print original price & tax amount on screen
		printf("\n\nThe tax on an item that costs $ %.2f is %.2f.\n\n", originalprice, sevenPer);

		//print price including tax amount
		printf("The price including tax is: $ %.2f.\n\n", sevenPer + originalprice);
	}

	else if (originalprice >= 250)
	{
		//if price is >= $250, taxes are 6%
		sixPer = originalprice*.06;

		//print original price & tax amount on screen
		printf("\n\nThe tax on an item that costs $ %.2f is %.2f.\n\n", originalprice, sixPer);

		//print price including tax amount
		printf("The price including tax is: $ %.2f.\n\n", sixPer + originalprice);
	}

	return 0;
}
