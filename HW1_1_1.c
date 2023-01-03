#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3
typedef int element;
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
	if (s->top >= (MAX_STACK_SIZE - 1))
		return 1;
	else
		return 0;
}
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
	}
}
void pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		s->top--;
}
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
void stack_print(StackType* s)
{
	int i;
	if (is_empty(s))
		fprintf(stderr, "<empty>\n");
	else {
		for (i = s->top; i >= 0; i--) {
			printf("%d", s->data[i]);
			if (i == s->top)
				printf(" <- top");
			printf("\n");
		}
	}
	printf("--\n");
}
int main(void)
{
	StackType s;

	init(&s);
	stack_print(&s);
	push(&s, 10);
	stack_print(&s);
	push(&s, 20);
	stack_print(&s);
	push(&s, 30);
	stack_print(&s);
	push(&s, 40);
	stack_print(&s);
	push(&s, 50);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);

	return 0;
}