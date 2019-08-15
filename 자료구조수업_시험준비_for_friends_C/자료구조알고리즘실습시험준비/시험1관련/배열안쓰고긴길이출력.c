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

	printf("가장 긴 단어 : ");
	while (i--)
	{
		if (*ptr == ' ' || *ptr == '\0')
		{
			if (max < temp)
			{
				if (max != 0)
				{
					for (j = 0; j < max; j++)
						putchar('\b');
				}
				max = temp;
				ptr -= max;
				for (j = 0; j < max; j++)
					putchar(*ptr++);
			}
			temp = 0;
		}
		else
		{
			temp++;
		}
		ptr++;
	}

	printf("\n\n가장 긴 단어의 길이 : %d\n\n",max);
	

	return 0;
}