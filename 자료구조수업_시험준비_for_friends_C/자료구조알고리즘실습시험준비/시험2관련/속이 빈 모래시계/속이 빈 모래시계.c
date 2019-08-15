#include <stdio.h>
#include <string.h>

void main() {
	int i , j, n;

	scanf("%d",&n);

	for (i = 1; i <= 2*n - 1; i++)
	{
		if (i == n)
		{
			for (j = 0; j < n - 1; j++)
				putchar(' ');
			putchar('*');
		}
		else if (i == 1)
		{					
			for (j = 0; j < 2*n - 1; j++)
				putchar('*');
		}
		else if (i == 2 * n - 1)
		{
			for (j = 0; j < 2*n - 1; j++)
				putchar('*');
		}
		else if ( i < n)
		{
			for (j = 0; j < i - 1; j++)
				putchar(' ');
			putchar('*');
			for (j = 0; j < 2 * (n - i) - 1; j++)
				putchar(' ');
			putchar('*');
		}
		else
		{
			for (j = 0; j < 2 * n - i - 1; j++)
				putchar(' ');
			putchar('*');
			for (j = 0; j <  2 * (i - n) - 1; j++)
				putchar(' ');
			putchar('*');
		}
		putchar('\n');
	}
}
