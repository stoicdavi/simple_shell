#include "shell.h"
int main(void)
{
	char input[25];

	while (1)
	{
		printf("cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;
		printf("%s\n", input);
		if (strcmp(input, "ls\n") == 0)
			printf("listing all the files and directories");
	}
	return (0);
}
