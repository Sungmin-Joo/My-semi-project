#include<stdio.h>
#include<string.h>

void main()
{
	int i,j;
	int k=0;
	char input[100];
	char output[5][16];

	printf(" 단어 5개를 띄어쓰기로 구분하여 한 문자열로 입력하시오(특수문자 포함 가능) : \n");
	printf(" 예: Apple Banana Watermelon Love Great!! \n\n");

    gets(input);

	for(i=0; i<5; i++)
	{
		for (j=0; j<16; j++)
		{
		  if((input[k] == ' ') || (input[k] == '\0')) // input[k]가 빈칸이거나 널값이다?
		  { output[i][j] = '\0'; k++; break;} // output[i][글자수] 
		  else if (input[k] == ' ' && input[k + 1] != ' ' && input[k + 1] != NULL)
		  { output[i][j] = input[k]; } 
		  else
		  { output[i][j] = input[k]; k++; }
		}
	}
		printf("\n\n");

		for (i=0; i<5; i++)
			printf("%s\n", output[i]);

		printf("\n\n");
	
   i=0;
   for(j=0; j<5; j++)
         if(strlen(output[i]) < strlen(output[j]))
            i=j;
   printf("\n 제일 긴 문자열은? : %s", output[i]);

   i=0;
   for(j=0; j<5; j++)
         if(strlen(output[i]) > strlen(output[j]))
            i=j;
   printf("\n 제일 짧은 문자열은? : %s\n", output[i]);
   

}
