//Erik Roeckel (Efr11)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char string[200];
	int length = 0;
	char character;
	FILE* file;

	file = fopen(argv[1], "rb");

	if(file == NULL)
	
	{
		printf("This file doesn't exist...");
		return 0;
	}

	while(!feof(file))
	{
		fread(&character, sizeof(character), 1, file);

		if(character >= 32 && character <= 126)
		{
			string[length] = character;
			length++;
			continue;
		}
		string[length] = '\0';

		if(length >= 4)
		{
			printf("%s\n", string);
		}
		length = 0;
		string[0] = '\0';

	}

	fclose(file);
	return 0;
}

