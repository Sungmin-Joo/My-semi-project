#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}

char* titel_1 = "                ■■■■■       ■■■■      ■■■■  　■■   ■■　■■■■■　■■■      ■■\n";
char* titel_2 = "                ■■   ■■     ■■  ■■    ■■       　■■ ■■  　   ■■   　■■■■    ■■\n";
char* titel_3 = "                ■■■■■     ■■■■■■     ■■■   　■■■■   　   ■■   　■■  ■■  ■■\n";
char* titel_4 = "                ■■   ■■   ■■      ■■        ■■ 　■■ ■■  　   ■■   　■■    ■■■■\n";
char* titel_5 = "                ■■■■■   ■■        ■■  ■■■■  　■■   ■■　■■■■■　■■        ■■\n";

char Mainloop()
{
	char mode;
	system("cls");
	printf(titel_1);
	printf(titel_2);
	printf(titel_3);
	printf(titel_4);
	printf(titel_5);
	printf("%60s", "1. Going first\n");
	printf("%60s", "2. Going second\n");
	printf("\n\n\n");
	printf("%60s", "Please choose the options :");
	scanf("%c", &mode);
	while (getchar() != '\n');
	return mode;
}

void first_attack()
{
	char* user_num[3];
	int current_number = 0;
	int i;
	system("cls");
	while (1)
	{
		printf("%80s", "Input number ");
		printf("(in %d ~ %d) : ", current_number + 1, current_number + 3);
		scanf("%s", &user_num);
		while (getchar() != '\n');
		if (atoi(user_num) == 0)
		{
			printf("%40s", "Please check the range of values.\n");
		}
		else if (atoi(user_num) < current_number + 1 || atoi(user_num) > current_number + 3)
		{
			printf("%40s", "Please check the range of values.\n");
		}
		else
		{
			current_number = atoi(user_num);
			for (i = 2; i < 31; i+=4)
			{
				if (i > current_number)
				{
					current_number = i;
					break;
				}
			}
			printf("%40s", "This is an attack on the computer. :");
			printf("%d\n", current_number);
			if (current_number == 30)
			{
				printf("%70s", "You lose. Try again\n");
				printf("%70s", "Go to the initialization screen in   ");
				for (i = 3; i > 0; i--)
				{
					printf("\b\b%ds", i);
					delay(1000);
				}
				break;
			}
		}
	}
}

int main()
{
	while (1)
	{
		char mode;
		mode = Mainloop();
		if (mode == '1')
		{
			first_attack();
		}
		else
		{

		}
	}
	return 0;
}
