#include <stdio.h>
#include <string.h>

int  strdict(char *p1, char *p2)
{
	int max,i;
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

void main() {
	
	char *ptrArray[5] , input[100], output[5][20], *ptr;
	char **ptrptr;
	int buf;
	int i = 0, j, count = 0, max = 0,index = 0, min;

	gets(input);
	ptr = input;
	count = 0;
	i = 0;
	//Outputs the entered string with a pointer
	printf("\n--------------------\n", *ptr);
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
			printf("\n--------------------\n", *ptr);
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

	ptrptr = ptrArray;

	for(i = 0; i < 5; i++)
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
			max = strlen(*(ptrptr + i));
			index = i;
		}
	}
	printf("가장 짧은 길이 : %d\n", max);
	printf("가장 짧은 단어 : %s\n", *(ptrptr + index));
	printf("==================================\n");


	j = 0;
	for (i = 0; i < 5; i++)
	{
		
		buf = strdict(*(ptrptr + j), *(ptrptr + i));
		if (buf > 0)
		{
			j = i;
			index = i;
		}
		
	}
	printf("사전적으로 가장 뒤에오는 단어 : %s\n", *(ptrptr + index));
	printf("==================================\n");

}