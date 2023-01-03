#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reserve_string(char* str, int s, int e)
{
	char temp;
	while (s < e) {
		temp = str[e];
		str[e] = str[s];
		str[s] = temp;
		e--;
		s++;
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