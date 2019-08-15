#include <stdio.h>
#include <string.h>

int main() {
	char *str = "Korea Polytechnic University", *ptr;
	ptr = str + strlen(str);
	while (ptr-- != str)
	{
		if (*ptr >= 0x41 && *ptr <= 0x5A)
			putchar(*ptr + 0x20);
		else
			putchar(*ptr - 0x20);
	}
	putchar('\n');
	return 0;
}