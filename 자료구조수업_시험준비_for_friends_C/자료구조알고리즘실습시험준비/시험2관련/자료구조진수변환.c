#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hex_to_deciaml(char A);
char* decimal_to_hex(int dec, char *tmp);
char* decimal_to_binary(int dec, char *tmp);
char switch_decimal_to_16_notation(int A);

void main(void) {
	int decimal = 0;
	char usr[20] = { 0 };
	char *ptr;
	int val, i;

	// ---------- 16진수를 10진수로 바꾸는 부분입니다. ----------
	printf("\n16진수를 10진수로 바꾸는 알고리즘\n");
	printf("Enter the hex number :");
	gets(usr);
	val = strlen(usr) - 1;
	for (i = val; i >= 0; i--)
	{
		decimal += (hex_to_deciaml(usr[i]) * (int) pow(16.0, val - i));
		//The process of converting from hex to decimal.
	}
	printf("---------------result----------------\n");
	printf("%d\n", decimal);
	printf("-------------------------------------\n");


	// ---------- 10진수를 16진수로 바꾸는 부분입니다. ----------
	printf("\n10진수를 16진수로 바꾸는 알고리즘\n");
	printf("Enter the decimal number :");
	scanf("%d",&decimal);
	//printf("%d\n", decimal);
	ptr = decimal_to_hex(decimal, usr);
	printf("---------------result----------------\n");
	printf("%s\n", ptr);
	printf("-------------------------------------\n");


	// ---------- 10진수를 2진수로 바꾸는 부분입니다. ----------
	printf("\n10진수를 2진수로 바꾸는 알고리즘\n");
	printf("Enter the decimal number :");
	scanf("%d", &decimal);
	ptr = decimal_to_binary(decimal, usr);
	printf("---------------result----------------\n");
	printf("%s\n", ptr);
	printf("-------------------------------------\n");


	// ---------- 2진수를 10진수로 바꾸는 부분입니다. ----------
	printf("\n2진수를 10진수로 바꾸는 알고리즘\n");
	printf("Enter the binary number :");
	memset(usr, 0, sizeof(usr));
	decimal = 0;
	while (getchar() != '\n');
	gets(usr);
	val = strlen(usr) - 1;
	for (i = val; i >= 0; i--)
	{
		decimal += (usr[i] - 0x30) * (int) pow(2.0, val - i);
		//The process of converting from hex to decimal.
	}
	printf("---------------result----------------\n");
	printf("%d\n", decimal);
	printf("-------------------------------------\n");

	return 0;
}

int hex_to_deciaml(char A)
{
	switch (A)
	{
	case 'F':
	case 'f':
		return 15;
		break;
	case 'E':
	case 'e':
		return 14;
		break;
	case 'D':
	case 'd':
		return 13;
		break;
	case 'C':
	case 'c':
		return 12;
		break;
	case 'B':
	case 'b':
		return 11;
		break;
	case 'A':
	case 'a':
		return 10;
		break;
	default:
		return A - 48;
		break;
		//"A - 48" means "N - 48". if cha A = '3', then "A - 48" is "51 - 48". 
	}
}

char* decimal_to_hex(int dec, char *tmp)
{
	int remainder = dec, quotient, index = 0, main_index = 0;
	char temp[20];
	while (remainder > 16 - 1)
	{
		quotient = remainder% 16;
		remainder /= 16;
		temp[index++] = switch_decimal_to_16_notation(quotient);
		//Mapping the remaining values with the switch syntax defined above.
	}
	temp[index] = switch_decimal_to_16_notation(remainder);
	for (index; index >= 0; index--)
	{
		tmp[main_index++] = temp[index];
		//Pass the value to the variable in the main().
	}
	return tmp;
}

char* decimal_to_binary(int dec, char *tmp)
{
	int remainder = dec, quotient, index = 0, main_index = 0;
	char temp[20];
	while (remainder > 1)
	{
		quotient = remainder % 2;
		remainder /= 2;
		temp[index++] = quotient + 0x30;
		//Mapping the remaining values with the switch syntax defined above.
	}
	temp[index] = remainder + 0x30;
	for (index; index >= 0; index--)
	{
		tmp[main_index++] = temp[index];
		//Pass        the value to the variable in the main().
	}
	return tmp;
}

char switch_decimal_to_16_notation(int A)
{
	switch (A)
	{
	case 15:
		return 'F';
		break;
	case 14:
		return 'E';
		break;
	case 13:
		return 'D';
		break;
	case 12:
		return 'C';
		break;
	case 11:
		return 'B';
		break;
	case 10:
		return 'A';
		break;
	default:
		return '0' + A;
		break;
	}
}