#include "shell.h"


int deblank(char *input)
{
	int i, j;
	char *output = input;

	for (i = 0, j = 0; i < _strlen(input); i++, j++)
	{
		if (input[i] != ' ')
		{
			output[j] = input[i];/*if its an space put it and later we will overwrite tht*/

			if(input[i + 1] == ' ')
			{
				j++;
				i++;
				output[j] = input[i];
			}
		}
		else
			j--;
	}
	output[j] = '\0';
	input = _strcpy(output, input);
	return (0);
}
