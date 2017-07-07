//Author: Caroline N. Desouza
//COP 2220 
//October 28,2015
//Program 2 - Basic C program where user can purchase an app

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

//Function Prototypes
void DisplayApps(char*);
void SetCost(char, double*);
void PaymentOptions(double*, double);
int Compare(double, double);
void Pay(double*, double);
void GetChange(double*, double*);
void DoItAgain(char*);
void DisplayPurchases(double priceList[], int);


//Function main
int main()
{
	char letPtr, quitPtr, buy;
	double costPtr, depositPtr = 0;
	double choiceCost = 0;
	double priceList[20];
	int num = 0;
	int count = 0;


	do
	{
		printf("\nWould you like to buy an app? Enter Y or N: ");
		scanf(" %c", &buy);

		if (buy == 'N' || buy == 'n')
		{
			printf("Thanks for shopping!\n\n");
			break;
		}

		printf("\n\n**Welcome to the App Store**\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("You have $%.2f in your account.\n\n", depositPtr);

		//Function call to display apps 
		//Also prompts user for an app selection
		DisplayApps(&letPtr);

		//Sets cost of app selected
		SetCost(letPtr, &costPtr);
		printf("App %c costs $%.2f\n\n", letPtr, costPtr);

		//Function call to collect money & compare current
		//deposit to item cost
		Pay(&depositPtr, costPtr);
		printf("You purchased app %c", letPtr);

		//Calculates money leftover from deposits
		GetChange(&depositPtr, &costPtr);
		printf("\n\nYou have $%.2f left over.\n\n", depositPtr);

		priceList[count] = costPtr;
		count++;

		//Function call asking user if they want to make another purchase
		DoItAgain(&quitPtr);

		if (quitPtr == 'N' || quitPtr == 'n')
		{
			printf("Thanks for shopping!\n\n");
			break;
		}
	} while (quitPtr == 'Y' || quitPtr == 'y');
	
	//Function call to list of purchases in array
	DisplayPurchases(priceList, count);

	return 0;
}


//Function Definitions
//Displays list of apps available & prompts user for selection
void DisplayApps(char *letPtr)
{
	
	printf("These are the apps available: \n\n");
	printf("C -- Coding Extreme\t $999.99\n");
	printf("V -- Video Maker\t $1,199.99\n");
	printf("W -- Wedding Planner\t $219.99\n");
	printf("B -- Book Reader\t $4.99\n");
	printf("M -- Machine Learning\t $349.99\n\n");
	printf("Enter your selection: ");

	scanf(" %c", letPtr);
	*letPtr = toupper(*letPtr);
	printf("You selected %c\n\n", *letPtr);
}

//Sets app cost based on user selection
void SetCost(char let, double *costPtr)
{

	if (let == 'C' || let == 'c')
	{
		*costPtr = 999.99;
	}
	if (let == 'V' || let == 'v')
	{
		*costPtr = 1199.99;
	}
	if (let == 'W' || let == 'w')
	{
		*costPtr = 219.99;
	}
	if (let == 'B' || let == 'b')
	{
		*costPtr = 4.99;
	}
	if (let == 'M' || let == 'm')
	{
		*costPtr = 349.99;
	}
	
}

//Displays amounts for deposit & gets user input
void PaymentOptions(double *depositPtr)
{
	double input;

	printf("\n\n1 --\t$1000.00\n");
	printf("2 --\t$500.00\n");
	printf("3 --\t$100.00\n");
	printf("4 --\t$10.00\n");
	scanf("%lf", &input);

	if (input == 1)
	{
		*depositPtr += 1000.00;
	}
	if (input == 2)
	{
		*depositPtr += 500.00;
	}
	if (input == 3)
	{
		*depositPtr += 100.00;
	}
	if (input == 4)
	{
		*depositPtr += 10.00;
	}

	printf("You deposited $%.2f\n", *depositPtr);
}

//Compares user's deposit amount to price of app selected
int Compare(double depositPtr, double costPtr)
{
	if (depositPtr >= costPtr)
	{
		return 1;
	}

	else
	{
		printf("You don't have enough money. Please select a deposit amount: ");
		return 0;
	}
}

//Uses 2 other functions to display & collect money from user
//Also compares deposited value to item cost
void Pay(double *depositPtr, double choiceCost)
{
	if (Compare(*depositPtr, choiceCost) == 0)
	{
		PaymentOptions(depositPtr);
	}

}

//Calculates amount leftover from deposits
void GetChange(double *depositPtr, double *costPtr)
{
	*depositPtr = *depositPtr - *costPtr;
}

//Array of all purchases
void DisplayPurchases(double priceList[], int num)
{
	int i;
	double sum = 0;

	printf("You purchased %d app(s) that cost:\n", num);

	for (i = 0; i < num; i++)
	{
		printf("$%.2f\n", priceList[i]);

		sum = sum + priceList[i];
	}

	printf("The total cost of your purchase is $%.2f\n\n", sum);
}

//Asks user if they want another app
void DoItAgain(char *quitPtr)
{

	printf("Would you like to buy another app?\n");
	printf("Enter Y or N: \n");
	scanf(" %c", quitPtr);

}

