//Caroline Navega Desouza 
//September 25, 2015
//COP 2220 9:30am
//Lab 8: Arrays

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//Function Prototypes
void numFlights(int *flights);
void readMiles(double miles[], int *flights);
void printMiles(double miles[], int*flights);
void totalMiles(double miles[], int*flights);

int main()
{
	double miles[20];
	int count;

	printf("\t\t**Welcome to Owl Airlines!**\n\n\t\tFrequent Flyer Miles Tracker \n");

	//Function calls
	numFlights(&count);
	readMiles(miles, &count);
	printMiles(miles, &count);
	totalMiles(miles, &count);

	printf("\n\nThank you for updating your records! We hope you've enjoyed your travels!\n\n");

	return 0;
}

//Function definition for number of flights
void numFlights(int *flights)
{

	printf("\nPlease enter how many flights you've gone on recently: ");
	scanf("%d", flights);


}

//Function definition asking user input for flight miles
void readMiles(double miles[], int *flights)
{
	int i;
	printf("\n\nPlease enter the mileage of each flight & press enter after each entry: ");
	for (i = 0; i < *flights; i++)
	{
		printf("\n");
		scanf("%lf", &miles[i]);
	}
}

//Function definition printing total miles flown
void printMiles(double miles[], int*flights)
{
	int i;
	printf("\n----------------------------\n");
	printf("Here is your mileage for each flight:\n\n");
	for (i = 0; i < *flights; i++)
	{
		printf("%.2f\n", miles[i]);

	}
}

//definition Total miles ran
void totalMiles(double miles[], int*flights)
{
	double total = 0;
	int i;
	printf("\n-------------------------------\n");
	printf("\nYour total flight miles are:  ");
	for (i = 0; i < *flights; i++)
	{
		total = total + miles[i];

	}

	printf("%.2f\n", total);
}