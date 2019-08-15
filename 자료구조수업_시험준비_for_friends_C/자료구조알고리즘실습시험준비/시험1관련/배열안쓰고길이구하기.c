#include <stdio.h>
#include <string.h>

int main()
{
	char input[100] = { 0 };
	char *ptr;
	int i, j = 0,  max = 0, min = 0,temp = 0;

	printf("Input 5 world with space : ");
	gets(input);

	i = strlen(input) + 1;
	ptr = input;
	while (i--)
	{
		if (*ptr == ' ' || *ptr == '\0')
		{
			putchar('\n');
			if (max < temp)
			{
				max = temp;
			}

			if (min > temp)
			{
				min = temp;
			}
			temp = 0;
		}
		else
		{
			putchar(*ptr);
			temp++;
		}
		ptr++;
	}

	printf("\n\n가장 긴 단어의 길이 : %d\n\n",max);
	printf("\n\n가장 짧은 단어의 길이 : %d\n\n", min);
	

	return 0;
}