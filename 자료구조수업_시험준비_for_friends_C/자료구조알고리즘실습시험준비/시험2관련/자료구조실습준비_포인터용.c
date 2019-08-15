#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int  strdict(char *p1, char *p2);
void Switch_array(char *str1, char *str2);

void main(void) {
	char *str = "Korea Polytechnic University Love Me";
	char buff[5][20];
	char *ptr = str;
	char temp_buff[20];
	char data;
	int r = 0, c = 0, i, j;
	printf("포인터 문자열을 배열에 저장 + '\\0' 넣어서 각각 문자열처럼 쓸 수 있게 하는 과정\n");
	for(i = 0; i < strlen(str) ; i++)
	{
		data = *ptr;
		if (data == ' ')
		{
			buff[r][c] = '\0';
			r++;
			c = 0;
		}
		else
		{
			buff[r][c] = data;
			c++;
		}
		ptr++;
	}
	buff[r][c] = '\0';
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < strlen(buff[i]); j++)
			putchar(buff[i][j]);
		putchar('\n');
	}
	//정렬시작
	i = 0;
	do {
		j = 0;
		do {
			if (strlen(buff[j]) > strlen(buff[j + 1]))
			{
				strcpy(temp_buff, buff[j]);
				strcpy(buff[j], buff[j+1]);
				strcpy(buff[j+1], temp_buff);
			}
			j++;
		} while (j < 4 - i);
		i++;
	} while (i < 4);
	
	printf("==================================\n길이가 작은 순으로 정렬된 후 결과\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < strlen(buff[i]); j++)
			putchar(buff[i][j]);
		putchar('\n');
	}
	//사전순 정렬 시작

	printf("Output in dict order.\n");
	printf("==================================\n사전 순으로 정렬된 후 결과\n");
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strdict(buff[i], buff[j]) < 0)
			{
				Switch_array(buff[i], buff[j]);
				j = i;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", buff[i]);
	}
	printf("==================================\n");


}


int strdict(char *p1, char *p2)
{
	int max, i;
	char temp1, temp2;

	if (strlen(p1) < strlen(p2))
	{
		max = strlen(p2);
	}
	else
	{
		max = strlen(p1);
	}
	for (i = 0; i < max; i++)
	{
		temp1 = *p1;
		temp2 = *p2;
		if (temp1 >= 0x41 && temp1 <= 0x5A)
			temp1 += 0x20;
		if (temp2 >= 0x41 && temp2 <= 0x5A)
			temp2 += 0x20;
		if (temp1 != temp2)
		{
			break;
		}
		p1++;
		p2++;
	}
	return temp2 - temp1;
}

void Switch_array(char *str1, char *str2)
{
	char temp;
	int max, i;
	if (strlen(str1) < strlen(str2))
	{
		max = strlen(str2);
	}
	else
	{
		max = strlen(str1);
	}
	for (i = 0; i < max; i++)
	{
		temp = str1[i];
		str1[i] = str2[i];
		str2[i] = temp;
	}
}