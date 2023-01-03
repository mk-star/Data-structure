#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reserve_string(char* str, int s, int e)
{
	char temp;
	if (e < s)
		return;
	else {
		temp = str[e];
		str[e] = str[s];
		str[s] = temp;

		reserve_string(str, s + 1, e - 1);
	}
}
int main()
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	reserve_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}