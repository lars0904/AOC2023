#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int concat(int a, int b)
{

    char s1[20];
    char s2[20];

    // Convert both the integers to string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    // Concatenate both strings
    strcat(s1, s2);

    // Convert the concatenated string
    // to integer
    int c = atoi(s1);

    // return the formed integer
    return c;
}

int main(int argc, char* argv[])
{
	bool numOneRead = false;
	bool secondDigitPresent = false;

	int numOne = -1;
	int numTwo = -1;
	int total = 0;
	char readChar = 0;

	FILE* filePointer = fopen("input.txt", "r");

	if(filePointer == NULL)
	{
		printf("file not found\n");
		return -1;
	}

	else
	{
		printf("file found\n");
	}

	do
	{
		readChar = fgetc(filePointer);
		if(isdigit(readChar))
		{
			if(numOneRead)
			{
				numTwo = readChar - 0x30;
				secondDigitPresent = true;
			}

			else
			{
				numOne = readChar - 0x30;
				numOneRead = true;
			}
		}

		else if(readChar == '\n')
		{
			if(!secondDigitPresent)
			{
				numTwo = numOne;
			}
			secondDigitPresent = false;
			numOneRead = false;
			total += concat(numOne, numTwo);
		}
	}
	while(readChar != EOF);
	fclose(filePointer);
	printf("total is %d\n", total);
	return 0;
}
