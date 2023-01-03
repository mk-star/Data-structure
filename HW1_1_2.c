#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING 100
typedef struct {
	int num;
	char str[MAX_STRING];
} element;
element stack[MAX_STACK_SIZE];
int top = -1;
int is_empty()
{
	return (top == -1);
}
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		top++;
		stack[top] = item;
	}
}
void pop()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		top--;
}
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[top];
}
void stack_print(element* item)
{
	int i;
	if (is_empty())
		fprintf(stderr, "<empty>\n");
	else {
		for (i = top; i >= 0; i--) {
			printf("[%d, %s]", item[i].num, item[i].str);
			if (i == top)
				printf(" <- top");
			printf("\n");
		}
	}
	printf("--\n");
}
int main(void)
{
	element e;

	stack_print(&stack);
	e.num = 10;
	strcpy(e.str, "ten");
	push(e);
	stack_print(&stack);
	e.num = 20;
	strcpy(e.str, "twenty");
	push(e);
	stack_print(&stack);
	e.num = 30;
	strcpy(e.str, "thirty");
	push(e);
	stack_print(&stack);
	e.num = 40;
	strcpy(e.str, "forty");
	push(e);
	stack_print(&stack);
	pop();
	stack_print(stack);
	e.num = 50;
	strcpy(e.str, "fifty");
	push(e);
	stack_print(&stack);
	pop();
	stack_print(&stack);
	pop();
	stack_print(&stack);
	pop();
	stack_print(&stack);

	return 0;
}