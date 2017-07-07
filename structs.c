//Caroline Navega Desouza 
//November 20, 2015
//COP 2220 9:30am
//Lab 10 - Structs

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#define SIZE 20

typedef struct{
	char artist[SIZE];
	char songName[SIZE];
	int length;
	double cost;
}song;

//Function Prototypes

// fills the data fields of a song
//returns the filled song 
song FillSong();

//fills the data fields of a song instance
//by reference using a pointer to a song
void FillSongPtr(song *songptr);

//fills an array of songs
void FillSongArray(song arrayS[], int *size);

//displays one song
void DisplaySong(song anySong);

int main()
{

	//Declare variables
	song mySong, mySong1, mySong2;
	song manySongs[SIZE];
	int cSize;
	int i;

	//Fill structures with a function
	mySong = FillSong();
	mySong1 = FillSong();

	//print using display function
	printf("\n---------Display mySong\n");
	DisplaySong(mySong);
	printf("\n---------Display mySong1\n");
	DisplaySong(mySong1);

	//Fill structure using pointers and display it
	FillSongPtr(&mySong2);
	printf("\n---------Display mySong2\n");
	DisplaySong(mySong2);

	//Fill the array with the function
	printf("\n---------Fill array manySongs\n");
	FillSongArray(manySongs, &cSize);

	//display an array of songs
	printf("\n---------Display array manySongs\n");
	for (i = 0; i<cSize; i++)
	{
		DisplaySong(manySongs[i]);
	}

	return 0;
}

//Function Definitions

// fills the data fields of a song instance
//returns the filled song info
song FillSong()
{
	//Declare local variables
	song tempC;
	//prompt and get information
	printf("\nplease enter the song artist:  ");
	scanf("%s", tempC.artist);
	//print to check
	printf("artist:  %s\n", tempC.artist);

	//prompt and get information
	printf("\nplease enter the song name:  ");
	scanf("%s", tempC.songName);
	//print to check
	printf("song name:  %s\n", tempC.songName);

	//prompt and get information
	printf("\nplease enter the length of your song in seconds:  ");
	scanf("%d", &tempC.length);
	printf("song length:  %d\n", tempC.length);

	//prompt and get information
	printf("\nplease enter the cost of the song:  ");
	scanf("%lf", &tempC.cost);
	printf("song cost:  %.2f\n", tempC.cost);
	return tempC;
}

//displays one card
void DisplaySong(song anySong)
{
	printf("\n\nartist:  %s\n", anySong.artist);
	printf("songName:  %s\n", anySong.songName);
	printf("length:  %d\n", anySong.length);
	printf("cost:  %.2f\n", anySong.cost);
}

//fills the data fields of a song instance
//by reference using a pointer to a song
void FillSongPtr(song *songptr)
{
	//prompt and get information
	printf("\nplease enter the artist' name:  ");
	scanf("%s", (*songptr).artist);

	//prompt and get information
	printf("\nplease enter the name of your song:  ");
	scanf("%s", songptr->songName);

	//prompt and get information
	printf("\nplease enter the length of your song:  ");
	scanf("%d", &(*songptr).length);

	//prompt and get information
	printf("\nplease enter the cost of your song:  ");
	scanf("%lf", &(*songptr).cost);
}

//fills an array of songs
void FillSongArray(song arrayC[], int *size)
{
	int i;
	//prompt the user
	printf("\nenter the number of songs:  ");
	scanf("%d", size);

	//print to check
	printf("size:  %d\n", *size);

	for (i = 0; i < *size; i++)
	{
		printf("enter artist:  ");
		scanf("%s", arrayC[i].artist);

		printf("enter song name:  ");
		scanf("%s", arrayC[i].songName);

		printf("enter length:  ");
		scanf("%d", &arrayC[i].length);

		printf("enter cost:  ");
		scanf("%lf", &arrayC[i].cost);
	}
}