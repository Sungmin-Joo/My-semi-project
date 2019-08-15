#include <stdio.h>
#include <string.h>


void main()
{
	char *input = "korea polytechnic university love me";    
	int num[26] = { 0 };
	int i = 0;
	int max = 0;
	int max_idx = 0;
	int len = strlen(input);
	printf("문자열 : %s \n", input);
	while (len--)
	{
		char temp = *(input + i++);
		if(temp >= 'a' && temp < 'z')
			num[temp - 'a']++;
		else if(temp >= 'A' && temp <= 'Z')
			num[temp - 'A']++;
	}
	putchar('\n');

	len = 26;
	while (len--)
	{
		if (max < num[len])
		{
			max_idx = len;
			max = num[len++];
		}
	}
	printf("%d 번 %c가 제일 많이 나옴.", max, max_idx + 'a');
}