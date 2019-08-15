#include <stdio.h>
#include <string.h>

void main() {
	int i, j, n;

	scanf("%d", &n);

	for (i = 1; i <= 2 * n - 1; i++)
	{
		if (i == n)
		{
			for (j = 0; j < (2 * i) - 1; j++)
				if (j == 0)
					putchar('*');
				else if (j == ((2 * i) - 2) / 2)
					putchar('*');
				else if (j == (2 * i) - 2)
					putchar('*');
				else
					putchar('*');
		}
		else if (i <= n)
		{
			for (j = 0; j < n - i; j++)
				putchar(' ');
			for (j = 0; j < (2 * i) - 1; j++)
				if (j == 0)
					putchar('*');
				else if (j == (2 * i) - 2)
					putchar('*');
				else
					putchar('*');
		}
		putchar('\n');
	}
}
