#include <stdio.h>
#include <windows.h>
#include <time.h>
#define Size 15

void initialize(char *ptr);
void delay(clock_t n);
void view_stack(char *ptr, int cnt);
int push(char *ptr, int cnt, char d);
int pop(char *ptr, int cnt);


int main()
{
	char stack[Size], *stack_ptr, n;
	int cnt = 0;

	system("COLOR 02");
	stack_ptr = stack;
	initialize(stack_ptr);

	while (1)
	{
		view_stack(stack_ptr, cnt);
		printf("%30s", "* 1. Push mode.       \n");
		printf("%30s", "* 2. Pop mode.        \n");
		printf("%30s", "* 3. Exit the program.\n");
		printf("\n%24s", "Select number : ");
		scanf("%c", &n);

		if (n == '1')
		{
			while (1)
			{
				view_stack(stack_ptr, cnt);
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Push data : ");
				scanf("%c", &n);

				if (n == '/')
				{
					break;
				}
				else if ((n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
				{
					if (cnt >= Size)
					{
						printf("\n\n%39s", "The stack is full....");
						delay(1000);
					}
					else
					{
						cnt = push(stack_ptr, cnt, n);
					}
				}
			}
		}
		else if (n == '2')
		{
			while (getchar() != '\n');
			while (1)
			{
				view_stack(stack_ptr, cnt);
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Press enter to pop : ");
				scanf("%c", &n);

				if (n == '/')
				{
					break;
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
						printf("\n\n%39s", "The stack is emty....");
						delay(1000);
					}
					else
					{
						printf("\n\n%39s", "Output data : ");
						printf("0x%x", *(stack_ptr + cnt - 1));
						cnt = pop(stack_ptr, cnt);
						delay(1000);
					}
				}
			}
		}
		else if (n == '3')
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

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}

void view_stack(char *ptr,int cnt)
{
	int i;

	system("cls");
	for (i = Size ; i >= 0; i--)
	{
		if (i == Size)
			printf("	|--------------|");
		else
			printf("	|     0x%02x     |", *(ptr + i));
			
		if (i == cnt )
			printf("_______top\n");
		else
			putchar('\n');
	}
	printf("	|______________|\n");
}

int push(char *ptr, int cnt, char d)
{
	*(ptr + cnt++) = d;
	return cnt;
}

int pop(char *ptr, int cnt)
{
	*(ptr + --cnt) = NULL;
	return cnt;
}