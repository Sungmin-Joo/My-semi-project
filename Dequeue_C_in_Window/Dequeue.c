#include <stdio.h>
#include <windows.h>
#include <time.h>
#define Size 70

void initialize(char *ptr);
void print_deq(char *str, int cnt);
void delay(clock_t n);
int L_push(char *ptr, int cnt);
int R_push(char *ptr, int cnt);
int L_pop(char *ptr, int cnt);
int R_pop(char *ptr, int cnt);
int main()
{
	char dequeue[Size], n;
	int  cnt = 0;
	char *dequeue_ptr;

	system("COLOR 0C");

	dequeue_ptr = dequeue;
	initialize(dequeue_ptr);

	while (1)
	{
		print_deq(dequeue_ptr, cnt);

		printf("%45s", "* 1. L_push mode.     \n");
		printf("%45s", "* 2. R_push mode.     \n");
		printf("%45s", "* 3. L_pop mode.      \n");
		printf("%45s", "* 4. R_pop mode.      \n");
		printf("%45s", "* 5. Exit the program.\n");
		printf("\n%39s", "Select number : ");
		scanf("%c", &n);

		if (n == '1')
		{
			cnt = L_push(dequeue_ptr, cnt);
		}
		else if (n == '2')
		{
			cnt = R_push(dequeue_ptr, cnt);
		}
		else if (n == '3')
		{
			cnt = L_pop(dequeue_ptr, cnt);
		}
		else if (n == '4')
		{
			cnt = R_pop(dequeue_ptr, cnt);
		}
		else if (n == '5')
			break;
	}
	return 0;
}

void initialize(char *ptr)
{
	int i;

	for (i = 0; i < Size; i++)
		*ptr++ = 0;
}

void print_deq(char *str, int cnt)
{
	int i, t;
	t = (cnt / 2);
	system("cls");
	printf("======================================================================\n");
	for (i = 0; i < (Size / 2) - t; i++)
		putchar(' ');
	for (i = 0; i < cnt; i++)
		putchar(*str++);
	for (i = 0; i < (Size / 2) - t; i++)
		putchar(' ');
	printf("\n======================================================================\n");
}

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}

int L_push(char *ptr, int cnt)
{
	int i;
	char n;

	while (1)
	{
		print_deq(ptr, cnt);
		printf("\n\n%39s", "(Press '/' to out)");
		printf("\n%39s", "Pop data : ");
		scanf("%c", &n);

		if (n == '/')
		{
			return cnt;
			//break;
		}
		else if ((n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		{
			if (cnt >= Size)
			{
				printf("\n\n%39s", "The dequeue is full....");
				delay(1000);
			}
			else
			{
				for (i = cnt; i > 0; i--)
				{
					*(ptr + i) = *(ptr + i - 1);
				}
				*ptr = n;
				cnt++;
			}
		}
	}
}

int R_push(char *ptr, int cnt)
{
	int i;
	char n;

	while (1)
	{
		print_deq(ptr, cnt);
		printf("\n\n%39s", "(Press '/' to out)");
		printf("\n%39s", "Pop data : ");
		scanf("%c", &n);

		if (n == '/')
		{
			return cnt;
			//break;
		}
		else if ((n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
		{
			if (cnt >= Size)
			{
				printf("\n\n%39s", "The dequeue is full....");
				delay(1000);
			}
			else
			{
				*(ptr + cnt) = n;
				cnt++;
			}
		}
	}
}

int R_pop(char *ptr, int cnt)
{
	char n;

	while (getchar() != '\n');
	while (1)
	{
		print_deq(ptr, cnt);
		printf("\n\n%39s", "(Press '/' to out)");
		printf("\n%39s", "Press enter to pop : ");
		scanf("%c", &n);

		if (n == '/')
		{
			return cnt;
			//break;
		}
		else
		{
			/*
			else if ( n == '10)
			On the VS of the Windows operating system,
			'Enter' is detected as '10' because 'LF' of 'Enter' is entered first.
			*/
			if (cnt <= 0)
			{
				printf("\n\n%39s", "The dequeue is emty....");
				delay(1000);
			}
			else
			{
				printf("\n\n%39s", "Output data : ");
				putchar(*(ptr + --cnt));
				*(ptr + cnt) = NULL;
				delay(1000);
			}
		}
	}
}

int L_pop(char *ptr, int cnt)
{
	char n;
	int i;
	while (getchar() != '\n');
	while (1)
	{
		print_deq(ptr, cnt);
		printf("\n\n%39s", "(Press '/' to out)");
		printf("\n%39s", "Press enter to pop : ");
		scanf("%c", &n);

		if (n == '/')
		{
			return cnt;
			//break;
		}
		else
		{
			/*
			else if ( n == '10)
			On the VS of the Windows operating system,
			'Enter' is detected as '10' because 'LF' of 'Enter' is entered first.
			*/
			if (cnt <= 0)
			{
				printf("\n\n%39s", "The dequeue is emty....");
				delay(1000);
			}
			else
			{
				printf("\n\n%39s", "Output data : ");
				putchar(*(ptr));
				for (i = 0; i < cnt - 1; i++)
				{
					*(ptr + i) = *(ptr + i + 1);
				}
				*(ptr + cnt-- - 1) = NULL;
				delay(1000);
			}
		}
	}
}