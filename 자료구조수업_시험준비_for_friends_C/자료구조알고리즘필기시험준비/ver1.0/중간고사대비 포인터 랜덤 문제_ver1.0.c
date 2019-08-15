#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
	char **ptrptr, *ptrArray[5], ans, strans[20];
	int i, len, j, z, k, cnt, mod;

	srand(time(NULL));
	system("mode con cols=55 lines=15");
	system("tiTle 자료구조 중간고사 준비 ver 1.0_made by Joo");
	system("COLOR 0A");
	ptrArray[0] = "Korea";
	ptrArray[1] = "Polytechnic";
	ptrArray[2] = "University";
	ptrArray[3] = "Love";
	ptrArray[4] = "Study";

	ptrptr = ptrArray;
	
	while (1)
	{
		system("cls");
		printf("------------------------------------------------------\n");
		printf("문제 유형을 고르세요.\n1. 문자 예측\n2. 문자열 예측\n3. 섞어서 예측 해보기\n4. 종료\n-----------> : ");
		scanf_s("%d", &mod);
		while (getchar() != '\n');
		
		cnt = 0;
		if (mod == 1)
		{
			for (k = 0; k < 10; k++)
			{
				system("cls");
				printf("------------------------------------------------------\n");
				printf("ptrArray[0] = \"Korea\"\n");
				printf("ptrArray[1] = \"Polytechnic\"\n");
				printf("ptrArray[2] = \"University\"\n");
				printf("ptrArray[3] = \"Love\"\n");
				printf("ptrArray[4] = \"Study\"\n");
				printf("------------------------------------------------------\n");

				printf("'ptrptr = ptrArray' 를 수행했다.\n");

				i = rand() % 5;
				len = strlen(ptrArray[i]);
				j = rand() % len;
				z = rand() % 3;
				printf("다음 표현의 결과는?\n");

				if (!((*(*(ptrptr + i) + j) + z >= 'a' && *(*(ptrptr + i) + j) + z <= 'z') || (*(*(ptrptr + i) + j) + z >= 'A' && *(*(ptrptr + i) + j) + z <= 'Z')))
					z = 0;

				if (i != 0 && j != 0 && z != 0)
					printf("printf(\"%%c\",*(*(ptrptr + %d) + %d) + %d) : ", i, j, z);
				else if (i != 0 && j != 0 && z == 0)
					printf("printf(\"%%c\",*(*(ptrptr + %d) + %d)) : ", i, j);
				else if (i != 0 && j == 0 && z != 0)
					printf("printf(\"%%c\",**(ptrptr + %d) + %d) : ", i, z);
				else if (i != 0 && j == 0 && z == 0)
					printf("printf(\"%%c\",**(ptrptr + %d)) : ", i);
				else if (i == 0 && j != 0 && z != 0)
					printf("printf(\"%%c\",*(*ptrptr + %d) + %d) : ", j, z);
				else if (i == 0 && j != 0 && z == 0)
					printf("printf(\"%%c\",*(*ptrptr + %d)) : ", j);
				else if (i == 0 && j == 0 && z != 0)
					printf("printf(\"%%c\",**ptrptr + %d) : ", z);
				else
					printf("printf(\"%%c\",**ptrptr) : ");

				scanf_s("%c", &ans, sizeof(ans));
				while (getchar() != '\n');

				if (ans == *(*(ptrptr + i) + j) + z)
				{
					printf("정답! 엔터를 눌러 다음문제!\n");
					cnt += 10;
				}
				else
					printf("오답! 정답은 = %c\n엔터를 눌러 다음문제로!", *(*(ptrptr + i) + j) + z);
				getchar();
			}
			system("cls");
			printf("======================== 결과 ========================\n");
			printf("점수는 100점 만점에 %d 입니다.\n", cnt);
			printf("======================================================\n");
			printf("초기 화면으로 가려면 엔터를 누르시오!.\n");
			getchar();
		}
		else if (mod == 2)
		{
			for (k = 0; k < 10; k++)
			{
				system("cls");
				printf("------------------------------------------------------\n");
				printf("ptrArray[0] = \"Korea\"\n");
				printf("ptrArray[1] = \"Polytechnic\"\n");
				printf("ptrArray[2] = \"University\"\n");
				printf("ptrArray[3] = \"Love\"\n");
				printf("ptrArray[4] = \"Study\"\n");
				printf("------------------------------------------------------\n");

				printf("{ ptrptr = ptrArray; } 를 수행했다.\n");

				i = rand() % 5;
				len = strlen(ptrArray[i]);
				j = rand() % (len - 1);

				printf("다음 표현의 결과는?\n");

				if(i != 0 && j != 0)
					printf("printf(\"%%s\",*(ptrptr + %d) + %d) : ", i, j);
				else if(i != 0 && j == 0)
					printf("printf(\"%%s\",*(ptrptr + %d)) : ", i);
				else if (i == 0 && j != 0)
					printf("printf(\"%%s\",*(ptrptr) + %d) : ", j);
				else
					printf("printf(\"%%s\",*(ptrptr) : ");

				scanf_s("%s", strans, sizeof(strans));
				while (getchar() != '\n');

				if (!(strcmp(strans, *(ptrptr + i) + j)))
				{
					printf("정답! 엔터를 눌러 다음문제!\n");
					cnt += 10;
				}
				else
					printf("오답! 정답은 = %s\n엔터를 눌러 다음문제로!", *(ptrptr + i) + j);
				getchar();
			}
			system("cls");
			printf("======================== 결과 ========================\n");
			printf("점수는 100점 만점에 %d 입니다.\n", cnt);
			printf("======================================================\n");
			printf("초기 화면으로 가려면 엔터를 누르시오!.\n");
			getchar();
		}
		else if (mod == 3)
		{
			for (k = 0; k < 10; k++)
			{
				system("cls");
				printf("------------------------------------------------------\n");
				printf("ptrArray[0] = \"Korea\"\n");
				printf("ptrArray[1] = \"Polytechnic\"\n");
				printf("ptrArray[2] = \"University\"\n");
				printf("ptrArray[3] = \"Love\"\n");
				printf("ptrArray[4] = \"Study\"\n");
				printf("------------------------------------------------------\n");

				printf("{ ptrptr = ptrArray; } 를 수행했다.\n");

				i = rand() % 5;
				len = strlen(ptrArray[i]);
				j = rand() % (len - 1);

				printf("다음 표현의 결과는?\n");

				if (rand() % 2)
				{
					z = rand() % 3;
					if (!((*(*(ptrptr + i) + j) + z >= 'a' && *(*(ptrptr + i) + j) + z <= 'z') || (*(*(ptrptr + i) + j) + z >= 'A' && *(*(ptrptr + i) + j) + z <= 'Z')))
						z = 0;

					if (i != 0 && j != 0 && z != 0)
						printf("printf(\"%%c\",*(*(ptrptr + %d) + %d) + %d) : ", i, j, z);
					else if (i != 0 && j != 0 && z == 0)
						printf("printf(\"%%c\",*(*(ptrptr + %d) + %d)) : ", i, j);
					else if (i != 0 && j == 0 && z != 0)
						printf("printf(\"%%c\",**(ptrptr + %d) + %d) : ", i, z);
					else if (i != 0 && j == 0 && z == 0)
						printf("printf(\"%%c\",**(ptrptr + %d)) : ", i);
					else if (i == 0 && j != 0 && z != 0)
						printf("printf(\"%%c\",*(*ptrptr + %d) + %d) : ", j, z);
					else if (i == 0 && j != 0 && z == 0)
						printf("printf(\"%%c\",*(*ptrptr + %d)) : ", j);
					else if (i == 0 && j == 0 && z != 0)
						printf("printf(\"%%c\",**ptrptr + %d) : ", z);
					else
						printf("printf(\"%%c\",**ptrptr) : ");

					scanf_s("%c", &ans, sizeof(ans));
					while (getchar() != '\n');

					if (ans == *(*(ptrptr + i) + j) + z)
					{
						printf("정답! 엔터를 눌러 다음문제!\n");
						cnt += 10;
					}
					else
						printf("오답! 정답은 = %c\n엔터를 눌러 다음문제로!", *(*(ptrptr + i) + j) + z);
					getchar();
				}
				else
				{
					if (i != 0 && j != 0)
						printf("printf(\"%%s\",*(ptrptr + %d) + %d) : ", i, j);
					else if (i != 0 && j == 0)
						printf("printf(\"%%s\",*(ptrptr + %d)) : ", i);
					else if (i == 0 && j != 0)
						printf("printf(\"%%s\",*(ptrptr) + %d) : ", j);
					else
						printf("printf(\"%%s\",*(ptrptr) : ");

					scanf_s("%s", strans, sizeof(strans));
					while (getchar() != '\n');

					if (!(strcmp(strans, *(ptrptr + i) + j)))
					{
						printf("정답! 엔터를 눌러 다음문제!\n");
						cnt += 10;
					}
					else
						printf("오답! 정답은 = %s\n엔터를 눌러 다음문제로!", *(ptrptr + i) + j);
					getchar();
				}
			}
			system("cls");
			printf("======================== 결과 ========================\n");
			printf("점수는 100점 만점에 %d 입니다.\n", cnt);
			printf("======================================================\n");
			printf("초기 화면으로 가려면 엔터를 누르시오!.\n");
			getchar();
		}
		else if (mod == 4)
			break;
		else
		{
			printf("이상한 값은 넣지 마세요.\n");
			Sleep(1000);
		}

	}
	return 0;
}

