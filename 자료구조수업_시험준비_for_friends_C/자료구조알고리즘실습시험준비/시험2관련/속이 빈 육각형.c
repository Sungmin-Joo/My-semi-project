#include <stdio.h>
#include <string.h>

void main() {
	int i, j, n;

	scanf("%d", &n);

	for (i = 1; i <= 2 * n - 1; i++)
	{
		if (i == n)
		{
			for (j = 0; j < (2 * i) - 1 + (2 * n - 1); j++)
				if (j == 0)
					putchar('*');
				else if (j == (2 * i) - 2 + (2 * n - 1))
					putchar('*');
				else
					putchar(' ');
		}
		else if (i == 1)
		{
			for (j = 0; j < n - i; j++)
				putchar(' ');
			for (j = 0; j < n; j++)
				printf("%c ",'*');
				
		}
		else if (i == 2 * n - 1)
		{
			for (j = 0; j < i - n; j++)
				putchar(' ');
			for (j = 0; j < n; j++)
				printf("%c ", '*');
		}
		else if (i <= n)
		{
			for (j = 0; j < (n - i) ; j++)
				putchar(' ');
			for (j = 0; j < (2 * i) - 1 + (2 * n - 1); j++)
				if (j == 0)
					putchar('*');
				else if (j == (2 * i) - 2 + (2 * n - 1))
					putchar('*');
				else
					putchar(' ');
		}
		else
		{
			for (j = 0; j < i - n; j++)
				putchar(' ');
			for (j = 0; j < ((2 * n) - 1) - 2 * (i - n) + (2 * n - 1); j++)
				if (j == 0)
					putchar('*');
				else if (j == ((2 * n) - 2) - 2 * (i - n) + (2 * n - 1))
					putchar('*');
				else
					putchar(' ');
		}
		putchar('\n');
	}
}
