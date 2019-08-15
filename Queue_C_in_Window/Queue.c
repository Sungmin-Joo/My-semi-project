#include <stdio.h>
#include <windows.h>
#include <time.h>
#define Size 70

void initialize(char *ptr);
void print_q(char *str, int cnt);
void delay(clock_t n);
int enqueue(char *queue_ptr, int cnt);
int dequeue(char *queue_ptr, int cnt);

int main()
{
	char queue[Size], n;
	int cnt = 0;
	char *queue_ptr;

	queue_ptr = queue;
	initialize(queue);

	while (1)
	{
		print_q(queue_ptr, cnt);
		
		printf("%45s", "= 1. Enqueue mode.    \n");
		printf("%45s", "= 2. Dequeue mode.    \n");
		printf("%45s", "= 3. Exit the program.\n");
		printf("\n%39s", "Select number : ");
		scanf("%c", &n);

		if (n == '1')
		{
			while (1)
			{
				print_q(queue_ptr, cnt);
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Enqueue data : ");
				scanf("%c", &n);
				
				if (n == '/')
				{
					break;
				}
				else if ( (n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
				{
					if (cnt >= Size)
					{
						printf("\n\n%39s", "The queue is full....");
						delay(1000);
					}
					else
					{
						cnt = enqueue(queue_ptr, cnt);
						*queue_ptr = n;
					}
				}
			}
		}
		else if (n == '2')
		{
			while (getchar() != '\n');
			while (1)
			{
				print_q(queue_ptr, cnt);
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Press enter to dequeue : ");
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
						printf("\n\n%39s", "The queue is emty....");
						delay(1000);
					}
					else
					{
						printf("\n\n%39s", "Output data : ");
						putchar(*(queue_ptr + cnt - 1));
						cnt = dequeue(queue_ptr, cnt);
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

void print_q(char *str, int cnt)
{
	int i;

	system("cls");
	printf("======================================================================\n");
	for (i = 0; i < cnt; i++)
		putchar(*str++);
	printf("\n======================================================================\n");
}

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}

int enqueue(char *queue_ptr,int cnt)
{
	int i;

	for (i = cnt; i > 0 ; i--)
	{
		*(queue_ptr + i) = *(queue_ptr + i - 1);
	}
	return cnt + 1;
}

int dequeue(char *queue_ptr, int cnt)
{
	*(queue_ptr - 1 + cnt--) = 0;
	return cnt;
}
