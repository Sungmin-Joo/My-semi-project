#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int index = 15;

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}
//Define delay function.
int Detect_key()
{
	unsigned char key;
	char i, air[31] = { 0, };
	if (_kbhit())
	{
		key = _getch();
		if (key == 224 || key == 0)
		{
			key = _getch();
			switch (key)
			{
			case 75:
				//printf("LEFT\n");
				if (index >= 0) { index--; }
				break;
			case 77:
				//printf("RIGHT\n");
				if (index < 30) { index++; }
				break;
				//(224,72) = up, (224,75) = left, (224,77) = right, (224,80) = down.
			default:
				break;
			}
		}
	}
	for (i = 0; i < 30; i++)
	{
		if (i == index) { air[i] = 'o'; }
		else { air[i] = ' '; }
	}
	//Reflects detected actions.
	printf("%s\n", air);
}

void Game_over(int start_time)
{
	system("cls");
	printf("\a");
	printf("GAMEOVER!!!!\n");
	printf("GAMEOVER!!!!\n");
	printf("GAMEOVER!!!!\n");
	printf("GAMEOVER!!!!\n");
	printf("----- Record : %d sec -----\n", time(NULL) - start_time);
	while (_getch() != 'q');
	//Performed in the event of a game-over.
}

int main()
{
	int i = 0, j = 0;
	char first_line[10][31] = { 0, };
	int pro,gameover = 0;
	int start_time = time(NULL);
	srand(start_time);
	while (1)
	{
		for (i = 0; i < 30; i++)
		{
			pro = rand() % 100;
			if (pro > 95)
			{
				first_line[0][i] = '*';
			}
			else
			{
				first_line[0][i] = 0x20;
			}
		}
		//Make star in first line
		printf("------------------------------\n");
		
		printf("%s", first_line[0]);
		printf(" | %d |\n", time(NULL) - start_time);
		//First star line.
		for (j = 1; j < 10; j++) { printf("\n%s\n", first_line[j]); }
		//Second ~ end star line. 

		Detect_key();
		//Detect left,right key.
		printf("------------------------------\n");

		for (j = 9; j > 0; j--)
		{
			if (j == 9)
			{
				if (first_line[9][index] == '*')
				{
					gameover = 1;
					break;
				}
			}
			for (i = 0; i < 30; i++)
			{
				first_line[j][i] = first_line[j - 1][i];
			}
		}
		//Move star to next line.
		if (gameover)
		{
			Game_over(start_time);
			break;
		}
		else
		{
			delay(50);
			system("cls");
			//If it's not a gameover, continue.
		}
	}
	return 0;
}
