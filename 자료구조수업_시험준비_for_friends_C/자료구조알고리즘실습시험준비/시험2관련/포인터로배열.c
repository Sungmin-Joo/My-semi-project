#include <stdio.h>
#include <string.h>


int strdict(char *p1, char *p2)
{
	int max, i;
	char temp1, temp2;
	char *p_1, *p_2;
	p_1 = p1;
	p_2 = p2;
	if (strlen(p_1) < strlen(p_2))
	{
		max = strlen(p_2);
	}
	else
	{
		max = strlen(p_1);
	}
	for (i = 0; i < max; i++)
	{
		temp1 = *p_1;
		temp2 = *p_2;
		if (temp1 >= 0x41 && temp1 <= 0x5A)
			temp1 += 0x20;
		if (temp2 >= 0x41 && temp2 <= 0x5A)
			temp2 += 0x20;
		if (temp1 != temp2)
		{
			break;
		}
		p_1++;
		p_2++;
	}
	return temp2 - temp1;
}

void main()
{
	char fruit[4][20] = { "apple@@@@@@@@@@@@@","grape!","banana!!","mango" };
	char *ptr[4], *temp;
	int i, j;
	ptr[0] = fruit[0];
	ptr[1] = fruit[1];
	ptr[2] = fruit[2];
	ptr[3] = fruit[3];
	printf("%s\n", ptr[0]);
	printf("%s\n", ptr[1]);
	printf("%s\n", ptr[2]);
	printf("%s\n", ptr[3]);
	i = 0;
	do {
		j = 0;
		do {
			if (strlen(ptr[j]) > strlen(ptr[j + 1]))
			{
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
			j++;
		} while (j < 3 - i);
		i++;
	} while (i < 3);
	printf("==================================길이순 배열\n");
	printf("%s\n", ptr[0]);
	printf("%s\n", ptr[1]);
	printf("%s\n", ptr[2]);
	printf("%s\n", ptr[3]);
	printf("==================================사전 순으로 정렬된 후 결과\n");
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			if (strdict(ptr[i], ptr[j]) < 0)
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
				j = i;
			}
		}
	}
	printf("%s\n", ptr[0]);
	printf("%s\n", ptr[1]);
	printf("%s\n", ptr[2]);
	printf("%s\n", ptr[3]);

}