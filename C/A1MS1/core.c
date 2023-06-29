#define _CRT_SECURE_NO_WARNINGS

//#define scanf_s

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer 
// Clear the standard input buffer 

void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer: 
	while (getchar() != '\n')
	{
		;//do nothing!
	}
}

// Wait for user to input the "enter" key to continue

void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}
//get valid int from keyboard
		//display error message if invalid value is entered
		//guarantee an int vale is enteres and returned
int inputInt(void)
{
	int intValue = 0;
	//char string;

	//printf("\nEnter num: ");
	while (scanf("%d", &intValue) != 1)
	{
		
		//********char string = getchar();

		// checking input
				//printf("string entered ");
				//putchar(string);

		clearInputBuffer();

		printf("Error! Input a whole number: ");

	}

	return intValue;
}

int inputIntPositive(void)
{
	//return intValue
	int intValue = 0;
	scanf("%d", &intValue);
	
	while (intValue <= 0)
	{
		printf("ERROR! Value must be > 0: ");
		scanf("%d", &intValue);
	}

	return intValue;
}

int inputIntRange(int LOWERbound, int UPPERbound)
{
	int intValue = 0;
	intValue = inputInt();

	//scanf("%d", &intValue);
	while ((intValue < LOWERbound) || (intValue > UPPERbound))
	{
		printf("ERROR! Value must be between %d and %d inclusive: ", LOWERbound, UPPERbound);
		scanf("%d", &intValue);
	}

	return intValue;
}
// receives one string and return a single character value
char inputCharOption(char* str)
{
	char* string = str;
	int flag = 1;
	char userInput;

	while (flag == 1)
	{
		char * result;
		scanf(" %c", &userInput);
		//char *strrchr(const char *str, int c) searches for the last occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
		result = strrchr(string, userInput);
		//printf("Character  %c result: %s\n", userInput, result);

		if (result != NULL)
		{
			flag = 0;
			//printf("Character -> %c <- return: => %s\n", userInput, result);
			//return userInput;
		}
		else {
			printf("ERROR: Character must be one of [%s]: ", string);
		}
	}
	return userInput;
}
void inputCString(char* string, int MINvalue, int MAXvalue)
{
	char newLine = 'x';
	//char character;
	int flag = 0;


	do {
		//find string length
		scanf(" %[^\n]%c", string, &newLine);
		int i, length = 0;

		for (i = 0; string[i] != '\0'; i++)
		{
			length++;
		}


		//printf("character = %s, str_len = %d, flag = %d\n", list_characters, str_len, flag);
		if (newLine != '\n')
		{
			clearInputBuffer();
			printf("ERROR: String length must be exactly %d chars: ", MINvalue);
		}
		else if (MINvalue == MAXvalue && (length < MINvalue || length > MINvalue))
		{

			printf("ERROR: String length must be exactly %d chars: ", MINvalue);
		}
		else if (length < MINvalue)
		{

			printf("ERROR: String length must be between %d and %d chars: ", MINvalue, MAXvalue);
		}
		else if (length > MAXvalue)
		{

			printf("ERROR: String length must be no more than %d chars: ", MAXvalue);
		}
		else
		{
			flag = 1;
		}

	} while (flag == 0);

}

//strlen() - get length of a string
//strcmp() - compare two strings

void displayFormattedPhone(char number[])
{
	if (number == NULL)
	{
		printf("(___)___-____");
	}
	
	else
	{
		int i, length_num = 0;
		int is_all_digit = 0;

		for (i = 0; number[i] != '\0'; i++)
		{
			length_num++;
		}

		if (length_num != 10)
		{
			printf("(___)___-____");

		}
		else if (length_num == 10)
		{
			
			int i;
			for (i = 0; i < length_num; i++)
			{
				if (isdigit(number[i]) == 0)
				{
					is_all_digit = 0;
					printf("(___)___-____");
					break;
				}
				else
				{
					is_all_digit = 1;
				}
			}
			if (is_all_digit == 1)
			{
				printf("(%c%c%c)%c%c%c-%c%c%c%c", number[0], number[1], number[2], number[3], number[4],
					number[5], number[6], number[7], number[8], number[9]);
			}
		}

	}
}