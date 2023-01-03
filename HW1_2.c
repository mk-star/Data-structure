#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
void init(StackType* s)
{
	s->top = -1;
}
int is_empty(StackType* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}
int is_full(StackType* s)
{
	if (s->top == (MAX_STACK_SIZE - 1))
		return 1;
	else
		return 0;
}
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
	}
}
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		int e = s->data[s->top];
		s->top--;
		return e;
	}
}
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
int palindrome(char str[]) 
{
	StackType s;
	int i;

	init(&s);
	for (i = 0; i < strlen(str); i++)
		push(&s, str[i]);
	for (i = 0; i < strlen(str); i++)
		if (str[i] != pop(&s))
			return 0;
	return 1;
}
int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome�Դϴ�.\n");
	else
		printf("palindrome�� �ƴմϴ�.\n");

	return 0;
}