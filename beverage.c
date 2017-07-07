//Caroline N. Desouza 
//September 25, 2015
//COP 2220
//1st Programming Assignment: Beverage inventory
//uses an external "records" file which is not posted here

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//FUNCTION PROTOTYPES:

//greet user
void Greeting(void);

//takes quantities of each brand and displays totals on screen
void Display(int z, int d, int s, int e, int p);

//takes quantities of each brand and returns the id of the brand with the largest inventory
void MostInStock(int, int, int, int, int);

//takes the quantities in inventory and displays the brand name of those with less than 
//10 cases in stock
void Restock(int, int, int, int, int);

int main()
{
	//declare variables and file pointer
	int id, qty;
	int zephyrhills = 0, dasani = 0, smartWater = 0, ethos = 0, perrier = 0;

	FILE *inPtr;

	//connect to file
	inPtr = fopen("records.txt", "r");

	//read inputs from file
	fscanf(inPtr, "%d", &id);
	fscanf(inPtr, "%d", &qty);


	//function call to greeting
	Greeting();

	//test that id is not -9999
	while (id != -9999)
	{

		//update the quantity based on the id
		if (id == 1)
		{
			//add qty to zephyrhills
			zephyrhills = zephyrhills + qty;
			printf("Zephyrhills Quantity: %d\n\n", zephyrhills);
		}
		else if (id == 2)
		{
			//add qty to dasani
			dasani = dasani + qty;
			printf("Dasani Quantity: %d\n\n", dasani);
		}
		else if (id == 3)
		{
			//add qty to smartWater
			smartWater = smartWater + qty;
			printf("Smart Water Quantity: %d\n\n", smartWater);
		}
		else if (id == 4)
		{
			//add qty to ethos
			ethos = ethos + qty;
			printf("Ethos Quantity: %d\n\n", ethos);
		}
		else if (id == 5)
		{
			//add qty to perrier
			perrier = perrier + qty;
			printf("Perrier Quantity: %d\n\n", perrier);
		}
		else
		{
			printf("Not recognized");
		}

		//get the next id and quantity from the file
		fscanf(inPtr, "%d", &id);
		fscanf(inPtr, "%d", &qty);
	}

	//the id entered was -9999 to stop the loop
	printf("\n******************************************\n\n");
	printf("id is %d\n\n\n\n", id);

	//close file
	fclose(inPtr);

	//function call to display inventory totals on screen
	Display(zephyrhills, dasani, smartWater, ethos, perrier);

	//function call to return the id of brand with largest inventory
	MostInStock(zephyrhills, dasani, smartWater, ethos, perrier);

	//function call to display the brand name of the those with less 
	//than 10 cases in stock
	Restock(zephyrhills, dasani, smartWater, ethos, perrier);

	return 0;
}

//FUNCTION DEFINITIONS

//greeting to user
void Greeting()
{
	printf("Hello, this is a report for the inventory of water");
	printf(" in stock this month.\n\n");
}

//function to display current inventory
void Display(int z, int d, int s, int e, int p)
{
	printf("Current water inventory: \n\n");
	printf("(1) Zephyrhills:   %d\n", z);
	printf("(2) Dasani:        %d\n", d);
	printf("(3) Smart Water:   %d\n", s);
	printf("(4) Ethos:         %d\n", e);
	printf("(5) Perrier:       %d\n\n", p);

	printf("\n******************************************\n\n");
}

///returns the id & brand name with largest inventory
void MostInStock(int z, int d, int s, int e, int p)
{
	int largest = 0;

	if (z > d && z > s && z > e && z > p)
	{
		largest = z;
		printf("Zephyrhills has the most cases in stock, the id is 1.\n\n");
	}
	if (d > z && d > s && d > e && d > p)
	{
		largest = d;
		printf("Dasani has the most cases in stock, the id is 2.\n\n");
	}
	if (s > z && s > d && s > e && s > p)
	{
		largest = s;
		printf("Smart Water has the most cases in stock, the id is 3.\n\n");
	}
	if (e > z && e > d && e > s && e > p)
	{
		largest = e;
		printf("Ethos has the most cases in stock, the id is 4.\n\n");
	}
	if (p > z && p > d && p > s && p > e)
	{
		largest = p;
		printf("Perrier has the most cases in stock, the id is 5.\n\n");
	}
}

//displays brand names needing restock
void Restock(int z, int d, int s, int e, int p)
{
	int restock = 10;

	printf("The brands that need to be restocked are: \n\n");

	if (z < 10)
	{
		restock = z;
		printf("Zephyrhills\n\n");
	}
	if (d < 10)
	{
		restock = d;
		printf("Dasani\n\n");
	}
	if (s < 10)
	{
		restock = s;
		printf("Smart Water\n\n");
	}
	if (e < 10)
	{
		restock = e;
		printf("Ethos\n\n");
	}
	if (p < 10)
	{
		restock = p;
		printf("Perrier\n\n");
	}

	return restock;
}






