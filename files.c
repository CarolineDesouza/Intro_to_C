//Caroline Navega Desouza
//November 8, 2015
//COP 2220 9:30am
//Lab 9: 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//Function Prototypes
void Greeting(void);

int main()

{
	//Variable declarations
	double num, prod = 0;
	int filenum = 0;
	FILE* inPtr = NULL;
	FILE* outPtr = NULL;

	//Connect to input/output files
	inPtr = fopen("numInput.txt", "r");
	outPtr = fopen("resOut.txt", "a");

	//Function call to greeting
	Greeting();

	//ask user for initial input
	printf("Input your mileage: ");
	//obtain user's miles ran
	scanf("%lf", &num); 
	//read 1st num from file
	fscanf(inPtr, "%d", &filenum);

	//multiply user miles to num in file
	prod = num * filenum;

	//display product of miles ran
	printf("You ran %.2f miles. Good job! ", prod);
	
	//record product into output file
	fprintf(outPtr, "%.2f\n", prod);

	//Notify user their run data has been input into file
	printf("Your run has been recorded.\n");

	//test that num in file isn't = 0
	while (filenum != 0)
	{
		//repeat steps above for user input
		printf("Input your mileage: ");
		scanf("%lf", &num);
		fscanf(inPtr, "%d", &filenum);

		prod = num * filenum;
		printf("You ran %.2f miles. Good job! ", prod);

		fprintf(outPtr, "%.2f\n", prod);
	
		printf("Your run has been recorded.\n");
		
	}

	//Zero was entered, end of file reached
	printf("\n\nGet out there & keep rockin'\n\n!");

	//Close files
	fclose(inPtr);
	fclose(outPtr);
	
	return 0;

}

//Function Definition to greet user
void Greeting()
{
	printf("\t\t*****This is a Runner's World*****\n\n");
	printf("\t\t\tHow hard do you run?\n\n");
	printf("Let's see if you gave it all you've got today...\n");
}
