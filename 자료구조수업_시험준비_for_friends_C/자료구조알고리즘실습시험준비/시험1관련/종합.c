#include <stdio.h>
#include <string.h>
#include <math.h>

int  strdict(char *p1, char *p2);
void Switch_array(char *str1, char *str2);

void main() {

	char *ptrArray[5], input[100], output[5][20] = { 0, }, *ptr;
	char **ptrptr;
	int buf;
	int i = 0, j, count = 0, max = 0, index = 0, min, sum = 0, cnt = 0;

	ptrptr = ptrArray;
	printf("Enter 5 strings separated by spacing. : ");
	gets(input);
	ptr = input;
	count = 0;
	i = 0;

	//Outputs the entered string with a pointer
	printf("========입력문자 그냥출력==========\n");
	while (1)
	{
		if (*ptr == ' ') //Outputs an opening character when the current pointer indicates a space in the charactor.
		{
			printf("\n");
			output[count][i] = '\0';
			count++;
			i = 0;
		}
		else if (*ptr == NULL)//Breaks the while statement when the current pointer points to NULL.
		{
			output[count][i] = '\0';
			printf("\n===================================\n");
			break;
		}
		else
		{
			output[count][i++] = *ptr;
			printf("%c", *ptr);
		}
		ptr++;
	}

	for (i = 0; i < 5; i++)
		ptrArray[i] = output[i];



	printf("========대소문자 반전출력==========\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < strlen(*(ptrptr + i)); j++)
		{
			if (*(*(ptrptr + i) + j) >= 'A' && *(*(ptrptr + i) + j) <= 'Z')
				putchar(*(*(ptrptr + i) + j) + 0x20);
			else if (*(*(ptrptr + i) + j) >= 'a' && *(*(ptrptr + i) + j) <= 'z')
				putchar(*(*(ptrptr + i) + j) - 0x20);
			else
				putchar(*(*(ptrptr + i) + j));
		}
		putchar('\n');
	}

	printf("==================================\n");

	ptrptr = ptrArray;
	for (i = 0; i < 5; i++)
	{
		if (strlen(*(ptrptr + i)) > max)
		{
			max = strlen(*(ptrptr + i));
			index = i;
		}
	}
	printf("가장 긴 길이 : %d\n", max);
	printf("가장 긴 단어 : %s\n", *(ptrptr + index));
	printf("==================================\n");


	min = max;
	for (i = 0; i < 5; i++)
	{
		if (strlen(*(ptrptr + i)) < min)
		{
			min = strlen(*(ptrptr + i));
			index = i;
		}
	}
	printf("가장 짧은 길이 : %d\n", min);
	printf("가장 짧은 단어 : %s\n", *(ptrptr + index));
	printf("==================================\n");


	j = 0;
	index = 0;
	for (i = 0; i < 5; i++)
	{

		buf = strdict(*(ptrptr + j), *(ptrptr + i));
		if (buf >  0)
		{
			j = i;
			index = i;
		}

	}
	printf("사전적으로 가장 뒤에오는 단어 : %s\n", *(ptrptr + index));
	printf("==================================\n");

	printf("Output in length order.\n");
	printf("==================================\n");
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strlen(output[i]) > strlen(output[j]))
			{
				Switch_array(output[i], output[j]);
				j = i;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", output[i]);
	}
	printf("==================================\n");


	printf("Output in dict order.\n");
	printf("==================================\n");
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strdict(output[i], output[j]) < 0)
			{
				Switch_array(output[i], output[j]);
				j = i;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", output[i]);
	}
	printf("==================================\n");


	printf("Enter binary code. : ");
	gets(input);
	ptr = input;
	buf = strlen(input);
	printf("2의 보수 출력 : ");
	while (buf--)
		(*ptr++ == '1') ? putchar('0') : putchar('1');
	putchar('\n');

	ptr = input;
	buf = strlen(input);
	while (buf--)
	{
		if (*ptr++ == '1')
			sum += pow(2.0, buf);
	}
	printf("입력한 2진수의 10진수 값 : %d\n", sum);


	printf("입력한 2진수의 16진수 값 : ");
	ptr = input;
	buf = strlen(input);
	cnt = buf % 4;
	sum = 0;
	for (i = 0 ; i < cnt; i++)
	{
		if (*ptr++ == '1')
			sum += pow(2.0, cnt - i - 1);
	}
	if(sum)
		(sum >= 10) ? putchar('A'+ sum - 10) : putchar('0'+sum);
	for (i = 0; i < (buf / 4) ; i++)
	{
		sum = 0;
		for (j = 0; j < 4; j++)
		{
			if (*ptr++ == '1')
				sum += pow(2.0, 3 - j);
		}
		(sum >= 10) ? putchar('A' + sum - 10) : putchar('0' + sum);
	}
	
	printf("\n==================================\n");
/*
	printf("Enter binary code. : ");
	gets(input);
	ptr = input;
	buf = strlen(input);*/
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