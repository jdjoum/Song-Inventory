
// Julian-Justin Djoum
// 4.27.2018
// Large Program 4 (Inventory)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50

typedef struct {
	char artistName[SIZE];
	char songName[SIZE];
	int songId;
	int songStreams;
	double songCost;
	double albumCost;
}tunes;

//Function Prototypes:
//Greets the User & Explains the Program's Obj.
void Greeting();

//Adds 5 Songs to the tuneList Array
void Add5(tunes tunesList[]);

//Displays Tune Information 
void TunesToScreen(tunes tunesList[], int count);

//Gets Option Letter from User
char GetLetter();

//Saves Tune Information to 'out.txt' File
void SaveToFile(tunes tunesList[], int count);

//Adds Tune to 'tunesList[SIZE]'
void AddTune(tunes tunesList[], int count);

//Displays All Song IDs
int DisplaySongIDs(tunes tunesList[], int count);

//Checks if the entered ID (#) matches one of the Song ID (#'s) / if yes, returns the corresponding array index (#) / if no, returns -1
int Search(tunes tunesList[], int count, int songId);

// Update a Tune's Song Cost
void UpdateSongCost(tunes tunesList[], int index);

// Delete a song from 'tunesList'
void DeleteSong(tunes tunesList[], int count, int index);

int main()
{
	tunes tunesList[SIZE];
	char letter;

	int count = 0;
	int temp;
	int index;

	Greeting();
	Add5(tunesList);
	count = 5;



	letter = GetLetter();
	letter = toupper(letter);

	while (letter != 'Q')
	{
		if (letter == 'P')
		{
			printf("\n[PRINT]\n");
			TunesToScreen(tunesList, count);
		}
		else if (letter == 'A')
		{
			printf("\n[ADD]\n");
			AddTune(tunesList, count);
			count = count + 1;
		}
		else if (letter == 'C')
		{
			printf("\n[CLEAR]\n");
			printf("\n[THE TUNE LIST HAS BEEN CLEARED]\n");
			count = 0;
		}
		else if (letter == 'S')
		{
			printf("\n[SAVE TO FILE]\n");
			SaveToFile(tunesList, count);
		}
		else if (letter == 'D')
		{
			printf("\n[DELETE]\n\n");
			temp = DisplaySongIDs(tunesList, count);
			printf("\nYou entered Song ID (#): %d.", temp);
			index = Search(tunesList, count, temp);
			printf("\nThe index is: %d\n", index);
			printf("\n[THE SONG HAS BEEN DELETED]\n");
			if (index == -1)
			{
				printf("\n[Song ID (#) Unrecognized]\n");
			}
			else
			{
				DeleteSong(tunesList, count, index);
				count = count - 1;
			}

		}
		else if (letter == 'U')
		{
			printf("\n[UPDATE]\n\n");
			temp = DisplaySongIDs(tunesList, count);
			//printf("\nYou entered: %d", temp);
			index = Search(tunesList, count, temp);
			printf("\nYou entered Song ID (#): %d, & the corresponding Index is: %d.\n", temp, index);
			if (index == -1)
			{
				printf("\n[Song ID (#) Unrecognized]\n");
			}
			else
			{
				UpdateSongCost(tunesList, index);
			}
		}

		else
		{
			printf("\n[Letter Unrecognized]\n");
		}
		letter = GetLetter();
		letter = toupper(letter);
	}

	if (letter == 'Q')
	{
		printf("\n[GOODBYE USER!]\n");
	}

	return 0;
}

//Function Definitions:
//Greets the User & Explains the Program Obj.
void Greeting()
{
	printf("--Welcome to the Music Inventory Program--\n\n");
	printf("This Program manages lists of: \n\n-artist name\n-song name\n-(#) of online song streams\n-song ID (#)\n-cost of song ($)\n-and the cost of the whole album containing the song ($)\n\n");
	printf("Each Song has a unique ID (#)\n\n");
	printf("Follow the Prompts in the Menu:\n");
	printf("\n---------------------------------\n");


}

//Adds 5 Songs to the tuneList Array
void Add5(tunes tunesList[])
{
	strcpy(tunesList[0].artistName, "Bones");
	strcpy(tunesList[0].songName, "Drip");
	tunesList[0].songId = 90;
	tunesList[0].songStreams = 1222;
	tunesList[0].songCost = 1.29;
	tunesList[0].albumCost = 7.99;

	strcpy(tunesList[1].artistName, "XavierWulf");
	strcpy(tunesList[1].songName, "Dengen");
	tunesList[1].songId = 87;
	tunesList[1].songStreams = 1679;
	tunesList[1].songCost = 1.29;
	tunesList[1].albumCost = 8.99;

	strcpy(tunesList[2].artistName, "LilUziVert");
	strcpy(tunesList[2].songName, "XOTourLife");
	tunesList[2].songId = 57;
	tunesList[2].songStreams = 1890;
	tunesList[2].songCost = 1.29;
	tunesList[2].albumCost = 10.99;

	strcpy(tunesList[3].artistName, "GucciMane");
	strcpy(tunesList[3].songName, "Lemonade");
	tunesList[3].songId = 24;
	tunesList[3].songStreams = 1997;
	tunesList[3].songCost = 1.29;
	tunesList[3].albumCost = 6.99;

	strcpy(tunesList[4].artistName, "LilSkies");
	strcpy(tunesList[4].songName, "Lust");
	tunesList[4].songId = 32;
	tunesList[4].songStreams = 1427;
	tunesList[4].songCost = 1.29;
	tunesList[4].albumCost = 5.99;

}

//Displays Tune Information
void TunesToScreen(tunes tunesList[], int count)
{
	int i;
	int x = 1;

	if (count == 0)
	{
		printf("\n[TUNE LIST IS EMPTY]\n");
	}

	for (i = 0; i < count; i++)
	{

		printf("\nTune (#): %d", x);
		printf("\nThe Artist Name is: %s.", tunesList[i].artistName);
		printf("\nThe Song Name is: %s.", tunesList[i].songName);
		printf("\nThe Song ID is: %d.", tunesList[i].songId);
		printf("\nThe (#) of online Song Streams is: %d.", tunesList[i].songStreams);
		printf("\nThe Song Cost is: $%.2f", tunesList[i].songCost);
		printf("\nThe Album Cost is: $%.2f\n", tunesList[i].albumCost);
		x++;
	}

}


//Gets Option Letter from User
char GetLetter()
{
	printf("\n--OPTION LIST:--\n");
	printf("\n[P] - Print All Tune Information.\n");
	printf("[A] - Add a New Tune. \n");
	printf("[C] - Clear All Tunes. \n");
	printf("[S] - Save Tune Information to a File (out.txt). \n");
	printf("[D] - Delete a Tune.\n");
	printf("[U] - Update a Tune's (Song Cost). \n");
	printf("[Q] - Quit. \n");


	char templetter;

	printf("\nUser, please enter a letter option: ");
	scanf(" %c", &templetter);

	return templetter;
}

//Saves Tune Information to 'out.txt' File
void SaveToFile(tunes tunesList[], int count)
{

	FILE *outPtr;
	outPtr = fopen("out.txt", "w");
	int i;
	int x = 1;

	for (i = 0; i < count; i++)
	{
		fprintf(outPtr, "\nTune (#): %d", x);
		fprintf(outPtr, "\nThe Artist Name is: %s.", tunesList[i].artistName);
		fprintf(outPtr, "\nThe Song Name is: %s.", tunesList[i].songName);
		fprintf(outPtr, "\nThe Song ID is: %d.", tunesList[i].songId);
		fprintf(outPtr, "\nThe (#) of online Song Streams is: %d.", tunesList[i].songStreams);
		fprintf(outPtr, "\nThe Song Cost is: $%.2f", tunesList[i].songCost);
		fprintf(outPtr, "\nThe Album Cost is: $%.2f\n", tunesList[i].albumCost);
		x++;
	}

	fclose(outPtr);

}

//Adds Tune to 'tunesList[SIZE]'
void AddTune(tunes tunesList[], int count)
{
	printf("\nEnter the Artist Name: ");
	scanf("%s", tunesList[count].artistName);
	printf("\nEnter the Song Name: ");
	scanf("%s", tunesList[count].songName);
	printf("\nEnter the Song ID: ");
	scanf("%d", &tunesList[count].songId);
	printf("\nEnter the (#) of online Song Streams: ");
	scanf("%d", &tunesList[count].songStreams);
	printf("\nEnter the Song Cost: $");
	scanf("%lf", &tunesList[count].songCost);
	printf("\nEnter the Album Cost: $");
	scanf("%lf", &tunesList[count].albumCost);
}

//Displays All Song IDs
int DisplaySongIDs(tunes tunesList[], int count)
{
	int i;
	int currentid;

	for (i = 0; i < count; i++)
	{
		printf("The Song ID is: %d.\n", tunesList[i].songId);
	}
	printf("\nEnter the Song ID that you would like to modify: ");
	scanf("%d", &currentid);
	return currentid;
}

//Checks if the entered ID (#) matches one of the Song ID (#'s) / if yes, returns the corresponding array index (#) / if no, returns -1
int Search(tunes tunesList[], int count, int currentid)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (currentid == tunesList[i].songId)
		{
			return i;
		}
		//else { return -1; }
	}
	return -1;
}

// Update a Tune's Song Cost
void UpdateSongCost(tunes tunesList[], int index)
{
	double temp;
	printf("\nThe Song Cost is currently: $%.2f", tunesList[index].songCost);
	printf("\nUser, please enter the updated Song Cost: $");
	scanf("%lf", &temp);
	tunesList[index].songCost = temp;
	printf("\nThe updated Song Cost is: $%.2f.\n", temp);

}

// Delete a song from 'tunesList'
void DeleteSong(tunes tunesList[], int count, int index)
{
	tunesList[index] = tunesList[count - 1];
	//count = count - 1;
}