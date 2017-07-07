//Caroline Navega Desouza 
//November 15, 2015
//COP 2220 9:30am
//Program 3 - Makes words plural

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function Prototypes
void Greeting(void); //Greeting to user
void upLoCase(char); //Checks if word is upper or lower case
void wordLength(int, char);
void whichRuleLower(int, char);
void whichRuleUpper(int, char);
void otherChar(int, char);
void applyRuleLo(char, char, int);
void applyRuleUp(char, char, int);
void otherRules(char, char, int);



int main()
{
	//declare variables
	char let;
	char word[20];
	char plural[20];
	int length = 0;
	int len = 0;
	FILE* outPtr = NULL;


	//Function call to greet user
	Greeting();

	//ask user if they want to play
	printf("Would you like to play? Enter y for yes or n for no: ");
	scanf(" %c", &let);

	//open file to write words to
	outPtr = fopen("wordList.txt", "w");

	if (let == 'y' || let == 'Y')
	{
		//acknowledgement that user agreed to play
		printf("Great! Let's learn the plural of some words today!\n\n");
	}
	
	//Loop for when user enters yes to play
	while (let == 'y' || let == 'Y')
	{
		//Ask user for a word
		printf("Go ahead and enter a word on Elmo's list: ");
		scanf("%s", word);
		
		//function call to check if word is upper/lowercase
		upLoCase(word);

		//function call to count how many letters are in the word
		wordLength(length, word);

		//function call to check if and which lowercase rules apply
		whichRuleLower(length, word);

		//function call to check if and which uppercase rules apply
		whichRuleUpper(length, word);

		//function call to check if rules 5 or 6 apply to word
		otherChar(length, word);
		
		//function call to apply rules 1 or 3 for lowercase words
		applyRuleLo(plural, word, length);

		//function call to apply rules 2 or 4 for uppercase words
		applyRuleUp(plural, word, length);

		//function call to apply rules 5 or 6 for upper/lowercase words
		otherRules(plural, word, length);

		//prints words into file
		fprintf(outPtr, "%s and %s\n\n", word, plural);

		//ask user if they want to play again
		printf("Would you like to play again? Enter y for yes or n for no: ");
		scanf(" %c", &let);

		//if user says no, say goodybye
		if (let == 'n' || let == 'N')
		{
			printf("I hope you learned some new words today! See you next time!\n\n");
		}
	}

	//Close file
	fclose(outPtr);

	return 0;

}

//Function Definitions
//Definition to greet user
void Greeting()
{
	//Game title
	printf("\t\t*****What's the Word on the Street?*****\n");
	printf("\t\t  A game with Elmo from Sesame Street!\n\n");
	//Elmo greets user
	printf("Hi! My name is Elmo and I want to play a word game called plurals!\n");
}

//Verifies if word entered is upper or lowercase
void upLoCase(char *word)
{
	//checks if word is uppercase
	if (isupper(word[0]))
	{
		printf("You entered an uppercase word, %s.\n", word);
	}
	//if word is lowercase, prints statement below
	else
	{
		printf("You entered a lowercase word, %s.\n", word);
	}
}

//Counts number of letters in word entered & tells the user
void wordLength(int length, char *word)
{
	//counts how many letters in word & prints onto screen
	length = strlen(word);
	printf("%s has %d letters in it. ", word, length);
}

//Checks if and which lowercase rule applies to the word
void whichRuleLower(int length, char *word)
{
	length = strlen(word);

	//verifies if word is uppercase
	if (islower(word[0]))
	{
		//verifies if word ends in lowercase y. If so, indicates rule 1 should be used
		if (word[strlen(word) - 1] == 'y')
		{
			//says to apply rule 1 if word ends in y
			printf("\nWe're going to use rule #1 for this one because it ends in a lowercase y!\n");
		}
		//verifies if word ends in an s. If so, says to apply rule 3
		if (word[strlen(word) - 1] == 's')
		{
			//says to apply rule 3 if word ends in s
			printf("\nWe're going to use rule #3 for this one because it ends in a lowercase s!\n");
		}
		//verifies if word ends in ch. If so, says to apply rule 3
		if (word[(strlen(word) - 2)] == 'c' && word[(strlen(word) - 1)] == 'h')
		{
			//apply rule 3 if word ends in "ch"
			printf("\nWe're going to use rule #3 for this one because it ends in a lowercase ch!\n");
		}
		//verifies if word ends in sh. If so, says to apply rule 3
		if (word[(strlen(word) - 2)] == 's' && word[(strlen(word) - 1)] == 'h')
		{
			//apply rule 3 if word ends in "sh"
			printf("\nWe're going to use rule #3 for this one because it ends in a lowercase sh!\n");
		}
	}
}

//Checks if and which uppercase rule applies to the word
void whichRuleUpper(int length, char *word)
{
	length = strlen(word);

	//verifies if word is uppercase
	if (isupper(word[0]))
	{
		//verifies if word ends in uppercase Y. If so, indicates rule 1 should be used
		if (word[strlen(word) - 1] == 'Y')
		{
			//says to apply rule #2 if word ends in Y
			printf("\nWe're going to use rule #2 for this one because it ends in an uppercase Y!\n");
		}
		//verifies if word ends in an S. If so, says to apply rule 4
		if (word[strlen(word) - 1] == 'S')
		{
			//says to apply rule 4 if word ends in S
			printf("\nWe're going to use rule #4 for this one because it ends in an uppercase S!\n");
		}
		//verifies if word ends in CH. If so, says to apply rule 4
		if (word[(strlen(word) - 2)] == 'C' && word[(strlen(word) - 1)] == 'H')
		{
			//apply rule 4 if word ends in "CH"
			printf("\nWe're going to use rule #4 for this one because it ends in an uppercase CH!\n");
		}
		//verifies if word ends in SH. If so, says to apply rule 4
		if (word[(strlen(word) - 2)] == 'S' && word[(strlen(word) - 1)] == 'H')
		{
			//apply rule 4 if word ends in "SH"
			printf("\nWe're going to use rule #4 for this one because it ends in uppercase SH!\n");
		}
	
	}
}

//Definition for words ending in other letters - Checks if rules 5 or 6 apply
void otherChar(int length, char *word)
{
	length = strlen(word);

	//checks if word is lowercase
	if (islower(word[0]))
	{
		//checks if word ends in y, s, ch or sh
		if (word[strlen(word) - 1] != 'y' && word[strlen(word) - 1] != 's' && word[strlen(word) - 2] != 'c' && word[strlen(word) - 1] != 'h'
			&& word[strlen(word) - 2] != 's' && word[strlen(word) - 1] != 'h')
		{
			//if word ends in letter other than above, says rule 5 to be used
			printf("\nWe're going to use rule #5 for this one because no other rule applies!\n");
		}
	}
	//checks if word is uppercase
	if (isupper(word[0]))
	{
		//checks if word ends in capital Y, S, CH OR SH
		if (word[strlen(word) - 1] != 'Y' && word[strlen(word) - 1] != 'S' && word[strlen(word) - 2] != 'C' && word[strlen(word) - 1] != 'H'
			&& word[strlen(word) - 2] != 'S' && word[strlen(word) - 1] != 'H')
		{
			//if word ends in letter other than above, says rule 6 to be used
			printf("\nWe're going to use rule #6 for this one because no other rule applies!\n");
		}
	}
}

//Applies rules 1 & 3 for lowercase words
void applyRuleLo(char *plural, char *word, int length)
{
	length = strlen(word);

	//checks if word is lowercase
	if (islower(word[0]))
	{
		//apply rule 1: remove y & add "ies" to word ending
		if (word[strlen(word) - 1] == 'y')
		{
			strcpy(plural, word);

			plural[length - 1] = 'i';
			strcat(plural, "es");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
		//apply rule 3: add "es" to word ending in s
		if (word[strlen(word) - 1] == 's')
		{
			strcpy(plural, word);
			strcat(plural, "es");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
		//apply rule 3: add "es" to word ending in ch
		if (word[strlen(word) - 2] == 'c' && word[strlen(word) - 1] == 'h')
		{
			strcpy(plural, word);
			strcat(plural, "es");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
		//apply rule 3: add "es" to word ending in sh
		if (word[strlen(word) - 2] == 's' && word[strlen(word) - 1] == 'h')
		{
			strcpy(plural, word);
			strcat(plural, "es");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}

	}
	
}

//Applies rules 2 & 4 for uppercase words
void applyRuleUp(char *plural, char *word, int length)
{
	length = strlen(word);
	//checks if word is uppercase
	if (isupper(word[0]))
	{
		//apply rule 2: remove Y & add "IES" to word ending
		if (word[strlen(word) - 1] == 'Y')
		{
			strcpy(plural, word);

			plural[length - 1] = 'I';
			strcat(plural, "ES");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
		//apply rule 4: add "ES" to word ending in S
		if (word[strlen(word) - 1] == 'S')
		{
			strcpy(plural, word);
			strcat(plural, "ES");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
		//apply rule 4: add "ES" to word ending in CH
		if (word[strlen(word) - 2] == 'C' && word[strlen(word) - 1] == 'H')
		{
			strcpy(plural, word);
			strcat(plural, "ES");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
		//apply rule 4: add "ES" to word ending in SH
		if (word[strlen(word) - 2] == 'S' && word[strlen(word) - 1] == 'H')
		{
			strcpy(plural, word);
			strcat(plural, "ES");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
	}
}

//Applies rules 5 or 6 for upper/lowercase words
void otherRules(char *plural, char *word, int length)
{
	length = strlen(word);

	//checks if word is lowercase
	if (islower(word[0]))
	{
		//checks if word ends in y, s, sh or ch & applies rule 5 if not
		if (word[strlen(word) - 1] != 'y' && word[strlen(word) - 1] != 's' && word[strlen(word) - 2] != 'c' && word[strlen(word) - 1] != 'h'
			&& word[strlen(word) - 2] != 's' && word[strlen(word) - 1] != 'h')
		{
			strcpy(plural, word);
			strcat(plural, "s");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
	}
	if (isupper(word[0]))
	{
		//checks if word end in Y, S, CH OR SH & applies rule 6 if not
		if (word[strlen(word) - 1] != 'Y' && word[strlen(word) - 1] != 'S' && word[strlen(word) - 2] != 'C' && word[strlen(word) - 1] != 'H'
			&& word[strlen(word) - 2] != 'S' && word[strlen(word) - 1] != 'H')
		{
			strcpy(plural, word);
			strcat(plural, "S");
			//prints singular & plural words onto screen
			printf("The plural of %s is %s\n\n", word, plural);
		}
	}
}


