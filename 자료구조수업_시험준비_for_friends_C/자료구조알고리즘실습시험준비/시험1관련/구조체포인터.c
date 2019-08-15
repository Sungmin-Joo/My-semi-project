#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;
};

void main() {
	int i, max = 0, index = 0;
	struct employee team[4] = {
		{ "이진호", 2014, 4200 },
		{ "이한영", 2015, 3300 },
		{ "이상원", 2015, 3500 },
		{ "이상범", 2016, 2900 }
	}; 
	struct employee *ptr;
	ptr = team;

	for (i = 0; i < 4; i++)
	{
		if ((ptr + i)->pay > max)
		{
			max = (ptr + i)->pay;
			index = i;
		}
	}
	printf("\n\n가장 큰 월급은 : %d \n\n", max);
	printf("\n\n가장 월급이 많은 사람 이름 : %s \n\n", (ptr+index) -> name);


	for (i = 0; i<4; i++) {
		printf("\n 이름 : %s", team[i].name);
		printf("\n 입사 : %d", team[i].year);
		printf("\n 연봉 : %d \n", team[i].pay);
	}
	getchar();

	/*char *ptrArray[5];
	char **ptrptr;
	int i, max = 0,index = 0;

	ptrptr = ptrArray;

	ptrArray[0] = "Korea";
	ptrArray[1] = "Polytechic";
	ptrArray[2] = "University";
	ptrArray[3] = "Apppppppppppppple";
	ptrArray[4] = "Pi";
	
	for(i = 0; i < 5; i++)
	{
		if (strlen(*(ptrptr + i)) > max)
		{
			max = strlen(*(ptrptr + i));
			index = i;
		}
	}
	printf("가장 긴 길이 : %d\n", max);
	printf("가장 긴 단어 : %s\n", *(ptrptr + index));*/
}