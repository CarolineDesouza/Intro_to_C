//Caroline Navega Desouza 
//November 30, 2015
//COP 2220 9:30am
//Program 4 - Catalog

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> //for malloc and calloc

#define size 50

//STRUCT
typedef struct {
	char brand[size]; //char array for brand of guitar
	char guitarName[size]; //char array for name of guitar
	int prodID; //guitar's product ID
	int qtyAvail; //quantity available in stock
	double cost; //wholesale cost of guitar
	double price; //retail cost of guitar
}guitars; //struct name

//FUNCTION PROTOTYPES
void Greeting(void); //greet user
char menu(void); //menu options
void addNew(guitars [], int); //add new entry
void savetofile(guitars [], int); //saves records to an external file
void printToScreen(guitars[], int); //prints records onto screen
void fillFive(guitars []); //hardcodes 5 guitars
int Delete(guitars[], int); //searches for product ID and returns its location to be deleted in main
void Revise(guitars[], int); //updates retail price of guitar
void Clear(guitars[], int); //clears the array's contents

int main()

{
	//local variable declarations
	char let;
	guitars guitarList[size];
	int num = 5, index = 0;

	//function call to greet user
	Greeting();

	//function call to 5 hardcoded guitars list
	fillFive(guitarList);
	
	//loop to present menu options & make function calls until user wants to quit program
	do{
		//function call to present menu options
		let = menu();
		
		//switch statements for menu options
		switch (let){
			//makes function call to add new entry if user enters letter A/a
			case 'A':
				num++;
				addNew(guitarList, num);
				break;
			case 'a':
				num++;
				addNew(guitarList, num);
				break;
			//function call to save file externally if user enters letter S/s
			case 'S':
				savetofile(guitarList, num);
				printf("The report has been saved to file named Out.\n\n");
				break;
			case 's':
				savetofile(guitarList, num);
				printf("The report has been saved to file named Out.\n\n");
				break;
			//function call to print list of guitars entered & their data onto screen if user enters letter P/p
			case 'P':
				printToScreen(guitarList, num);
				break;
			case 'p':
				printToScreen(guitarList, num);
				break;
			//function call to delete an entry if user selects letter D/d
			case 'D':
				index =	Delete(guitarList, num); //function call to find position in array of prodID
				guitarList[index] = guitarList[num - 1]; //deletes designated instance of prodID
				num = num - 1; //subtracts 1 from the count of items in array 
				break;
			case 'd':
				index = Delete(guitarList, num); //function call to find position in array of prodID
				guitarList[index] = guitarList[num - 1];//deletes designated instance of prodID
				num = num - 1; //subtracts 1 from the count of items in array 
				break;
			//function call to update retail price if user selects letter R/r
			case 'R':
				Revise(guitarList, num);
				break;
			case'r': 
				Revise(guitarList, num);
				break;
			//function call to clear contents of array if user selects letter C/c
			case 'C':
				Clear(guitarList, num);
				break;
			case 'c':
				Clear(guitarList, num);
				break;
				
			//message when user opts to quit
			default: printf("Thanks for visiting Guitar Town! Rock on!\n\n");
		}
	}while (let != 'q' && let != 'Q');
	
	return 0;
}

//FUNCTION DEFINITIONS
//greet user
void Greeting(void)
{
	printf("\t\t***Welcome to Guitar Town***\n\n");
}

//function to hardcode the 5 guitar entries
void fillFive(guitars list[])
{
	//fills array index 0 with guitar info
	strcpy(list[0].brand, "Fender");
	strcpy(list[0].guitarName, "Jimi_Hendrix_Stratocaster_Electric_Guitar");
	list[0].prodID = 10;
	list[0].qtyAvail = 50;
	list[0].cost = 500.00;
	list[0].price = 899.99;

	//fills array index 1 with guitar info
	strcpy(list[1].brand, "Fender");
	strcpy(list[1].guitarName, "Eric_Clapton_Stratocaster_Electric_Guitar");
	list[1].prodID = 20;
	list[1].qtyAvail = 50;
	list[1].cost = 1000.00;
	list[1].price = 5000.00;

	//fills array index 2 with guitar info
	strcpy(list[2].brand, "Gibson");
	strcpy(list[2].guitarName, "Billy_Joe_Semi-Hollow_Body_Electric_Guitar");
	list[2].prodID = 30;
	list[2].qtyAvail = 25;
	list[2].cost = 1500.00;
	list[2].price = 3500.00;

	//fills array index 3 with guitar info
	strcpy(list[3].brand, "Gibson");
	strcpy(list[3].guitarName, "Les_Paul_Standard_Electric_Guitar");
	list[3].prodID = 40;
	list[3].qtyAvail = 87;
	list[3].cost = 1299.00;
	list[3].price = 2900.00;

	//fills array index 4 with guitar info
	strcpy(list[4].brand, "Ibanez");
	strcpy(list[4].guitarName, "Iron_Label_Electric_Guitar");
	list[4].prodID = 50;
	list[4].qtyAvail = 92;
	list[4].cost = 450.00;
	list[4].price = 1700.00;

}

//function displays menu options and returns user's selection
char menu(void)
{
	//local variable declaration
	char tempLet;

		//menu options
		printf("\nP - Display all records onscreen\n");
		printf("S - Create a current report (external file)\n");
		printf("A - Add new entry\n");
		printf("D - Delete an item from the list\n");
		printf("C - Clear all records\n");
		printf("R - Revise price\n");
		printf("Q - Quit\n");

		printf("\n\nPlease select a menu option above: "); //prompts user for menu selection
		scanf(" %c", &tempLet); //scans user's selection

		//displays user's selection onscreen
		printf("\nYour selection is: %c\n\n", tempLet);

	return tempLet;
}

//function adds new entry
void addNew(guitars listA[], int numA)
{
	//declare local variable
	guitars inventory;

	//prompt and get info from user
	printf("Enter the brand name: ");
	scanf("%s", &inventory.brand);

	//prompt and get info from user
	printf("Enter the guitar model: ");
	scanf("%s", &inventory.guitarName);
	
	//prompt and get info from user
	printf("Enter the product ID: ");
	scanf("%d", &inventory.prodID);
	
	//prompt and get info from user
	printf("Enter the quantity in stock: ");
	scanf("%d", &inventory.qtyAvail);
	
	//prompt and get info from user
	printf("Enter the cost: ");
	scanf("%lf", &inventory.cost);

	//prompt and get info from user
	printf("Enter the retail price: ");
	scanf("%lf", &inventory.price);
	
	listA[numA - 1] = inventory;
}

//function saves records to external file
void savetofile(guitars listS[], int numS)
{
	//local variable declarations
	int i;
	FILE *out;

	//connect to file
	out = fopen("Out.txt", "w");

	for (i = 0; i < numS; i++)
	{
		//prints each category onto an external file
		fprintf(out, "Brand name: %s\n", listS[i].brand);
		fprintf(out, "Guitar Model: %s\n", listS[i].guitarName);
		fprintf(out, "Product ID: %d\n", listS[i].prodID);
		fprintf(out, "Quantity available: %d\n", listS[i].qtyAvail);
		fprintf(out, "Wholesale cost: $%.2f\n", listS[i].cost);
		fprintf(out, "Retail price: $%.2f\n\n", listS[i].price);
	}
	//closes file
	fclose(out);
}

//function prints array of guitars onto screen
void printToScreen(guitars listP[], int numP)
{
	//local variable declaration
	int i;

	//checks if number of elements in array is 0, if so, prints
	//that no records are on file
	if (numP == 0)
	{
		printf("No records on file!\n\n");
	}
	//if items are in array, prints list of guitars in array
	for (i = 0; i < numP; i++)
	{
		printf("Brand name: %s", listP[i].brand);
		printf("\nGuitar model: %s", listP[i].guitarName);
		printf("\nProduct ID: %d\n", listP[i].prodID);
		printf("Quantity available: %d\n", listP[i].qtyAvail);
		printf("Wholesale cost: $%.2f\n", listP[i].cost);
		printf("Retail price: $%.2f\n\n", listP[i].price);
	}
}

//function searches for item in list & deletes it if found
int Delete(guitars listD[], int numD)
{
	//local variable declaration
	int i, currentID, location;

	//displays list of product ID's to user
	printf("The current list of product ID's is:\n", numD);

	for (i = 0; i < numD; i++)
	{
		printf("%d, ", listD[i].prodID);
	}

	//prompt user to enter ID # to be deleted
	printf("\nEnter the ID number you'd like to delete: ");
	scanf("%d", &currentID);
	
	for (i = 0; i < numD; i++)
	{
		if (currentID == listD[i].prodID)
			location = i;
	}
	//won't allow user to delete an ID # outside the scope of what's been input into the array
	if (location >= numD + 1)
	{
		printf("Deletion not possible.\n");
	}
	printf("\nID %d has been deleted.\n", currentID);

	//returns location in the array of the item to be deleted
	return location;
}

//function updates retail price of guitar
void Revise(guitars listU[], int numU)
{
	//local variable declaration
	int i, ID, index;
	double new;
	
	//displays list of product ID's to user
	printf("The current list of product ID's is:\n", numU);

	for (i = 0; i < numU; i++)
	{
		printf("%d, ", listU[i].prodID);
	}

	//prompt user to enter ID # to be updated
	printf("\n\nEnter the ID number you'd like to update: ");
	scanf("%d", &ID);

	//searches for ID # in array 
	for (i = 0; i < numU; i++)
	{
		//if ID # is found, displays contents of ID & prompts user for new price info
		if (ID == listU[i].prodID)
		{
			index = i;

			printf("\nBrand name: %s", listU[i].brand);
			printf("\nGuitar model: %s", listU[i].guitarName);
			printf("\nProduct ID: %d\n", listU[i].prodID);
			printf("Quantity available: %d\n", listU[i].qtyAvail);
			printf("Wholesale cost: $%.2f\n", listU[i].cost);
			printf("Retail price: $%.2f\n\n", listU[i].price);

			printf("Enter the new retail price: ");
			scanf("%lf", &new);

			//substitutes new price info into price element
			listU[i].price = new;
		}
	}
}

//function clears all contents of the array
void Clear(guitars listC[], int numC)
{
	//local variable declaration
	int i;

	for (i = 0; i < numC; i++)
	{
		//clears contents of array at index 0
		strcpy(listC[0].brand, "\0");
		strcpy(listC[0].guitarName, "\0");
		listC[0].prodID = 0;
		listC[0].qtyAvail = 0;
		listC[0].cost = 0;
		listC[0].price = 0;

		//clears contents of array at index 1
		strcpy(listC[1].brand, "\0");
		strcpy(listC[1].guitarName, "\0");
		listC[1].prodID = 0;
		listC[1].qtyAvail = 0;
		listC[1].cost = 0;
		listC[1].price = 0;

		//clears contents of array at index 2
		strcpy(listC[2].brand, "\0");
		strcpy(listC[2].guitarName, "\0");
		listC[2].prodID = 0;
		listC[2].qtyAvail = 0;
		listC[2].cost = 0;
		listC[2].price = 0;

		//clears contents of array at index 3
		strcpy(listC[3].brand, "\0");
		strcpy(listC[3].guitarName, "\0");
		listC[3].prodID = 0;
		listC[3].qtyAvail = 0;
		listC[3].cost = 0;
		listC[3].price = 0;

		//clears contents of array at index 4
		strcpy(listC[4].brand, "\0");
		strcpy(listC[4].guitarName, "\0");
		listC[4].prodID = 0;
		listC[4].qtyAvail = 0;
		listC[4].cost = 0;
		listC[4].price = 0;

		//clears contents of array at all other indexes
		strcpy(listC[i + 1].brand, "\0");
		strcpy(listC[i + 1].guitarName, "\0");
		listC[i + 1].prodID = 0;
		listC[i + 1].qtyAvail = 0;
		listC[i + 1].cost = 0;
		listC[i + 1].price = 0;
	}
	
}